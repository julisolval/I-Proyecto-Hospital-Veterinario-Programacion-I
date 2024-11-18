#include "ColeccionCita.h"

ColeccionCita::ColeccionCita() : can(0), tam(528) {
    for (int i = 0; i < 528; ++i) {
        vecCitas[i] = nullptr; 
    }
}

ColeccionCita::~ColeccionCita() {
    for (int i = 0; i < can; ++i) {
        delete vecCitas[i]; 
    }
}

bool ColeccionCita::agregarCita(Cita* cita) {
    if (can < 528) { 
        vecCitas[can++] = cita; 
        return true;
    }
    else return false; 
}

bool ColeccionCita::cancelarCita(std::string idDuenio, std::string numMascota, std::string idDoc, std::string especialidad, int hora, std::string diaDeLaSemana) {
    
    for (int i = 0; i < can; ++i) {
        if (vecCitas[i] != nullptr) {
            if (vecCitas[i]->getCedulaDuenio() == idDuenio && vecCitas[i]->getNumeroDeIdentificacionMascota() == numMascota && vecCitas[i]->getCedulaDoc() == idDoc && vecCitas[i]->getNombreEspecialidad() == especialidad && vecCitas[i]->getHora() == hora && vecCitas[i]->getDiaDeLaSemana() == diaDeLaSemana) {
                delete vecCitas[i];
                vecCitas[i] = vecCitas[can - 1];
                vecCitas[--can] = nullptr;
                return true;
            }
        }
    }
    return false;
}

bool ColeccionCita::existenCitas() const
{
    if (can != 0) {
        return true;
    }
    else { return false; }
}

std::string ColeccionCita::toStringCitasPorDoctor(std::string cedula) const {
    std::stringstream s;
    for (int i = 0; i < can; ++i) {
        if (vecCitas[i] != nullptr) {
            if (vecCitas[i]->getCedulaDoc() == cedula) {
                s << vecCitas[i]->toString() << "\n";
            }
        }
    }
    return s.str();
}

std::string ColeccionCita::toStringCitasPorDuenio(std::string cedula, std::string numId) const {
    std::stringstream s;
    for (int i = 0; i < can; ++i) {
        if (vecCitas[i] != nullptr) {
            if (vecCitas[i]->getCedulaDuenio() == cedula && vecCitas[i]->getNumeroDeIdentificacionMascota() == numId) {
                s << vecCitas[i]->toString() << "\n";
            }
            else {
                s << "Mascota no tiene citas disponibles.\n";
            }
        }
    }
    return s.str();
}

bool ColeccionCita::existenCitasPorDuenio(std::string cedula, std::string numId) const
{
    for (int i = 0; i < can; ++i) {
        if (vecCitas[i] != nullptr) {
            if (vecCitas[i]->getCedulaDuenio() == cedula && vecCitas[i]->getNumeroDeIdentificacionMascota() == numId) {
                return true;
            }
            else { return false; }
        }
    }
}

bool ColeccionCita::existenCitasPorDoctor(std::string cedula) const
{
    for (int i = 0; i < can; ++i) {
        if (vecCitas[i] != nullptr) {
            if (vecCitas[i]->getCedulaDoc() == cedula) {
                return true;
            }
            else { return false; }
        }
    }
}


std::string ColeccionCita::toString() const {
    std::stringstream ss;
    for (int i = 0; i < can; ++i) {
        if (vecCitas[i] != nullptr) {
            ss << vecCitas[i]->toString() << "\n";
        }
    }
    return ss.str();
}