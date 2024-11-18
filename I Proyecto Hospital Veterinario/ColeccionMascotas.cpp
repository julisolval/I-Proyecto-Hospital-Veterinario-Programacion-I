#include "ColeccionMascotas.h"

ColeccionMascotas::ColeccionMascotas(): can{ 0 }, tam{ 3 }
{
    for (int i = 0; i < tam; i++) {
        vecMascotas[i] = nullptr;
    }
}

ColeccionMascotas::~ColeccionMascotas()
{
    for (int i = 0; i < can; i++) {
        if (vecMascotas[i] != nullptr) {
            delete vecMascotas[i];
        }
    }
}

bool ColeccionMascotas::ingresaMascota(Mascota* mascota)
{
    if (yaExisteLaMascota(mascota->getNumeroDeIdentificacion()) == false) {
        if (can < tam) {
            vecMascotas[can++] = mascota;
            return true;
        }
        else
            return false;
    }
    else return false;
}

bool ColeccionMascotas::yaExisteLaMascota(std::string id) const
{
    for (int i = 0; i < can; i++) {
        if (vecMascotas[i] != nullptr) {
            if (vecMascotas[i]->getNumeroDeIdentificacion() == id) {
                return true;
            }
        }
    }
    return false;
}

bool ColeccionMascotas::cantidadDeMascotas() const
{
    if (can != 0) {
        return true;
    }
    else { return false; }
}

bool ColeccionMascotas::vectorLleno() const
{
    if (can == tam) {
        return true;
    }
    else { return false; }
}

Mascota* ColeccionMascotas::getMascota(std::string id) const
{
    for (int i = 0; i < can; i++) {
        if (id == vecMascotas[i]->getNumeroDeIdentificacion()) {
            return vecMascotas[i];
        }
    }
    return nullptr;
}

std::string ColeccionMascotas::toString() const
{
    std::stringstream s;
    if (can == 0) {
        s << "No se encuentran mascotas registradas.\n";
    }
    else {
        s << "Mascotas:\n";
        s << "--------------------------------------------------\n";
        for (int i = 0; i < can; i++) {
            if (vecMascotas[i] != nullptr) {
                s << vecMascotas[i]->toString();
                s << "--------------------------------------------------\n";
            }
        }
    }
    return s.str();
}
