/*
 * Cliente.cpp
 *
 *  Created on: 03/12/2014
 *      Author: i32moaba
 */

#include "Cliente.h"

using namespace std;

Cliente::Cliente() {
	dni_ = "";
	nombre_ = "";
	apellidos_ = "";
	telefono_ = 0;
	anotaciones_ = "";
	favorito_ = "";
	numUsos_ = 0;
}

Cliente::~Cliente() {
	// TODO Auto-generated destructor stub
}

string Cliente :: getDireccionesAsString (std::list <Direccion> direcciones)
{
	list<Direccion>::iterator i;
	string d, aux1, aux2;
	for (i=direcciones.begin(); i!=direcciones.end(); i++)
		{
			stringstream stream;
			stream << i->numero;
			aux1 = stream.str();
			stream << i->cp;
			aux2 = stream.str();
			d = i->tipo_calle + "." + i->calle + "." + aux1 + "." + aux2 + "." + i->ciudad + "-";
		}
	return d;
}

string Cliente :: getRedesSocialesAsString (std::list <RedSocial> redesSociales)
{
	list<RedSocial>::iterator i;
	string r;
	for (i=redesSociales.begin(); i!=redesSociales.end(); i++)
		{
			r = i->nombreRed + "." + i->url + "-";
		}
	return r;
}



