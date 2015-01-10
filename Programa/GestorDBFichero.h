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
	const std::list<Cliente>& getClientes() const {
			return clientes_;
	}
	void setClientes(Cliente c)
	{
		clientes_.push_back(c);
	}
	void salvar (std::list <Cliente> clientes);
	void restaurar ();


};

#endif /* GESTORDBFICHERO_H_ */
