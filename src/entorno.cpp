/**

 INTRODUCCIÓN A LA PROGRAMACIÓN / FUNDAMENTOS DE PROGRAMACIÓN
 Curso 2019/2020

 Nombre: entorno.cpp
 Descripción: Implementación del TAD Entorno para el proyecto Merge
 Encargado del manejo de la interfaz del juego.
 Autor:	Profesores de las asignaturas
 Fecha:	25/11/2012
 Fecha última modificación: 30/10/2019 Allegro5

 */

#include "entorno.h"

#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro5.h>

#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>

using namespace std;

// -------------------------------------------------------------
// Definicion de constantes privadas
// -------------------------------------------------------------
// Definición de colores que usa el entorno

const int COLOR_AZUL      = 1;
const int COLOR_BLANCO    = 2;
const int COLOR_ROJO      = 3;
const int COLOR_NEGRO     = 4;
const int COLOR_GRIS      = 5;
const int COLOR_AMARILLO  = 6;
const int COLOR_ORO       = 7;
const int COLOR_VERDE     = 8;
const int COLOR_GRIS_CLARO = 9;
const int COLOR_PLATA     = 10;



const int COLOR_LINEAS = COLOR_BLANCO;
const float GROSOR_LINEAS = 2.0;


const int ANCHO_VENTANA = 600;
const int ALTO_VENTANA  = 650;

// Definicón de constantes para posicionar los números en el tablero
const int DISTANCIA_COLS  = 45;  // Distancia entre columnas
const int DISTANCIA_FILAS = 45;  // Distancia entre filas
const int SEPARACION_FILAS_COL = 4;  // separacion entre las filas y columnas

int ORIGEN_X           = 80 ;  // Origen de las x
const int ORIGEN_Y     = 60 ;  // Origen de las y

// valor del radio para el redondeo de las esquinas del rectangulo
const int RADIO = 12;

// definicion de las constantes para posicionar los marcadores
const int FILA_MARCADOR = 110;
const int COL_MARCADOR  = 14;



ALLEGRO_DISPLAY     *display;
ALLEGRO_FONT        *font;
ALLEGRO_EVENT_QUEUE *colaEventos = NULL;


// -------------------------------------------------------------
// Definición de módulos PRIVADOS
// -------------------------------------------------------------

// define el color en función de los valores makecol - allegro library
ALLEGRO_COLOR makecolor2(int color) {

	ALLEGRO_COLOR alColor;

	switch (color) {
	case COLOR_BLANCO:
		alColor = al_map_rgb (255, 255, 255);
		break;
	case COLOR_ROJO:
		alColor = al_map_rgb (255,   69,  0);
		break;
	case COLOR_NEGRO:
		alColor = al_map_rgb (0,    0,   0);
		break;
	case COLOR_AZUL:
		alColor = al_map_rgb (70,   150, 255);
		break;
	case COLOR_GRIS:
		alColor = al_map_rgb ( 47, 79, 79);
		break;
	case COLOR_AMARILLO:
		alColor = al_map_rgb ( 255, 255, 000);
		break;
	case COLOR_ORO:
		alColor = al_map_rgb ( 234, 190, 63);
		break;
	case COLOR_VERDE:
		alColor = al_map_rgb ( 036,231,017);
		break;
	case COLOR_GRIS_CLARO:
		alColor = al_map_rgb ( 192,192,192);
		break;
	case COLOR_PLATA:
		alColor = al_map_rgb ( 138,149,151);
		break;
	default:
		alColor = al_map_rgb (255, 255, 255);
		break; //color blanco
	}

	return alColor;
}
void invertirFC(int &fila, int &columna) {
	int aux = columna;
	columna = fila;
	fila = aux;
}

// -------------------------------------------------------------
// Definición de la interfaz PÚBLICA
// -------------------------------------------------------------

