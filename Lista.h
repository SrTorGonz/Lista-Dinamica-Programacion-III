#pragma once
#include<iostream>
#include "Nodo.h"
/*
Descripción de clase : La clase funciona bajo la politica FIFO(first in, first out)
Explicación de atributos : aInicio es de tipo CNodoy siempre esta en la
							primera posicion de la lista
							aI es de tipo bool e indica cuandoo se pudo o no
							realizar una accion
							aN es la cantidad de nodos existentes
Contrato : La clase permite crear una lista de tipo pila y a las primitivas de esta
*/
class CLista
{
	private:
		//atributos
		CNodo* aInicio;
		bool aI;
		int aN;

	public:
		//constructores
		CLista();
		~CLista();

		//get
		CNodo* getaInicio();
		bool getaI();
		int getaN();

		//set
		void setaInicio(CNodo* paInicio);
		void setaI(bool paI);
		void setaN(int paN);

		//primitivas
		void crear(int paDato);
		void agregar(int paDato, int paPos);
		void eliminar(int paPos);
		int ver(int paPos);
		bool probar();
		void destruir();

		//otros
		//ordenamientos
		void ordenLineal();
		void ordenBurbuja();
		void ordenInserccion(int paDato);

		//busquedas
		int linealDesordenada(int paDato);
		int linealOrdenada(int paDato);
		int Binaria(int paDato);

		//Operaciones
		void suma(CNodo* paiL1, int paN1, CNodo* paiL3, int paN2);
		void resta(CNodo* paiL1, int paN1, CNodo* paiL3, int paN2);
		void productoescalar(CNodo* paInicio, int paN, int paDato);
		void multiplicacion(CNodo* paInicio1, int paN1,CNodo* paInicio2, int paN2);
};



