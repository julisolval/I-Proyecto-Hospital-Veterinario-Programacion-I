#include "Especialidad.h"

Especialidad::Especialidad() :nombreEspecialidad{ "Indef" }, vecDoctores{ new ColeccionDoctores() } {}

Especialidad::Especialidad(std::string nombreEspecialidad, ColeccionDoctores* vecDoctores) {
    this->nombreEspecialidad = nombreEspecialidad;
    this->vecDoctores = new ColeccionDoctores(*vecDoctores);
}

Especialidad::~Especialidad() {
    if (vecDoctores != nullptr) delete vecDoctores;
}


void Especialidad::setNombreEspecialidad(std::string nombreEspecialidad)
{
    this->nombreEspecialidad = nombreEspecialidad;
}

void Especialidad::setVecDoctores(ColeccionDoctores* vecDoctores)
{
    this->vecDoctores = new ColeccionDoctores(*vecDoctores);
}

std::string Especialidad::getEspecialidad() const
{
    return this->nombreEspecialidad;
}

ColeccionDoctores* Especialidad::getVecDoctores() const
{
    return this->vecDoctores;
}

bool Especialidad::ingresaDoctores(Doctor* doctor) const
{
    return vecDoctores->ingresaDoctores(doctor);
}

bool Especialidad::yaExisteElDoctor(std::string cedula) const
{
    return vecDoctores->yaExisteElDoctor(cedula);
}

bool Especialidad::vectorLleno() const
{
    return vecDoctores->vectorLleno();
}

Doctor* Especialidad::getDoctor(std::string id) const
{
    return vecDoctores->getDoctor(id);
}

bool Especialidad::cantidadDeDoctores() const
{
    return vecDoctores->cantidadDeDoctores();
}

bool Especialidad::getHoraCita(int pos, std::string diaDeLaSemana, std::string id) const
{
    return vecDoctores->getHoraCita(pos, diaDeLaSemana, id);
}

void Especialidad::sacarCita(int hora, std::string diaDeLaSemana, std::string id)
{
    vecDoctores->sacarCita(hora, diaDeLaSemana, id);
}

void Especialidad::cancelarCita(int hora, std::string diaDeLaSemana, std::string id)
{
    vecDoctores->cancelarCita(hora, diaDeLaSemana, id);
}

std::string Especialidad::toStringEspecialidades() const
{
    std::stringstream s;
    s << nombreEspecialidad << std::endl;
    return s.str();
}

std::string Especialidad::toStringDoctoresPorEspecialidad() const
{
    std::stringstream s;
    s << "--------------------------------------------------\n";
    s << nombreEspecialidad << std::endl;
    s << "--------------------------------------------------\n";
    s << vecDoctores->toString();
    return s.str();
}

std::string Especialidad::toStringHorarioDoc() const
{
    std::stringstream s;
    s << "--------------------------------------------------\n";
    s << nombreEspecialidad << std::endl;
    s << "--------------------------------------------------\n";
    s << vecDoctores->toStringHorarioDoc();
    return s.str();
}

std::string Especialidad::toStringHorarioDocEspecifico(std::string id) const
{
    std::stringstream s;
    s << vecDoctores->toStringHorarioDocEspecifico(id);
    return s.str();
}
