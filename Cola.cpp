#include<iostream>
#include"Cola.h"
using namespace std;

/*
Condicion: Se crean las primitivas de los nodos
Precondicion:Debe estar creada la clase .h
Postcondicion:
*/

//constructor
CCola::CCola()
{
	aPrimero = NULL;
	aUltimo = NULL;
	aI = false;
	aN = 0;
}

//destructor
CCola::~CCola()
{
}

//get
CNodo* CCola::getaPrimero()
{
	return aPrimero;
}

CNodo* CCola::getaUltimo()
{
	return aUltimo;
}

bool CCola::getaI()
{
	return aI;
}

int CCola::getaN()
{
	return aN;
}


//set

void CCola::setaPrimero(CNodo* paPrimero)
{
	aPrimero = paPrimero;
}

void CCola::setaUltimo(CNodo* paUltimo)
{
	aUltimo = paUltimo;
}

void CCola::setaI(bool paI)
{
	aI = paI;
}

void CCola::setaN(int paN)
{
	aN = paN;
}

//primitivas
//crear
/*
Descripcion: Se modifican los valores de aBase y aTope y se asigna el valor ingresado por el usuario
Precondicion: aInicio == NULL
Condicion: se ejecuta una vez
Postcondicion: aBase y aTope pasa de NULL a ser un nodo con el valor ingresado por el usuario
*/
void CCola::crear(int paDato)
{
	CNodo* Q = new CNodo(paDato);

	if (probar())
	{
		aPrimero = Q;
		aUltimo = Q;
		aN++;
	}
}

//Agregar
/*
Condicion: El usuario ingresa el dato
Precondicion: Se debe preguntar al usuario que datos desea ingresar
Postcondicion: Se agrega un nodo con la informacion dada por el usuario
*/
void CCola::agregar(int paDato)
{
	CNodo* P = NULL;
	CNodo* Q = new CNodo(paDato);

	//si es el primer nodo creado, establecer aPrimero como este
	if (aN == 0)
	{
		crear(paDato);
	}
	else
	{
		P = aPrimero;
		//reacomodar el puntero P a la posicion aN
		for (int i = 1; i < aN; i++)
		{
			P = P->sig;
		}
		Q->sig = P->sig;
		P->sig = Q;
		aUltimo = Q;
		aN++;
	}
	
}

//Eliminar
/*
Condicion: Elimina el primer dato
Precondicion: Existen datos para eliminar por lo tanto aPrimero!=NULL
Postcondicion: Elimina el primer nodo;
*/
void CCola::eliminar()
{
	//para poder eliminar debe existir aPrimero
	if (!probar())
	{
		aI = true;
		CNodo* aux = aPrimero;
		aPrimero = aPrimero->sig;
		int datos = aux->info;
		delete aux;
		if (aN==1)
		{
			aPrimero = NULL;
		}
		aN--;
	}
	else
	{
		aI = false;
	}
}
//Ver
/*
Condicion: La funcion probar debe retornar que hay datos
Precondicion: Deben existir datos para mostrar
Postcondicion: Muestra info de todos los nodos
*/
int CCola::ver()
{
	if (!probar())
	{
		aI = true;
		return aPrimero->info;
	
	}
	else
	{
		aI = false;
		return 0;	
	}

}
//Probar
/*
Condicion:
Precondicion:
Postcondicion: Retorna verdadero si hay datos, y falso si no hay
*/
bool CCola::probar()
{
	bool vacia;
	if (aPrimero != NULL)
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
Condicion: Debe existir la funcion eliminar
Precondicion: Deben existir datos
Postcondicion: Elimina todos los datos
*/
void CCola::destruir()
{
	if (!probar())
	{
		while (aPrimero != NULL)
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