#include "Mascota.h"
Mascota::Mascota() :numeroDeIdentificacion{ "Indef" }, nombre{ "Indef" }, tipoDeMascota{ "Indef" }, raza{ "Indef" } {}

Mascota::Mascota(std::string numeroDeIdentificacion, std::string nombre, std::string tipoDeMascota, std::string raza)
{
    this->numeroDeIdentificacion = numeroDeIdentificacion;
    this->nombre = nombre;
    this->tipoDeMascota = tipoDeMascota;
    this->raza = raza;
}

Mascota::~Mascota(){}

void Mascota::setNumeroDeIdentificacion(std::string numeroDeIdentificacion)
{
    this->numeroDeIdentificacion = numeroDeIdentificacion;
}

void Mascota::setNombre(std::string nombre)
{
    this->nombre = nombre;
}

void Mascota::setTipoDeMascota(std::string tipoDeMascota)
{
    this->tipoDeMascota = tipoDeMascota;
}

void Mascota::setRaza(std::string raza)
{
    this->raza = raza;
}

std::string Mascota::getNumeroDeIdentificacion() const
{
    return this->numeroDeIdentificacion;
}

std::string Mascota::getNombre() const
{
    return this->nombre;
}

std::string Mascota::getTipoDeMascotas() const
{
    return this->tipoDeMascota;
}

std::string Mascota::getRaza() const
{
    return this->raza;
}

std::string Mascota::toString() const
{
    std::stringstream s;
    s << "Numero de Identifiacion de la mascota: " << numeroDeIdentificacion << std::endl;
    s << "Nombre de la mascota: " << nombre << std::endl;
    s << "Tipo de mascota: " << tipoDeMascota << std::endl;
    s << "Raza: " << raza << std::endl;
    return s.str();
}