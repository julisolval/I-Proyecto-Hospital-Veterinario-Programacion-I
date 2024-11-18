#pragma once
#include "Duenio.h"

class ColeccionDuenios
{
private:
	Duenio* vecDuenios[8];
	int can, tam;
public:
	ColeccionDuenios();
	virtual ~ColeccionDuenios();

	bool ingresaDuenio(Duenio*);
	bool yaExisteElDuenio(std::string) const;

	bool cantidadDeDuenios() const;
	bool vectorLleno() const;

	bool ingresaMascota(Mascota*, std::string);
	bool yaExisteLaMascota(std::string) const;
	bool yaExisteLaMascotaEnDuenio (std::string, std::string) const;
	bool vectorLlenoMascota(std::string) const;
	bool cantidadDeMascotas(std::string) const;

	Duenio* getDuenio(std::string) const;
	Mascota* getMascota(std::string, std::string) const;

	std::string toString() const;
	std::string toStringMascotasDeDuenio(std::string) const;
	std::string toStringCompleto() const;
};

