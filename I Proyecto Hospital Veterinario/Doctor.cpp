#include "Doctor.h"

Doctor::Doctor() :nombreDoctor{ "Indef" }, cedula{ "Indef" }, horario{ new ColeccionDias()} {}

Doctor::Doctor(std::string nombreDoctor, std::string cedula, ColeccionDias* horario)
{
    this->nombreDoctor = nombreDoctor;
    this->cedula = cedula;
    this->horario = horario;
}

Doctor::~Doctor() {
    if (horario != nullptr) delete horario;
}

void Doctor::setNombreDoctor(std::string nombreDoctor)
{
    this->nombreDoctor = nombreDoctor;
}

void Doctor::setCedula(std::string cedula)
{
    this->cedula = cedula;
}

void Doctor::setHorario(ColeccionDias* horario)
{
    this->horario = horario;
}

std::string Doctor::getNombreDoctor() const
{
    return this->nombreDoctor;
}

std::string Doctor::getCedula() const
{
    return this->cedula;
}

ColeccionDias* Doctor::getHorario() const
{
    return this->horario;
}

bool Doctor::getHoraCita(int pos, std::string diaDeLaSemana) const
{
    return horario->getHoraCita(pos, diaDeLaSemana);
}

void Doctor::sacarCita(int hora, std::string diaDeLaSemana)
{
    horario->sacarCita(hora, diaDeLaSemana);
}

void Doctor::cancelarCita(int hora, std::string diaDeLaSemana)
{
    horario->cancelarCita(hora, diaDeLaSemana);
}

std::string Doctor::toString() const
{
    std::stringstream s;
    s << "Nombre del doctor: " << nombreDoctor << std::endl;
    s << "Cedula: " << cedula << std::endl;
    s << "--------------------------------------------------\n";
    return s.str();
}

std::string Doctor::toStringHorarioDoc() const
{
    std::stringstream s;
    s << "Nombre del doctor: " << nombreDoctor << std::endl;
    s << "Cedula: " << cedula << std::endl;
    s << horario->toString();
    return s.str();
}
