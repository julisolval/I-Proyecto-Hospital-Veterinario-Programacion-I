#pragma once
#include <iostream>
#include <string>
#include <sstream>

class Mascota
{
private:
	std::string numeroDeIdentificacion, nombre, tipoDeMascota, raza;
public:
	Mascota();
	Mascota(std::string, std::string, std::string, std::string);
	virtual ~Mascota();

	void setNumeroDeIdentificacion(std::string);
	void setNombre(std::string);
	void setTipoDeMascota(std::string);
	void setRaza(std::string);

	std::string getNumeroDeIdentificacion() const;
	std::string getNombre() const;
	std::string getTipoDeMascotas() const;
	std::string getRaza() const;

	std::string toString() const;
};

