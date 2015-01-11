/*
 * GestorDBFichero.cpp
 *
 *  Created on: 10/12/2014
 *      Author: angel
 */
#include "Agenda.h"
#include "GestorDBFichero.h"
#include "Cliente.h"
using namespace std;

GestorDBFichero::GestorDBFichero() {
	// TODO Auto-generated constructor stub

}

GestorDBFichero::~GestorDBFichero() {
	// TODO Auto-generated destructor stub
}

void GestorDBFichero :: salvar (list <Cliente> clientes)
{
	GestorDBFichero gf;
	fstream f;
	string nombreF = gf.getNombreFichero() + ".txt";
	f.open(nombreF.c_str());
	list <Cliente> :: iterator i; //Declaramos el iterador que vamos a utilizar como puntero dentro de la lista
	for (i=clientes.begin(); i!=clientes.end(); i++)
	{
		f << i-> getApellidos() << "," << i-> getNombre() << "," << i-> getDni() << "," << "," << i-> getTelefono() << "," << i-> getDireccionesAsString(i->getDirecciones()) << "," << i-> getAnotaciones() << "," << i-> getRedesSocialesAsString(i->getRedesSociales()) << "," << i-> getNumUsos() << "," << i-> isFavorito() << "\n";
	}
	f.close();
}

void GestorDBFichero :: restaurar ()
{
	GestorDBFichero gf;
	list <Cliente> clientes;
	fstream f;
	string nombreF = gf.getNombreFichero() + ".txt";
	string dni, nombre, apellidos, telefono, anotaciones, favorito, numUsos, direcciones, redesSociales;
	Direccion d;
	RedSocial r;
	Cliente c;
	f.open(nombreF.c_str());
	if (!f)
	{
		cout <<"Error de apertura del fichero"<<endl;
	}
	else
	{
		while (getline(f, apellidos, ','))//cambiar variables por las de cliente
		{
			getline (f, nombre, ',');
			getline (f, dni, ',');
			getline (f, telefono, ',');
			getline (f, direcciones, ',');
			getline (f, anotaciones, ',');
			getline (f, redesSociales, ',');
			getline (f, numUsos, ',');
			getline (f, favorito, ',');
			c.setApellidos(apellidos);
			c.setNombre(nombre);
			c.setTelefono ((long)telefono.c_str());
			c.setAnotaciones(anotaciones);
			c.setNumUsos((long)numUsos.c_str());
			c.setFavorito((bool)favorito.c_str());
			cout <<endl<<"Introducidas en la lista las variables leidas del fichero: "<<apellidos<<", "<<nombre<<", "<<dni<<", "<<telefono<<", "<<anotaciones<<", "<<numUsos<< ", "<<favorito<< ", ";//INCOMPLETO
			gf.setClientes(c);
		}
	}
	f.close();
}
