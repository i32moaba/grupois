/*
 * Agenda.cpp
 *
 *  Created on: 04/12/2014
 *      Author: i32roraj
 */

#include "Cliente.h"
#include "Agenda.h"
#include <iostream>
#include <string>
#include <list>

Agenda::Agenda() {
	// TODO Auto-generated constructor stub

}

Agenda::~Agenda() {
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
				std::cout << "\n\nCliente encontrado: DNI: " << (*it).getDni() << ",\n\tNombre completo: " << (*it).getApellidos() << ", " << (*it).getNombre();
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
	std::string aux;
	long auxN;
	for (std::list<Cliente>::iterator it=listaClientes_.begin(); it != listaClientes_.end(); it++)
	{
		if ((*it).getApellidos() == apellidos)
		{
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
			//CAMBIO DE REDES SOCIALES
			//CAMBIO DE ANOTACIONES
			//CAMBIO DE FAVORITO
		}
	}
}

bool Agenda::borrarCliente(std::string& apellidos)
{
	bool control;
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
