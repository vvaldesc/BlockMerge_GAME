/*
 * TAD_Tablero.cpp
 *
 *  Created on: 30 dic. 2019
 *      Author: Juan Carlos MUñoz Fernández y Víctor Valldés Cobos
 */


#include "TAD_Tablero.h"

void mostrarPantalla (Tablero &t, int dimension){

	int fila;
	t.dimension = dimension;
	for(fila=0; fila<dimension; fila++){
		cout << obtenerValor(t.mtablero[fila][0]) << " " << obtenerValor(t.mtablero[fila][1]) << " " << obtenerValor(t.mtablero[fila][2])<< " " << obtenerValor(t.mtablero[fila][3])<< " " << obtenerValor(t.mtablero[fila][4])<< " " << obtenerValor(t.mtablero[fila][5])<< endl;

	}
	cout << "	" << endl;

}

void iniciarAleatoriamente (Tablero &t, int n, int dimension){

	int fila;
	int columna;
	t.dimension = dimension;
	for(fila=0; fila<dimension; fila++){
		for(columna = 0; columna<dimension; columna++){
			ponerValor(t.mtablero[fila][columna], rand()%n+1);

		}
	}
}



void iniciarInformacion (Tablero &t, int dimension,int m[MAX][MAX]){
	int fila;
	int col;
	t.dimension =dimension;
	for ( fila = 0; fila < t.dimension; fila++) {
		for ( col = 0; col < t.dimension; col++) {
			ponerValor(t.mtablero[fila][col],m[fila][col]);
		}
	}
}



int obtenerTamanos(Tablero t){

	return t.dimension;
}



void ponerValor (Tablero &t, int fila, int columna, int valor ){

	ponerValor(t.mtablero[fila][columna],valor);

}



void vaciarCasilla (Tablero &t, int fila, int columna){

	vaciar(t.mtablero[fila][columna]);
}



int obtenerValorCasilla (Tablero t, int fila, int columna){


	return obtenerValor (t.mtablero[fila][columna]);
}



bool formaParte (Tablero t, int fila, int columna){

	bool fp;
	fp = false;
	int valor;
	valor = obtenerValor (t.mtablero[fila][columna]);
	int MAX;
	MAX = obtenerTamanos(t);




	if(columna-1>=0 ){
		if(obtenerValor (t.mtablero[fila][columna -1]) == valor)
			fp = true;
	}

	if(columna+1<MAX ){
		if(obtenerValor (t.mtablero[fila][columna +1]) == valor)
			fp = true;
	}

	if(fila -1 >=0  ){
		if(obtenerValor (t.mtablero[fila-1][columna]) == valor)
			fp = true;
	}

	if(fila+ 1<MAX ){
		if(obtenerValor (t.mtablero[fila+1][columna]) == valor)
			fp = true;
	}




	return fp;

}



bool algunBloque (Tablero t){
	bool enc;
	enc = false;
	int fila;
	int columna;
	fila = 0;
	columna = 0;

	for(fila=0; fila< obtenerTamanos(t)  and !enc; fila++){
		for(columna=0; columna< obtenerTamanos(t)  and !enc; columna++){
			if(formaParte (t, fila, columna) ==true){
				enc =true;
			}

		}
	}

	return enc;
}



int valorMax (Tablero t){
	int fila,i;
	int columna,j;
	j=0;
	i=0;
	for(fila=0; fila<obtenerTamanos(t); fila++){
		for(columna=0; columna<obtenerTamanos(t); columna++){
			if(obtenerSiOcupadaCasilla (t,fila,columna) == true){
				if (obtenerValor (t.mtablero[fila][columna]) >= obtenerValor (t.mtablero[i][j])){
					i = fila;
					j =columna;
				}
			}
		}
	}
	return obtenerValor (t.mtablero[i][j]);
}



void vaciarBloque (Tablero &t, int fila, int columna, int valor, int &i){
	if(fila >= 0 and fila < obtenerTamanos(t)  ){
		if(columna >= 0 and columna < obtenerTamanos(t)  ){
			if( obtenerSiOcupadaCasilla (t,fila,columna) == true ){
				if( obtenerValor (t.mtablero[fila][columna]) ==valor){
					i++;
					vaciar(t.mtablero[fila][columna]);
					vaciarBloque (t, fila +1, columna, valor, i);
					vaciarBloque (t, fila -1, columna, valor,i);
					vaciarBloque (t, fila, columna+1, valor,i);
					vaciarBloque (t, fila, columna-1, valor,i);

				}
			}
		}
	}

}



