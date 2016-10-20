// Head over Heels (A remake by helmántika.org)
//
// © Copyright 2008 Jorge Rodríguez Santos <jorge@helmantika.org>
// © Copyright 1987 Ocean Software Ltd. (Original game)
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details
//
// You should have received a copy of the GNU General Public License along
// with this program; if not, write to the Free Software Foundation, Inc.,
// 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA

#ifndef Widget_hpp_
#define Widget_hpp_

#include <allegro.h>

namespace gui
{

/**
 * Base para la creación de los elementos existentes en la interfaz gráfica de usuario
 * Cada nuevo elemento debe recodificar la operación 'draw'
 */
class Widget
{

public:

        /**
         * Constructor
         * @param x Coordenada X de pantalla donde situar el elemento
         * @param x Coordenada X de pantalla donde situar el elemento
         */
        Widget( unsigned int x, unsigned int y ) ;

        virtual ~Widget( ) ;

        /**
         * Dibuja el elemento
         */
        virtual void draw ( BITMAP* where ) = 0 ;

        /**
         * Recibe la pulsación de una tecla. Las subclases pueden responder a dicho evento
         * o comunicárselo al siguiente componente
         */
        virtual void handleKey ( int key ) ;

        /**
         * Cambia la posición del elemento
         * @param x Coordenada X de pantalla donde situar el elemento
         * @param y Coordenada Y de pantalla donde situar el elemento
         */
        virtual void changePosition ( unsigned int x, unsigned int y ) {  this->x = x;  this->y = y;  }

protected:

        /**
         * Coordenada X de pantalla donde situar el elemento
         */
        unsigned int x ;

        /**
         * Coordenada Y de pantalla donde situar el elemento
         */
        unsigned int y ;

        /**
         * When this widget wants to share with some other one
         */
        Widget* next ;

public: // Operaciones de consulta y actualización

        /**
         * Coordenada X de pantalla donde situar el elemento
         * @return Una coordenada de pantalla que no tiene porque estar en
         * los límites de la resolución establecida
         */
        unsigned int getX () const {  return this->x ;  }

        /**
         * Coordenada Y de pantalla donde situar el elemento
         * @return Una coordenada de pantalla que no tiene porque estar en
         * los límites de la resolución establecida
         */
        unsigned int getY () const {  return this->y ;  }

        /**
         * Establece el sucesor del componente en la cadena de responsabilidad para dar respuesta
         * a la pulsación de una tecla
         * @param widget Un componente de la interfaz gráfica
         */
        void setNext ( Widget* widget ) {  this->next = widget ;  }

};

}

#endif
