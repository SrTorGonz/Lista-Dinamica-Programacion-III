#include<iostream>
#include"Lista.h"
using namespace std;



//Constructor
CLista::CLista()
{
	aInicio = NULL;
	aI = false;
	aN = 0;
}

//Destructor
CLista::~CLista()
{
}

//get
CNodo* CLista::getaInicio()
{
	return aInicio;
}

bool CLista::getaI()
{
	return aI;
}

int CLista::getaN()
{
	return aN;
}


//Set
void CLista::setaInicio(CNodo* paInicio)
{
	aInicio = paInicio;
}

void CLista::setaI(bool paI)
{
	aI = paI;
}

void CLista::setaN(int paN)
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
void CLista::crear(int paDato)
{
	CNodo* Q = new CNodo(paDato);

	if (probar())
	{
		aInicio = Q;
		aN++;
	}
}

//Agregar
/*
Descripcion: Crea el primer nodo y los siguientes dependiendo de lo que el usuario digite
Precondicion: Debe preguntar al usuario si desea agregar un nodo y un valor
Condicion: Desde aInicio hasta que el usuario se detenga
Postcondicion: inserta el dato del usuario en la posicion elegida
*/
void CLista::agregar(int paDato, int paPos)
{
	CNodo* P = NULL;
	CNodo* Q = new CNodo(paDato);
	int vCiclo = 0;

	//verificar que la posicion sea mayor que 0, de lo contrario no se puede insertar
	if (paPos<=0)
	{
		aI = false;
	}
	else
	{
		aI = true;
		//si no hay datos se pone directamente en la primera pos
		if (aN == 0)
		{
			crear(paDato);
		}
		else
		{
			//si se inserta en pos 1, establecer aInicio como este
			if (paPos == 1)
			{
				P = aInicio;
				aInicio = Q;
				Q->sig = P;
			}
			else
			{
				//modificar la cantidad de veces que se va a repetir el bucle
				//en el caso de que paPos <= aN el bucle ira hasta uno antes de paPos
				//en el caso contrario el ciclo se repitira aN veces
				if (paPos <= aN)
				{
					vCiclo = paPos - 1;
				}
				else
				{
					vCiclo = aN;
				}

				P = aInicio;
				//reacomodar el puntero P a la posicion paPos
				for (int i = 1; i < vCiclo; i++)
				{
					P = P->sig;
				}
				Q->sig = P->sig;
				P->sig = Q;
				aN++;
			}
		}

	}
	
}

