/*
 * Cliente.cpp
 *
 *  Created on: 03/12/2014
 *      Author: i32moaba
 */

#include "Cliente.h"

Cliente::Cliente(std::string DNI, std::string n, std::string ap, long t, std::list<Direccion> d, std::string an, std::list<RedSocial> rs, long u, bool f) {
	dni_ = DNI;
	nombre_ = n;
	apellidos_ = ap_;
	telefono_ = t;
	direcciones_ = d;
	anotaciones_ = an;
	redesSociales_ = rs;
	favorito_ = f;
}

Cliente::~Cliente() {
	// TODO Auto-generated destructor stub
}

