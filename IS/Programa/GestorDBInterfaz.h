/*
 * GestorDB.h
 *
 *  Created on: 10/12/2014
 *      Author: angel
 */

#ifndef GESTORDBINTERFAZ_H_
#define GESTORDBINTERFAZ_H_
#include "Cliente.h"
class GestorDBInterfaz
{
public:
	GestorDBInterfaz();
	virtual ~GestorDBInterfaz();
	virtual void salvar (std::list <Cliente> clientes){};
	virtual std::list<Cliente> restaurar () = 0;
};

#endif /* GESTORDBINTERFAZ_H_ */
