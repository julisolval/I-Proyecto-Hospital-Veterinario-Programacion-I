#pragma once
#include "ColeccionMascotas.h"

class Duenio
{
private:
	std::string nombreDuenio, numeroTelefonico, cedula;
	ColeccionMascotas* vecMascotas;
public:
	Duenio();
	Duenio(std::string, std::string, std::string, ColeccionMascotas*);
	virtual ~Duenio();

	void setNombreDuenio(std::string);
	void setNumeroTelefonico(std::string);
	void setCedula(std::string);
	void setVecMascotas(ColeccionMascotas*);

	std::string getNombreDuenio() const;
	std::string getNumeroTelefonico() const;
	std::string getCedula() const;
	ColeccionMascotas* getVecMascotas() const;

	bool ingresaMascota(Mascota*) const;
	bool yaExisteLaMascota(std::string) const;

	bool vectorLlenoMascota() const;
	bool cantidadDeMascotas() const;
	Mascota* getMascota(std::string) const;

	std::string toString()const;
	std::string toStringMascotasDeDuenio() const;
	std::string toStringCompleto() const;
};
