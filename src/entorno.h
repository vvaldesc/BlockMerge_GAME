/**

	INTRODUCCIÓN A LA PROGRAMACIÓN / FUNDAMENTOS DE PROGRAMACIÓN
	Curso 2019/2020

	Nombre: entorno.h
	Descripción: Especificación del TAD Entorno para el proyecto BlockMerge
	     	 	 encargado del manejo de la interfaz del juego.
	     	 	 versión allegro 5.2
	Autor:	Juan Carlos Muñoz Fernández y Víctor Valdés Cobos
    Fecha:	25/11/2019
*/

#ifndef ENTORNO_H_
#define ENTORNO_H_

#include <iostream>
#include <string>

using namespace std;


// -------------------------------------------------------------
// Definicion de constantes públicas
// -------------------------------------------------------------

/*
 *  La constante MAX_TAMANO define el tamaño máximo (número de filas y columas) del tablero
 */
const int MAX_TAMANO = 8;


// -------------------------------------------------------------
// Definicion de tipos
// -------------------------------------------------------------

/**
 *   Este es el tipo devuelto por la operacion LeerTecla que indica la tecla
 *   de los cursores o teclas válidas que se ha pulsado
 */
enum TipoTecla {TNada, TEnter, TIzquierda, TDerecha, TArriba, TAbajo, TSalir};




// ----------------------------------------------------------------
// Declaración de la interfaz pública (módulos que se pueden usar)
// ----------------------------------------------------------------


 /*
  *	PRE:  4 <= tam <= MAX_TAMANO
  *	DESCRIPCIÓN: Inicia la interfaz gráfica del juego, preparada para
  *		  un tablero de tam x tam casillas.
  */
void entornoIniciar (int tam);


 /*
  *	DESCRIPCIÓN: Libera los recursos usados por el entorno gráfico
  */
void entornoTerminar ();


/*
 *	PRE: Archivo merge.cnf correcto y en la carpeta raíz del proyecto
 *	     (NO SE COMPRUEBAN ERRORES EN LOS DATOS)
 *	POST: Devuelve:
 *	        TRUE:  si se carga correctamente la configuración del juego,
 *		     FALSE: en caso contrario.
 *   PARÁMETROS:
 *		Si la configuración se lee de forma correcta se devolverá:
 *		   tamano:		     número de filas y columnas del tablero del juego
 *		   obj:              valor objetivo a alcanzar para terminar el juego
 *		   d:                si d == 0 el tablero se lee desde el fichero de configuración
 *		   					 si es positivo (>0) el tablero se generará aleatoriamente,
 *		   					 siendo este valor d el maximo para los valores aleatorios generados
 *		   m:				 matriz que contiene los valores numéricos del tablero del juego. Solo si d es 0.
 *
 *		Por omisión, el archivo merge.cnf se encuentra en el directorio  del proyecto
 */
bool entornoCargarConfiguracion ( int &tamano, int &obj,  int &d, int m[MAX_TAMANO][MAX_TAMANO]);


/*
 * PRE: { 0 <= fila < MAX_TAMANO }
 *      { 0 <= columna < MAX_TAMANO }
 *      { 1 <=  numero <= 999 }
 *
 * DESCRIPCIÓN: Coloca en la posición (fila,columna) del tablero el número indicado dentro de un cuadrado
 */
void entornoPonerNumero  (int fila, int columna, int numero);


/*
 * PRE: { 0 <= fila < MAX_TAMANO }
 *      { 0 <= columna < MAX_TAMANO }
 *
 * DESCRIPCIÓN: Deja en blanco la posición (fila, columna) del tablero
 */
void entornoPonerVacio  (int fila, int columna);


/*
 * PRE: { 0 <= fila < MAX_TAMANO }
 *      { 0 <= columna < MAX_TAMANO }
 *      { 1 <=  numero <= 999 }
 *
 * DESCRIPCIÓN: Coloca en la posición (fila,columna) del tablero el número indicado dentro de un círculo resaltado
 *       Sirve para resaltar el valor mayor.
 */
void entornoPonerNumeroResaltado  (int fila, int columna);


/*
 * PRE: valor >= 0
 *
 * DESCRIPCIÓN: Muestra el valor indicado como puntuación en el marcador situado en la parte superior del tablero
 */
void entornoPonerPuntuacion( int valor);


/*
 * PRE: valor >= 0
 * DESCRIPCIÓN: Muestra el valor indicado como objetivo al que llegar para terminar la partida en el marcador situado
 *       en la parte superior del tablero
 */
void entornoPonerObjetivo( int valor);


/*
 * PRE: { 0 <= fila < MAX_TAMANO }
 *      { 0 <= columna < MAX_TAMANO }
 *
 * DESCRIPCIÓN: Enmarca la casilla que ocupa la posición (fila, columna) en un cuadrado negro
 *       Se utiliza para simular el movimiento por el tablero
 */
void entornoMarcarPosicion(int fila, int columna);


/*
 * PRE: { 0 <= fila < MAX_TAMANO }
 *      { 0 <= columna < MAX_TAMANO }
 *
 *       DESCRIPCIÓN: Elimina el marco negro de la casilla que ocupa la posición (fila, columna)
 *       Se utiliza para simular el movimiento por el tablero
*/
void entornoDesmarcarPosicion(int fila, int columna);


/*
 * PRE: { 0 <= fila < MAX_TAMANO }
 *      { 0 <= columna < MAX_TAMANO }
 *
 * DESCRIPCIÓN: Enmarca la casilla que ocupa la posición (fila, columna) en un cuadrado gris
 *       Se utiliza para la ampliación de enmarcar el bloque
 */
void entornoMarcarBloque(int fila, int columna);


/*
 * PRE: { 0 <= fila < MAX_TAMANO }
 *      { 0 <= columna < MAX_TAMANO }
 *
 * DESCRIPCIÓN: Elimina el marco gris de la casilla que ocupa la posición (fila, columna).
 *       Se utiliza para la ampliación de enmarcar el bloque
 */
void entornoDesmarcarBloque(int fila, int columna);


/*
 * PRE: { }
 *
 * POST:Devuelve el valor enumerado de TipoTecla que corresponde a la tecla que se haya pulsado
 */
TipoTecla entornoLeerTecla();


/*
 * PRE: "msg" está correctamente inicializado
 *
 * DESCRIPCIÓN: Muestra el mensaje "msg" en el centro de la ventana para indicar que ha finalizado el juego
 */
void entornoMostrarMensajeFin (string msg);


/*
 * PRE: {0 < pausa y "msg" está correctamente inicializado}
 *
 * DESCRIPCIÓN:	Muestra el mensaje "msg" en la parte inferior de la pantalla
 *              durante los segundos indicados por "pausa"
 */
void entornoMostrarMensaje (string msg, float pausa);


/*
 * PRE: {0 < pausa}
 *
 * DESCRIPCIÓN: para la ejecución durante "pausa" segundos
 */
void entornoPausa(float pausa);

#endif
