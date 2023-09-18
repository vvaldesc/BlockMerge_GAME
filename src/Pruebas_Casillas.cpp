/*
 * Pruebas_Casillas.cpp
 *
 *  Created on: 30 dic. 2019
	Autor:	Juan Carlos Muñoz Fernández y Víctor Valdés Cobos
 */

#include "Pruebas_Casillas.h"




void pruebaCasilla(){




	Casilla c;
	iniciar(c);


	if( obtenerSiOcupada(c) != false){
		cout<<"Error al obtener ocupadas"<<endl;
		cout<<"Error al iniciar casilla"<<endl;
	}

	ponerValor(c, 3);
	if (obtenerSiOcupada(c) !=true and obtenerValor(c) !=3){
		cout<<"Error al poner valor"<<endl;
	}
	if(obtenerValor(c) != 3){
		cout<<"Error al obtener valor"<<endl;

	}
	if( obtenerSiOcupada(c) != true){
		cout<<"Error al obtener ocupadas"<<endl;
	}
	vaciar(c);
	if( obtenerSiOcupada(c) != false){
		cout<<"Error al vaciar casilla"<<endl;
	}
	iniciar(c);
	ponerValor(c, -30);
	if (obtenerSiOcupada(c) !=false){
		cout<<"Error al poner valor"<<endl;
	}
	if(obtenerValor(c) != 0){
		cout<<"Error al obtener valor"<<endl;

	}
	if( obtenerSiOcupada(c) != false){
		cout<<"Error al obtener ocupadas"<<endl;
	}


}



void pruebaAmpliaciones(){// Ampliación



	Casilla c;
	iniciar(c);
	casillaDesresaltar(c);



	if(obtenerResaltada (c) !=false){
		cout <<  "ERROR: al obtener resaltada" << endl;
		cout <<  "ERROR: al desresaltar" << endl;
	}
	casillaResaltada(c);
	if((obtenerResaltada(c)) != true) {

		cout <<  "ERROR: al resaltar" << endl;
	}


}


void prueba_Casillas(){

	cout << "INICIO PRUEBAS " <<endl;
	cout <<"Inicio pruebas TAD_Casilla"<<endl;

	pruebaCasilla();
	pruebaAmpliaciones();


	cout<<"Fin prubas TAD_Casillas"<<endl;



}
