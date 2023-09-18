/*

	INTRODUCCIÓN A LA PROGRAMACIÓN / FUNDAMENTOS DE PROGRAMACIÓN
	Curso 2019/2020

	Nombre: TAD_Casilla.h
	Descripción: Especificación del TAD Casilla para el proyecto BlockMerge encargado de gestionar la información de una
				casilla del tablero. Cada casilla puede estar vacía o no. Si no está vacía, tendrá un número.
	Autor:	Juan Carlos Muñoz Fernández y Víctor Valdés Cobos
    Fecha:	21/12/2019
 */

#ifndef TAD_CASILLA_H_
#define TAD_CASILLA_H_
#include <iostream>
using namespace std;



struct Casilla{
	int valor;
	bool ocupada;
	bool resaltada;

};



/*
 * PRE : {}
 *  POST: {Inicia la estructura casilla}
 * COMPLEJIDAD: O(1)
 */
void iniciar(Casilla &c);



/*
 * PRE:{Casilla iniciada correctamente }
 * POST: { "c" es una casilla no vacía con valor n }
 * COMPLEJIDAD:O(1)
 */
void ponerValor(Casilla &c, int n);


/*
 * PRE:{ "c" no es una casilla vacía }
 * POST:{ Devuelve el valor de la casilla}
 * COMPLEJIDAD:O(1)
 */
int obtenerValor(Casilla c);



/*
 * PRE:{ Casilla iniciada correctamente }
 * POST:{ Devuelve true si la casilla esta ocupada y false si no esta ocupada}
 * COMPLEJIDAD:O(1)
 */
bool obtenerSiOcupada (Casilla c);



/*
 * PRE:{ Casilla iniciada correctamente  }
 * POST: { Vacia casilla }
 * COMPLEJIDAD:O(1)
 */
void vaciar(Casilla &c);
/*
 * PRE:{Estructura casilla iniciada correctamente }
 * POST:{ Pone resaltar a false }
 * COMPLEJIDAD: O(1)
 */
void casillaDesresaltar(Casilla &c);// Ampliación



/*
 * PRE:{Casilla iniciada correctamente }
 * POST:{ Pone resaltar a true }
 * COMPLEJIDAD: O(1)
 */
void casillaResaltada(Casilla &c);// Ampliación



/*
 * PRE:{Casilla iniciada correctamente }
 * POST:{ Devueve la información de resaltar}
 * COMPLEJIDAD: O(1)
 */
bool obtenerResaltada (Casilla c);// Ampliación




#endif /* TAD_CASILLA_H_ */