void entornoIniciar(int tam) {

	// Iniciar el entorno

	if (al_init()){
	al_install_keyboard();

	al_set_new_display_option(ALLEGRO_SINGLE_BUFFER, 1, ALLEGRO_REQUIRE);
	al_set_new_display_flags (ALLEGRO_WINDOWED);


	display = al_create_display(ANCHO_VENTANA,ALTO_VENTANA);
	al_init_primitives_addon(); //

	al_init_font_addon();
	al_init_ttf_addon();


	// carga las fuentes con tamaño 18
	font = al_load_ttf_font("DroidSerif-Regular.ttf", 18, 0);

    // borra la ventana con el color blanco
    al_clear_to_color(makecolor2(COLOR_BLANCO));
    al_set_window_title(display, "Uex Block Merge");

    // se refresca la pantalla
    colaEventos = al_create_event_queue();
    al_register_event_source(colaEventos, al_get_keyboard_event_source());
    ORIGEN_X = (ANCHO_VENTANA -((tam)*DISTANCIA_COLS))/2;


    al_draw_text(font, makecolor2(COLOR_NEGRO), ORIGEN_X/2,550,  ALLEGRO_ALIGN_LEFT,"Teclas: izqda, dcha, arriba, abajo, Enter, Esc");


    al_flip_display();

	}
}

void entornoTerminar(){

	al_destroy_display          (display);
	al_destroy_event_queue      (colaEventos);
	al_destroy_font				(font);
	al_shutdown_primitives_addon();
	al_shutdown_font_addon      ();
}



bool entornoCargarConfiguracion ( int &tamano, int &obj, int &d, int m[MAX_TAMANO][MAX_TAMANO]){

	bool leido;
	int i, j;
	ifstream fEntrada;
	string cadena, cad;
	fEntrada.open("merge.cnf");
	if (fEntrada.is_open()) {
		getline(fEntrada, cadena);
		tamano = atoi(cadena.c_str());
		getline(fEntrada, cadena);
		obj = atoi(cadena.c_str());
		getline(fEntrada, cadena);
		d = atoi(cadena.c_str());

		for (i = 0; i<tamano; i++){
				for (j = 0; j< tamano-1; j++){
					getline (fEntrada,cad,' ');
					m[i][j]= atoi(cad.c_str());
				}
				getline (fEntrada,cad);
				m[i][j]= atoi(cad.c_str());
				}
		leido = true;


		fEntrada.close();
	} else {
		cout
				<< "Fichero de configuración no encontrado (<proyecto>/merge.cnf)."
				<< endl;
		cout << "Formato:" << endl;
		cout << "\t[Tamaño del tablero ]" << endl;

		leido = false;
	}

	return leido;
}



void entornoPonerNumero(int fila, int columna, int numero) {
	invertirFC(fila, columna);
	float base, altura, ptoMedioX, ptoMedioY;
	float x1 = (ORIGEN_X + fila    * DISTANCIA_COLS                   ) + SEPARACION_FILAS_COL;
	float y1 = (ORIGEN_Y + columna * DISTANCIA_FILAS                  ) + SEPARACION_FILAS_COL;
	float x2 = (ORIGEN_X + fila    * DISTANCIA_COLS  + DISTANCIA_COLS )	- SEPARACION_FILAS_COL;
	float y2 = (ORIGEN_Y + columna * DISTANCIA_FILAS + DISTANCIA_FILAS) - SEPARACION_FILAS_COL;

	al_draw_filled_rectangle(x1, y1, x2, y2, al_map_rgb ( 150 * numero, 88 * numero, 112 * numero ));

	base      = (x2 - x1);
	altura    = (y2 - y1);
	ptoMedioX = ((base / 2.0) + x1);
	ptoMedioY = ((y2 + y1) / 2.0) - (altura / 2.0) + SEPARACION_FILAS_COL;

	al_draw_text(font, makecolor2(COLOR_BLANCO), ptoMedioX, ptoMedioY,	ALLEGRO_ALIGN_CENTER, to_string(numero).c_str());

	al_flip_display();

}

