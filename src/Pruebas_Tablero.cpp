/*
 * Pruebas_Tablero.cpp
 *
 *  Created on: 30 dic. 2019
	Autor:	Juan Carlos Muñoz Fernández y Víctor Valdés Cobos
 */
#include "Pruebas_Tablero.h"

void prueba_IniciarAleatoriamente(){


	cout << "INICIO: prueba iniciar aleatoriamente"<<endl;
	int fil;

	Tablero t;
	iniciarAleatoriamente (t,7,8);
	for(fil=0; fil<MAX; fil++){

		cout << obtenerValorCasilla (t,fil,0)<<" " << obtenerValorCasilla (t,fil,1)<<" ";
		cout <<obtenerValorCasilla (t,fil,2)<<" " << obtenerValorCasilla (t,fil,3)<<" ";
		cout <<obtenerValorCasilla (t,fil,4)<<" " << obtenerValorCasilla (t,fil,5)<<" ";
		cout <<obtenerValorCasilla (t,fil,6)<<" " << obtenerValorCasilla (t,fil,7)<<endl;


	}
	cout << "FIN: prueba iniciar aleatoriamente"<<endl;
}



void prueba_IniciarInformacion(){


	cout << "INICIO: prueba indicar información"<<endl;
	Tablero t;
	int m[MAX][MAX];

	m [0][0] = 1;
	m [0][1] = 2;
	m [0][2] = 3;
	m [0][3] = 4;
	m [1][0] = 1;
	m [1][1] = 2;
	m [1][2] = 3;
	m [1][3] = 4;
	m [2][0] = 1;
	m [2][1] = 2;
	m [2][2] = 3;
	m [2][3] = 4;
	m [3][0] = 1;
	m [3][1] = 2;
	m [3][2] = 3;
	m [3][3] = 4;



	 iniciarInformacion (t,4,m);



	if(obtenerValorCasilla (t,0,0) != 1){

		cout<<"Error prueba iniciar informacion 00"<<endl;

	}

	if(obtenerValorCasilla (t,0,1) != 2){

		cout<<"Error prueba iniciar informacion 01"<<endl;

	}

	if(obtenerValorCasilla (t,0,2) != 3){

		cout<<"Error prueba iniciar informacion 02"<<endl;

	}

	if(obtenerValorCasilla (t,0,3) != 4){

		cout<<"Error prueba iniciar informacion 03"<<endl;

	}
	if(obtenerValorCasilla (t,1,0) != 1){

		cout<<"Error prueba iniciar informacion 10"<<endl;

	}

	if(obtenerValorCasilla (t,1,1) != 2){

		cout<<"Error prueba iniciar informacion 11"<<endl;

	}

	if(obtenerValorCasilla (t,1,2) != 3){

		cout<<"Error prueba iniciar informacion 12"<<endl;

	}

	if(obtenerValorCasilla (t,1,3) != 4){

		cout<<"Error prueba iniciar informacion 13"<<endl;

	}
	if(obtenerValorCasilla (t,2,0) != 1){

		cout<<"Error prueba iniciar informacion 20"<<endl;

	}

	if(obtenerValorCasilla (t,2,1) != 2){

		cout<<"Error prueba iniciar informacion 21"<<endl;

	}

	if(obtenerValorCasilla (t,2,2) != 3){

		cout<<"Error prueba iniciar informacion 22"<<endl;

	}

	if(obtenerValorCasilla (t,2,3) != 4){

		cout<<"Error prueba iniciar informacion 23"<<endl;

	}
	if(obtenerValorCasilla (t,3,0) != 1){

		cout<<"Error prueba iniciar informacion 30"<<endl;

	}

	if(obtenerValorCasilla (t,3,1) != 2){

		cout<<"Error prueba iniciar informacion 31"<<endl;

	}

	if(obtenerValorCasilla (t,3,2) != 3){

		cout<<"Error prueba iniciar informacion 32"<<endl;

	}

	if(obtenerValorCasilla (t,3,3) != 4){

		cout<<"Error prueba iniciar informacion 33"<<endl;

	}


	cout << "FIN: prueba indicar información"<<endl;



}



