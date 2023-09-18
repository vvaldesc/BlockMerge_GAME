/*
 * TAD_Tablero.h
 *
 *  Created on: 30 dic. 2019
 *      Author: Juan Carlos MUñoz Fernández y Víctor Valldés Cobos
 */

#ifndef TAD_TABLERO_H_
#define TAD_TABLERO_H_

#include "TAD_Casilla.h"
#include "entorno.h"




const int MAX = 8;
typedef Casilla MatrizTablero[MAX][MAX];

struct  Tablero {
	MatrizTablero mtablero;
	int dimension;
};

/*
 * PRE:{ Tablero debe de estar inicializado y 4 <= dimension <= 8}
 * POST:{Muestra el tablero en pantalla  }
 * COMPLEJIDAD:O(n²)
 */
void mostrarPantalla (Tablero &t,int dimension);



/*
 * PRE:{ Tablero debe de estar inicializado, n>=0 y 4 <= dimension <= 8}
 * POST:{Inicia un tablero t de dimension x dimension, con casillas no vacías con valores aleatorios
 * menores que n  }
 * COMPLEJIDAD:O(n²)
 */
void iniciarAleatoriamente (Tablero &t, int n, int dimension);



/*
 * PRE:{ Tablero debe de estar inicializado, 0<= fila < dimension, 0<= columna < dimension,  y 4 <= dimension <= 8}
 * POST:{Inicia un tablero t de dimension x dimension, con casillas no vacías con valores copiados de la matriz m}
 * COMPLEJIDAD:O(n²)
 */
void iniciarInformacion (Tablero &t, int dimension,int m[MAX][MAX]);



/*
 * PRE:{ Tablero debe de estar inicializado }
 * POST:{ Obtiene el tamaño o dimension de Tablero }
 * COMPLEJIDAD:O(1)
 */
int obtenerTamanos(Tablero t);



/*
 * PRE:{Tablero debe de estar inicializado, valor >=0,   0<= fila < dimension y 0<= columna < dimension }
 * POST:{ Introduce el valor, en la posicion dada por la fila y la columna  }
 * COMPLEJIDAD:O(1)
 */
void ponerValor (Tablero &t, int fila, int columna, int valor );



/*
 * PRE:{Tablero debe de estar inicializado,  0<= fila < dimensiony 0<= columna < dimension}
 * POST:{ Vacia la casilla, en la posicion dada por fila y columna  }
 * COMPLEJIDAD:O(1)
 */
void vaciarCasilla (Tablero &t, int fila, int columna);



/*
 * PRE:{ Tablero debe de estar inicializado,  0<= fila < dimension, 0<= columna < dimension}
 * POST:{ Obtiene el valor de la casilla en la posicion dada por fil y columna }
 * COMPLEJIDAD:O(1)
 */
int obtenerValorCasilla (Tablero t, int fil, int columna);



/*
 * PRE:{Tablero debe de estar inicializado, todas las casillas no deben de estar vacias ,  0<= fila < dimension, 0<= columna < dimension}
 * POST:{Devuelve true si en la posicion dada por fila y columna se encuentra un bloque y false en caso de que no lo haya}
 * COMPLEJIDAD:O(1)
 */
bool formaParte (Tablero t, int fila, int columna);



/*
 * PRE:{ Tablero debe de estar inicializado }
 * POST:{ Devuelve true si hay algun bloque en Tablero y False en el caso de que no haya }
 * COMPLEJIDAD:O(n²)
 */
bool algunBloque (Tablero t);



/*
 * PRE:{ Tablero debe de estar inicializado }
 * POST:{ devuelve el valor maxímo que haya en la matriz de Tablero  }
 * COMPLEJIDAD:O(n²)
 */
int valorMax (Tablero t);



/*
 * PRE:{ Tablero debe de estar inicializado,  0<= fila < dimension, 0<= columna < dimension,valor e i >=0}
 * POST:{ Vacia las casillas que pertenecen a un bloque con el mismo valor, que se encuentra el la posicion dada por fila y comuna,
 *  además nos devuelve el número de elementos que forman el bloques (i)}
 * COMPLEJIDAD: Modulo recursivo
 */
void vaciarBloque (Tablero &t, int fila, int columna, int valor, int &i);



/*
 * PRE:{ Tablero debe de estar inicializado y 0<= n < dimension}
 * POST:{ Desplaza hacia abajo las casillas que contengan número a las casillas vacias, en la comuna n }
 * COMPLEJIDAD:O(n²)
 */
void desplazarColumna(Tablero &t, int n);



/*
 * PRE:{ Tablero debe de estar inicializado }
 * POST:{ Recorre el tablero desplazando las que se encuentren con valor útil hacia las que no lo tiene  }
 * COMPLEJIDAD:O(n³)
 */
void desplazarVacias (Tablero &t);



/*
 * PRE:{ Tablero debe de estar inicializado ,  0<= f < dimension, 0<= c < dimension y  valor>=0}
 * POST:{ Rellena las casillas vacias con números alatorios menores que valor  }
 * COMPLEJIDAD:O(n²)
 */
void rellenarVacias (Tablero &t, int valor);



/*
 * PRE:{ Tablero debe de estar inicializado ,  0<= f < dimension, 0<= c < dimension y  valor>=0}
 * POST:{ Resalta la casilla que contiene el may  }or valor del tablero }
 * COMPLEJIDAD:O(n)
 */
void resaltarMayor(Tablero t,int n);



/*
 * PRE:{ Tablero debe de estar inicializado }
 * POST:{ Pone las casillas del tablero en resaltar a false }
 * COMPLEJIDAD:O(n²)
 */
void reseteoResaltar(Tablero &t);// Ampliación



/*
 * PRE:{ Tablero debe de estar inicializado }
 * POST:{ Recorre  tablero quitando el marco de marcarbloque}
 * COMPLEJIDAD:O(n²)
 */
void desResaltarBloque (Tablero t);// Ampliación




/*
 * PRE:{ Tablero debe de estar inicializado }
 * POST:{ realiza la animación al fusiona bloque, poniendo todas las casillas del bloque vacias  }
 * COMPLEJIDAD:O(n²)
 */
void fusion(Tablero &t);// Ampliación



/*
 * PRE:{ Tablero debe de estar inicializado, 0<= fila < dimension, 0<= columna < dimension y valor>=o }
 * POST: { Dado un valor y una posición (ubicado en fila y comlumna) en el tablero, marca el bloque que lo forma}
 * COMPLEJIDAD: o(1)
 */
void animacionResaltar(Tablero &t,int fila, int columna, int valor);// Ampliación



/*
 * PRE:{ Tablero debe de estar inicializado}
 * POST: {Resalta las casillas con resaltada en true}
 * COMPLEJIDAD: O(n²)
 */
void graficaResaltar(Tablero t);// Ampliación



/*
 * PRE:{ Tablero debe de estar inicializado, 0<= fila < dimension, 0<= columna < dimension y valor>=o }
 * POST: { Dado un valor y una posición, pone resaltada en true de las casillas que formen el bloque de esa posición}
 * COMPLEJIDAD: Módulo recursivo
 */
void casillaResaltar(Tablero &t,int fila, int columna, int valor);// Ampliación

/*
 * PRE:{ Tablero debe de estar inicializado}
 * POST:{ Devuelve true si la casilla esta ocupada y false si no esta ocupada}
 * COMPLEJIDAD: O(1)
 */
bool obtenerSiOcupadaCasilla(Tablero t,int fila, int columna);// Ampliación




#endif /* TAD_TABLERO_H_ */
