#pragma once
#include<iostream>

/*
Descripción de clase : permite la creacion de un nodo
Explicación de atributos : info  es de tipo int y permite acceder al dato almacenado en el nodo
							sig es de tipo cNodo y permite acceder al nodo siguiente del seleccionado
Contrato : La clase cuenta con los constructores que permiten asignar un valor ingresado 
			por el usuario al nodo
*/

class CNodo
{
	public:
		int info;
		CNodo* sig;

		//constructores
		CNodo() 
		{ 
			info = NULL;
			sig = NULL; 
		}

		CNodo(int paDato)
		{
			info = paDato;
			sig = NULL;
		}
		

};
