/*
 * Pruebas_Casillas.h
 *
 *  Created on: 30 dic. 2019
	Autor:	Juan Carlos Muñoz Fernández y Víctor Valdés Cobos
 */

#ifndef PRUEBAS_CASILLAS_H_
#define PRUEBAS_CASILLAS_H_

#include <iostream>
using namespace std;

#include "TAD_Casilla.h"





/*DESCRIPCION: Modulo de prueba de la casilla base, se comprueba la inicialización de las casillas,
 * la asignación de valores a las casillas, la obtención del valor de una casilla,  si la casilla se
 * encuentra con un valor útil y si se vacia correctamente las casillas
 */
void pruebaCasilla();


/*
 * DESCRIPCION: Modulo de prueba para las ampliaciones (),
 * donde esta inciado correctamente la estructura, comprobamos que se cambia el valor de resaltar a false,
 * comprobamos que se cambia el valor de resaltar a true,comprobamos que se obtiene resaltada adecuadamente.
 */
void pruebaAmpliaciones();

/*
 * DESCRIPCION: Modulo que llama a todas las pruebas de casilla.
 */
void prueba_Casillas();

#endif /* PRUEBAS_CASILLAS_H_ */
