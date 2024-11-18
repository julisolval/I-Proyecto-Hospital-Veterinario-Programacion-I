#pragma once
#include "Mascota.h"

class ColeccionMascotas
{
private:
	Mascota* vecMascotas[3];
	int can, tam;
public:
	ColeccionMascotas();
	virtual ~ColeccionMascotas();

	bool ingresaMascota(Mascota*);
	bool yaExisteLaMascota(std::string) const;

	bool cantidadDeMascotas() const;
	bool vectorLleno() const;

	Mascota* getMascota(std::string) const;

	std::string toString() const;
};

