/*
 * Agenda.cpp
 *
 *  Created on: 04/12/2014
 *      Author: i32roraj
 */

#include "Agenda.h"
#include <iostream>
#include <string>
#include <list>
using namespace std;

Agenda::Agenda(GestorDBInterfaz* g)
{
	_gestor = g;
}

Agenda::~Agenda()
{
	// TODO Auto-generated destructor stub
}

bool Agenda::buscarCliente (std::string& apellidos)
{
	bool control = false;
	if (!listaClientes_.empty())
	{
		for (std::list<Cliente>::iterator it=listaClientes_.begin(); it != listaClientes_.end(); it++)
		{
			if ((*it).getApellidos() == apellidos)
			{
				std::cout << "\n\nDNI: " << (*it).getDni() << ",\n\tNombre completo: " << (*it).getApellidos() << ", " << (*it).getNombre();
				(*it).usado();
				control = true;
			}
		}
	}
	return (control);
}

void Agenda::insertarCliente (Cliente c)
{
	listaClientes_.push_back(c);
}


bool Agenda::modificarCliente (std::string& apellidos)
{
	bool control = false;
	bool fav;
	std::string aux;
	long auxN;
	int opc;
	for (std::list<Cliente>::iterator it=listaClientes_.begin(); it != listaClientes_.end(); it++)
	{
		if ((*it).getApellidos() == apellidos)
		{
			control = true;
			cout <<"Introduzca el campo que desea modificar:"
					"1. DNI"
					"2. Nombre"
					"3. Apellidos"
					"4. Teléfono"
					"5. Direcciones"
					"6. Redes Sociales"
					"7. Anotaciones"
					"8. Favorito o No favorito";
			cin >> opc;
			getchar ();
			switch (opc)
			{
			//CAMBIO DE DNI
			case 1:
			{
				std::cout << "\n\nCliente encontrado.\n\nDNI actual: " << (*it).getDni() << " (para no modificarlo introduzca un guión -).\n\tIntroduzca - o nuevo DNI: ";
				std::getline (std::cin, aux);
				if (aux != "-")
				{
					(*it).setDni(aux);
				}
				break;
			}

			//CAMBIO DE APELLIDOS Y NOMBRE
			case 2:
			{
				std::cout << "\n\nNombre completo actual: " << (*it).getApellidos() << ", " << (*it).getNombre() << "(para no modificarlo introduzca un guión -).\n\tIntroduzca - o nuevos apellidos: ";
				std::getline (std::cin, aux);
				if (aux != "-")
				{
					(*it).setApellidos(aux);
				}
				break;
			}
			case 3:
			{
				std::cout << "\n\tIntroduzca - o nuevo nombre: ";
				std::getline (std::cin, aux);
				if (aux != "-")
				{
					(*it).setNombre(aux);
				}
				break;
			}
			//CAMBIO DE TELÉFONO
			case 4:
			{
				std::cout << "\n\nTeléfono actual: " << (*it).getTelefono() << " (para no modificarlo introduzca 0).\n\tIntroduzca 0 o nuevo teléfono: ";
				std::cin >> auxN;
				if (auxN != 0)
				{
					(*it).setTelefono(auxN);
				}
				break;
			}
			//CAMBIO DE DIRECCIONES
			case 5:
			{
				std::cout << "\n\nDirecciones actuales: ";
				std::list<Direccion> auxd = (*it).getDirecciones();
				for (std::list<Direccion>::iterator ite = auxd.begin(); ite != auxd.end(); ite++)
				{
					cout << "\n" << (*ite).tipo_calle << " " << (*ite).calle << ", " << (*ite).numero << ", " << (*ite).cp << ", " << (*ite).ciudad << ".";
					std::cout << "\n\tIntroduzca - si no quiere cambiar la dirección, o el nombre de la nueva calle: ";
					std::getline (std::cin, aux);
					if (aux != "-")
					{
						(*ite).calle = aux;
						std::cout << "\n\tIntroduzca el número: ";
						std::cin >> (*ite).numero;
						std::cout << "\n\tIntroduzca el código postal: ";
						std::cin >> (*ite).cp;
						std::cout << "\n\tIntroduzca la ciudad: ";
						std::getline (std::cin, (*ite).ciudad);
						std::cout << "\n\tIntroduzca el tipo de calle: ";
						std::getline (std::cin, (*ite).tipo_calle);
					}
					std::cout << "\n";
				}
				break;
			}
			//CAMBIO DE REDES SOCIALES
			case 6:
			{
				std::cout << "\n\nRedes sociales actuales: ";
				std::list<RedSocial> auxrs = (*it).getRedesSociales();
				for (std::list<RedSocial>::iterator ito = auxrs.begin(); ito != auxrs.end(); ito++)
				{
					cout << "\n" << (*ito).nombreRed << ": " << (*ito).url;
					std::cout << "\n\tIntroduzca - si no quiere cambiar la cuenta, o el nombre de la nueva red social: ";
					std::getline (std::cin, aux);
					if (aux != "-")
					{
						(*ito).nombreRed = aux;
						std::cout << "\n\tIntroduzca la URL de la cuenta del cliente en esa red social: ";
						std::getline (std::cin, (*ito).url);
					}
					std::cout << "\n";
				}
				break;
			}
			//CAMBIO DE ANOTACIONES
			case 7:
			{
				cout << "\n\tAnotaciones actuales:\n" << (*it).getAnotaciones () << "\n\tIntroduzca - o las nuevas anotaciones: ";
				std::getline (std::cin, aux);
				if (aux != "-")
				{
					(*it).setAnotaciones(aux);
				}
				break;
			}
			//CAMBIO DE FAVORITO
			case 8:
			{
				std::cout << "\n\tEstado de favorito actual: ";
				if ((*it).isFavorito())
				{
					std::cout << "FAVORITO.";
				}
					else
				{
					std::cout << "NO FAVORITO.";
				}
				std :: cout << "\n\tIntroduzca F para que sea favorito, N para que sea no favorito o - para que se quede como está: ";
				if (aux == "F")
				{
					fav = true;
					(*it).setFavorito (fav);
				}
				if (aux == "N")
				{
					fav = false;
					(*it).setFavorito (fav);
				}
			}
			}
		}
	}
	return (control);
}

bool Agenda::borrarCliente(std::string& apellidos)
{
	bool control = false;
	if (!listaClientes_.empty())
	{
		for (std::list<Cliente>::iterator it=listaClientes_.begin(); it != listaClientes_.end(); it++)
		{
			if((*it).getApellidos() == apellidos)
			{
				it = listaClientes_.erase(it);
				control = true;
			}
		}
	}
	return (control);
}

void Agenda::imprimir()
{
	if (listaClientes_.empty())
	{
		std::cout << "\n\nLista vacía\n\n";
	}
	else
	{
		std::cout << "\n\t\tLista de contactos:\n\n";
		for (std::list<Cliente>::iterator it=listaClientes_.begin(); it != listaClientes_.end(); it++)
		{
			std::cout << "\n" << (*it).getApellidos() << ", " << (*it).getNombre() << ". Teléfono: " << (*it).getTelefono() << ".";
			if ((*it).isFavorito())
			{
				std::cout << " FAVORITO.";
			}
			std::cout << "\n";
		}
	}
}

bool orden(Cliente c1, Cliente c2)
{
	return (c1.getApellidos() < c2.getApellidos());
}

void Agenda::ordenar()
{
	listaClientes_.sort(orden);
	std::cout << "\nLista ordenada por apellidos.\n";
}
