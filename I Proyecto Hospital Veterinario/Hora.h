#pragma once
#include <iostream>
#include <string>
#include <sstream>

class Hora
{
private:
	int hora;
	bool horaCita;
public:
	Hora();
	Hora(int, bool);
	virtual ~Hora();

	void setHora(int);
	void setHoraCita(bool);

	int getHora() const;
	bool getHoraCita() const;

	void sacarCita();
	void cancelarCita();
};

