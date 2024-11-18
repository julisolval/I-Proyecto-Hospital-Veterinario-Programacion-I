#include "Duenio.h"

Duenio::Duenio() : nombreDuenio{ "Indef" }, numeroTelefonico{ "Indef" }, cedula{ "Indef" }, vecMascotas{ new ColeccionMascotas() } {}

Duenio::Duenio(std::string nombreDuenio, std::string numeroTelefonico, std::string cedula, ColeccionMascotas* vecMascotas)
{
	this->nombreDuenio = nombreDuenio;
	this->numeroTelefonico = numeroTelefonico;
	this->cedula = cedula;
	this->vecMascotas = new ColeccionMascotas(*vecMascotas);
}

Duenio::~Duenio() {
	if (vecMascotas != nullptr) delete vecMascotas;
}

void Duenio::setNombreDuenio(std::string nombreDuenio)
{
	this->nombreDuenio = nombreDuenio;
}

void Duenio::setNumeroTelefonico(std::string numeroTelefonico)
{
	this->numeroTelefonico = numeroTelefonico;
}

void Duenio::setCedula(std::string cedula)
{
	this->cedula = cedula;
}

void Duenio::setVecMascotas(ColeccionMascotas* vecMascotas)
{
	this->vecMascotas = new ColeccionMascotas(*vecMascotas);
}

std::string Duenio::getNombreDuenio() const
{
	return this->nombreDuenio;
}

std::string Duenio::getNumeroTelefonico() const
{
	return this->numeroTelefonico;
}

std::string Duenio::getCedula() const
{
	return this->cedula;
}

ColeccionMascotas* Duenio::getVecMascotas() const
{
	return this->vecMascotas;
}

bool Duenio::ingresaMascota(Mascota* mascota) const
{
	return vecMascotas->ingresaMascota(mascota);
}

bool Duenio::yaExisteLaMascota(std::string id) const
{
	return vecMascotas->yaExisteLaMascota(id);
}

bool Duenio::vectorLlenoMascota() const
{
	return vecMascotas->vectorLleno();
}

bool Duenio::cantidadDeMascotas() const
{
	return vecMascotas->cantidadDeMascotas();
}

Mascota* Duenio::getMascota(std::string id) const
{
	return vecMascotas->getMascota(id);
}

std::string Duenio::toString() const
{
	std::stringstream s;
	s << "\nCedula: " << cedula << std::endl; 
	s << "Nombre del duenio: " << nombreDuenio << std::endl;
	return s.str();
}

std::string Duenio::toStringMascotasDeDuenio() const
{
	std::stringstream s;
	s << vecMascotas->toString();
	return s.str();
}

std::string Duenio::toStringCompleto() const
{
	std::stringstream s;
	s << "-------------INFORMACION DUENIO-------------------\n";
	s << "Cedula: " << cedula << std::endl;
	s << "Nombre del duenio: " << nombreDuenio << std::endl;
	s << "Numero telefonico: " << numeroTelefonico << std::endl;
	s << "--------------------------------------------------\n";
	s << vecMascotas->toString();
	return s.str();
}
