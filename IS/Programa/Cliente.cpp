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
			d = ":" + i->tipo_calle + "." + i->calle + "·" + aux1 + "{" + aux2 + "}" + i->ciudad + "-";
		}
	return d;
}

list<Direccion> Cliente :: getDireccionesFromString (string direcciones)
{
	list<Direccion> listaDir;
	int pos1, pos2, pos3, pos4, pos5, pos6;
	struct Direccion i;
	string numero, cp;
	while (direcciones.find (":"))
	{
		pos1 = direcciones.find (":");
		pos2 = direcciones.find (".");
		i.tipo_calle = direcciones.substr (pos1, pos2-pos1);
		pos3 = direcciones.find (".");
		i.calle = direcciones.substr (pos2, pos3 - pos2);
		pos4 = direcciones.find ("{");
		numero = direcciones.substr (pos3, pos4 - pos3);
		i.numero = atoi (numero.c_str());
		pos5 = direcciones.find ("}");
		cp = direcciones.substr (pos4, pos5 - pos4);
		i.cp = atol (cp.c_str());
		pos6 = direcciones.find ("-");
		i.ciudad = direcciones.substr (pos5, pos6 - pos5);
		listaDir.push_back (i);
	}
	return listaDir;
}

string Cliente :: getRedesSocialesAsString (std::list <RedSocial> redesSociales)
{
	list<RedSocial>::iterator i;
	string r;
	for (i=redesSociales.begin(); i!=redesSociales.end(); i++)
		{
			r = ":" + i->nombreRed + "." + i->url + "-";
		}
	return r;
}

list<RedSocial> Cliente :: getRedesSocialesFromString (string redesSociales)
{
	list<RedSocial> listaRed;
	int pos1, pos2, pos3;
	struct RedSocial i;
	while (redesSociales.find (":"))
	{
		pos1 = redesSociales.find (":");
		pos2 = redesSociales.find (".");
		i.nombreRed = redesSociales.substr (pos1, pos2-pos1);
		pos3 = redesSociales.find ("-");
		i.url = redesSociales.substr (pos2, pos3 - pos2);
		listaRed.push_back (i);
	}
	return listaRed;
}

void Cliente :: imprimeDirecciones (list <Direccion> direcciones)
{
	list<Direccion> :: iterator it;
	int i = 0;
	for (it=direcciones.begin(); it!=direcciones.end(); it++)
		{
			std::cout << "\nDireccion nº:"<<i+1<<endl<< "\tNombre de la calle: "<<it->calle<<endl;
			std::cout << "\tNumero: " <<it->numero<<endl;
			std::cout << "\tCodigo Postal: "<<it->cp<<endl;
			std::cout << "\tCiudad: " <<it->ciudad<<endl;
			std::cout << "\tTipo de calle: " <<it->tipo_calle<<endl;
			i++;
		}
}

void Cliente :: imprimeRedesSociales (list <RedSocial> redesSociales)
{
	list<RedSocial> :: iterator it;
	int i = 0;
	for (it=redesSociales.begin(); it!=redesSociales.end(); it++)
		{
			std::cout << "\nRed Social nº:"<<i+1<<endl<< "\tNombre de la red: "<<it->nombreRed<<endl;
			std::cout << "\tURL: " <<it->url<<endl;
			i++;
		}
}



