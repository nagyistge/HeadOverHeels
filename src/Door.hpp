// The free and open source remake of Head over Heels
//
// Copyright © 2017 Douglas Mencken dougmencken@gmail.com
// Copyright © 2008 Jorge Rodríguez Santos
// Original game copyright © 1987 Ocean Software Ltd.
//
// This program is free software
// You may redistribute it and~or modify it under the terms of the GNU General Public License
// either version 3 of the License or at your option any later version

#ifndef Door_hpp_
#define Door_hpp_

#include "Ism.hpp"
#include "Drawable.hpp"
#include "Mediated.hpp"

namespace isomot
{

// Declaraciones adelantadas
class ItemDataManager;
class FreeItem;

/**
 * Una puerta de la sala. Realmente una puerta son tres elementos libres: las jambas y el dintel
 */
class Door : public Drawable, public Mediated
{
public:

  /**
   * Constructor
   * @param itemDataManager Gestor de datos necesario para encontrar las tres partes de la puerta
   * @param label Identificador de la puerta
   * @param cx Celda que ocupa el elemento en el eje X
   * @param cy Celda que ocupa el elemento en el eje Y
   * @param z Posición espacial Z o a qué distancia está el elemento del suelo
   * @param direction Dirección inicial del elemento
   */
	Door(ItemDataManager* itemDataManager, short label, int cx, int cy, int z, const Direction& direction);

	virtual ~Door();

	void draw( BITMAP* where ) { }

private:

  /**
   * Identificador de la puerta
   */
  short label;

  /**
   * Celda que ocupa el elemento en el eje X
   */
  int cx;

  /**
   * Celda que ocupa el elemento en el eje Y
   */
  int cy;

  /**
   * Posición espacial Z o a qué distancia está el elemento del suelo
   */
  int z;

  /**
   * Coordenada inicial del vado de la puerta
   */
  int rightLimit;

  /**
   * Coordenada final del vado de la puerta
   */
  int leftLimit;

  /**
   * El tipo de puerta determinado por su posición en la sala
   */
  Direction direction;

  /**
   * Gestor de los datos invariables de los elementos del juego
   */
  ItemDataManager* itemDataManager;

  /**
   * Jamba izquierda
   */
  FreeItem* leftJamb;

  /**
   * Jamba derecha
   */
  FreeItem* rightJamb;

  /**
   * Dintel
   */
  FreeItem* lintel;

public: // Operaciones de consulta y actualización

  /**
   * Indica si un determinado elemento se encuentra en el vado de la puerta
   * @param x Coordenada isométrica X del elemento
   * @param y Coordenada isométrica Y del elemento
   * @param z Coordenada isométrica Z del elemento
   * @return true si el elemento está bajo la puerta o false en caso contrario
   */
  bool isUnderDoor(int x, int y, int z);

  /**
   * El tipo de puerta determinado por su posición en la sala
   * @return North, South, East o West
   */
  Direction getDirection() const { return direction; }

  /**
   * La jamba izquierda de la puerta. Si no existe se crea
   * @return Un elemento libre
   */
  FreeItem* getLeftJamb();

  /**
   * La jamba derecha de la puerta. Si no existe se crea
   * @return Un elemento libre
   */
  FreeItem* getRightJamb();

  /**
   * El dintel de la puerta. Si no existe se crea
   * @return Un elemento libre
   */
  FreeItem* getLintel();
};

}

#endif
