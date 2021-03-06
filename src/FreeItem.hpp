// The free and open source remake of Head over Heels
//
// Copyright © 2017 Douglas Mencken dougmencken@gmail.com
// Copyright © 2008 Jorge Rodríguez Santos
// Original game copyright © 1987 Ocean Software Ltd.
//
// This program is free software
// You may redistribute it and~or modify it under the terms of the GNU General Public License
// either version 3 of the License or at your option any later version

#ifndef FreeItem_hpp_
#define FreeItem_hpp_

#include <utility>
#include <cmath>
#include <allegro.h>
#include "Ism.hpp"
#include "Item.hpp"
#include "Drawable.hpp"


namespace isomot
{

class ItemData;

/**
 * Los elementos libres son aquellos que pueden estar en cualquier lugar y moverse libremente
 * por la sala como, por ejemplo, los enemigos, el propio jugador o todo aquello que deba tener
 * anchuras distintas de las anchuras de las celdas de la rejilla
 */
class FreeItem : public Drawable, public Item
{

public:

       /**
        * Constructor
        * @param itemData Datos invariables del elemento
        * @param x Posición espacial X
        * @param y Posición espacial Y
        * @param z Posición espacial Z o a qué distancia está el elemento del suelo
        * @param direction Dirección inicial del elemento
        */
        FreeItem( ItemData* itemData, int x, int y, int z, const Direction& direction ) ;

       /**
        * Constructor copia. No copia los atributos que son punteros
        * @param freeItem Un objeto de esta clase
        */
        FreeItem( const FreeItem& freeItem ) ;

        virtual ~FreeItem( ) ;

        /**
         * Dibuja el elemento libre
         */
        void draw ( BITMAP* where ) ;

        /**
         * Cambia la presentación gráfica del elemento, destruyendo la imagen procesada y señalando qué elementos
         * hay que volver a enmascarar
         * @param image Un fotograma del elemento
         */
        void changeImage ( BITMAP* image ) ;

        /**
         * Cambia la sombra de la presentación gráfica del elemento, destruyendo la imagen procesada y señalando
         * qué elementos hay que volver a sombrear
         * @param image Una sombra de un fotograma del elemento
         */
        void changeShadow ( BITMAP* shadow ) ;

        /**
         * Solicita el sombreado del elemento
         */
        void requestCastShadow () ;

        /**
         * Sombrea la imagen del elemento con la sombra de otro elemento
         * @param x Coordenada X de pantalla donde está situada la base del elemento que sombrea
         * @param y Coordenada Y de pantalla donde está situada la base del elemento que sombrea
         * @param shadow La sombra que se proyecta sobre el elemento
         * @param shadingScale Grado de opacidad de las sombras desde 0, sin sombras, hasta 256,
         *                     sombras totalmente opacas
         * @param transparency Grado de transparencia del elemento que sombrea
         */
        void castShadowImage ( int x, int y, BITMAP* shadow, short shadingScale, unsigned char transparency = 0 ) ;

        /**
         * Solicita enmascarar el elemento
         */
        void requestMask () ;

        /**
         * Enmascara la imagen del elemento con la imagen de otro elemento
         * @param x Coordenada X de pantalla donde está situada la imagen del elemento que servirá de máscara
         * @param y Coordenada Y de pantalla donde está situada la imagen del elemento que servirá de máscara
         */
        void maskImage ( int x, int y, BITMAP* image ) ;

        /**
         * Cambia el valor de la coordenada X
         * @param value Nuevo valor para X
         * @return true si se pudo cambiar el dato o false si hubo colisión y no hubo cambio
         */
        virtual bool changeX ( int value ) ;

        /**
         * Cambia el valor de la coordenada Y
         * @param value Nuevo valor para Y
         * @return true si se pudo cambiar el dato o false si hubo colisión y no hubo cambio
         */
        virtual bool changeY ( int value ) ;

        /**
         * Cambia el valor de la coordenada Z
         * @param value Nuevo valor para Z
         * @return true si se pudo cambiar el dato o false si hubo colisión y no hubo cambio
         */
        virtual bool changeZ ( int value ) ;

        /**
         * Cambia la posición del elemento
         * @param x Nuevo valor para la coordenada X
         * @param y Nuevo valor para la coordenada Y
         * @param z Nuevo valor para la coordenada Z
         * @return true si se pudo cambiar el dato o false si hubo colisión y no hubo cambio
         */
        virtual bool changePosition ( int x, int y, int z ) ;

