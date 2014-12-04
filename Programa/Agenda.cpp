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
			std::cout << "\n\nCliente encontrado.\n\nDNI actual: " << (*it).getDni() << " (para no modificarlo introduce un guión -).\n\tIntroduce - o nuevo DNI: ";
			std::getline (std::cin, aux);
			if (aux != "-")
			{
				(*it).setDni(aux);
			}

			//CAMBIO DE APELLIDOS Y NOMBRE
			std::cout << "\n\nNombre completo actual: " << (*it).getApellidos() << ", " << (*it).getNombre() << "(para no modificarlo introduce un guión -).\n\tIntroduce - o nuevos apellidos: ";
			std::getline (std::cin, aux);
			if (aux != "-")
			{
				(*it).setApellidos(aux);
			}
			std::cout << "\n\tIntroduce - o nuevo nombre: ";
			std::getline (std::cin, aux);
			if (aux != "-")
			{
				(*it).setNombre(aux);
			}
	
			//CAMBIO DE TELÉFONO
			std::cout << "\n\nTeléfono actual: " << (*it).getTelefono() << " (para no modificarlo introduce 0).\n\tIntroduce 0 o nuevo teléfono: ";
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
		for (list<Jugador>::iterator it=listaClientes_.begin(); it != listaClientes_.end(); it++)
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
		cout << "\n\nLista vacía\n\n";
	}
	else
	{
	}
}

bool orden(Cliente c1, Cliente c2)
{
}
void Agenda::ordenar()
{
}

int main ()
{
}
