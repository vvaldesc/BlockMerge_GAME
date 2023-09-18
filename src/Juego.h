/*
 * Juego.h
 *
 *
	Autor:	Juan Carlos Muñoz Fernández y Víctor Valdés Cobos
 *      Grupo: B
 *      Fecha : 5 ene. 2020
 */

#ifndef JUEGO_H_
#define JUEGO_H_

#include <iostream>
using namespace std;
#include "entorno.h"
#include "TAD_Tablero.h"



struct Juego{
	Tablero tablero;
	int puntuacion;
	int valorObjetivo;
};

/*
 * PRE:--
 * POST:  Inicia la estructura creada juego, según la configuración de merge.cnf, con valores aleatorios o valores predefinidos.
 * COMPLEJIDAD:O(n²)
 */
bool iniciarJuego(Juego &t);


/*
 * PRE: Se ha iniciado la estructura del juego.
 * POST: Realiza la actualización de la matriz de entorno
 *  * COMPLEJIDAD:O(n²)
 */
void actualizarJuego(Juego &t);


/*
 * PRE: Se ha iniciado la estructura del juego.
 * POST: Gestiona los controles del juego además de los aspectos gráficos y matemáticos.
 */
void gestionar(Juego &t, int &valorMaximo);



/*
 * PRE: Se ha iniciado la estructura del juego.
 * POST:Termina el juego, al haberse se ha presionado la tecla "Escape" o logrado la puntuacón máxima.
 * COMPLEJIDAD:O(1)
 */
void acabar(Juego &t, int valorMaximo);

#endif /* JUEGO_H_ */
