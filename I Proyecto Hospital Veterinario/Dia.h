#pragma once
#include <ctime> //https://www.w3schools.com/cpp/cpp_date.asp
#include "ColeccionHoras.h"

class Dia
{
private:
	int dia, anio;
	std::string diaDeLaSemana, mes;
	ColeccionHoras* horas;
public:
	Dia();
	Dia(std::string, ColeccionHoras*);
	virtual ~Dia();

	void setDia(int);
	void setDiaDeLaSemana(std::string);
	void setHoras(ColeccionHoras*);
	

	ColeccionHoras* getHoras() const;
	int getAnio() const;
	int getDia() const;
	std::string getMes() const;
	std::string getDiaDeLaSemana() const;

	bool getHoraCita(int) const;
	int getHora(int) const;

	void sacarCita(int);
	void cancelarCita(int);
};

