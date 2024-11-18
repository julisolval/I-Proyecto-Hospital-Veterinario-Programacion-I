#pragma once
#include "Especialidad.h"

class ColeccionEspecialidades
{
private:
	Especialidad* vecEspecialidades[4];
	int can, tam;
public:
	ColeccionEspecialidades();
	virtual ~ColeccionEspecialidades();

	bool ingresaEspecialidad(Especialidad*);
	bool yaExisteEspecialidad(std::string) const;

	bool vectorLleno() const;
	bool cantidadDeEspecialidades() const;

	bool ingresaDoctorEnEspecialidad(Doctor*, std::string);
	bool yaExisteElDoctor(std::string) const;
	bool vectorLlenoDoc(std::string) const;

	bool cantidadDeDoctores(std::string) const;

	Especialidad* getEspecialidad(std::string) const;
	Doctor* getDoctor(std::string, std::string) const;

	bool getHoraCita(int, std::string, std::string, std::string);

	void sacarCita(int, std::string, std::string, std::string);
	void cancelarCita(int, std::string, std::string, std::string);

	std::string toString() const;
	std::string toStringCompleto() const;
	std::string toStringDoctoresPorEspecialidad(std::string) const;

	std::string toStringHorarioDoc() const;
	std::string toStringHorarioDocEspecifico(std::string, std::string) const;
};