void prueba_obtenerTamano(){
	cout << "INICIO: prueba obtener tamaño"<<endl;
	Tablero t;
	iniciarAleatoriamente (t, 10, 8);

	if(obtenerTamanos(t) !=8) {
		cout <<  "ERROR: al obtener el tañano de la matriz" << endl;
	}
	cout << "FIN: prueba obtener tamaño"<<endl;
}



void prueba_PonerValor (){
	cout << "INICIO: prueba poner valor "<<endl;


	Tablero t;
	iniciarAleatoriamente(t,1,4);
	ponerValor (t, 0, 0, 1 );
	ponerValor (t, 0, 1, 4 );
	ponerValor (t, 0, 2, 3 );
	ponerValor (t, 0, 3, 7 );
	ponerValor (t, 1, 0, 7 );
	if (obtenerValorCasilla (t,0,0) !=1){
		cout<<"ERROR: al introducir valor"<<endl;
	}
	if (obtenerValorCasilla (t,0,1) !=4){
		cout<<"ERROR: al introducir valor"<<endl;
	}
	if (obtenerValorCasilla (t,0,2) !=3){
		cout<<"ERROR: al introducir valor"<<endl;
	}
	if (obtenerValorCasilla (t,0,3) !=7){
		cout<<"ERROR: al introducir valor"<<endl;
	}
	if (obtenerValorCasilla (t,1,0) !=7){
		cout<<"ERROR: al introducir valor"<<endl;
	}

	cout << "FIN: prueba poner valor "<<endl;
}



void prueba_VaciarCasilla (){
	cout << "INICIO: prueba vaciar casilla "<<endl;

	Tablero t;
	iniciarAleatoriamente (t, 10,8);
	vaciarCasilla (t, 0, 0);
	vaciarCasilla (t, 0, 3);
	if (obtenerSiOcupadaCasilla (t,0,0)  == true){
		cout<<"ERROR: al vaciar casilla 1"<<endl;
	}
	if (obtenerSiOcupadaCasilla (t,0,3)  == true){
		cout<<"ERROR: al vaciar casilla 2"<<endl;
	}
	if (obtenerSiOcupadaCasilla (t,1,0)  == false){
		cout<<"ERROR: al vaciar casilla 2"<<endl;
	}
	cout << "FIN: prueba vaciar casilla "<<endl;


}



void prueba_ObtenerValorCasilla (){

	cout << "INICIO: prueba indicar información"<<endl;

	Tablero t;
	iniciarAleatoriamente (t,7,8);

	if(obtenerValorCasilla (t, 0, 0) != obtenerValorCasilla (t,0,0)){
		cout<<" ERROR al obtener valor en 00"<<endl;
	}
	if(obtenerValorCasilla (t, 0, 5) != obtenerValorCasilla (t,0,5)){
		cout<<"ERROR al obtener valor en 05"<<endl;
	}
	if(obtenerValorCasilla (t, 1, 0) != obtenerValorCasilla (t,1,0)){
		cout<<"ERROR al obtener valor en 10"<<endl;
	}
	if(obtenerValorCasilla (t, 5, 3) != obtenerValorCasilla (t,5,3)){
		cout<<"ERROR al obtener valor en 53"<<endl;
	}
	if(obtenerValorCasilla (t, 4, 0) != obtenerValorCasilla (t,4,0)){
		cout<<"ERROR al obtener valor en 40"<<endl;
	}
	cout << "FIN: prueba indicar información"<<endl;

}



