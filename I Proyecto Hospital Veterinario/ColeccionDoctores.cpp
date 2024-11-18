#include "ColeccionDoctores.h"

ColeccionDoctores::ColeccionDoctores() : can{ 0 }, tam{ 2 }
{
    for (int i = 0; i < tam; i++) {
        vecDoctores[i] = nullptr;
    }
}

ColeccionDoctores::~ColeccionDoctores()
{
    for (int i = 0; i < can; i++) {
        if (vecDoctores[i] != nullptr) {
            delete vecDoctores[i];
        }
    }
}

bool ColeccionDoctores::ingresaDoctores(Doctor* doctor)
{
    if (yaExisteElDoctor(doctor->getCedula()) == false) {
        if (can < tam) {
            vecDoctores[can++] = doctor;
            return true;
        }
        else
            return false;
    }
    else return false;
}

bool ColeccionDoctores::yaExisteElDoctor(std::string cedula) const
{
    for (int i = 0; i < can; i++) {
        if (vecDoctores[i] != nullptr) {
            if (vecDoctores[i]->getCedula() == cedula) {
                return true;
            }
        }
    }
    return false;
}

bool ColeccionDoctores::cantidadDeDoctores() const
{
    if (can != 0) {
        return true;
    }
    else { return false; }
}

bool ColeccionDoctores::vectorLleno() const
{
    if (can == tam) {
        return true;
    }
    else { return false; }
}

Doctor* ColeccionDoctores::getDoctor(std::string id) const
{
    for (int i = 0; i < can; i++) {
        if (vecDoctores[i]->getCedula() == id) {
            return vecDoctores[i];
        }
    }
    return nullptr;
}

bool ColeccionDoctores::getHoraCita(int pos, std::string diaDeLaSemana, std::string id) const
{
    for (int i = 0; i < can; i++) {
        if (vecDoctores[i]->getCedula() == id) {
            return vecDoctores[i]->getHoraCita(pos, diaDeLaSemana);
        }
    }
}

void ColeccionDoctores::sacarCita(int hora, std::string diaDeLaSemana, std::string id)
{
    for (int i = 0; i < can; i++) {
        if (vecDoctores[i]->getCedula() == id) {
            vecDoctores[i]->sacarCita(hora, diaDeLaSemana);
        }
    }
}

void ColeccionDoctores::cancelarCita(int hora, std::string diaDeLaSemana, std::string id)
{
    for (int i = 0; i < can; i++) {
        if (vecDoctores[i]->getCedula() == id) {
            vecDoctores[i]->cancelarCita(hora, diaDeLaSemana);
        }
    }
}

std::string ColeccionDoctores::toString() const
{
    std::stringstream s;
    if (can == 0) {
        s << "No se encuentran doctores registrados.\n";
        s << "--------------------------------------------------\n";
    }
    else {
        for (int i = 0; i < can; i++) {
            if (vecDoctores[i] != nullptr) {
                s << vecDoctores[i]->toString();
            }
        }
    }
    return s.str();
}

std::string ColeccionDoctores::toStringHorarioDocEspecifico(std::string id) const
{
    std::stringstream s;
    for (int i = 0; i < can; i++) {
        if (vecDoctores[i]->getCedula() == id) {
            s << vecDoctores[i]->toStringHorarioDoc();
        }
    }
    return s.str();
}

std::string ColeccionDoctores::toStringHorarioDoc() const
{
    std::stringstream s;
    if (can == 0) {
        s << "No se encuentran doctores registrados.\n";
        s << "--------------------------------------------------\n";
    }
    else {
        for (int i = 0; i < can; i++) {
            s << vecDoctores[i]->toStringHorarioDoc();
        }
    }
    return s.str();
}

