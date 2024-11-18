#include "ColeccionEspecialidades.h"

ColeccionEspecialidades::ColeccionEspecialidades() : can{ 0 }, tam{ 4 }
{
    for (int i = 0; i < tam; i++) {
        vecEspecialidades[i] = nullptr;
    }
}

ColeccionEspecialidades::~ColeccionEspecialidades()
{
    for (int i = 0; i < can; i++) {
        if (vecEspecialidades[i] != nullptr) {
            delete vecEspecialidades[i];
        }
    }
}

bool ColeccionEspecialidades::ingresaEspecialidad(Especialidad* especialidad)
{
    if (yaExisteEspecialidad(especialidad->getEspecialidad()) == false) {
        if (can < tam) {
            vecEspecialidades[can++] = especialidad;
            return true;
        }
        else
            return false;
    }
    else return false;
}

bool ColeccionEspecialidades::yaExisteEspecialidad(std::string nomEspecialidad) const
{
    for (int i = 0; i < can; i++) {
        if (vecEspecialidades[i] != nullptr) {
            if (vecEspecialidades[i]->getEspecialidad() == nomEspecialidad) {
                return true;
            }
        }
    }
    return false;
}

bool ColeccionEspecialidades::vectorLleno() const
{
    if (can == tam) {
        return true;
    }
    else { return false; }
}

bool ColeccionEspecialidades::cantidadDeEspecialidades() const
{
    if (can == 0) {
        return false;
    }
    else { return true; }
}

bool ColeccionEspecialidades::ingresaDoctorEnEspecialidad(Doctor* doctor, std::string especialidad) {

    return getEspecialidad(especialidad)->ingresaDoctores(doctor);
}

bool ColeccionEspecialidades::yaExisteElDoctor(std::string cedula) const
{
    for (int i = 0; i < can; i++) {
        if (vecEspecialidades[i] != nullptr) {
            if (vecEspecialidades[i]->yaExisteElDoctor(cedula)) {
                return true;
            }
        }
    }
    return false;
}

bool ColeccionEspecialidades::vectorLlenoDoc(std::string especialidad) const
{
    for (int i = 0; i < can; i++) {
        if (vecEspecialidades[i] != nullptr) {
            return getEspecialidad(especialidad)->vectorLleno();
        }
    }
    return false;
}

bool ColeccionEspecialidades::cantidadDeDoctores(std::string especialidad) const
{
    for (int i = 0; i < can; i++) {
        if (vecEspecialidades[i] != nullptr) {
            return getEspecialidad(especialidad)->cantidadDeDoctores();
        }
    }
    return false;
}

Especialidad* ColeccionEspecialidades::getEspecialidad(std::string especialidad) const {
    for (int i = 0; i < can; i++) {
        if (vecEspecialidades[i]->getEspecialidad() == especialidad) {
            return vecEspecialidades[i];
        }
    }
    return nullptr;
}

Doctor* ColeccionEspecialidades::getDoctor(std::string especialidad, std::string id) const
{
    return getEspecialidad(especialidad)->getDoctor(id);
}

bool ColeccionEspecialidades::getHoraCita(int pos, std::string diaDeLaSemana, std::string id, std::string especialidad)
{
    for (int i = 0; i < can; i++) {
        if (vecEspecialidades[i]->getEspecialidad() == especialidad) {
            return vecEspecialidades[i]->getHoraCita(pos, diaDeLaSemana, id);
        }
    }
}

void ColeccionEspecialidades::sacarCita(int hora, std::string diaDeLaSemana, std::string id, std::string especialidad)
{
    for (int i = 0; i < can; i++) {
        if (vecEspecialidades[i]->getEspecialidad() == especialidad) {
            vecEspecialidades[i]->sacarCita(hora, diaDeLaSemana, id);
        }
    }
}

void ColeccionEspecialidades::cancelarCita(int hora, std::string diaDeLaSemana, std::string id, std::string especialidad)
{
    for (int i = 0; i < can; i++) {
        if (vecEspecialidades[i]->getEspecialidad() == especialidad) {
            vecEspecialidades[i]->cancelarCita(hora, diaDeLaSemana, id);
        }
    }
}

std::string ColeccionEspecialidades::toString() const
{
    std::stringstream s;
    if (can == 0) {
        s << "No hay especialidades ingresadas aun.\n";
    }
    else {
        for (int i = 0; i < can; i++) {
            if (vecEspecialidades[i] != nullptr) {
                s << "--------------------------------------------------\n";
                s << i + 1 << ". ";
                s << vecEspecialidades[i]->toStringEspecialidades();
                s << "--------------------------------------------------\n";
            }
        }
    }
    return s.str();
}

std::string ColeccionEspecialidades::toStringCompleto() const
{
    std::stringstream s;
    if (can == 0) {
        s << "No hay especialidades ingresadas aun.\n";
    }
    else {
        for (int i = 0; i < can; i++) {
            if (vecEspecialidades[i] != nullptr) {
                s << vecEspecialidades[i]->toStringDoctoresPorEspecialidad() << std::endl;
            }
        }
    }
    return s.str();
}

std::string ColeccionEspecialidades::toStringDoctoresPorEspecialidad(std::string especialidad) const
{
    std::stringstream s;
        for (int i = 0; i < can; i++) {
            if (vecEspecialidades[i]->getEspecialidad() == especialidad) {
                s << vecEspecialidades[i]->toStringDoctoresPorEspecialidad() << std::endl;
            }
        }
    return s.str();
}

std::string ColeccionEspecialidades::toStringHorarioDoc() const
{
    std::stringstream s;
    for (int i = 0; i < can; i++) {
        s << vecEspecialidades[i]->toStringHorarioDoc() << std::endl;
    }
    return s.str();
}

std::string ColeccionEspecialidades::toStringHorarioDocEspecifico(std::string id, std::string especialidad) const
{
    std::stringstream s;
    for (int i = 0; i < can; i++) {
        if (vecEspecialidades[i]->getEspecialidad() == especialidad) {
            s << vecEspecialidades[i]->toStringHorarioDocEspecifico(id) << std::endl;
        }
    }
    return s.str();
}