void prueba_FormaParte (){
	cout << "INICIO: prueba  Obtener si una casilla pertenece a un bloque "<<endl;



	Tablero t;

	iniciarAleatoriamente (t,7,8);
	ponerValor (t, 2, 0, 7 );
	ponerValor (t, 1, 0, 7 );

	if (formaParte (t,2, 0) != true){

		cout << "ERROR  bloque 1"<<endl;
	}
	if (formaParte (t,1, 0) != true){

		cout << "ERROR  bloque 2"<<endl;
	}
	iniciarAleatoriamente (t,6,4);
	ponerValor (t, 1, 1, 6 );
	ponerValor (t, 1, 2, 6 );

	if (formaParte (t,1, 1) != true){

		cout << "ERROR  bloque 3"<<endl;
	}
	if (formaParte (t,1, 2) != true){

		cout << "ERROR  bloque 4"<<endl;
	}
	ponerValor (t, 1, 1, 6 );
	ponerValor (t, 1, 2, 5 );

	if (formaParte (t,1, 1) != false){

		cout << "ERROR  bloque 5"<<endl;
	}
	if (formaParte (t,1, 2) != false){

		cout << "ERROR  bloque 6"<<endl;
	}
	iniciarAleatoriamente (t,7,7);
	ponerValor (t, 2, 0, 7 );
	ponerValor (t, 1, 0, 6 );
	ponerValor (t, 2, 1, 8 );
	ponerValor (t, 1, 1, 9 );

	if (formaParte (t,2, 0) == true){

		cout << "ERROR  bloque 9"<<endl;
	}
	if (formaParte (t,1, 0) == true){

		cout << "ERROR  bloque 10"<<endl;
	}
	iniciarAleatoriamente (t,6,8);
	ponerValor (t, 1, 1, 6 );
	ponerValor (t, 1, 2, 3 );

	if (formaParte (t,1, 1) == true){

		cout << "ERROR  bloque 3"<<endl;
	}
	if (formaParte (t,1, 2) == true){

		cout << "ERROR  bloque 4"<<endl;
	}
	Tablero c;
	iniciarAleatoriamente (c,2,2);
	ponerValor (c, 0, 0, 0 );
	ponerValor (c, 0, 1, 1 );
	ponerValor (c, 1, 0, 2 );
	ponerValor (c, 1, 1, 3 );

	if (formaParte (t,1, 0) != false){

			cout << "ERROR  bloque 7"<<endl;
		}
	if (formaParte (t,0, 0) != false){

			cout << "ERROR  bloque 8"<<endl;
		}



	cout << "FIN: prueba  Obtener si una casilla pertenece a un bloque "<<endl;

}



void prueba_AlgunBloque (){

	cout << "INICIO: prueba  Obtener si hay algun bloque en la matriz "<<endl;



	Tablero t;
	iniciarAleatoriamente (t,7,8);
	ponerValor (t, 2, 0, 7 );
	ponerValor (t, 1, 0, 7 );

	if ( algunBloque (t) != true){

		cout << "ERROR  bloque 1"<<endl;
	}
	if (algunBloque (t) != true){

		cout << "ERROR  bloque 2"<<endl;
	}
	iniciarAleatoriamente (t,6,8);

	ponerValor (t, 1, 1, 6 );
	ponerValor (t, 1, 2, 6 );

	if (algunBloque (t) != true){

		cout << "ERROR  bloque 3"<<endl;
	}
	if (algunBloque (t) != true){

		cout << "ERROR  bloque 4"<<endl;
	}
	Tablero c;
	iniciarAleatoriamente (c,4,4);
	ponerValor (c, 0, 0, 0 );
	ponerValor (c, 0, 1, 1 );
	ponerValor (c, 0, 2, 2 );
	ponerValor (c, 0, 3, 3 );
	ponerValor (c, 1, 0, 4 );
	ponerValor (c, 1, 1, 5 );
	ponerValor (c, 1, 2, 6 );
	ponerValor (c, 1, 3, 7 );
	ponerValor (c, 2, 0, 0 );
	ponerValor (c, 2, 1, 1 );
	ponerValor (c, 2, 2, 2 );
	ponerValor (c, 2, 3, 3 );
	ponerValor (c, 3, 0, 4 );
	ponerValor (c, 3, 1, 5 );
	ponerValor (c, 3, 2, 6 );
	ponerValor (c, 3, 3, 7 );


		if (algunBloque (c) != false){

				cout << "ERROR  bloque 5"<<endl;
			}

	int fil;
	iniciarAleatoriamente (t,6,6);
	for(fil=0; fil<t.dimension; fil++){

		cout << obtenerValorCasilla (t,fil,0)<<" " << obtenerValorCasilla (t,fil,1)<<" ";
		cout <<obtenerValorCasilla (t,fil,2)<<" " << obtenerValorCasilla (t,fil,3)<<" ";
		cout <<obtenerValorCasilla (t,fil,4)<<" " << obtenerValorCasilla (t,fil,5)<<endl;

	}
	if(algunBloque (t) == true){
		cout<< "Hay un bloque"<<endl;

	}
	else{
		cout<< " No hay un bloque"<<endl;




	}





	cout << "FIN: prueba  Obtener si hay algun bloque en la matriz "<<endl;
}



