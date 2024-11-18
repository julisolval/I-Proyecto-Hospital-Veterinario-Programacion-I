#include "ColeccionDuenios.h"

ColeccionDuenios::ColeccionDuenios() : can{ 0 }, tam{ 8 } 
{
	for (int i = 0; i < tam; i++) {
		vecDuenios[i] = nullptr;
	}
}

ColeccionDuenios::~ColeccionDuenios()
{
	for (int i = 0; i < can; i++) {
		if (vecDuenios[i] != nullptr) {
			delete vecDuenios[i];
		}
	}
	delete[] vecDuenios;
}

bool ColeccionDuenios::ingresaDuenio(Duenio* duenio)
{
	if (yaExisteElDuenio(duenio->getCedula()) == false) {
		if (can < tam) {
			vecDuenios[can++] = duenio;
			return true;
		}
		else
			return false;
	}
	else return false;
}

bool ColeccionDuenios::yaExisteElDuenio(std::string cedula) const
{
	for (int i = 0; i < can; i++) {
		if (vecDuenios[i] != nullptr) {
			if (vecDuenios[i]->getCedula() == cedula) {
				return true;
			}
		}
	}
	return false;
}

bool ColeccionDuenios::cantidadDeDuenios() const
{
	if (can != 0) {
		return true;
	}
	else { return false; }
}

bool ColeccionDuenios::vectorLleno() const
{
	if (can == tam) {
		return true;
	}
	else { return false; }
}

bool ColeccionDuenios::ingresaMascota(Mascota* mascota, std::string cedula)
{
	return getDuenio(cedula)->ingresaMascota(mascota);
}

bool ColeccionDuenios::yaExisteLaMascota(std::string id) const
{
	for (int i = 0; i < can; i++) {
		if (vecDuenios[i] != nullptr) {
			if (vecDuenios[i]->yaExisteLaMascota(id)) {
				return true;
			}
		}
	}
	return false;
}

bool ColeccionDuenios::yaExisteLaMascotaEnDuenio(std::string id, std::string numId) const
{
	for (int i = 0; i < can; i++) {
		if (vecDuenios[i]->getCedula() == id) {
			return vecDuenios[i]->yaExisteLaMascota(numId);
		}
	}
	return false;
}

bool ColeccionDuenios::vectorLlenoMascota(std::string cedula) const
{
	for (int i = 0; i < can; i++) {
		if (vecDuenios[i] != nullptr) {
			return getDuenio(cedula)->vectorLlenoMascota();
		}
	}
	return false;
}

bool ColeccionDuenios::cantidadDeMascotas(std::string cedula) const
{
	for (int i = 0; i < can; i++) {
		if (vecDuenios[i] != nullptr) {
			return getDuenio(cedula)->cantidadDeMascotas();
		}
	}
	return false;
}

Duenio* ColeccionDuenios::getDuenio(std::string cedula) const
{
	for (int i = 0; i < can; i++) {
		if (cedula == vecDuenios[i]->getCedula()){
			return vecDuenios[i];
		}
	}
	return nullptr;
}

Mascota* ColeccionDuenios::getMascota(std::string cedula, std::string id) const
{
	return getDuenio(cedula)->getMascota(id);
}

std::string ColeccionDuenios::toString() const
{
	std::stringstream s;
	if (can == 0) {
		s << "No hay duenios de mascotas ingresados aun.\n";
	}
	else {
		for (int i = 0; i < can; i++) {
			if (vecDuenios[i] != nullptr) {
				s << "--------------------------------------------------";
				s << vecDuenios[i]->toString();
				s << "--------------------------------------------------\n";
			}
		}
	}
	return s.str();
}

std::string ColeccionDuenios::toStringMascotasDeDuenio(std::string cedula) const
{
	std::stringstream s;
	for (int i = 0; i < can; i++) {
		if (cedula == vecDuenios[i]->getCedula()) {
			s << vecDuenios[i]->toStringMascotasDeDuenio();
		}
	}
	return s.str();
}

std::string ColeccionDuenios::toStringCompleto() const
{
	std::stringstream s;
	if (can == 0) {
		s << "No hay duenios de mascotas ingresados aun.\n";
	}
	else {
		for (int i = 0; i < can; i++) {
			if (vecDuenios[i] != nullptr) {
				s << vecDuenios[i]->toStringCompleto() << std::endl;
			}
		}
	}
	return s.str();
}