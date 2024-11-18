#pragma once
#include "Hora.h"

class ColeccionHoras
{
private:
	Hora* vecHoras[11];
	int tam;
public:
	ColeccionHoras();
	virtual ~ColeccionHoras();

	bool getHoraCita(int) const;
	int getHora(int) const;

	void sacarCita(int);
	void cancelarCita(int);
};