void entornoPonerVacio(int fila, int columna) {
	invertirFC(fila, columna);

	float x1 = (ORIGEN_X + fila    * DISTANCIA_COLS                   ) + SEPARACION_FILAS_COL;
	float y1 = (ORIGEN_Y + columna * DISTANCIA_FILAS                  ) + SEPARACION_FILAS_COL;
	float x2 = (ORIGEN_X + fila    * DISTANCIA_COLS  + DISTANCIA_COLS )	- SEPARACION_FILAS_COL;
	float y2 = (ORIGEN_Y + columna * DISTANCIA_FILAS + DISTANCIA_FILAS) - SEPARACION_FILAS_COL;

	al_draw_filled_rectangle(x1, y1, x2, y2, makecolor2(COLOR_BLANCO));
	al_flip_display();

}

void entornoPonerNumeroResaltado(int fila, int columna) {
	invertirFC(fila, columna);
	float base, radio;
	float x1 = (ORIGEN_X + fila    * DISTANCIA_COLS                   ) + SEPARACION_FILAS_COL;
	float y1 = (ORIGEN_Y + columna * DISTANCIA_FILAS                  ) + SEPARACION_FILAS_COL;
	float x2 = (ORIGEN_X + fila    * DISTANCIA_COLS  + DISTANCIA_COLS )	- SEPARACION_FILAS_COL;

	base      = (x2 - x1);
	radio     =  base/2;

	al_draw_circle(x1+radio, y1+radio, radio-1, makecolor2(COLOR_NEGRO),3);
	al_flip_display();
}



void entornoMarcarPosicion(int fila, int columna) {

	invertirFC(fila, columna);
	al_draw_rectangle( (ORIGEN_X + fila * DISTANCIA_COLS ) + SEPARACION_FILAS_COL -2,
				(ORIGEN_Y + columna * DISTANCIA_FILAS) + SEPARACION_FILAS_COL -2 ,
				(ORIGEN_X + fila * DISTANCIA_COLS + DISTANCIA_COLS) - SEPARACION_FILAS_COL +2 ,
				(ORIGEN_Y + columna * DISTANCIA_FILAS + DISTANCIA_FILAS)-SEPARACION_FILAS_COL +2 , makecolor2(COLOR_NEGRO) ,5);


	al_flip_display();
}

void entornoDesmarcarPosicion(int fila, int columna) {

	invertirFC(fila, columna);
    al_draw_rectangle( (ORIGEN_X + fila * DISTANCIA_COLS ) + SEPARACION_FILAS_COL -2,
				(ORIGEN_Y + columna * DISTANCIA_FILAS) + SEPARACION_FILAS_COL -2 ,
				(ORIGEN_X + fila * DISTANCIA_COLS + DISTANCIA_COLS) - SEPARACION_FILAS_COL +2 ,
				(ORIGEN_Y + columna * DISTANCIA_FILAS + DISTANCIA_FILAS)-SEPARACION_FILAS_COL +2 , makecolor2(COLOR_BLANCO) ,5);
 	al_flip_display();
}

void entornoMarcarBloque(int fila, int columna) {
	invertirFC(fila, columna);
	al_draw_rectangle( (ORIGEN_X + fila * DISTANCIA_COLS ) + SEPARACION_FILAS_COL -2,
				(ORIGEN_Y + columna * DISTANCIA_FILAS) + SEPARACION_FILAS_COL -2 ,
				(ORIGEN_X + fila * DISTANCIA_COLS + DISTANCIA_COLS) - SEPARACION_FILAS_COL +2 ,
				(ORIGEN_Y + columna * DISTANCIA_FILAS + DISTANCIA_FILAS)-SEPARACION_FILAS_COL +2 , makecolor2(COLOR_PLATA) ,3);


	al_flip_display();
}

void entornoDesmarcarBloque(int fila, int columna) {
	invertirFC(fila, columna);
	    al_draw_rectangle( (ORIGEN_X + fila * DISTANCIA_COLS ) + SEPARACION_FILAS_COL -2,
					(ORIGEN_Y + columna * DISTANCIA_FILAS) + SEPARACION_FILAS_COL -2 ,
					(ORIGEN_X + fila * DISTANCIA_COLS + DISTANCIA_COLS) - SEPARACION_FILAS_COL +2 ,
					(ORIGEN_Y + columna * DISTANCIA_FILAS + DISTANCIA_FILAS)-SEPARACION_FILAS_COL +2 , makecolor2(COLOR_BLANCO) ,3);
	 	al_flip_display();
}


