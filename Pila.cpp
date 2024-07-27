#include<iostream>
#include"Pila.h"
using namespace std;

//Constructor
CPila::CPila()
{
	aBase = NULL;
	aTope = NULL;
	aI = false;
	aN = 0;
}

//Destructor
CPila::~CPila()
{
}

//Get

CNodo* CPila::getaBase()
{
	return aBase;
}

CNodo* CPila::getaTope()
{
	return aTope;
}

bool CPila::getaI()
{
	return aI;
}

int CPila::getaN()
{
	return aN;
}


//Set

void CPila::setaBase(CNodo* paBase)
{
	aBase = paBase;
}

void CPila::setaTope(CNodo* paTope)
{
	aTope = paTope;
}

void CPila::setaI(bool paI)
{
	aI = paI;
}

void CPila::setaN(int paN)
{
	aN = paN;
}

//Primitivas

//crear
/*
Descripcion: Se modifican los valores de aBase y aTope y se asigna el valor ingresado por el usuario
Precondicion: aInicio == NULL
Condicion: se ejecuta una vez
Postcondicion: aBase y aTope pasa de NULL a ser un nodo con el valor ingresado por el usuario
*/
void CPila::crear(int paDato)
{
	CNodo* Q = new CNodo(paDato);

	if (probar())
	{
		aBase = Q;
		aTope = Q;
		aN++;
	}
}

//Agregar
/*
Descripcion: Crea el primer nodo y los siguientes dependiendo de lo que el usuario digite
Precondicion: Debe preguntar al usuario si desea agregar un nodo y un valor
Condicion: Desde aInicio hasta que el usuario se detenga
Postcondicion: Se muestran los datos que el usuario decidio
*/
void CPila::agregar(int paDato)
{
	CNodo* P = NULL;
	CNodo* Q = new CNodo(paDato);

	//si es el primer nodo creado, establecer aBase como este
	if (aN == 0)
	{
		crear(paDato);
	}
	else
	{
		P = aBase;
		//reacomodar el puntero P a la posicion aN
		for (int i = 1; i < aN; i++)
		{
			P = P->sig;
		}
		Q->sig = P->sig;
		P->sig = Q;
		aTope = Q;
		aN++;
	}
	
}

//Eliminar
/*
Descripcion: Elimina los datos de la lista
Precondicion: Debe haber creado al menos un nodo para eliminarlo
Condicion: debe tener datos en el primer nodo hasta el que el usuario digite
Postcondicion: se muestra la lista sin el nodo que el usuario elimino
*/
void CPila::eliminar()
{
	//para poder eliminar debe existir aBase
	if (!probar())
	{
		aI = true;
		//Apuntadores
		CNodo* P = aBase;
		CNodo* Q = aBase;

		//Cuando se quiere eliminar aBase no se requiere acomodar los punteros
		if (aN != 1)
		{
			//acomodar puntero P en el que se quiere eliminar
			for (int i = 1; i < aN; i++)
			{
				P = P->sig;
			}
			//acomodar puntero Q uno antes del que se quiere eliminar
			for (int i = 1; i < aN - 1; i++)
			{
				Q = Q->sig;
			}
		}

		Q->sig = P->sig;
		delete P;
		//aTope pasa a ser el anterior a aTope
		aTope = Q;

		//cuando solo hay un dato, al borrarlo aBase y aTope pasan a NULL
		if (aN == 1)
		{
			aBase = NULL;
			aTope = NULL;
		}
		aN--;
		P = NULL;	
	}
	else
	{
		aI = false;
	}
}
//Ver
/*
Descripcion: Comprueba si hay datos en la lista y los muestra
Precondicion: Debe haber datos en al menos un nodo para que retorne datos
Condicion: debe tener datos en el primer nodo hasta el que el usuario digite
Postcondicion: Muestra la informacion de todos los nodos
*/
int CPila::ver()
{
	if (!probar())
	{
		aI = true;
		return aTope->info;
	}
	else
	{
		aI = false;
		return 0;
	}

}
//Probar
/*
Descripcion: Desmuestra si hay una lista creada
Precondicion: se debe poder preguntar si hay datos o no
Condicion: No requiere datos creados para funcionar
Postcondicion: Retorna falso si hay datos y verdadero si no hay datos
*/
bool CPila::probar()
{
	bool vacia;
	if (aBase != NULL)
	{
		vacia = false;
		return vacia;
	}
	else
	{
		vacia = true;
		return vacia;
	}
}

//Destruir
/*
Descripcion: Se llama a la funcion elminar y al final elimina el ultimo nodo vacio
Precondicion: Debe estar creada la funcion eliminar
Condicion: debe haber minimo un nodo creado
Postcondicion: Se elimina el nodo de aInicio
*/
void CPila::destruir()
{
	if (!probar())
	{
		while (aBase != NULL)
		{
			eliminar();
		}
		aI = true;
	}
	else
	{
		aI = false;
	}
}