#pragma once
#include<iostream>
#include "Nodo.h"
/*
Descripción de clase : La clase funciona bajo la politica LIFO(last in, first out)
Explicación de atributos : aBase es de tipo CNodoy siempre esta en la 
							primera posicion de la lista
							aTope es de tipo cNodo y siempre esta en la ultima
							posicion de la lista
							aI es de tipo bool e indica cuandoo se pudo o no
							realizar una accion
							aN es la cantidad de nodos existentes
Contrato : La clase permite crear una lista de tipo pila y a las primitivas de esta
*/


class CPila
{
private:
	//atributos
	CNodo* aBase;
	CNodo* aTope;
	bool aI;
	int aN;

public:
	//constructores
	CPila();
	~CPila();

	//get
	CNodo* getaBase();
	CNodo* getaTope();
	bool getaI();
	int getaN();

	//set
	void setaBase(CNodo* paBase);
	void setaTope(CNodo* paTope);
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
