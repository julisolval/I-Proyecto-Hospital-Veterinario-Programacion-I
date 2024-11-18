#include "ColeccionHoras.h"

ColeccionHoras::ColeccionHoras() : tam{ 11 }
{
    for (int i = 0; i < tam; i++) {
        vecHoras[i] = new Hora(8 + i, false);
    }
}

ColeccionHoras::~ColeccionHoras()
{
    for (int i = 0; i < tam; i++) {
        delete vecHoras[i]; 
    }
}

bool ColeccionHoras::getHoraCita(int pos) const
{
    return vecHoras[pos]->getHoraCita();
}

int ColeccionHoras::getHora(int pos) const
{
    return vecHoras[pos]->getHora();
}

void ColeccionHoras::sacarCita(int hora)
{
    for (int i = 0; i < tam; i++) {
        if (vecHoras[i]->getHora() == hora) {
            vecHoras[i]->sacarCita();
        }
    }
}

void ColeccionHoras::cancelarCita(int hora)
{
    for (int i = 0; i < tam; i++) {
        if (vecHoras[i]->getHora() == hora) {
            vecHoras[i]->cancelarCita();
        }
    }
}