void prueba_ValorMax (){



	cout << "INICIO: prueba  Obtener mayor valor "<<endl;


	Tablero t;
	iniciarAleatoriamente (t,3,8);
	ponerValor (t, 2, 0, 3 );

	if (valorMax (t) != 3){
		cout<< "ERROR al obtener mayor valor prueba 1"<<endl;

	}
	iniciarAleatoriamente (t,5,8);
	ponerValor (t, 2, 0, 5 );

	if (valorMax (t) != 5){
		cout<< "ERROR al obtener mayor valor prueba 2"<<endl;

	}
	iniciarAleatoriamente (t,7,8);
	ponerValor (t, 2, 0, 7 );

	if (valorMax (t) != 7){
		cout<< "ERROR al obtener mayor valor prueba 3"<<endl;

	}
	iniciarAleatoriamente (t,10,8);
	ponerValor (t, 2, 0, 10 );

	if (valorMax (t) != 10){
		cout<< "ERROR al obtener mayor valor prueba 4"<<endl;

	}
	iniciarAleatoriamente (t,1,8);
	ponerValor (t, 2, 0, 1 );

	if (valorMax (t) != 1){
		cout<< "ERROR al obtener mayor valor prueba 5"<<endl;

	}
	cout << "FIN: prueba  Obtener mayor valor "<<endl;


}



void prueba_VaciarBloque (){
	cout << "INICIO: prueba  vaciar bloque "<<endl;
	Tablero t;
	int n;
	n = 0;
	iniciarAleatoriamente (t,7,7);
	ponerValor (t, 1, 2, 7 );
	ponerValor (t, 2, 1, 7 );
	ponerValor (t, 2, 2, 7 );
	ponerValor (t, 2, 3, 7 );
	ponerValor (t, 3, 2, 7 );
	ponerValor (t, 4, 4, 2 );
	ponerValor (t, 4, 5, 2 );
	ponerValor (t, 4, 0, 2 );
	ponerValor (t, 5, 0, 2 );

	vaciarBloque (t,2, 2, 7,n);
	if(n <! 5){
		cout << "ERROR al contar elementos que componene el bloque 1"<<endl;

	}
	n = 0;
	vaciarBloque (t,4, 4, 2,n);
	if(n <! 2){
		cout << "ERROR al contar elementos que componene el bloque 1"<<endl;

	}
	n=0;
	vaciarBloque (t,5, 0, 2,n);
	if(n <! 2){
		cout << "ERROR al contar elementos que componene el bloque 1"<<endl;

	}
	ponerValor (t, 3, 1, 3 );
	ponerValor (t, 4, 3, 4 );

	if(obtenerSiOcupadaCasilla (t,1,2) !=false){
		cout<<"ERROR al vaciar bloque 12"<<endl;

	}
	if(obtenerSiOcupadaCasilla (t,2,1) !=false){
		cout<<"ERROR al vaciar bloque 21"<<endl;
	}
	if(obtenerSiOcupadaCasilla (t,2,2) !=false){
		cout<<"ERROR al vaciar bloque 22"<<endl;

	}
	if(obtenerSiOcupadaCasilla (t,2,3) !=false){
		cout<<"ERROR al vaciar bloque 23"<<endl;

	}
	if(obtenerSiOcupadaCasilla (t,3,2) !=false){
		cout<<"ERROR al vaciar bloque 32"<<endl;

	}
	if(obtenerSiOcupadaCasilla (t,4,4) !=false){
		cout<<"ERROR al vaciar bloque 44"<<endl;

	}
	if(obtenerSiOcupadaCasilla (t,4,5) !=false){
		cout<<"ERROR al vaciar bloque 45"<<endl;

	}
	if(obtenerSiOcupadaCasilla (t,4,3) !=true){
		cout<<"ERROR al vaciar bloque 43"<<endl;

	}
	if(obtenerSiOcupadaCasilla (t,3,1) !=true){
		cout<<"ERROR al vaciar bloque 31"<<endl;

	}
	if(obtenerSiOcupadaCasilla (t,4,0) !=false){
		cout<<"ERROR al vaciar bloque 40"<<endl;

	}

	if(obtenerSiOcupadaCasilla (t,5,0) !=false){
		cout<<"ERROR al vaciar bloque 50"<<endl;

	}
	cout << "FIN: prueba  vaciar bloque "<<endl;

}



