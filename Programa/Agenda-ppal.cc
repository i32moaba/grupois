/*
 * Agenda-ppal.cpp
 *
 *  Created on: 04/12/2014
 *      Author: i32roraj
 */

#include "Cliente.h"
#include "Agenda.h"
#include <iostream>
#include <string>
#include <list>

int menu ()
{
	int opcion;
	std::cout << "\n\tSeleccione una opción, para ello introduzca el número de cada opción y accederá a ella. Las opciones disponibles son:\n\n0: Salir del programa.\n1: Imprimir la agenda.\n2: Ordenar agenda por apellidos.\n3: Insertar un nuevo cliente en la agenda.\n4: Busca un cliente en la agenda según su apellido.\n5: Borra un cliente según su apellido.\n6: Modifica los datos de un cliente buscándolo por su apellido.\n\nIntroduzca su elección: ";
	std::cin >> opcion;
	return opcion;
}

int main ()
{
	std::cout << "\n\nBienvenido a la Agenda de Negocios BETA. El sistema almacena los datos de sus clientes ... "; //INCOMPLETO.
}
