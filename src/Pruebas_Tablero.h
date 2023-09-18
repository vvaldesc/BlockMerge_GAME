/*
 * Pruebas_Tablero.h
 *
 *  Created on: 30 dic. 2019
 *      Author: Juan Carlos MUñoz Fernández y Víctor Valdés Cobos
 */

#ifndef PRUEBAS_TABLERO_H_
#define PRUEBAS_TABLERO_H_

#include <iostream>
using namespace std;

#include "TAD_Tablero.h"
#include"entorno.h"



/*
 * DESCRIPCION: Modulo de prueba para IniciarAleatorimente(),
 * donde esta inciado correctamente la estructura,
 * indica si introduce valores alatorios menores que el parámetro dado.
 */
void prueba_IniciarAleatoriamente();



/*
 * DESCRIPCION: Modulo de prueba para IniciarInformacion(),
 * donde esta inciado correctamente la estructura,
 * indica si copia correctamente los elementos de la matriz en el tablero.
 */
void prueba_IniciarInformacion();



/*
 * DESCRIPCION: Modulo de prueba para obtenerTamanos(),
 * donde esta inciado correctamente la estructura,
 * comprueba que la informacion del tamaño de la matriz es correcta.
 */
void prueba_obtenerTamano();



/*
 * DESCRIPCION: Modulo de prueba para PonerValor(),
 * donde esta inciado correctamente la estructura,
 *comprueba que introduce los valores en el Tablero adecuadamente.
 */
void prueba_PonerValor ();



/*
 * DESCRIPCION: Modulo de prueba para VaciarCasilla(),
 * donde esta inciado correctamente la estructura,
 *comprueba que se vacia correctamente la casilla indicada.
 */
void prueba_VaciarCasilla ();



/*
 * DESCRIPCION: Modulo de prueba para ObtenerValor(),
 * donde esta inciado correctamente la estructura,
 *comprueba que obtiene correctamente el valor de una determinada casilla.
 */
void prueba_ObtenerValorCasilla ();



/*
 * DESCRIPCION: Modulo de prueba para FormaParte(),
 * donde esta inciado correctamente la estructura,
 * comprueba que se obtiene correctamente si una casilla
 * determinada forma parte de algun bloque.
 */
void prueba_FormaParte ();



/*
 * DESCRIPCION: Modulo de prueba para AlgunBloque(),
 * donde esta inciado correctamente la estructura,
 * que hay algun bloque en la matriz .
 */
void prueba_AlgunBloque ();



/*
 * DESCRIPCION: Modulo de prueba para ValorMax(),
 * donde esta inciado correctamente la estructura,
 *comprueba que se obtiene de manera adecuada el valor maximo
 * deL Tablero.
 */
void prueba_ValorMax ();



/*
 * DESCRIPCION: Modulo de prueba para VaciarBloque(),
 * donde esta inciado correctamente la estructura,
 *comprueba que se vacia correctamente el bloque indicado.
 */
void prueba_VaciarBloque ();



/*
 * DESCRIPCION: Modulo de prueba para DesplazarVacia(),
 * donde esta inciado correctamente la estructura,
 *comprueba que se desplazan las casillas hacia abajo ocupando
 * la posicion de las casillas vacias.
 */
void prueba_DesplazarVacias ();



/*
 * DESCRIPCION: Modulo de prueba para DesplazarTodas(),
 * donde esta inciado correctamente la estructura,
 *comprueba que se desplazan correctamente todas las casillas.
 */

void prueba_RellenarVacias ();



/*
 * DESCRIPCION: Modulo de prueba para RealtarBloque(),
 * donde esta inciado correctamente la estructura,
 * comprueba que se Resalta Jugando al juego.
 */
void prueba_ResaltarBloque ();




/*
 * DESCRIPCION: Modulo de prueba para Resteo Resaltar(),
 * donde esta inciado correctamente la estructura,
 * comprueba que cada casilla resetea "resaltar" a su estado original a false.
 */
void prueba_ReseteoResaltar ();


/*
 * DESCRIPCION: Módulo que llama a todas las pruebas del tablero.
 */
void prueba_Tablero();

#endif /* PRUEBAS_TABLERO_H_ */