void prueba_DesplazarVacias (){
	cout << "INICIO: prueba  desplazar vacias"<<endl;


	Tablero t;
	int n;
	n= 0;
	iniciarAleatoriamente (t,7,7);
	ponerValor (t, 1, 2, 7 );
	ponerValor (t, 2, 1, 7 );
	ponerValor (t, 2, 2, 7 );
	ponerValor (t, 2, 3, 7 );
	ponerValor (t, 3, 2, 7 );
	ponerValor (t, 4, 4, 2 );
	ponerValor (t, 4, 5, 2 );
	ponerValor (t, 4, 0, 2 );
	ponerValor (t, 5, 0, 2 );
	vaciarBloque (t, 2, 2, 7,n);
	vaciarBloque (t, 4, 4, 2,n);
	vaciarBloque (t, 5, 0, 2,n);

	desplazarVacias (t);
	if(obtenerSiOcupadaCasilla (t,0,0) !=false){
		cout<<"ERROR al desplazar vaciar  00"<<endl;

	}
	if(obtenerSiOcupadaCasilla (t,0,1) !=false){
		cout<<"ERROR al desplazar vaciar  01"<<endl;
	}
	if(obtenerSiOcupadaCasilla (t,0,2) !=false){
		cout<<"ERROR al desplazar vaciar  02"<<endl;
	}
	if(obtenerSiOcupadaCasilla (t,0,3) !=false){
		cout<<"ERROR al desplazar bloque 03"<<endl;

	}
	if(obtenerSiOcupadaCasilla (t,0,4) !=false){
		cout<<"ERROR al desplazar bloque 04"<<endl;

	}
	if(obtenerSiOcupadaCasilla (t,0,5) !=false){
		cout<<"ERROR al desplazar bloque 05"<<endl;

	}
	if(obtenerSiOcupadaCasilla (t,1,0) !=false){
		cout<<"ERROR al desplazar bloque 10"<<endl;

	}
	if(obtenerSiOcupadaCasilla (t,1,2) !=false){
		cout<<"ERROR al desplazar bloque 12"<<endl;

	}
	if(obtenerSiOcupadaCasilla (t,2,2) !=false){
		cout<<"ERROR al desplazar bloque 22"<<endl;

	}

	cout << "FIN: prueba  desplazar vacias "<<endl;

}






void prueba_RellenarVacias (){
	cout << "INICIO: prueba  rellenar vacias"<<endl;


	Tablero t;
	int n;
	n = 0;
	iniciarAleatoriamente (t,7,6);
	vaciarBloque (t, 2, 2, 7, n);
	vaciarBloque (t, 4, 4, 2, n);
	vaciarBloque (t, 5, 0, 2, n);
	rellenarVacias (t,1);

	int i;
	int h;
	int p;
	p=0;
	for(i = 0; i<6; i++){
		for(h=5;h>=0;h--){
			if(obtenerSiOcupadaCasilla (t,i,h) !=true){
				p++;
			}
		}
	}


	cout << "FIN: prueba  rellenar todas con total de "<< p<< " errores "<<endl;
}




