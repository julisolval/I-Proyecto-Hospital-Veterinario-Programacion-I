#pragma once
#include "ColeccionDias.h";

class Doctor
{
private:
	std::string nombreDoctor, cedula;
	ColeccionDias* horario;
public:
	Doctor();
	Doctor(std::string, std::string, ColeccionDias*);
	virtual ~Doctor();

	void setNombreDoctor(std::string);
	void setCedula(std::string);
	void setHorario(ColeccionDias*);

	std::string getNombreDoctor() const;
	std::string getCedula() const;
	ColeccionDias* getHorario() const;

	bool getHoraCita(int, std::string) const;

	void sacarCita(int, std::string);
	void cancelarCita(int, std::string);

	std::string toString() const;
	std::string toStringHorarioDoc() const;
};

