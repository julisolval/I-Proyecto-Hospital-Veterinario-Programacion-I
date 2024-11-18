#include "Cita.h"

Cita::Cita() : doctor{ new Doctor() }, especialidad{ new Especialidad() }, duenio{ new Duenio() }, mascota{ new Mascota() }, diaDeLaSemana{ "Indef" }, hora{ 0 } {}


Cita::Cita(Doctor* doctor, Especialidad* especialidad, Duenio* duenio, Mascota* mascota, std::string diaDeLaSemana, int hora) {
    this->doctor = doctor;
    this->especialidad = especialidad;
    this->duenio = duenio;
    this->mascota = mascota;
    this->diaDeLaSemana = diaDeLaSemana;
    this->hora = hora;
}


Cita::~Cita() {}

void Cita::setDoctor(Doctor* doctor) {
    this->doctor = doctor;
}

void Cita::setEspecialidad(Especialidad* especialidad) {
    this->especialidad = especialidad;
}

void Cita::setDuenio(Duenio* duenio) {
    this->duenio = duenio;
}

void Cita::setMascota(Mascota* mascota) {
    this->mascota = mascota;
}

void Cita::setDia(std::string diaDeLaSemana) {
    this->diaDeLaSemana = diaDeLaSemana;
}

void Cita::setHora(int hora) {
    this->hora = hora;
}

Doctor* Cita::getDoctor() const {
    return this->doctor;
}

Especialidad* Cita::getEspecialidad() const {
    return this->especialidad;
}

Duenio* Cita::getDuenio() const {
    return this->duenio;
}

Mascota* Cita::getMascota() const {
    return this->mascota;
}

std::string Cita::getDiaDeLaSemana() const {
    return this->diaDeLaSemana;
}

int Cita::getHora() const {
    return this->hora;
}

std::string Cita::getCedulaDuenio() const
{
    return duenio->getCedula();
}

std::string Cita::getNumeroDeIdentificacionMascota() const
{
    return mascota->getNumeroDeIdentificacion();
}

std::string Cita::getCedulaDoc() const
{
    return doctor->getCedula();
}

std::string Cita::getNombreEspecialidad() const
{
    return especialidad->getEspecialidad();
}

std::string Cita::toString() const {
    std::stringstream s;
    s << "--------------------------------------------------\n";
    s << "Cita del " << diaDeLaSemana << " a las " << hora << ":00\n";
    s << "--------------------------------------------------\n";
    s << "Info Doctor:\n";
    s << "Especialidad: " << especialidad->getEspecialidad() << std::endl;
    s << "ID: " << doctor->getCedula() << std::endl;
    s << "Nombre: " << doctor->getNombreDoctor() << std::endl << std::endl;

    s << "Info Duenio:\n";
    s << "ID: " << duenio->getCedula() << std::endl;
    s << "Nombre: " << duenio->getNombreDuenio() << std::endl << std::endl;
    
    s << "Info Mascota:\n";
    s << "Numero de Identificacion: " << mascota->getNumeroDeIdentificacion() << std::endl;
    s << "Nombre: " << mascota->getNombre() << std::endl;
    s << "--------------------------------------------------\n";
    return s.str();
}