/*
 * GestorDBFichero.h
 *
 *  Created on: 10/12/2014
 *      Author: angel
 */

#ifndef GESTORDBFICHERO_H_
#define GESTORDBFICHERO_H_

#include "GestorDBInterfaz.h"

class GestorDBFichero: public GestorDBInterfaz {
private:
	std::string nombreFichero_;
	std::list <Cliente> clientes_;
public:
	GestorDBFichero();
	virtual ~GestorDBFichero();

	const std::string& getNombreFichero() const {
		return nombreFichero_;
	}
	void setNombreFichero(const std::string& nombreFichero) {
		nombreFichero_ = nombreFichero;
	}

	void salvar (std::list <Cliente> clientes);
	virtual std::list<Cliente> restaurar ();

	const std::list<Cliente>& getClientes() const {
		return clientes_;
	}

	void setClientes(const std::list<Cliente>& clientes) {
		clientes_ = clientes;
	}
};

#endif /* GESTORDBFICHERO_H_ */
