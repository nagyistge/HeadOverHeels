
#include "PlayerHead.hpp"
#include "Item.hpp"
#include "ItemData.hpp"
#include "PlayerItem.hpp"
#include "Mediator.hpp"
#include "MoveState.hpp"
#include "DisplaceState.hpp"
#include "FallState.hpp"
#include "InputManager.hpp"
#include "SoundManager.hpp"


namespace isomot
{

PlayerHead::PlayerHead( Item* item, const BehaviorId& id ) :
        UserControlled( item, id )
{
        // Fotogramas del salto
        jumpFrames = 20;
        highJumpFrames = 19;

        // Definición del salto normal
        for ( int i = 0; i < jumpFrames; i++ )
        {
                // Unidades que se desplazará en el eje X o Y y en el eje Z, respectivamente
                JumpMotion jumpMotion( 1, 3 );
                jumpMatrix.push_back( jumpMotion );
        }

        // Definición del salto largo
        for ( int i = 0; i < highJumpFrames; i++ )
        {
                // Unidades que se desplazará en el eje X o Y y en el eje Z, respectivamente
                JumpMotion jumpMotion( 1, 4 );
                highJumpMatrix.push_back( jumpMotion );
        }

        // La primera fase del salto
        jumpIndex = 0;

        // Fotogramas de caída
        fallFrames[ North ] = 6;
        fallFrames[ South ] = 12;
        fallFrames[ East ] = 9;
        fallFrames[ West ] = 13;

        // Fotograma en blanco
        nullFrame = 14;

        // Fotogramas de parpadeo
        blinkFrames[ North ] = 6;
        blinkFrames[ South ] = 15;
        blinkFrames[ East ] = 9;
        blinkFrames[ West ] = 16;

        // Elemento de transición entre telepuertos
        transitionDataLabel = 38;
        // Elemento empleado como disparo
        shotDataLabel = 38;

        // Pasos automáticos
        automaticStepsCounter = 16;

        // Estado inicial
        stateId = StateWait;

        // Creación y puesta en marcha de los cronómetros
        speedTimer = new HPC ();
        fallTimer = new HPC ();
        glideTimer = new HPC ();
        blinkingTimer = new HPC ();
        speedTimer->start ();
        fallTimer->start ();
        glideTimer->start ();
        blinkingTimer->start ();

        // En principio no hay ningún disparo en la sala
        shotPresent = false;
}

PlayerHead::~PlayerHead( )
{
        delete speedTimer;
        delete fallTimer;
        delete glideTimer;
        delete blinkingTimer;

        jumpMatrix.clear();
        highJumpMatrix.clear();
}

bool PlayerHead::update ()
{
        PlayerItem* playerItem = dynamic_cast< PlayerItem* >( this->item );

        // Comprueba si tiene inmunidad y, en tal caso, si ha finalizado
        if ( playerItem->getShieldTime() > 0 )
        {
                playerItem->decreaseShield();
        }

        // Parche para facilitar la entrada a las escaleras pero manteniendo la altura "real" de Head
        playerItem->setHeight( stateId == StateFall || stateId == StateGlide ? 23 : 24 );

        // Acciones a realizar en función del estado actual del jugador
        switch ( stateId )
        {
                case StateWait:
                        wait( playerItem );
                        break;

                case StateAutoMoveNorth:
                case StateAutoMoveSouth:
                case StateAutoMoveEast:
                case StateAutoMoveWest:
                        autoMove( playerItem );
                        break;

                case StateMoveNorth:
                case StateMoveSouth:
                case StateMoveEast:
                case StateMoveWest:
                        move( playerItem );
                        break;

                case StateDisplaceNorth:
                case StateDisplaceSouth:
                case StateDisplaceEast:
                case StateDisplaceWest:
                case StateDisplaceNortheast:
                case StateDisplaceSoutheast:
                case StateDisplaceSouthwest:
                case StateDisplaceNorthwest:
                case StateForceDisplaceNorth:
                case StateForceDisplaceSouth:
                case StateForceDisplaceEast:
                case StateForceDisplaceWest:
                        displace( playerItem );
                        break;

                case StateCancelDisplaceNorth:
                case StateCancelDisplaceSouth:
                case StateCancelDisplaceEast:
                case StateCancelDisplaceWest:
                        cancelDisplace( playerItem );
                        break;

                case StateFall:
                        fall( playerItem );
                        break;

                case StateJump:
                case StateRegularJump:
                case StateHighJump:
                        jump( playerItem );
                        break;

                case StateStartWayOutTeletransport:
                case StateWayOutTeletransport:
                        wayOutTeletransport( playerItem );
                        break;

                case StateStartWayInTeletransport:
                case StateWayInTeletransport:
                        wayInTeletransport( playerItem );
                        break;

                case StateStartDestroy:
                case StateDestroy:
                        destroy( playerItem );
                        break;

                case StateGlide:
                        glide( playerItem );
                        break;

                case StateBlink:
                        blink( playerItem );
                        break;

                default:
                        ;
        }

        // Reproduce el sonido asociado al estado actual
        this->soundManager->play( playerItem->getLabel(), stateId );

        return false;
}

void PlayerHead::behave ()
{
        PlayerItem* playerItem = dynamic_cast< PlayerItem* >( this->item );
        InputManager* input = InputManager::getInstance();

        // Si no está en modo automático
        if ( stateId != StateAutoMoveNorth && stateId != StateAutoMoveSouth && stateId != StateAutoMoveEast && stateId != StateAutoMoveWest &&
                stateId != StateStartWayOutTeletransport && stateId != StateWayOutTeletransport && stateId != StateStartWayInTeletransport && stateId != StateWayInTeletransport &&
                stateId != StateStartDestroy && stateId != StateDestroy )
        {
                // Si está esperando o parpadeando
                if ( stateId == StateWait || stateId == StateBlink )
                {
                        // ...y se ha pulsado la tecla de salto entonces salta
                        if ( input->jump() )
                        {
                                // Almacena en la pila de colisiones los elementos que tiene debajo
                                playerItem->checkPosition(0, 0, -1, Add);
                                // Si está sobre un telepuerto y salta entonces el jugador será teletransportado, sino saltará
                                stateId = ( playerItem->getMediator()->collisionWithByBehavior( TeleportBehavior ) ? StateStartWayOutTeletransport : StateJump );
                        }
                        // ...y ha pulsado la tecla de disparo entonces dispara
                        else if ( input->shoot() && !shotPresent )
                        {
                                shot( playerItem );
                                // Las repeticiones de esta tecla no deben procesarse
                                input->noRepeat( "shoot" );
                        }
                        // ...y se ha pulsado alguna tecla de movimiento entonces se mueve
                        else if ( input->movenorth() && !input->movesouth() && !input->moveeast() && !input->movewest() )
                        {
                                stateId = StateMoveNorth;
                        }
                        else if ( !input->movenorth() && input->movesouth() && !input->moveeast() && !input->movewest() )
                        {
                                stateId = StateMoveSouth;
                        }
                        else if ( !input->movenorth() && !input->movesouth() && input->moveeast() && !input->movewest() )
                        {
                                stateId = StateMoveEast;
                        }
                        else if ( !input->movenorth() && !input->movesouth() && !input->moveeast() && input->movewest() )
                        {
                                stateId = StateMoveWest;
                        }
                }
                // Si está moviéndose
                else if ( stateId == StateMoveNorth || stateId == StateMoveSouth || stateId == StateMoveEast || stateId == StateMoveWest )
                {
                        // ...y se ha pulsado la tecla de salto entonces salta
                        if ( input->jump() )
                        {
                                // Almacena en la pila de colisiones los elementos que tiene debajo
                                playerItem->checkPosition( 0, 0, -1, Add );
                                // Si está sobre un telepuerto y salta entonces el jugador será teletransportado, sino saltará
                                stateId = ( playerItem->getMediator()->collisionWithByBehavior( TeleportBehavior ) ? StateStartWayOutTeletransport : StateJump );
                        }
                        // ...y ha pulsado la tecla de disparo entonces dispara
                        else if ( input->shoot() && !shotPresent )
                        {
                                shot( playerItem );
                                // Las repeticiones de esta tecla no deben procesarse
                                input->noRepeat( "shoot" );
                        }
                        // ...y se ha pulsado alguna tecla de movimiento entonces sigue moviéndose
                        else if ( input->movenorth() && !input->movesouth() && !input->moveeast() && !input->movewest() )
                        {
                                stateId = StateMoveNorth;
                        }
                        else if ( !input->movenorth() && input->movesouth() && !input->moveeast() && !input->movewest() )
                        {
                                stateId = StateMoveSouth;
                        }
                        else if ( !input->movenorth() && !input->movesouth() && input->moveeast() && !input->movewest() )
                        {
                                stateId = StateMoveEast;
                        }
                        else if ( !input->movenorth() && !input->movesouth() && !input->moveeast() && input->movewest() )
                        {
                                stateId = StateMoveWest;
                        }
                        // Si por el contrario se han soltado las teclas de movimiento entonces se pone en espera
                        else if ( !input->movenorth() && !input->movesouth() && !input->moveeast() && !input->movewest() )
                        {
                                SoundManager::getInstance()->stop( playerItem->getLabel(), stateId );
                                stateId = StateWait;
                        }
                }
                // Si está siendo desplazado
                else if ( stateId == StateDisplaceNorth || stateId == StateDisplaceSouth || stateId == StateDisplaceEast || stateId == StateDisplaceWest )
                {
                        // ...y se ha pulsado la tecla de salto entonces salta
                        if ( input->jump() )
                        {
                                stateId = StateJump;
                        }
                        // ...y se ha pulsado la tecla de disparo entonces dispara
                        else if ( input->shoot() && !shotPresent )
                        {
                                shot( playerItem );
                                // Las repeticiones de esta tecla no deben procesarse
                                input->noRepeat( "shoot" );
                        }
                        // ...y se ha pulsado alguna tecla de movimiento entonces sigue moviéndose
                        else if ( input->movenorth() && !input->movesouth() && !input->moveeast() && !input->movewest() )
                        {
                                stateId = StateMoveNorth;
                        }
                        else if ( !input->movenorth() && input->movesouth() && !input->moveeast() && !input->movewest() )
                        {
                                stateId = StateMoveSouth;
                        }
                        else if ( !input->movenorth() && !input->movesouth() && input->moveeast() && !input->movewest() )
                        {
                                stateId = StateMoveEast;
                        }
                        else if ( !input->movenorth() && !input->movesouth() && !input->moveeast() && input->movewest() )
                        {
                                stateId = StateMoveWest;
                        }
                }
                // Si está siendo desplazado forzosamente
                else if ( stateId == StateForceDisplaceNorth || stateId == StateForceDisplaceSouth || stateId == StateForceDisplaceEast || stateId == StateForceDisplaceWest )
                {
                        // ...y se ha pulsado la tecla de salto entonces salta
                        if ( input->jump() )
                        {
                                stateId = StateJump;
                        }
                        // ...y se ha pulsado alguna tecla de movimiento entonces: si pretende avanzar en la dirección
                        // contraria a la que se está deplazando entonces se anula el desplazamiento; en caso contrario,
                        // avanza en la dirección que se esté ordenando
                        else if ( input->movenorth() && !input->movesouth() && !input->moveeast() && !input->movewest() )
                        {
                                stateId = ( stateId == StateForceDisplaceSouth ? StateCancelDisplaceSouth : StateMoveNorth );
                        }
                        else if ( !input->movenorth() && input->movesouth() && !input->moveeast() && !input->movewest() )
                        {
                                stateId = ( stateId == StateForceDisplaceNorth ? StateCancelDisplaceNorth : StateMoveSouth );
                        }
                        else if ( !input->movenorth() && !input->movesouth() && input->moveeast() && !input->movewest() )
                        {
                                stateId = ( stateId == StateForceDisplaceWest ? StateCancelDisplaceWest : StateMoveEast );
                        }
                        else if ( !input->movenorth() && !input->movesouth() && !input->moveeast() && input->movewest() )
                        {
                                stateId = ( stateId == StateForceDisplaceEast ? StateCancelDisplaceEast : StateMoveWest );
                        }
                }
                // Si está saltando
                else if ( stateId == StateJump || stateId == StateRegularJump || stateId == StateHighJump )
                {
                        // ...y ha pulsado la tecla de disparo entonces dispara
                        if ( input->shoot() && !shotPresent )
                        {
                                shot( playerItem );
                                // Las repeticiones de esta tecla no deben procesarse
                                input->noRepeat( "shoot" );
                        }
                        // ...y se ha pulsado alguna tecla de movimiento entonces el salto cambia de orientación
                        else if ( input->movenorth() && !input->movesouth() && !input->moveeast() && !input->movewest() && playerItem->getDirection() != North )
                        {
                                playerItem->changeDirection( North );
                        }
                        else if ( !input->movenorth() && input->movesouth() && !input->moveeast() && !input->movewest() && playerItem->getDirection() != South )
                        {
                                playerItem->changeDirection( South );
                        }
                        else if ( !input->movenorth() && !input->movesouth() && input->moveeast() && !input->movewest() && playerItem->getDirection() != East )
                        {
                                playerItem->changeDirection( East );
                        }
                        else if ( !input->movenorth() && !input->movesouth() && !input->moveeast() && input->movewest() && playerItem->getDirection() != West )
                        {
                                playerItem->changeDirection( West );
                        }
                }
                // Si está cayendo
                else if ( stateId == StateFall )
                {
                        // ...y ha pulsado la tecla de disparo entonces dispara
                        if ( input->shoot() && !shotPresent )
                        {
                                shot( playerItem );
                                // Las repeticiones de esta tecla no deben procesarse
                                input->noRepeat( "shoot" );
                        }
                        // ...y se intenta mover entonces Head planea
                        else if ( input->movenorth() || input->movesouth() || input->moveeast() || input->movewest() )
                        {
                                stateId = StateGlide;
                        }
                }

                // Si está planeando se procesa sin necesidad de esperar al siguiente ciclo pues existe la posibilidad
                // de que el estado provenga del estado de caída. En este caso un procesamiento posterior provocará
                // que el personaje no sea capaz de entrar en los huecos existentes entre dos elementos rejilla
                if ( stateId == StateGlide )
                {
                        // ...y ha pulsado la tecla de disparo entonces dispara
                        if ( input->shoot() && !shotPresent )
                        {
                                shot( playerItem );
                                // Las repeticiones de esta tecla no deben procesarse
                                input->noRepeat( "shoot" );
                        }
                        // ...y se ha pulsado alguna tecla de movimiento entonces cambia la orientación
                        else if ( input->movenorth() && !input->movesouth() && !input->moveeast() && !input->movewest() && playerItem->getDirection() != North )
                        {
                                playerItem->changeDirection( North );
                        }
                        else if ( !input->movenorth() && input->movesouth() && !input->moveeast() && !input->movewest() && playerItem->getDirection() != South )
                        {
                                playerItem->changeDirection( South );
                        }
                        else if ( !input->movenorth() && !input->movesouth() && input->moveeast() && !input->movewest() && playerItem->getDirection() != East )
                        {
                                playerItem->changeDirection( East );
                        }
                        else if ( !input->movenorth() && !input->movesouth() && !input->moveeast() && input->movewest() && playerItem->getDirection() != West )
                        {
                                playerItem->changeDirection( West );
                        }
                        // ...y deja de moverse con las teclas de dirección entonces simplemente cae
                        else if ( !input->movenorth() && !input->movesouth() && !input->moveeast() && !input->movewest() )
                        {
                                stateId = StateFall;
                        }
                }
        }
}

void PlayerHead::wait( PlayerItem* playerItem )
{
        playerItem->wait();

        // Si está detenido entre 4 y 9 segundos entonces parpadea
        if( blinkingTimer->getValue() >= ( rand() % 4 ) + 5 )
        {
                blinkingTimer->reset();
                stateId = StateBlink;
        }

        // Se comprueba si el jugador debe empezar a caer
        if( FallState::getInstance()->fall( this ) )
        {
                speedTimer->reset();
                stateId = StateFall;
        }
}

void PlayerHead::blink( PlayerItem* playerItem )
{
        double timeValue = blinkingTimer->getValue();

        // Si el crono se encuentra entre los tiempos especificados, Head cierra los ojos
        if( ( timeValue > 0.0 && timeValue < 0.050 ) || ( timeValue > 0.400 && timeValue < 0.450 ) )
        {
                playerItem->changeFrame( blinkFrames[ playerItem->getDirection() ] );
        }
        // Si el crono se encuentra entre los tiempos especificados, Head abre los ojos
        else if( ( timeValue > 0.250 && timeValue < 0.300 ) || ( timeValue > 0.750 && timeValue < 0.800 ) )
        {
                playerItem->changeDirection( playerItem->getDirection() );
        }
        // Después de 0,8 segundos el parpadeo termina
        else if( timeValue > 0.800 )
        {
                blinkingTimer->reset();
                stateId = StateWait;
        }
}

}