void prueba_ResaltarBloque (){

	Tablero t;
	int j,i,k;
	k=0;
	iniciarAleatoriamente (t,4,6);

	ponerValor (t, 0, 0, 7 );
	ponerValor (t, 0, 1, 7 );
	ponerValor (t, 0, 2, 7 );
	ponerValor (t, 0, 3, 7 );
	ponerValor (t, 1, 0, 7 );
	ponerValor (t, 1, 1, 1 );
	ponerValor (t, 1, 2, 2 );
	ponerValor (t, 1, 3, 3 );
	ponerValor (t, 2, 0, 4 );
	ponerValor (t, 2, 1, 5 );
	ponerValor (t, 2, 2, 6 );
	ponerValor (t, 2, 3, 7 );
	ponerValor (t, 3, 0, 8 );
	ponerValor (t, 3, 1, 9 );
	ponerValor (t, 3, 2, 4 );
	ponerValor (t, 3, 3, 5 );


	casillaResaltar(t,  0,  0,  7);
	cout << "INICIO: prueba Resaltar Filas"<<endl;
	for(i = 0; i< obtenerTamanos(t) ; i++){
		for(j=0; j< obtenerTamanos(t) ; j++){
			if(obtenerResaltada(t.mtablero[i][j])==true){
				k++;

			}
		}
	}

	if(k!= 5){
		cout<< "Error al resaltar filas"<<endl;
	}
	cout << "FIN: prueba Resaltar Filas"<<endl;

}
void prueba_ReseteoResaltar (){
	Tablero t;
	int j,i,k;
	k=0;
	iniciarAleatoriamente (t,4,6);

	ponerValor (t, 0, 0, 7 );
	ponerValor (t, 0, 1, 7 );
	ponerValor (t, 0, 2, 7 );
	ponerValor (t, 0, 3, 7 );
	ponerValor (t, 1, 0, 7 );
	ponerValor (t, 1, 1, 1 );
	ponerValor (t, 1, 2, 2 );
	ponerValor (t, 1, 3, 3 );
	ponerValor (t, 2, 0, 4 );
	ponerValor (t, 2, 1, 5 );
	ponerValor (t, 2, 2, 6 );
	ponerValor (t, 2, 3, 7 );
	ponerValor (t, 3, 0, 8 );
	ponerValor (t, 3, 1, 9 );
	ponerValor (t, 3, 2, 4 );
	ponerValor (t, 3, 3, 5 );

	casillaResaltar(t,  0,  0,  7);

	cout << "INICIO: prueba Reseteoresaltar Filas"<<endl;

	k=0;
	reseteoResaltar(t);
	for(i = 0; i< obtenerTamanos(t) ; i++){
		for(j=0; j< obtenerTamanos(t) ; j++){
			if(obtenerResaltada(t.mtablero[i][j])==true){
				k++;

			}
		}
	}
	if(k!=0){
		cout<<"Error: al resetear el resaltado fila"<<endl;
	}

	cout << "FIN: prueba Reseteoresaltar Filas"<<endl;

}


void prueba_Tablero(){
	cout <<"Inicio pruebas TAD_Tablero"<<endl;

	prueba_IniciarAleatoriamente();
	prueba_IniciarInformacion();
	prueba_obtenerTamano();
	prueba_PonerValor ();
	prueba_VaciarCasilla ();
	prueba_ObtenerValorCasilla ();
	prueba_FormaParte ();
	prueba_AlgunBloque ();
	prueba_ValorMax ();
	prueba_VaciarBloque ();
	prueba_DesplazarVacias ();
	prueba_RellenarVacias ();
	prueba_ResaltarBloque ();
	prueba_ReseteoResaltar ();
	cout<<"Fin prubas TAD_Tablero"<<endl;



	cout << "FIN PRUEBAS" << endl;
}




