/*

	Descripción: Crea una lista dinamica a partir de lo que el usuario decida ingresar
	Precondición: Que le pregunte al usuario detalladamente que le gustaria proceder a hacer
	Condiciones:  Debe tener sus respectivos .cpp y .h para que funcione correctamente
	Poscondiciones: Debe imprimir correctamente dependiendo de la opcion del usuario
	Autor(s): Daniel Alejandro Torres Gonzales - Juan David Plata Garrido
	Fecha:
	Clase: Programacion III
	Profesor: Wilman Helioth Sánchez Rodríguez
	Universidad: Militar Nueva Granada

*/
#include <iostream>
#include "Lista.h"
#include "Nodo.h"
#include "Pila.h"
#include "Cola.h"
using namespace std;


//funciones
//primitivas
void insertar(bool paI);
void probar(bool paPrueba);
void eliminar(bool paI);
void destruir(bool paI);

//busquedas
void busqueda(bool paI, int paPos);

int main()
{
	//instacias tipo lista
	CLista iL1;
	CLista iL4;
	CLista iLans;
	//instancias tipo pila
	CPila iL2;
	//instancias tipo cola
	CCola iL3;
	int opcion1 = 0, opcion2 = 0, opcion3 = 0;
	int vDato = 0, vPos = 0, terminar = 0, vcont = 0, cond = 0;
	do
	{
		cout << "\nMenu" << endl;
		cout << "1.Lista" << endl;
		cout << "2.Pila" << endl;
		cout << "3. Cola" << endl;
		cout << "4. Terminar" << endl;

		cout << "Ingrese una opcion" << endl;
		cin >> opcion1;

		switch (opcion1)
		{
			
			//lista dinamica
			case 1:
			{
				do
				{
					cout << "\nMenu Lista dinamica" << endl;
					cout << "1.Primitivas" << endl;
					cout << "2.Ordenamientos" << endl;
					cout << "3.Busquedas" << endl;
					cout << "4. Operaciones" << endl;

					cout << "5. Volver" << endl;

					cout << "Ingrese una opcion" << endl;
					cin >> opcion2;

					//condiciona que para poder hacer operaciones se deeben crear dos listas
					if (opcion2==4)
					{
						if (cond<2)
						{
							opcion2 = 100;
						}
					}

					switch (opcion2)
					{
						//primitivas
						case 1:
						{
							do
							{
								cout << "\nMenu primitivas" << endl;
								cout << "Lista #1" << endl;
								cout << "1.Agregar lista 1" << endl;
								cout << "2.Probar lista 1" << endl;
								cout << "3. Ver lista 1" << endl;
								cout << "4. Eliminar lista 1" << endl;
								cout << "5. Destruir lista 1" << endl;

								cout << "\nLista #2" << endl;
								cout << "6.Agregar lista 2" << endl;
								cout << "7.Probar lista 2" << endl;
								cout << "8. Ver lista 2" << endl;
								cout << "9. Eliminar lista 2" << endl;
								cout << "10. Destruir lista 2" << endl;
								cout << "11. Volver" << endl;

								cout << "Ingrese una opcion" << endl;
								cin >> opcion3;

								switch (opcion3)
								{
									//Agregar lista 1
									case 1:
									{
										do
										{
											cout << "Ingrese el dato a ingresar" << endl;
											cin >> vDato;
											cout << "Ingrese la posicion" << endl;
											cin >> vPos;
											iL1.agregar(vDato,vPos);
											insertar(iL1.getaI());

											cout << "Desea ingresar otro 1, sino 0" << endl;
											cin >> terminar;

										} while (terminar != 0);
										cond++;
									}
									break;

									//Probar lista 1
									case 2:
									{
										iL1.probar();
										probar(iL1.getaI());
									}
									break;

									//Ver lista 1
									case 3:
									{
										cout << "ingrese la posicion" << endl;
										cin >> vPos;
										cout<< iL1.ver(vPos);

										if (iL1.getaI() == false)
										{
											cout << "No hay datos para mostrar" << endl;
										}
									}
									break;

									//Eliminar lista 1
									case 4:
									{
										cout << "Ingrese la posicion a eliminar" << endl;
										cin >> vPos;
										iL1.eliminar(vPos);
										eliminar(iL1.getaI());
									}
									break;

									//Destruir lista 1
									case 5:
									{
										iL1.destruir();
										destruir(iL1.getaI());
									}
									break;

									//Agregar lista 2
									case 6:
									{
										do
										{
											cout << "Ingrese el dato a ingresar" << endl;
											cin >> vDato;
											cout << "Ingrese la posicion" << endl;
											cin >> vPos;
											iL4.agregar(vDato, vPos);
											insertar(iL4.getaI());

											cout << "Desea ingresar otro 1, sino 0" << endl;
											cin >> terminar;

										} while (terminar != 0);
										cond++;
									}
									break;

									//probar lista 2
									case 7:
									{
										iL4.probar();
										probar(iL4.getaI());
									}
									break;

									//ver lista 2
									case 8:
									{
										cout << "ingrese la posicion" << endl;
										cin >> vPos;
										cout << iL4.ver(vPos);

										if (iL4.getaI() == false)
										{
											cout << "No hay datos para mostrar" << endl;
										}
									}
									break;

									//eliminar lista 2
									case 9:
									{
										cout << "Ingrese la posicion a eliminar" << endl;
										cin >> vPos;
										iL4.eliminar(vPos);
										eliminar(iL4.getaI());
									}
									break;

									//destruir lista 2
									case 10:
									{
										iL4.destruir();
										destruir(iL4.getaI());
									}
									break;

									//volver
									case 11:
									{

									}
									break;
									default:
									{
										cout << "Opcion incorrecta" << endl;
									}
									break;
								}

							} while (opcion3 != 11);
						}
						break;

						//ordenamientos
						case 2:
						{
							do
							{
								cout << "\nMenu Ordenamientos" << endl;
								cout << "Lista #1" << endl;
								cout << "1.Ordenamiento Lineal Lista 1" << endl;
								cout << "2.Ordenamiento Burbuja Lista 1" << endl;
								cout << "3.Ordenamiento insercion Lista 1" << endl;
								cout << "\nLista #2" << endl;
								cout << "4.Ordenamiento Lineal Lista 2" << endl;
								cout << "5.Ordenamiento Burbuja Lista 2" << endl;
								cout << "6.Ordenamiento insercion Lista 2" << endl;
								cout << "\n7. Volver" << endl;

								cout << "Ingrese una opcion" << endl;
								cin >> opcion3;

								switch (opcion3)
								{
									//ordenamiento lineal
									case 1:
									{
										iL1.ordenLineal();
										cout << endl;
										for (int i = 1; i <= iL1.getaN(); i++)
										{
											cout <<"Pos "<<i<<" " <<iL1.ver(i) << endl;
										}
									}
									break;
									//ordenamiento burbuja
									case 2:
									{
										iL1.ordenBurbuja();
										cout << endl;
										for (int i = 1; i <= iL1.getaN(); i++)
										{
											cout << "Pos " << i << " " << iL1.ver(i) << endl;
										}
									}
									break;
									//ordenamiento insercion
									case 3:
									{
										do
										{
											cout << "Ingrese el dato" << endl;
											cin >> vDato;

											iL1.ordenInserccion(vDato);

											cout << "Desea ingresar otro 1, sino 0" << endl;
											cin >> terminar;

										} while (terminar);

										for (int i = 1; i <= iL1.getaN(); i++)
										{
											cout << "Pos " << i << " " << iL1.ver(i) << endl;
										}
									}
									break;
									
									//orden lineal Lista 2
									case 4:
									{
										iL4.ordenLineal();
										cout << endl;
										for (int i = 1; i <= iL4.getaN(); i++)
										{
											cout << "Pos " << i << " " << iL4.ver(i) << endl;
										}
									}
									break;

									//orden burbuja lista 2
									case 5:
									{
										iL1.ordenBurbuja();
										cout << endl;
										for (int i = 1; i <= iL1.getaN(); i++)
										{
											cout << "Pos " << i << " " << iL1.ver(i) << endl;
										}
									}
									break;
									
									//orden inserccion lista 2
									case 6:
									{
										do
										{
											cout << "Ingrese el dato" << endl;
											cin >> vDato;

											iL1.ordenInserccion(vDato);

											cout << "Desea ingresar otro 1, sino 0" << endl;
											cin >> terminar;

										} while (terminar);

										for (int i = 1; i <= iL1.getaN(); i++)
										{
											cout << "Pos " << i << " " << iL1.ver(i) << endl;
										}
									}
									break;

									//volver
									case 7:
									{

									}
									break;

									default:
									{
										cout << "Opcion incorrecta" << endl;
									}
									break;
								}
							} while (opcion3!=7);	
						}
						break;

						//Busquedas
						case 3:
						{
							do
							{
								cout << "\nMenu Busquedas" << endl;
								cout << "Lista #1" << endl;
								cout << "1.Busqueda lineal desordenada lista 1" << endl;
								cout << "2.Busqueda lineal ordenada lista 1" << endl;
								cout << "3.Busqueda binaria lista 1" << endl;
								cout << "\nLista #2" << endl;
								cout << "4.Busqueda lineal desordenada lista 1" << endl;
								cout << "5.Busqueda lineal ordenada lista 1" << endl;
								cout << "6.Busqueda binaria lista 1" << endl;
								cout << "7. Volver" << endl;

								cout << "Ingrese una opcion" << endl;
								cin >> opcion3;

								switch (opcion3)
								{
									//Busqueda lineal desordenada lista 1
									case 1:
									{
										cout << "Ingrese el dato a buscar" << endl;
										cin >> vDato;
										busqueda(iL1.getaI(), iL1.linealDesordenada(vDato));
									}
									break;
									//Busqueda lineal ordenada lista 1
									case 2:
									{
										cout << "Ingrese el dato a buscar" << endl;
										cin >> vDato;
										busqueda(iL1.getaI(), iL1.linealOrdenada(vDato));
									}
									break;
									//Busqueda binaria lista 1
									case 3:
									{
										cout << "Ingrese el dato a buscar" << endl;
										cin >> vDato;
										busqueda(iL1.getaI(), iL1.Binaria(vDato));
									}
									break;
									//busqueda lineal desordenada lista 2
									case 4:
									{
										cout << "Ingrese el dato a buscar" << endl;
										cin >> vDato;
										busqueda(iL1.getaI(), iL1.linealDesordenada(vDato));
									}
									break;
									//busqueda lineal ordenada lista 2
									case 5:
									{
										cout << "Ingrese el dato a buscar" << endl;
										cin >> vDato;
										busqueda(iL1.getaI(), iL1.linealOrdenada(vDato));
									}
									break;
									//busqueda binaria lista 2
									case 6:
									{
										cout << "Ingrese el dato a buscar" << endl;
										cin >> vDato;
										busqueda(iL1.getaI(), iL1.Binaria(vDato));
									}
									break;
									//volver
									case 7:
									{

									}
									break;

									default:
									{
										cout << "Opcion incorrecta" << endl;
									}
									break;
								}
							} while (opcion3 != 7);
						}
						break;
						//operaciones
						case 4:
						{
							do
							{
								cout << "\nMenu Operaciones" << endl;
								cout << "1.Suma" << endl;
								cout << "2.Resta" << endl;
								cout << "3.Multiplicacion" << endl;
								cout << "4. Escalar" << endl;
								cout << "5. Volver" << endl;

								cout << "Ingrese una opcion" << endl;
								cin >> opcion3;

								switch (opcion3)
								{
									//suma
									case 1: 
									{
										iLans.suma(iL1.getaInicio(), iL1.getaN(), iL4.getaInicio(), iL4.getaN());
										for (int i = 1; i <= iLans.getaN(); i++)
										{
											cout << "Pos " << i << " " << iLans.ver(i) << endl;
										}
									}
									break;

									//resta
									case 2:
									{
										iLans.resta(iL1.getaInicio(), iL1.getaN(), iL4.getaInicio(), iL4.getaN());
										for (int i = 1; i <= iLans.getaN(); i++)
										{
											cout << "Pos " << i << " " << iLans.ver(i) << endl;
										}
									}
									break;

									//multiplicacion
									case 3:
									{
										iLans.multiplicacion(iL1.getaInicio(), iL1.getaN(), iL4.getaInicio(), iL4.getaN());
										for (int i = 1; i <= iLans.getaN(); i++)
										{
											cout << "Pos " << i << " " << iLans.ver(i) << endl;
										}
									}
									break;

									//multiplicacion escalar
									case 4:
									{
										cout << "Ingrese el numero por el que desea multiplicar la lista #1" << endl;
										cin >> vDato;
										iLans.productoescalar(iL1.getaInicio(), iL1.getaN(), vDato);
										for (int i = 1; i <= iLans.getaN(); i++)
										{
											cout << "Pos " << i << " " << iLans.ver(i) << endl;
										}
										if (!iLans.getaI())
										{
											cout << "No se puede multiplicar debido a que las listas no tienen el mismo tamano" << endl;
										}
									}
									break;

									case 5:
									{

									}
									break;

									default:
									break;
								}
							} while (opcion3!=5);
						}
						break;
						//volver
						case 5:
						{

						}
						break;

						case 100:
						{
							cout << "\nPRIMERO DEBE AGREGAR DATOS A DOS LISTAS" << endl;
						}
						break;

						default:
						{
							cout << "El dato ingresado no es valido" << endl;
						}
						break;
					}
				} while (opcion2!=5);
			}
			break;

			//pila
			case 2:
			{
				do
				{
					cout << "\nMenu Pila" << endl;
					cout << "1. Agregar" << endl;
					cout << "2. Probar" << endl;
					cout << "3. Ver" << endl;
					cout << "4. Eliminar" << endl;
					cout << "5. Destruir" << endl;
					cout << "6. Volver" << endl;

					cout << "Ingrese una opcion" << endl;
					cin >> opcion3;

					switch (opcion3)
					{
						//Agregar
						case 1:
						{
							do
							{
								cout << "Ingrese el dato a ingresar" << endl;
								cin >> vDato;
								iL2.agregar(vDato);

								cout << "Desea ingresar otro 1, sino 0" << endl;
								cin >> terminar;

							} while (terminar != 0);
						}
						break;

						//Probar
						case 2:
						{
							iL2.probar();
							probar(iL2.getaI());
						}
						break;

						//Ver
						case 3:
						{
							cout << iL2.ver() << endl;
							if (iL2.getaI() == false)
							{
								cout << "No hay datos para mostrar" << endl;
							}
						}
						break;

						//Eliminar
						case 4:
						{
							iL2.eliminar();
							eliminar(iL2.getaI());
						}
						break;

						//Destruir
						case 5:
						{
							iL2.destruir();
							destruir(iL2.getaI());
						}
						break;
						case 6:
						{

						}
						break;
						default:
						{
							cout << "Opcion incorrecta" << endl;
						}
						break;
					}

				} while (opcion3 != 6);
			}
			break;

			//cola
			case 3:
			{
				do
				{
					cout << "\nMenu cola" << endl;
					cout << "1. Agregar" << endl;
					cout << "2. Probar" << endl;
					cout << "3. Ver" << endl;
					cout << "4. Eliminar" << endl;
					cout << "5. Destruir" << endl;
					cout << "6. Volver" << endl;

					cout << "Ingrese una opcion" << endl;
					cin >> opcion3;

					switch (opcion3)
					{
						//Agregar
					case 1:
					{
						do
						{
							cout << "Ingrese el dato a ingresar" << endl;
							cin >> vDato;
							iL3.agregar(vDato);

							cout << "Desea ingresar otro 1, sino 0" << endl;
							cin >> terminar;

						} while (terminar != 0);
					}
					break;

					//Probar
					case 2:
					{
						iL3.probar();
						probar(iL3.getaI());
					}
					break;

					//Ver
					case 3:
					{
						cout << iL3.ver() << endl;
						if (iL3.getaI() == false)
						{
							cout << "No hay datos para mostrar" << endl;
						}
					}
					break;

					//Eliminar
					case 4:
					{
						iL3.eliminar();
						eliminar(iL3.getaI());
					}
					break;

					//Destruir
					case 5:
					{
						iL3.destruir();
						destruir(iL3.getaI());
					}
					break;
					case 6:
					{

					}
					break;
					default:
					{
						cout << "Opcion incorrecta" << endl;
					}
					break;
					}

				} while (opcion3 != 6);
			}
			break;

			//terminar
			case 4:
			{
				cout << "Terminado" << endl;
			}
			break;

			default:
			{
				cout << "Opcion incorrecta" << endl;
			}
			break;
		}
	} while (opcion1!=4);
}

void insertar(bool paI)
{
	if (paI)
	{
		cout << "Insertado con exito" << endl;
	}
	else
	{
		cout << "Debe ingresar una posicion mayor a 0 para poder insertar" << endl;
	}
}
void probar(bool paPrueba)
{
	if (paPrueba)
	{
		cout << "Hay datos" << endl;
	}
	else
	{
		cout << "No hay datos" << endl;
	}
}

void eliminar(bool paI)
{
	if (paI)
	{
		cout << "Eliminado con exito" << endl;
	}
	else
	{
		cout << "No hay datos para eliminar" << endl;
	}
}

void destruir(bool paI)
{
	if (paI)
	{
		cout << "Destruido con exito" << endl;
	}
	else
	{
		cout << "No hay datos para eliminar" << endl;
	}
}



void busqueda(bool paI, int paPos) 
{
	if (paI)
	{
		cout << "Se encontro el dato en la pos " << paPos << endl;
	}
	else
	{
		cout << "No se encontro el dato" << endl;
	}
}

