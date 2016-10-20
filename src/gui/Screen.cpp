#include "Screen.hpp"
#include "Gui.hpp"
#include "actions/Action.hpp"

namespace gui
{

Screen::Screen( unsigned int x, unsigned int y, BITMAP* picture )
: Widget( x, y ),
  backgroundColor( makecol( 0, 0, 0 ) ),
  backgroundPicture( 0 ),
  where( picture ),
  escapeAction( 0 )
{

}

Screen::~Screen()
{
        std::for_each( this->widgets.begin(), this->widgets.end(), DeleteObject() );
}

void Screen::draw( BITMAP* where )
{
        // Pinta del color de fondo la imagen destino
        clear_to_color( where, backgroundColor );

        // Si se definió una imagen de fondo entonces se vuelca
        if ( this->backgroundPicture != 0 )
        {
                blit( this->backgroundPicture, where, 0, 0, 0, 0, this->backgroundPicture->w, this->backgroundPicture->h );
        }

        // Dibuja cada componente en la pantalla
        std::for_each( widgets.begin (), widgets.end (), std::bind2nd( std::mem_fun( &Widget::draw ), where ) );

        // Vuelca la imagen destino a la memoria de pantalla
        blit( where, screen, 0, 0, 0, 0, where->w, where->h );
}

void Screen::handleKey( int key )
{
        if ( escapeAction != 0 && key >> 8 == KEY_ESC )
        {
                this->escapeAction->doIt ();
        }
        else
        {
                Widget::handleKey( key );
        }
}

void Screen::addWidget( Widget* widget )
{
        this->widgets.push_back( widget );
}

}
