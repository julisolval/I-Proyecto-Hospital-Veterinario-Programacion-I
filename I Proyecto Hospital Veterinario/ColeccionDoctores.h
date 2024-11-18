#pragma once
#include "Doctor.h"

class ColeccionDoctores
{
private:
	Doctor* vecDoctores[2];
	int can, tam;

public:
	ColeccionDoctores();
	virtual ~ColeccionDoctores();

	bool ingresaDoctores(Doctor*);
	bool yaExisteElDoctor(std::string) const;

	bool cantidadDeDoctores() const;
	bool vectorLleno() const;

	Doctor* getDoctor(std::string) const;

	bool getHoraCita(int, std::string, std::string) const;

	void sacarCita(int, std::string, std::string);
	void cancelarCita(int, std::string, std::string);

	std::string toString() const;
	std::string toStringHorarioDocEspecifico(std::string) const;
	std::string toStringHorarioDoc() const;
};

