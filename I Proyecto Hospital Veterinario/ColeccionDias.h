#pragma once
#include "Dia.h"

class ColeccionDias
{
private:
	Dia* vecDias[6];
	int tam;
public:
	ColeccionDias();
	virtual ~ColeccionDias();

	bool getHoraCita(int, std::string) const;

	void sacarCita(int, std::string);
	void cancelarCita(int, std::string);

	std::string toString() const;
};

