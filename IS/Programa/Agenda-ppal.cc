/*
 * Agenda-ppal.cpp
 *
 *  Created on: 04/12/2014
 *      Author: i32roraj
 */

#include "Cliente.h"
#include "Agenda.h"
#include "GestorDBInterfaz.h"
#include "GestorDBFichero.h"
#include <iostream>
#include <string>
#include <list>
using namespace std;

int menu ()
{
	int opcion;
	std::cout << "\n\tSeleccione una opción, para ello introduzca el número de cada opción y accederá a ella. "
			"Las opciones disponibles son:\n\n"
			"0: Salir del programa.\n"
			"1: Imprimir la agenda.\n"
			"2: Ordenar agenda por apellidos.\n"
			"3: Insertar un nuevo cliente en la agenda.\n"
			"4: Busca un cliente en la agenda según su apellido.\n"
			"5: Borra un cliente según su apellido.\n"
			"6: Modifica los datos de un cliente buscándolo por su apellido.\n"
			"7: Realiza una copia de seguridad del estado actual de la agenda. \n"
			"8: Restaura la base de datos de la agenda a un estado anterior. \n"
			"\nIntroduzca su elección: ";
	std::cin >> opcion;
	return opcion;
}

int main ()
{
	int instruccion;
	GestorDBFichero* g = new GestorDBFichero();
	Agenda a = Agenda(g);
	Cliente c;
				std::string dni;
				std::string nombre;
				std :: string apellidos;
				long telefono;
				std::list <Direccion> direcciones;
				std :: string anotaciones;
				std :: list <RedSocial> redesSociales;
	Direccion d;
	RedSocial r;
	int nDirecciones, nRedes;
	std::cout << "\n\nBienvenido a la Agenda de Negocios BETA. El sistema almacena los datos de sus clientes ... "; //INCOMPLETO.
	do
	{
		instruccion = menu ();
		switch (instruccion)
		{
		case 0:
		{
			instruccion = -1;
			std::cout << "\n\tGracias por utilizar el programa de gestión de agenda.\n\n";
			break;
		}
		case 1:
		{
			a.imprimir();
			std::cout << "\n\tFinalizada la impresión de la agenda de contactos.\n";
			break;
		}
		case 2:
		{
			a.ordenar();
			std::cout << "\n\tLista ordenada por orden alfabético de apellidos.\n";
			break;
		}
		case 3:
		{
			std::cout << "\n\tIntroduzca los datos correspondientes para el cliente a insertar (el campo de apellidos es obligatorio).\n"
					"Apellidos: ";
			std::cin>> apellidos;
			c.setApellidos(apellidos);
			std::cout << "Nombre: ";
			std::cin>> nombre;
			c.setNombre(nombre);
			std::cout << "DNI: ";
			std::cin>> dni;
			c.setDni(dni);
			getchar ();
			std::cout << "Telefono: ";
			std::cin>> telefono;
			c.setTelefono(telefono);
			getchar();
			std::cout << "¿Cuántas direcciones desea introducir?: ";
			std::cin>> nDirecciones;
			getchar ();
			for (int i=0; i<nDirecciones; i++)
			{
				std::cout << "Direccion nº:"<<i<<endl<< "\tNombre de la calle: "<<endl;
				std::getline (std::cin, d.calle);
				std::cout << "Numero: ";
				std::cin>> d.numero;
				std::cout << "Codigo Postal: ";
				std::cin>> d.cp;
				getchar ();
				std::cout << "Ciudad: ";
				std::getline (std::cin, d.ciudad);
				std::cout << "Tipo de calle: ";
				std::getline (std::cin, d.tipo_calle);
				direcciones.push_back(d);
			}
			c.setDirecciones(direcciones);
			std::cout << "¿Cuántas redes sociales desea introducir?: ";
			std::cin>> nRedes;
			getchar ();
			for (int i=0; i<nRedes; i++)
			{
				std::cout << "Red Social nº:"<<i<<endl<< "\tNombre de la red social: "<<endl;
				std::getline (std::cin, r.nombreRed);
				std::cout << "URL de la red: ";
				std::getline (std::cin, r.url);
				redesSociales.push_back(r);
			}
			c.setRedesSociales(redesSociales);
			std::cout << "¿Quisiera hacer alguna anotacion acerca del cliente actual?: ";
			std::cin>> anotaciones;
			c.setAnotaciones(anotaciones);
			a.insertarCliente (c);
			break;
		}
		case 4:
		{
			std::cout << "Introduzca los apellidos del cliente a buscar en la base de datos de la agenda: ";
			std::cin>> apellidos;
			if (a.buscarCliente(apellidos)!= true)
			{
				std::cout<<"El cliente no se halla en la base de datos."<<std::endl;
			}
			else
			{
				std::cout<<"Cliente encontrado."<<std::endl;
			}
			break;
		}
		case 5:
		{
			std::cout << "Introduzca los apellidos del cliente a borrar de la base de datos de la agenda: ";
			std::cin>> apellidos;
			if (a.borrarCliente(apellidos)!= true)
			{
				std::cout<<"El cliente no se halla en la base de datos."<<std::endl;
			}
			else
			{
				std::cout<<"Cliente borrado satisfactoriamente."<<std::endl;
			}
			break;
		}
		case 6:
		{
			std::cout << "Introduzca los apellidos del cliente a modificar en la base de datos de la agenda: ";
			std::cin>> apellidos;
			if (a.modificarCliente(apellidos)!= true)
			{
				std::cout<<"El cliente no se halla en la base de datos."<<std::endl;
			}
			else
			{
				std::cout<<"Cliente modificado satisfactoriamente."<<std::endl;
			}
			break;
		}
		case 7:
		{
			g->salvar(a.getLista());
			std::cout<<"\nBase de datos guardada satisfactoriamente."<<std::endl;
			break;
		}
		case 8:
		{
			int lenguaje;
			std::cout<<"\nSeleccione como desea guardar su base de datos: ";
			std::cin>>lenguaje;
			g->restaurar();
			a.setLista(g->getClientes());
			std::cout<<"\nBase de datos restaurada satisfactoriamente."<<std::endl;
			break;
		}
		default:
		{
			std::cout<<"\nOpción seleccionada incorrecta, por favor, introduzca un número del 0 al 8."<<std::endl;
			break;
		}
		}
	}
	while (instruccion != -1);
}

