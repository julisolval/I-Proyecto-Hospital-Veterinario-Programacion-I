#include "Dia.h"

Dia::Dia() : dia{ 0 }, anio{ 0 }, diaDeLaSemana{"Indef"}, mes{ "Indef" }, horas { new ColeccionHoras()} {}

Dia::Dia(std::string diaDeLaSemana, ColeccionHoras* horas)
{
    this->diaDeLaSemana = diaDeLaSemana;
    this->dia = dia;
    this->horas = horas;

    time_t t = time(&t);
    tm tiempoLocal;
    localtime_s(&tiempoLocal, &t);
    std::string m[] = { "Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre" };
    mes = m[tiempoLocal.tm_mon];
    anio = tiempoLocal.tm_year + 1900;
}

Dia::~Dia(){
    if (horas != nullptr) delete horas;
}

void Dia::setHoras(ColeccionHoras* horas)
{
    this->horas = horas;
}

void Dia::setDia(int dia)
{
    this->dia = dia;
}

void Dia::setDiaDeLaSemana(std::string diaDeLaSemana)
{
    this->diaDeLaSemana = diaDeLaSemana;
}

ColeccionHoras* Dia::getHoras() const
{
    return this->horas;
}

int Dia::getAnio() const
{
    return this->anio;
}

int Dia::getDia() const
{
    return this->dia;
}

std::string Dia::getMes() const
{
    return this->mes;
}

std::string Dia::getDiaDeLaSemana() const
{
    return this->diaDeLaSemana;
}

bool Dia::getHoraCita(int pos) const
{
    return horas->getHoraCita(pos);
}

int Dia::getHora(int pos) const
{
    return horas->getHora(pos);
}

void Dia::sacarCita(int hora)
{
    horas->sacarCita(hora);
}

void Dia::cancelarCita(int hora)
{
    horas->cancelarCita(hora);
}