//Eliminar
/*
Descripcion: Elimina el dato en la posicion ingresada por el usuario
Precondicion: Debe haber creado al menos un nodo para eliminarlo aN>0
Condicion: debe tener datos en el primer nodo hasta el que el usuario digite
Postcondicion: se muestra la lista sin el nodo que el usuario elimino
*/
void CLista::eliminar(int paPos)
{
	//para poder eliminar debe existir aInicio
	if (!probar())
	{
		aI = true;
		//apuntador
		CNodo* P = aInicio;
		CNodo* Q = aInicio;

		//Cuando se quiere eliminar aInicio no se requiere acomodar los punteros
		if (paPos==1)
		{
			aInicio = P->sig;
		}
		else
		{
			//acomodar puntero P en el que se quiere eliminar
			for (int i = 1; i < paPos; i++)
			{
				P = P->sig;
			}
			//acomodar puntero Q uno antes del que se quiere eliminar
			for (int i = 1; i < paPos - 1; i++)
			{
				Q = Q->sig;
			}

			Q->sig = P->sig;
		}

		delete P;

		//cuando solo hay un dato, al borrarlo a Inicio pasa a NULL
		if (aN == 1)
		{
			aInicio = NULL;
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
Descripcion: Comprueba si hay datos en la lista y muestra el solicitado por el usuario
Precondicion: Debe haber datos en al menos un nodo para que retorne datos
Condicion: debe tener datos en el primer nodo hasta el que el usuario digite
Postcondicion: Muestra el dato ubicado en la posicion ingresada por el usuario
*/
int CLista::ver(int paPos)
{
	if (!probar())
	{
		aI = true;
		CNodo* P = aInicio;
		//mover el puntero P a la posicion a ver
		if (paPos<=aN)
		{
			for (int i = 1; i < paPos; i++)
			{
				P = P->sig;
			}
			return P->info;
		}
		else
		{
			aI = false;
			return 0;
		}
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
bool CLista::probar()
{
	bool vacia;
	if (aInicio!=NULL)
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
void CLista::destruir()
{
	if (!probar())
	{
		//llamado al metodo eliminar hasta que aInicio sea NULL
		while (aInicio!=NULL)
		{
			eliminar(aN);
		}
		aI = true;
	}
	else
	{
		aI = false;
	}
	
}

//Ordenamientos

//Ordenamiento lineal
/*
Descripcion: Consiste en intercambiar la primera posición por el elemento más pequeño, luego con la segunda posición para el segundo elemento más pequeño y así sucesivamente
Precondicion: Se debe crear la lista y debe tener datos
Condicion: La cantidad maxima se agrega po el usuario 
Postcondicion: Muestra la lista ordenada de menor a mayor 
*/
void CLista::ordenLineal()
{
	if (!probar())
	{
		aI = true;

		int k = 0, cont = 2, save = 0;
		// Inicializar P en aInicio
		//Inicializar Q uno adelante de aInicio
		CNodo* P = aInicio;
		CNodo* Q = aInicio->sig;
		
		for (int i = 1; i < aN; i++)
		{
			k = cont;
			Q = P->sig;
			
			while (k<=aN)
			{	
				//si el dato en P es mayor que el dato en Q se realiza un intercambio
				if (P->info >= Q->info)
				{
					save = Q->info;
					Q->info = P->info;
					P->info = save;
				}
				//mover el puntero Q uno hacia el siguiente nodo
				Q = Q->sig;
				k++;
			}
			P = P->sig;
			cont++;
		}
	}
	else
	{
		aI = false;
	}
}

//Ordenamiento burbuja
/*
Descripcion:Se compara de manera adyacente entre parejas, el 1 y el 2, despues el 2 y el 3… y asi, si el de la izq > derecha entonces se hace el intercambio
Precondicion: Debe estar creda una lista y que tenga minimo dos datos
Condicion: La cantidad maxima se agrega po el usuario 
Postcondicion: Muestra de una manera rapida y optimizada el ordenamiento de la lista
*/
void CLista::ordenBurbuja()
{
	bool inter = false;
	int k = 1, save = 0, cont = 0;
	// Inicializar P en aInicio
	//Inicializar Q uno adelante de aInicio
	CNodo* P = aInicio;
	CNodo* Q = aInicio->sig;

	//debe haber minimo dos datos
	if (aN>=2)
	{
		cont = aN;
		aI = true;
		do
		{
			inter = false;
			k = 1;
			P = aInicio;
			Q = aInicio->sig;
			while (k < cont)
			{
				//si el dato en P es mayor que el dato en Q se realiza un intercambio
				if (P->info >= Q->info)
				{
					save = P->info;
					P->info = Q->info;
					Q->info = save;
					//si hubo intercambio inter = true
					inter = true;
				}
				//mover el puntero Q y P uno hacia el siguiente nodo
				P = P->sig;
				Q = Q->sig;
				k++;
			}
			//al terminar el ciclo, cont se reduce en uno para en el siguiente ciclo no ir 
			//hasta la ultima posicion que ya esta ordenada
			cont--;

			//si hubo intercambio se repite nuevamente
		} while (inter);
	}
	else
	{
		aI = false;
	}
}

//Ordenamiento inserccion
/*
Descripcion: Se crea una lista en la cual se van insertando números de manera ordenada
Precondicion: Poder agregar datos a la lista
Condicion: La cantidad la decide el usuario 
Postcondicion: Muestra la lista ordenada de menor a mayor 
*/

void CLista::ordenInserccion(int paDato)
{
	int cont = 0;
	aI = true;
	CNodo* P = NULL;
	CNodo* S = NULL;

	//en el caso de que no hayan datos se agrega en la pos 1
	if (probar())
	{
		crear(paDato);
	}
	else
	{
		cont = aN;
		P = aInicio;
		for (int i = 1; i <= cont; i++)
		{
			//en el caso de que el dato sea menor o igual que el que esta en pos i
			//agregar en la pos i
			if (paDato <= P->info)
			{
				agregar(paDato,i);
				//cont toma valor de 0 para que no se vuelva a ejecutar el bucle
				cont = 0;
			}
			else
			{
				//mover puntero S a la posicion aN
				S = aInicio;
				for (int i = 1; i < aN; i++)
				{
					S = S->sig;
				}
				//en el caso de que el dato sea mayor o igual al ultimo dato
				//agregar en la pos aN+1
				if (paDato >= S->info)
				{
					agregar(paDato, aN + 1);
					//cont toma valor de 0 para que no se vuelva a ejecutar el bucle
					cont = 0;
				}
			}
			P = P->sig;

		}
	}
}


//Busquedas

//Busqueda lineal desordenada
/*
Descripcion: Busca un dato mientras va pasando dato a dato mediante una lista desordenada
Precondicion: para que funcione tiene que estar creada la lista de nodos
Condicion: Trabaja como maximo rango aN y como minimo aInicio
Postcondicion: Se muestra el dato ingresado a buscar
*/
int CLista::linealDesordenada(int paDato)
{
	if (!probar())
	{
		CNodo* P = aInicio;
		//el bucle va desde pos 1 hasta a aN
		for (int i = 1; i <= aN; i++)
		{
			if (paDato == P->info)
			{
				aI = true;
				return i;
			}
			P = P->sig;
		}
		aI = false;
		return 0;
	}
	else
	{
		aI = false;
		return 0;
	}
}

//Busqueda lineal ordenada
/*
Descripcion: Busca un dato mediante una lista que se ordena y va pasando dato a dato
Precondicion: para que funcione tiene que estar ordenada mediante un metodo de ordenamiento
Condicion: Trabaja como maximo rango aN y como minimo aInicio
Postcondicion: Se muestra el dato ingresado a buscar
*/

int CLista::linealOrdenada(int paDato)
{
	ordenBurbuja();
	if (!probar())
	{
		CNodo* P = aInicio;
		for (int i = 1; i <= aN; i++)
		{
			if (paDato == P->info)
			{
				aI = true;
				return i;
			}
			else
			{
				if (P->info > paDato)
				{
					aI = false;
					return 0;
				}
			}
			P = P->sig;
		}
		aI = false;
		return 0;
	}
	else
	{
		aI = false;
		return 0;
	}
}



//Busqueda binaria
/*
Descripcion: Busca mediante la mitad de la lista el dato ingresado a buscar
Precondicion: Crear una lista de nodos
Condicion: Trabaja maximo con aInicio hasta aN
Postcondicion: Devuelve la posicion del dato que se quiere buscar
*/
int CLista::Binaria(int paDato)
{
	int izq = 0, der = 0, c = 0;
	CNodo* I = aInicio;
	CNodo* D = aInicio;
	CNodo* C = aInicio;
	if (!probar())
	{
		izq = 1;
		der = aN;
		c = aN / 2;
		
		for (int i = 1; i < aN; i++)
		{
			//mover C a centro
			if (i<aN/2)
			{
				C = C->sig;
			}
			//mover D a derecha
			D = D->sig;
		}

		do
		{	
			if (C->info == paDato)
			{
				aI = true;
				return c;
			}
			else
			{
				if (C->info > paDato)
				{
					der = c - 1;
					//mover a la nueva ubicacion para D
					D = aInicio;
					for (int i = 1; i < c-1; i++)
					{
						D = D->sig;
					}
				}
				else
				{
					izq = c + 1;
					//mover a la nueva ubicacion para C
					I = C->sig;
				}

				c = ((der - izq) / 2) + izq;

				C = aInicio;
				for (int i = 1; i < c; i++)
				{
					C = C->sig;
				}
			}

		} while (izq != der);

		if (C->info == paDato)
		{
			aI = true;
			return c;
		}
		else
		{
			aI = false;
			return 0;
		}
	}
	else
	{
		aI = false;
		return 0;
	}
}

//operaciones

//suma
/*
Descripcion: realiza la suma de dos listas y las almacena en una tercera
Condicion: Se necesitan dos listas con datos
Precondicion: 
Postcondicion :
*/
void CLista::suma(CNodo* paInicio1, int paN1, CNodo* paInicio2, int paN2)
{
	//en el caso de que hayan datos se debe destruir para ingresar nuevos datos
	if (!probar())
	{
		destruir();
	}
	int mayor = 0, menor = 0, ans = 0;
	CNodo* P1 = paInicio1;
	CNodo* P2 = paInicio2;
	CNodo* P3 = aInicio;
	//asigna mayor y menor respectivamente teniendo el cuenta el tamaño de la lista
	if (paN1 > paN2)
	{
		mayor = paN1;
		menor = paN2;
	}
	else
	{
		mayor = paN2;
		menor = paN1;
	}
	//el bucle va desde pos 1 hasta el menor realizando la operacion suma
	for (int i = 1; i <= menor; i++)
	{
		agregar(P1->info + P2->info, i);
		P1 = P1->sig;
		P2 = P2->sig;
	}
	//el bucle va desde uno adelante del menor hasta el mayor
	//con el objetivo de bajar los datos sin operaciones
	for (int i = menor + 1; i <= mayor; i++)
	{
		if (menor == paN2)
		{
			agregar(P1->info, i);
			P1 = P1->sig;
		}
		else
		{
			agregar(P2->info, i);
			P2 = P2->sig;
		}
	}
}

void CLista::resta(CNodo* paInicio1, int paN1, CNodo* paInicio2, int paN2)
{
	//en el caso de que hayan datos se debe destruir para ingresar nuevos datos

	if (!probar())
	{
		destruir();
	}
	int mayor = 0, menor = 0, ans = 0;
	CNodo* P1 = paInicio1;
	CNodo* P2 = paInicio2;
	CNodo* P3 = aInicio;

	//asigna mayor y menor respectivamente teniendo el cuenta el tamaño de la lista
	if (paN1 > paN2)
	{
		mayor = paN1;
		menor = paN2;
	}
	else
	{
		mayor = paN2;
		menor = paN1;
	}

	//el bucle va desde pos 1 hasta el menor realizando la operacion resta
	for (int i = 1; i <= menor; i++)
	{
		agregar(P1->info - P2->info, i);
		P1 = P1->sig;
		P2 = P2->sig;
	}
	//el bucle va desde uno adelante del menor hasta el mayor
	//con el objetivo de bajar los datos sin operaciones
	for (int i = menor + 1; i <= mayor; i++)
	{
		if (menor == paN2)
		{
			agregar(P1->info, i);
			P1 = P1->sig;
		}
		else
		{
			agregar(P2->info * -1, i);
			P2 = P2->sig;
		}
	}
}
//Producto escalar
/*
Descripcion:Multiplica lista de nodo con un escalar
Precondicion: Crear una lista de nodos
Condicion: El maximo rango es aN de la lista
Postcondicion: Muestra los valores resultante de una multiplicacion entre una lista de nodos y un escalar
*/
void CLista::productoescalar(CNodo* paInicio, int paN, int paDato)
{
	//en el caso de que hayan datos se debe destruir para ingresar nuevos datos

	if (!probar())
	{
		destruir();
	}
	CNodo* P1 = paInicio;
	for (int i = 1; i <= paN; i++)
	{
		agregar(P1->info * paDato, i);
		P1 = P1->sig;
	}
}

//Producto escalar
/*
Descripcion:Multiplica listas de nodos 
Precondicion: Crear dos listas de nodos
Condicion: El maximo rango es aN de las dos listas
Postcondicion: Muestra los valores resultante de una multiplicacion entre la lista de nodos
*/
void CLista::multiplicacion(CNodo* paInicio1, int paN1, CNodo* paInicio2, int paN2)
{
	//en el caso de que hayan datos se debe destruir para ingresar nuevos datos
	if (!probar())
	{
		destruir();
	}
	CNodo* P1 = paInicio1;
	CNodo* P2 = paInicio2;
	CNodo* P3 = aInicio;
	//el metodo funciona unicamente para listas de igual tamaño
	if (paN1 == paN2)
	{
		for (int i = 1; i <= paN1; i++)
		{
			agregar(P1->info * P2->info, i);
			P1 = P1->sig;
			P2 = P2->sig;
		}
		aI = true;
	}
	else
	{
		aI = false;
	}
}