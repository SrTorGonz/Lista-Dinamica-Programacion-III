#pragma once
#include<iostream>
#include "Nodo.h"

class CCola
{
	private:
		//atributos
		CNodo* aPrimero;
		CNodo* aUltimo;
		bool aI;
		int aN;

	public:
		//constructores
		CCola();
		~CCola();

		//get
		CNodo* getaPrimero();
		CNodo* getaUltimo();
		bool getaI();
		int getaN();

		//set
		void setaPrimero(CNodo* paPrimero);
		void setaUltimo(CNodo* paUltimo);
		void setaI(bool paI);
		void setaN(int paN);

		//primitivas
		void crear(int paDato);
		void agregar(int paDato);
		void eliminar();
		int ver();
		bool probar();
		void destruir();

};
