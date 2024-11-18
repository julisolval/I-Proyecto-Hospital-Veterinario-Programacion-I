#include "Hora.h"

Hora::Hora() : hora{ 0 }, horaCita{ false } {}

Hora::Hora(int hora, bool horaCita)
{
    this->hora = hora;
    this->horaCita = horaCita;
}

Hora::~Hora(){}

void Hora::setHora(int hora)
{
    this->hora = hora;
}

void Hora::setHoraCita(bool horaCita)
{
    this->horaCita = horaCita;
}


int Hora::getHora() const
{
    return this->hora;
}

bool Hora::getHoraCita() const
{
    return this->horaCita;
}

void Hora::sacarCita()
{
    setHoraCita(true);
}

void Hora::cancelarCita()
{
    setHoraCita(false);
}
