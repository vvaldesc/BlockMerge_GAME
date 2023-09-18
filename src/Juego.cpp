/*
 * INTRODUCCIÓN A LA PROGRAMACIÓN / FUNDAMENTOS DE PROGRAMACIÓN
	Curso 2019/2020

	Nombre: TAD_Juego.cpp
	Descripción: TAD Juego gestionar las aciones q se realizan en el juego.
	Autor:	Juan Carlos MUñoz Fernández y Víctor Valdés Cobos
 *      Fecha: 5 ene. 2020
 */

#include "Juego.h"



bool iniciarJuego(Juego &t){

	bool inicioCorrecto;
	int objetivo, tam,deDonde;


	deDonde = 8;
	int m[MAX_TAMANO][MAX_TAMANO];
	inicioCorrecto = entornoCargarConfiguracion ( tam, objetivo, deDonde, m);
	if(inicioCorrecto){
		int fila, col;
		entornoIniciar(tam);
		t.valorObjetivo=objetivo;
		t.puntuacion=0;

		if(deDonde == 0){
			iniciarInformacion (t.tablero,tam,m);
			for ( fila = 0; fila < tam; fila++) {
				for ( col = 0; col < tam; col++) {
					entornoPonerNumero(fila, col, m[fila][col]);
				}
			}


		}
		else{
			iniciarAleatoriamente (t.tablero, deDonde, tam);
			for ( fila = 0; fila < tam; fila++) {
				for ( col = 0; col < tam; col++) {
					entornoPonerNumero(fila, col,obtenerValorCasilla (t.tablero, fila, col));

				}
			}

		}
	}
	return inicioCorrecto;
}



void actualizarJuego(Juego &t) {
	int fila, col;
		for ( col = 0; col < obtenerTamanos(t.tablero) ; col++) {
				for ( fila = 0; fila < obtenerTamanos(t.tablero) ; fila++) {
					entornoPonerNumero(fila, col,obtenerValorCasilla (t.tablero, fila, col)); // Copia la informacion que se encuentra en Tablero
					entornoPausa(0.03);

					}
			}

}



void gestionar(Juego &t,int &vm){



vm = valorMax (t.tablero);
	bool salir = false; //bandera utilizada para finalizar el bucle
	TipoTecla tecla;    //almacena la tecla pulsada por el usuario
	int n,fila,col,total;
	fila=col=total = 0;


	desResaltarBloque (t.tablero);


	entornoPonerPuntuacion(0); // Pone la puntuacion// Ampliación
	entornoPonerObjetivo( t.valorObjetivo); // Pone el el juego la informacio del valor que se tiene conseguir para superar el juego
	entornoMarcarPosicion(fila, col);
	entornoMostrarMensaje("Pulsa ESC para salir",1.5);
	resaltarMayor(t.tablero,valorMax (t.tablero)); //Obtiene la posicion del mayor valor en el tablero//Ampliación



	//el bucle permite al jugador desplazarse por el tablero de juego
	while (!salir) {
		vm = valorMax (t.tablero);
		mostrarPantalla(t.tablero,obtenerTamanos(t.tablero));


		int valor;
		valor = obtenerValorCasilla (t.tablero,fila, col);
		animacionResaltar (t.tablero,fila,col, valor);
		if(vm <t.valorObjetivo and algunBloque (t.tablero)){ // Si el valor no se ha superado continua el juego


			tecla = entornoLeerTecla();
			switch (tecla) {



			case TEnter:

				int nc,vt;
				vt = nc= 0;
				n = obtenerValorCasilla (t.tablero,fila, col); // Obtiene el valor de la casilla que se encuentra marcada

				if(formaParte (t.tablero,fila,col)){
				desResaltarBloque (t.tablero);
				vaciarBloque (t.tablero, fila, col, n,nc); // Vacia el bloque selecionado
				fusion(t.tablero);// Ampliación
				entornoPausa(0.1);// Ampliación
				ponerValor (t.tablero, fila, col, n+1 );
				desplazarVacias (t.tablero);  // Desplaza hacia abajo todas las casillas hasta ocupar las vacias
				rellenarVacias (t.tablero,vm); // Rellenas las casillas que han quedado vacia
				actualizarJuego(t);

				resaltarMayor(t.tablero,valorMax (t.tablero)); //Obtiene la posicion del mayor valor en el tablero//Ampliación
				vt = nc * n; // Producto para optener la puntuacion al vaciar bloque// Ampliación
				total = total + vt;  // Almacena la puntuacion// Ampliación
				entornoPonerPuntuacion(total); // Muestra en pantalla la puntuacion almacenada// Ampliación

		

				break;
			case TDerecha:
				desResaltarBloque (t.tablero);
				entornoDesmarcarPosicion(fila, col);
				reseteoResaltar(t.tablero);

				if (col < obtenerTamanos(t.tablero) - 1)
					col++;
				else
					col = 0;
				entornoMarcarPosicion(fila, col);

				break;
			case TIzquierda:
				desResaltarBloque (t.tablero);
				entornoDesmarcarPosicion(fila, col);
				reseteoResaltar(t.tablero);

				if (col > 0)
					col--;
				else
					col = obtenerTamanos(t.tablero) - 1;
				entornoMarcarPosicion(fila, col);

				break;
			case TArriba:
				desResaltarBloque (t.tablero);
				entornoDesmarcarPosicion(fila, col);
				reseteoResaltar(t.tablero);


				if (fila > 0)
					fila--;
				else
					fila = obtenerTamanos(t.tablero) - 1;


				entornoMarcarPosicion(fila, col);

				break;
			case TAbajo:
				desResaltarBloque (t.tablero);
				entornoDesmarcarPosicion(fila, col);
				reseteoResaltar(t.tablero);


				if (fila < obtenerTamanos(t.tablero) - 1)
					fila++;
				else
					fila = 0;
				entornoMarcarPosicion(fila, col);



				break;

			case TSalir:
				salir = true;
				break;

			case TNada:
				break;
			} //Fin de switch
		}//Fin de while
		}
		else{// Si el juego se ha supero se acaba el juego
			salir  = true;
		}

	}



}//Fin de if

void acabar(Juego &t, int vm){

	if(vm < t.valorObjetivo){ // Si se ha superado el valor maximo muestra el siguiente mensaje
		entornoMostrarMensajeFin("Juego no superado");
		entornoTerminar();
	}
	else{ // Si no se ha superado el valor maximo muestra el siguiente mensaje
		entornoMostrarMensajeFin("¡Juego superado!");
		entornoTerminar();

	}
}


