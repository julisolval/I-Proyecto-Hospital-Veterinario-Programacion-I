#pragma once
#include "ColeccionDoctores.h"

class Especialidad
{
private:
	std::string nombreEspecialidad;
	ColeccionDoctores* vecDoctores;
public:
	Especialidad();
	Especialidad(std::string, ColeccionDoctores*);
	virtual ~Especialidad();

	void setNombreEspecialidad(std::string);
	void setVecDoctores(ColeccionDoctores*);

	std::string getEspecialidad() const;
	ColeccionDoctores* getVecDoctores() const;

	bool ingresaDoctores(Doctor*) const;
	bool yaExisteElDoctor(std::string) const;

	bool vectorLleno() const;

	Doctor* getDoctor(std::string) const;

	bool cantidadDeDoctores() const;

	bool getHoraCita(int, std::string, std::string) const;

	void sacarCita(int, std::string, std::string);
	void cancelarCita(int, std::string, std::string);

	std::string toStringEspecialidades() const;
	std::string toStringDoctoresPorEspecialidad() const;
	std::string toStringHorarioDoc() const;
	std::string toStringHorarioDocEspecifico(std::string) const;
};

