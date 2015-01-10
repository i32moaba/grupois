/*
 * Cliente.h
 *
 *  Created on: 03/12/2014
 *      Author: i32moaba
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_

#include <string>
#include <list>
#include <fstream>
#include <iostream>
#include <sstream>

struct Direccion
{
	std :: string calle;
	int numero;
	long cp;
	std :: string ciudad;
	std :: string tipo_calle;
};

struct RedSocial
{
	std :: string nombreRed;
	std :: string url;
};

class Cliente {
private:
		std :: string dni_;
		std :: string nombre_;
		std :: string apellidos_;
		long telefono_;
		std :: list <Direccion> direcciones_;
		std :: string anotaciones_;
		std :: list <RedSocial> redesSociales_;
		long numUsos_;
		bool favorito_;
public:
	Cliente();
	virtual ~Cliente();

	const std::string& getAnotaciones() const
	{
		return anotaciones_;
	}

	void setAnotaciones(const std::string& anotaciones)
	{
		anotaciones_ = anotaciones;
	}

	const std::string& getApellidos() const
	{
		return apellidos_;
	}

	void setApellidos(const std::string& apellidos)
	{
		apellidos_ = apellidos;
	}

	const std::list<Direccion>& getDirecciones() const
	{
		return direcciones_;
	}

	void setDirecciones(const std::list<Direccion>& direcciones)
	{
		direcciones_ = direcciones;
	}

	const std::string& getDni() const
	{
		return dni_;
	}

	void setDni(const std::string& dni)
	{
		dni_ = dni;
	}

	const std::string& getNombre() const
	{
		return nombre_;
	}

	void setNombre(const std::string& nombre) {
		nombre_ = nombre;
	}

	long getNumUsos() const {
		return numUsos_;
	}

	void setNumUsos(long numUsos) {
		numUsos_ = numUsos;
	}

	const std::list<RedSocial>& getRedesSociales() const {
		return redesSociales_;
	}

	void setRedesSociales(const std::list<RedSocial>& redesSociales) {
		redesSociales_ = redesSociales;
	}

	long getTelefono() const {
		return telefono_;
	}

	void setTelefono(long telefono) {
		telefono_ = telefono;
	}

	bool isFavorito() const {
		return favorito_;
	}

	void setFavorito(bool favorito) {
		favorito_ = favorito;
	}
	void usado() {
			numUsos_++;
		}
	std :: string getDireccionesAsString (std::list<Direccion> direcciones);
	std :: string getRedesSocialesAsString (std::list<RedSocial> redesSociales);
};

#endif /* CLIENTE_H_ */
