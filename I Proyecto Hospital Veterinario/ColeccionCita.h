#pragma once
#include "Cita.h"

class ColeccionCita
{
private:
	Cita* vecCitas[528];
	int can, tam;
public:
    ColeccionCita();
    ~ColeccionCita();

    bool agregarCita(Cita*);
    bool cancelarCita(std::string, std::string, std::string, std::string, int, std::string);

    bool existenCitas() const;

    std::string toStringCitasPorDoctor(std::string) const;
    std::string toStringCitasPorDuenio(std::string, std::string) const;
    bool existenCitasPorDuenio(std::string, std::string) const;
    bool existenCitasPorDoctor(std::string) const;
    std::string toString() const;
};

