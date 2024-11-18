#include "ColeccionDias.h"

ColeccionDias::ColeccionDias() : tam{ 6 }
{
    time_t t = time(&t);
    tm tiempoLocal;
    localtime_s(&tiempoLocal, &t);

    int diaS = tiempoLocal.tm_wday;
    if (diaS == 0) {
        tiempoLocal.tm_mday += 1;
    }
    else {
        tiempoLocal.tm_mday -= (diaS - 1);
    }
    
    std::string s[] = { "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado" };

    for (int i = 0; i < tam; i++) {
        vecDias[i] = new Dia(s[i], new ColeccionHoras());
        vecDias[i]->setDia(tiempoLocal.tm_mday);
        tiempoLocal.tm_mday++;
        mktime(&tiempoLocal);
    }
}

ColeccionDias::~ColeccionDias()
{
    for (int i = 0; i < tam; i++) {
        delete vecDias[i];
    }
}

bool ColeccionDias::getHoraCita(int pos, std::string diaDeLaSemana) const
{
    for (int i = 0; i < tam; i++) {
        if (vecDias[i]->getDiaDeLaSemana() == diaDeLaSemana) {
            return vecDias[i]->getHoraCita(pos);
        }
    }
    return false;
}

void ColeccionDias::sacarCita(int hora, std::string diaDeLaSemana)
{
    for (int i = 0; i < tam; i++) {
        if (vecDias[i]->getDiaDeLaSemana() == diaDeLaSemana) {
            vecDias[i]->sacarCita(hora);
        }
    }
}

void ColeccionDias::cancelarCita(int hora, std::string diaDeLaSemana)
{
    for (int i = 0; i < tam; i++) {
        if (vecDias[i]->getDiaDeLaSemana() == diaDeLaSemana) {
            vecDias[i]->cancelarCita(hora);
        }
    }
}

std::string ColeccionDias::toString() const
{
    std::stringstream s;
    s << "-------------------\n";
    s << vecDias[0]->getMes() << ", " << vecDias[0]->getAnio() << ". |";
    s << "\n----------------------------------------------------------------------------------------------------\n";
    s << "Horas:   |";
    for (int i = 0; i < tam; ++i) {
        if (vecDias[i]->getDiaDeLaSemana() == "Lunes") {
            s << " " << vecDias[i]->getDiaDeLaSemana() << " ";
            if (vecDias[i]->getDia() >= 10) {
                s << vecDias[i]->getDia() << "     |";
            }
            else {
                s << vecDias[i]->getDia() << "      |";
            }

        }
        else if (vecDias[i]->getDiaDeLaSemana() == "Martes" || vecDias[i]->getDiaDeLaSemana() == "Jueves" || vecDias[i]->getDiaDeLaSemana() == "Sabado") {
            s << " " << vecDias[i]->getDiaDeLaSemana() << " ";
            if (vecDias[i]->getDia() >= 10) {
                s << vecDias[i]->getDia() << "     |";
            }
            else {
                s << vecDias[i]->getDia() << "      |";
            }
        }
        else if (vecDias[i]->getDiaDeLaSemana() == "Miercoles") {
            s << " " << vecDias[i]->getDiaDeLaSemana() << " ";
            if (vecDias[i]->getDia() >= 10) {
                s << vecDias[i]->getDia() << "     |";
            }
            else {
                s << vecDias[i]->getDia() << "      |";
            }
        }
        else {
            s << " " << vecDias[i]->getDiaDeLaSemana() << " ";
            if (vecDias[i]->getDia() >= 10) {
                s << vecDias[i]->getDia() << "     |";
            }
            else {
                s << vecDias[i]->getDia() << "      |";
            }
        }
    }
    s << "\n----------------------------------------------------------------------------------------------------\n";
    
   for (int i = 0; i < 11; i++) {
        if (vecDias[0]->getHora(i) < 10) {
            s << vecDias[0]->getHora(i) << ":00     | ";
        }
        else {
            s << vecDias[0]->getHora(i) << ":00    | ";
        }
        for (int j = 0; j < tam; ++j) {
            s << (vecDias[j]->getHoraCita(i) ? "Ocupado      | " : "Disponible   | ");
        }
   s << "\n----------------------------------------------------------------------------------------------------\n";
   }
    return s.str();
}
