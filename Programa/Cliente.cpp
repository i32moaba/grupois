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
	telefono_ = "";
	direcciones_ = "";
	anotaciones_ = "";
	redesSociales_ = "";
	favorito_ = "";
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
			d = (i*).tipo_calle + "." + (i*).calle + "." + (i*).numero + "." + (i*).cp + "." + (i*).ciudad + "-";
		}
	return d;
}

string Cliente :: getRedesSocialesAsString (std::list <RedSocial> redesSociales)
{
	list<RedSocial>::iterator i;
	string r;
	for (i=redesSociales.begin(); i!=redesSociales.end(); i++)
		{
			r = (i*).nombreRed + "." + (i*).url + "-";
		}
	return r;
}



