#pragma once
#include "ColeccionCita.h"
#include "Windows.h"


class InterfazDeUsuario
{
private:
	static ColeccionEspecialidades* vecEspecialidades;
	static Especialidad* especialidad;

	static ColeccionDoctores* vecDoctores;
	static Doctor* doctor;

	static ColeccionDuenios* vecDuenios;
	static Duenio* duenio;

	static ColeccionMascotas* vecMascotas;
	static Mascota* mascota;

	static ColeccionDias* dias;
	static ColeccionCita* citas;
public:
	static void bienvenidaUsuario();

	static void MenuPrincipal();

	static void subMenuAdministracion();

	static void venCreaEspecialidad();
	static void venCreaDoctor(ColeccionEspecialidades*, ColeccionDias*);
	static void venCreaDuenio();
	static void venCreaMascota(ColeccionDuenios*);

	static void submenuControlDeCitas();
	
	static void venSacarCita(ColeccionMascotas*, ColeccionDuenios*, ColeccionDoctores*, ColeccionEspecialidades*, ColeccionCita*);
	static void venCancelarCita();
	static void venMostrarCitasPorDuenio();

	static void submenuBusquedasYListados();
	static void venMostrarPacientesPorDoctor();
};

