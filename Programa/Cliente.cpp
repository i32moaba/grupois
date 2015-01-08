/*
 * Cliente.cpp
 *
 *  Created on: 03/12/2014
 *      Author: i32moaba
 */

#include "Cliente.h"
using namespace std;
Cliente::Cliente(std::string DNI, std::string n, std::string ap, long t, std::list<Direccion> d, std::string an, std::list<RedSocial> rs, long u, bool f) {
	dni_ = DNI;
	nombre_ = n;
	apellidos_ = ap;
	telefono_ = t;
	direcciones_ = d;
	anotaciones_ = an;
	redesSociales_ = rs;
	favorito_ = f;
	numUsos_ = 0;
}

Cliente::~Cliente() {
	// TODO Auto-generated destructor stub
}

string Cliente :: getDireccionesAsString (std::list <Direccion> direcciones)
{
	list<Direccion>::iterator i;
	string d;
	for (i=direcciones.begin(); i!=direcciones.end(); i++)
		{
			d << i-> direccion.getApellidos() << "." << i-> getNombre() << "," << i-> getDni() << "," << "," << i-> getTelefono() << "," << i-> getDireccionesAsString() << "," << i-> getAnotaciones() << "," << i-> getRedesSocialesAsString() << "," << i-> getNumUsos() << "," << i-> isFavorito() << "\n";
		}
}
