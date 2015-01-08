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

Agenda::Agenda(std::list<Cliente> lc, GestorDBInterfaz* g)
{
	listaClientes_ = lc;
	_gestor = g;
}

Agenda::~Agenda()
{
	// TODO Auto-generated destructor stub
}

virtual ~Agenda();

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
	for (std::list<Cliente>::iterator it=listaClientes_.begin(); it != listaClientes_.end(); it++)
	{
		if ((*it).getApellidos() == apellidos)
		{
			control = true;
			//CAMBIO DE DNI
			std::cout << "\n\nCliente encontrado.\n\nDNI actual: " << (*it).getDni() << " (para no modificarlo introduzca un guión -).\n\tIntroduzca - o nuevo DNI: ";
			std::getline (std::cin, aux);
			if (aux != "-")
			{
				(*it).setDni(aux);
			}

			//CAMBIO DE APELLIDOS Y NOMBRE
			std::cout << "\n\nNombre completo actual: " << (*it).getApellidos() << ", " << (*it).getNombre() << "(para no modificarlo introduzca un guión -).\n\tIntroduzca - o nuevos apellidos: ";
			std::getline (std::cin, aux);
			if (aux != "-")
			{
				(*it).setApellidos(aux);
			}
			std::cout << "\n\tIntroduzca - o nuevo nombre: ";
			std::getline (std::cin, aux);
			if (aux != "-")
			{
				(*it).setNombre(aux);
			}

			//CAMBIO DE TELÉFONO
			std::cout << "\n\nTeléfono actual: " << (*it).getTelefono() << " (para no modificarlo introduzca 0).\n\tIntroduzca 0 o nuevo teléfono: ";
			std::cin >> auxN;
			if (auxN != 0)
			{
				(*it).setTelefono(auxN);
			}

			//CAMBIO DE DIRECCIONES
			std::cout << "\n\nDirecciones actuales: ";
			for (std::list<Direccion>::iterator ite=(*it).getDirecciones().begin(); ite != (*it).getDirecciones().end(); ite++)
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
				
			
			//CAMBIO DE REDES SOCIALES
			std::cout << "\n\nRedes sociales actuales: ";
			for (std::list<RedSocial>::iterator ito=(*it).getRedesSociales().begin(); ito != (*it).getRedesSociales().end(); ito++)
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
			
			//CAMBIO DE ANOTACIONES
			std::cout << "\n\tAnotaciones actuales:\n" << (*it).getAnotaciones << "\n\tIntroduzca - o las nuevas anotaciones: ";
			std::getline (std::cin, aux);
			if (aux != "-")
			{
				(*it).setAnotaciones(aux);
			}
			//CAMBIO DE FAVORITO
			std::cout << "\n\tEstado de favorito actual: ";
			if ((*it).isFavorito())
			{
				std::cout << "FAVORITO.";
			}
				else
			{
				std::cout << "NO FAVORITO.";
			}
			std::cout "\n\tIntroduzca F para que sea favorito, N para que sea no favorito o - para que se quede como está: ";
			if (aux = "F")
			{
				fav = true;
				(*it).setFavorito (fav);
			}
			if (aux = "N")
			{
				fav = false;
				(*it).setFavorito (fav);
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

bool Agenda::orden(Cliente c1, Cliente c2)
{
	if (c1.getApellidos() < c1.getApellidos())
	{
		return true;
	}
	else
	{
		return false;
	}
}
void Agenda::ordenar()
{
	listaClientes_.sort(orden);
	std::cout << "\nLista ordenada por apellidos.\n";
}