        /**
         * Cambia el valor de la coordenada X
         * @param value Valor que se sumará a la coordenada X actual
         * @return true si se pudo cambiar el dato o false si hubo colisión y no hubo cambio
         */
        virtual bool addX ( int value ) ;

        /**
         * Cambia el valor de la coordenada Y
         * @param value Valor que se sumará a la coordenada Y actual
         * @return true si se pudo cambiar el dato o false si hubo colisión y no hubo cambio
         */
        virtual bool addY ( int value ) ;

        /**
         * Cambia el valor de la coordenada Z
         * @param value Valor que se sumará a la coordenada Z actual
         * @return true si se pudo cambiar el dato o false si hubo colisión y no hubo cambio
         */
        virtual bool addZ ( int value ) ;

        /**
         * Cambia la posición del elemento
         * @param x Valor que se sumará a la coordenada X actual
         * @param y Valor que se sumará a la coordenada Y actual
         * @param z Valor que se sumará a la coordenada Z actual
         * @return true si se pudo cambiar el dato o false si hubo colisión y no hubo cambio
         */
        virtual bool addPosition ( int x, int y, int z ) ;

        /**
         * Cambia el grado de transparencia del elemento
         * @param value Valor de transparencia en un porcentaje de 0 a 100
         * @param mode Modo para interpretar el nuevo valor. Puede usarse Change para cambiarlo o Add para sumarlo
         * @return true si el cambio de transparencia tuvo efecto o false en caso contrario
         */
        bool changeTransparency ( unsigned char value, const WhatToDo& changeOrAdd ) ;

protected:

        /**
         * Cambia el dato solicitado del elemento
         * @param value El nuevo valor
         * @param x La nueva coordenada X. El parámetro se ignora si datum no es CoordinatesXYZ
         * @param y La nueva coordenada Y. El parámetro se ignora si datum no es CoordinatesXYZ
         * @param z La nueva coordenada Z. El parámetro se ignora si datum no es CoordinatesXYZ
         * @param datum El dato que se quiere modificar: CoordinateX, la coordenada X; CoordinateY, la
         *              coordenada Y; CoordinateZ, la coordenada Z; WidthX, la anchura en el eje X;
         *              WidthY, la anchura en el eje Y; o, Height, la altura
         * @param mode Modo para interpretar el nuevo valor. Puede usarse Change para cambiarlo o Add para sumarlo
         * @return true si se pudo cambiar el dato o false si hubo colisión y no hubo cambio
         */
        virtual bool changeData ( int value, int x, int y, int z, const Datum& datum, const WhatToDo& addOrChange ) ;

protected:

        /**
         * Estado del proceso de enmascarado
         */
        WhichMask myMask ;

        /**
         * Grado de transparencia del elemento en un porcentaje de 0 a 100
         */
        unsigned char transparency ;

        /**
         * Indica si el elemento detecta colisiones
         */
        bool collisionDetector ;

        /**
         * Indica si el elemento está inactivo
         */
        bool dead ;

        /**
         * Fotograma actual del elemento sombreado pero sin enmascarar
         */
        BITMAP* shadyImage ;

public: // Operaciones de consulta y actualización

        /**
         * Establece el estado del proceso de enmascarado
         */
        void setWhichMask ( const WhichMask& mask ) {  myMask = mask ;  }

        /**
         * Devuelve el estado del proceso de enmascarado
         */
        WhichMask whichMask () const {  return myMask ;  }

        /**
         * Grado de transparencia del elemento
         * @return Un número entre 0 y 100, inclusive
         */
        unsigned char getTransparency () const {  return transparency ;  }

        /**
         * Establece la capacidad del elemento para detectar colisiones
         * @param collisionDetector true si detecta colisiones (valor por defecto al crear el elemento) o false caso contrario
         */
        void setCollisionDetector ( bool collisionDetector ) {  this->collisionDetector = collisionDetector ;  }

        /**
         * Indica si el elemento detecta colisiones
         * @return true si detecta colisiones o false caso contrario
         */
        bool isCollisionDetector () const {  return collisionDetector ;  }

        /**
         * Establece si el elemento está inactivo
         * @param dead true si está detenido o false en caso contrario
         */
        void setDead ( bool dead ) {  this->dead = dead ;  }

        /**
         * Indica si el elemento está inactivo
         * @return true si está detenido o false en caso contrario
         */
        bool isDead () const {  return dead ;  }

        /**
         * Datos invariables del elemento. Se emplea cuando el elemento cambia de aspecto y se desea
         * conservar el actual
         * @return Un registro con los datos que caracterizan al elemento
         */
        ItemData * getItemData () ;

};

}

#endif