void entornoPonerPuntuacion(int valor) {
	string msg;
	msg = "Puntuación: "+to_string(valor);
	al_draw_filled_rectangle(ORIGEN_X , COL_MARCADOR, ORIGEN_X+ 170, COL_MARCADOR+30, makecolor2(COLOR_BLANCO));
	al_draw_text(font, makecolor2(COLOR_GRIS),ORIGEN_X, COL_MARCADOR + 4  , ALLEGRO_ALIGN_LEFT, msg.c_str());
	al_flip_display();
}


void entornoPonerObjetivo( int valor){
	string msg;
	msg = "Max: "+to_string(valor);
	al_draw_filled_rectangle(ORIGEN_X +190, COL_MARCADOR, ORIGEN_X+ 300, COL_MARCADOR+30, makecolor2(COLOR_BLANCO));
	al_draw_text(font, makecolor2(COLOR_GRIS),ORIGEN_X+ 190, COL_MARCADOR + 4  , ALLEGRO_ALIGN_LEFT, msg.c_str());
	al_flip_display();
}


void entornoMostrarMensajeFin(string msg) {
	int i, j;
		for (i = 0, j = 0; i < 40 && j < 40; i += 4, j += 4) {

			al_draw_filled_rectangle(i + ORIGEN_X,     j + ORIGEN_Y   + 200,  ORIGEN_X   +350 - i, ORIGEN_Y+   320 -j,  makecolor2(COLOR_BLANCO));
			al_draw_filled_rectangle(i + ORIGEN_X + 2 ,j + ORIGEN_Y +2+ 200, (ORIGEN_X-2)+350 - i, ORIGEN_Y -2 +320 -j,  makecolor2(COLOR_GRIS));

			usleep(25000); //25 milisegundos
			al_flip_display();
		}

	al_draw_text(font, makecolor2(COLOR_BLANCO),ORIGEN_X+100,ORIGEN_Y+250, ALLEGRO_ALIGN_LEFT, msg.c_str());
	al_flip_display();
	usleep(500000); // medio segundo
}


void entornoMostrarMensaje( string msg, float pausa) {
	int col = 350;
	int fila = 600;
	int alto = 25;
	int ancho = 600;

	al_draw_filled_rectangle(col-2 , fila,  col + ancho, fila + alto,  makecolor2(COLOR_BLANCO));
	al_draw_text(font, makecolor2(COLOR_GRIS),col,fila, ALLEGRO_ALIGN_LEFT, msg.c_str());
	al_flip_display();
	entornoPausa(pausa);
	al_draw_filled_rectangle(col-2 , fila,  col + ancho,fila + alto,  makecolor2(COLOR_BLANCO));
	al_flip_display();

}


TipoTecla entornoLeerTecla() {

	TipoTecla tecla = TNada;
	ALLEGRO_EVENT evento;

	al_wait_for_event(colaEventos, &evento);

	if (evento.type == ALLEGRO_EVENT_KEY_DOWN) {
		switch (evento.keyboard.keycode) {
		case ALLEGRO_KEY_UP:
			tecla = TArriba;
			break;
		case ALLEGRO_KEY_DOWN:
			tecla = TAbajo;
			break;
		case ALLEGRO_KEY_LEFT:
			tecla = TIzquierda;
			break;
		case ALLEGRO_KEY_RIGHT:
			tecla = TDerecha;
			break;
		case ALLEGRO_KEY_ESCAPE:
			tecla = TSalir;
			break;
		case ALLEGRO_KEY_ENTER:
			tecla = TEnter;
			break;

		default:
			tecla = TNada;
			break;
		}
	};

	return tecla;

}



void entornoPausa(float pausa) {
	al_rest(pausa);
}



