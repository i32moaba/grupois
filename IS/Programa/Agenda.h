/*
 * Agenda.h
 *
 *  Created on: 04/12/2014
 *      Author: i32roraj
 */

#ifndef AGENDA_H_
#define AGENDA_H_

#include <string>
#include <list>
#include "Cliente.h"

class Agenda {
private:
		std :: list <Cliente> listaClientes_;
public:
	Agenda();
	virtual ~Agenda();

	const std::list<Cliente>& getLista() const
	{
		return listaClientes_;
	}
	
	void setLista (std::list<Cliente>& listaClientes)
	{
		listaClientes_ = listaClientes;
	}

	bool buscarCliente (std::string& apellidos);

	void insertarCliente (Cliente c);

	bool modificarCliente (std::string& apellidos);

	bool borrarCliente (std::string& apellidos);

	void imprimir();

	void ordenar();
};

#endif /* AGENDA_H_ */
	
