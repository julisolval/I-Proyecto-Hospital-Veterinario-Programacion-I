#pragma once
#include "ColeccionEspecialidades.h"
#include "ColeccionDuenios.h"

class Cita {
private:
    Doctor* doctor;
    Especialidad* especialidad;
    Duenio* duenio;
    Mascota* mascota;
    std::string diaDeLaSemana;
    int hora;

public:
    Cita();
    Cita(Doctor*, Especialidad*, Duenio*, Mascota*, std::string, int);
    ~Cita();

    void setDoctor(Doctor*);
    void setEspecialidad(Especialidad*);
    void setDuenio(Duenio*);
    void setMascota(Mascota*);
    void setDia(std::string);
    void setHora(int);

    
    Doctor* getDoctor() const;
    Especialidad* getEspecialidad() const;
    Duenio* getDuenio() const;
    Mascota* getMascota() const;
    std::string getDiaDeLaSemana() const;
    int getHora() const;

    std::string getCedulaDuenio() const;
    std::string getNumeroDeIdentificacionMascota() const;
    std::string getCedulaDoc() const;
    std::string getNombreEspecialidad() const;
    
    
    std::string toString() const;
};