void desplazarColumna(Tablero &t, int n){
	int fila;
	int m;
	int e;
	int v;
	fila= 0;
	m=0;
	while( fila < obtenerTamanos(t)){
		if(obtenerSiOcupadaCasilla (t,fila,n) == false){
			for(e = fila; e >=m; e-- ){
				v = obtenerValor (t.mtablero[e-1][n]);
				ponerValor(t.mtablero[e][n],v);

			}
			vaciar(t.mtablero[m][n]);
			m++;
		}
		fila++;
	}

}



void desplazarVacias (Tablero &t){

	int columna;

	for(columna = 0; columna< obtenerTamanos(t); columna++){
		desplazarColumna(t, columna);


	}
}



void rellenarVacias (Tablero &t, int valor){

	int fila;
	int columna;



	for(fila = 0; fila< obtenerTamanos(t); fila++){
		for(columna = 0; columna< obtenerTamanos(t); columna++){
			if (obtenerSiOcupadaCasilla (t,fila,columna) == false){
				ponerValor(t.mtablero[fila][columna], rand()%valor+1);
			}
		}
	}
}


void resaltarMayor(Tablero t,int n){

	int fila;
	int columna;

	for(fila = 0; fila< obtenerTamanos(t) ; fila++){
		for(columna=0; columna< obtenerTamanos(t) ; columna++){
			if(obtenerValorCasilla (t,fila,columna) == n){
				entornoPonerNumeroResaltado(fila, columna);


			}
		}
	}
}




void reseteoResaltar(Tablero &t){// Ampliación
	int i;
	int j;
	for(i = 0; i< obtenerTamanos(t) ; i++){
		for(j=0; j< obtenerTamanos(t) ; j++){
			casillaDesresaltar(t.mtablero[i][j]);
		}
	}
}



void desResaltarBloque (Tablero t){// Ampliación
	int i;
	int j;
	for(i = 0; i< obtenerTamanos(t) ; i++){
		for(j=0; j< obtenerTamanos(t) ; j++){
			if( obtenerSiOcupadaCasilla (t,i,j) == true ){
				if(obtenerResaltada(t.mtablero[i][j])==true){
					entornoDesmarcarBloque(i,j);

				}
			}

		}
	}

}



void fusion(Tablero &t){// Ampliación
	int columna,fila;

	for(fila = 0; fila< obtenerTamanos(t); fila++){
		for(columna = 0; columna< obtenerTamanos(t); columna++){
			if(obtenerSiOcupadaCasilla (t,fila,columna) == false){

				entornoPonerVacio( fila, columna); // Copia la informacion que se encuentra en Tablero a la Matriz

			}
		}
	}

}



void animacionNum(Tablero &t){// Ampliación
	int columna,fila, j;

	for(fila = 0; fila< obtenerTamanos(t); fila++){
		for(columna = 0; columna< obtenerTamanos(t); columna++){
			if(obtenerSiOcupadaCasilla (t,fila,columna) == false){

				for(j=0;j<=10;j++){
					entornoPonerNumero(fila, columna,j); // Copia la informacion que se encuentra en Tablero a la Matriz
					entornoPausa(0.01);

				}
			}
		}
	}
}



void animacionResaltar(Tablero &t,int fila, int columna, int valor) { // Ampliación
	casillaResaltar(t,fila, columna, valor);
	graficaResaltar(t);
}

void graficaResaltar(Tablero t) { // Ampliación


	int columna,fila;

	for(fila = 0; fila< obtenerTamanos(t); fila++){
		for(columna = 0; columna< obtenerTamanos(t); columna++){
			if(obtenerResaltada (t.mtablero[fila][columna]) != false){

				entornoMarcarBloque(fila,columna);
				entornoPausa(0.04);

			}
		}
	}

}

void casillaResaltar(Tablero &t, int fila, int columna, int valor) { // Ampliación
	if(obtenerResaltada(t.mtablero[fila][columna])==false){
		if(fila >= 0 and fila < obtenerTamanos(t) ){
			if(columna >= 0 and columna < obtenerTamanos(t)  ){
				if( obtenerSiOcupadaCasilla (t,fila,columna) == true ){
					if( obtenerValor (t.mtablero[fila][columna]) == valor){

						casillaResaltada(t.mtablero[fila][columna]);


						casillaResaltar (t, fila +1, columna, valor);
						casillaResaltar (t, fila -1, columna, valor);
						casillaResaltar (t, fila, columna+1, valor);
						casillaResaltar (t, fila, columna-1, valor);
					}
				}
			}
		}
	}
}

bool obtenerSiOcupadaCasilla(Tablero t, int fila, int columna) {
	return obtenerSiOcupada(t.mtablero[fila][columna]);
}
