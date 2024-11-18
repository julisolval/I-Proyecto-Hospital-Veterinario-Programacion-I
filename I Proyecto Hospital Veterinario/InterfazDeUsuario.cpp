#include "InterfazDeUsuario.h"

ColeccionEspecialidades* InterfazDeUsuario::vecEspecialidades = new ColeccionEspecialidades();
Especialidad* InterfazDeUsuario::especialidad = new Especialidad();

ColeccionDoctores* InterfazDeUsuario::vecDoctores = new ColeccionDoctores();
Doctor* InterfazDeUsuario::doctor = new Doctor();

ColeccionDuenios* InterfazDeUsuario::vecDuenios = new ColeccionDuenios();
Duenio* InterfazDeUsuario::duenio = new Duenio();

ColeccionMascotas* InterfazDeUsuario::vecMascotas = new ColeccionMascotas();
Mascota* InterfazDeUsuario::mascota = new Mascota();

ColeccionDias* InterfazDeUsuario::dias = new ColeccionDias();
ColeccionCita* InterfazDeUsuario::citas = new ColeccionCita();

void InterfazDeUsuario::bienvenidaUsuario()
{
	std::cout << "Bienvenido(a) al menu principal...\n";
	Sleep(3000);
	system("cls");
}

void InterfazDeUsuario::MenuPrincipal()
{
	int op;
	bienvenidaUsuario();
	do {
		std::cout << "---------MENU PRINCIPAL---------\n";
		std::cout << "1- Submenu Administracion\n";
		std::cout << "2- Submenu Control de Citas\n";
		std::cout << "3- Submenu Busquedas y Listados\n";
		std::cout << "4- Salir\n";
		std::cout << "---------------------------------\n";
		std::cout << "Ingrese la opcion: "; std::cin >> op;
		system("cls");

		if (op >= 1 && op <= 4) {
			switch (op) {
			case 1:
				subMenuAdministracion();
				break;

			case 2:
				submenuControlDeCitas();
				break;

			case 3:
				submenuBusquedasYListados();
				break;

			case 4:
				std::cout << "Saliendo del programa...\n";
				Sleep(3000);
				system("cls");
				break;
			}
		}
		else {
			std::cout << "Error! Numero ingresado no se encuentra en las opciones, intentelo de nuevo.\n ";
			Sleep(3000);
			system("cls");
		}
	} while (op != 4);
}

void InterfazDeUsuario::subMenuAdministracion()
{
	int op;
	std::cout << "Ingresando al submenu administracion...\n";
	Sleep(3000);
	system("cls");
	do {
		std::cout << "---------Submenu Administracion---------\n";
		std::cout << "(1) Ingresar Especialidades\n";
		std::cout << "(2) Ingresar Doctor (por especialidad)\n";
		std::cout << "(3) Ingresar Duenio\n";
		std::cout << "(4) Ingresar Mascota (por duenio)\n";
		std::cout << "(0) Regresar  al Menu Principal\n";
		std::cout << "----------------------------------------\n";
		std::cout << "Ingrese la opcion: "; std::cin >> op;
		system("cls");

		if (op >= 0 && op <= 4) {
			switch (op) {
			case 1:
				venCreaEspecialidad();
				break;
			case 2:
				venCreaDoctor(vecEspecialidades, dias);
				break;
			case 3:
				venCreaDuenio();
				break;
			case 4:
				venCreaMascota(vecDuenios);
				break;
			case 0:
				std::cout << "Regresando al menu principal...\n";
				Sleep(3000);
				system("cls");
				break;
			}
		}
		else {
			std::cout << "Error! Numero ingresado no se encuentra en las opciones, intentelo de nuevo.\n ";
			Sleep(3000);
			system("cls");
		}
	} while (op != 0);
}

void InterfazDeUsuario::venCreaEspecialidad()
{
	std::string nomEspecialidad;
	if (vecEspecialidades->vectorLleno()) {
		std::cout << "No se pueden registrar mas especialidades. Vector lleno!\n";
	}
	else {
		std::cout << "1- Ingresar Especialidades\n\n";
		std::cin.ignore();
		std::cout << "Ingrese una especialidad: "; std::getline(std::cin, nomEspecialidad);
		especialidad = new Especialidad(nomEspecialidad, vecDoctores);

		if (vecEspecialidades->ingresaEspecialidad(especialidad)) {
			std::cout << "\nSe ha registrado la especialidad con exito.\n";
		}
		else {
			std::cout << "\nError al registrar especialidad. Especialidad ya existente.\n";
			delete especialidad;
		}
	}
	Sleep(4000);
	system("cls");
}

void InterfazDeUsuario::venCreaDoctor(ColeccionEspecialidades* vecEspecialidades, ColeccionDias* horario)
{
	std::string nombre, cedula, especialidadDr, respuesta;
	if (vecEspecialidades->cantidadDeEspecialidades()) {
		std::cout << "2-Ingresar Doctor (por especialidad)\n\n";
		std::cin.ignore();

		std::cout << "Estas son las especialidades registradas:\n";
		std::cout << vecEspecialidades->toString();

		std::cout << "\nLa especialidad del doctor ya se encuentra registrada? (Si/No) "; std::getline(std::cin, respuesta);
		if (respuesta.length() == 2 && std::toupper(respuesta.at(0)) == 'S') {

			std::cout << "\nIngrese la especialidad del doctor: "; std::getline(std::cin, especialidadDr);

			if (vecEspecialidades->yaExisteEspecialidad(especialidadDr)) {
				if (vecEspecialidades->vectorLlenoDoc(especialidadDr)) {
					std::cout << "No se pueden registrar mas doctores en esta especialidad. Vector lleno!\n";
				}
				else {
					std::cout << "Ingrese el numero de cedula del doctor: "; std::getline(std::cin, cedula);
					if (vecEspecialidades->yaExisteElDoctor(cedula)) {
						std::cout << "\nError al registrar doctor. Doctor ya existente!\n";
					}
					else {
						std::cout << "Ingrese el nombre del doctor: "; std::getline(std::cin, nombre);
						doctor = new Doctor(nombre, cedula, horario);
						especialidad = vecEspecialidades->getEspecialidad(especialidadDr);
						especialidad->ingresaDoctores(doctor);
						std::cout << "\nSe ha registrado el doctor con exito.\n";
					}
				}
			}
			else {
				std::cout << "\nError al registrar doctor. Antes de crear al doctor debe crear la especialidad a elegir.\n";
			}
		}
		else if (respuesta.length() == 2 && std::toupper(respuesta.at(0)) == 'N') {
			std::cout << "\nError al registrar doctor. Antes de crear al doctor debe crear la especialidad a elegir.\n";
		}
		else {
			std::cout << "\nError al registrar doctor, respuesta no valida. Solo responder: Si/No.\n";
		}
	}
	else {
		std::cout << "Para registrar un doctor debe ingresar antes una especialidad.\n";
	}
	Sleep(4000);
	system("cls");
}

void InterfazDeUsuario::venCreaDuenio()
{
	std::string nombre, numeroTelefonico, cedula;
	if (vecDuenios->vectorLleno()) {
		std::cout << "No se pueden registrar mas duenios(as) de mascotas. Vector lleno!\n";
	}
	else {
		std::cout << "3- Ingresar Duenio\n\n";
		std::cin.ignore();
		std::cout << "Ingrese la cedula del duenio: "; std::getline(std::cin, cedula);

		if (vecDuenios->yaExisteElDuenio(cedula)) {
			std::cout << "\nError al registrar duenio(a) de la mascota. Duenio(a) ya existente.\n";
		}
		else {
			std::cout << "Ingrese el nombre del duenio: "; std::getline(std::cin, nombre);
			std::cout << "Ingrese el numero telefonico del duenio: "; std::getline(std::cin, numeroTelefonico);
			duenio = new Duenio(nombre, numeroTelefonico, cedula, vecMascotas);
			vecDuenios->ingresaDuenio(duenio);
			std::cout << "\nSe ha registrado a el/la duenio(a) de la mascota con exito.\n";
		}
	}
	Sleep(4000);
	system("cls");
}

void InterfazDeUsuario::venCreaMascota(ColeccionDuenios* vecDuenios)
{
	std::string numeroDeIdentificacion, nombre, tipoDeMascota, raza, respuesta, cedula;
	if (vecDuenios->cantidadDeDuenios()) {
		std::cout << "4- Ingresar Mascota (por duenio)\n\n";
		std::cin.ignore();

		std::cout << "Estos son los/las duenios(as) registrados(as):\n";
		std::cout << vecDuenios->toString(); 
		 
		std::cout << "\nSe encuentra el/la duenio(a) de la mascota registrada? (Si/No) "; std::getline(std::cin, respuesta);
		if (respuesta.length() == 2 && std::toupper(respuesta.at(0)) == 'S') {
			std::cout << "Ingrese la cedula de el/la duenio(a) de la mascota: "; std::getline(std::cin, cedula);

			if (vecDuenios->yaExisteElDuenio(cedula)) {
				if (vecDuenios->vectorLlenoMascota(cedula)) {
					std::cout << "No se pueden registrar mas mascotas en este duenio. Vector lleno!\n";
				}
				else {
					std::cout << "Ingrese el numero de identificacion de la mascota: "; std::getline(std::cin, numeroDeIdentificacion);
					if (vecDuenios->yaExisteLaMascota(numeroDeIdentificacion)) {
						std::cout << "\nError al registrar mascota. Mascota ya existente.\n";
					}
					else {
						std::cout << "Ingrese el nombre de la mascota: "; std::getline(std::cin, nombre);
						std::cout << "Ingrese el tipo de mascota: "; std::getline(std::cin, tipoDeMascota);
						std::cout << "Ingrese la raza de la mascota: "; std::getline(std::cin, raza);
						mascota = new Mascota(numeroDeIdentificacion, nombre, tipoDeMascota, raza);
						duenio = new Duenio(*vecDuenios->getDuenio(cedula));
						duenio->ingresaMascota(mascota);
						std::cout << "\nSe ha registrado la mascota con exito.\n";
					}
				}
			}
			else {
				std::cout << "\nError al registrar mascota. Antes de crear la mascota debe registrar a su duenio(a).\n";
			}
		}
		else if (respuesta.length() == 2 && std::toupper(respuesta.at(0)) == 'N') {
			std::cout << "\nError al registrar mascota. Antes de crear la mascota debe registrar a su duenio(a).\n";
		}
		else {
			std::cout << "\nError al registrar mascota, respuesta no valida. Solo responder: Si/No.\n";
		}
	}
	else {
		std::cout << "Para registrar una mascota debe ingresar antes un(a) duenio(a).\n";
	}
	Sleep(4000);
	system("cls");
}

void InterfazDeUsuario::submenuControlDeCitas()
{
	int op;
	std::cout << "Ingresando al submenu control de citas...\n";
	Sleep(3000);
	system("cls");

	do {
		std::cout << "-----------Submenu Control Citas------------\n";
		std::cout << "(1) Sacar Cita\n";
		std::cout << "(2) Cancelar Cita\n";
		std::cout << "(3) Mostrar Calendario de Citas por Doctor\n";
		std::cout << "(4) Mostrar Citas por Duenio\n";
		std::cout << "(0) Regresar  al Menu Principal\n";
		std::cout << "---------------------------------------------\n";
		std::cout << "Ingrese la opcion: "; std::cin >> op;
		system("cls");

		if (op >= 0 && op <= 4) {
			switch (op) {
			case 1:
				venSacarCita(vecMascotas, vecDuenios, vecDoctores, vecEspecialidades, citas);
				break;
			case 2:
				venCancelarCita();
				break;
			case 3:
				std::cout << "Mostrando Calendario de Citas por Doctor...\n";
				Sleep(3000);
				system("cls");
				if (citas->existenCitas()){
					std::cout << vecEspecialidades->toStringHorarioDoc();
				}
				else {
					std::cout << "No existen citas aun.\n";
				}
				system("pause");
				system("cls");
				break;
			case 4:
				venMostrarCitasPorDuenio();
				system("pause");
				system("cls");
				break;
			case 0:
				std::cout << "Regresando al menu principal...\n";
				Sleep(3000);
				system("cls");
				break;
			}
		}
		else {
			std::cout << "Error! Numero ingresado no se encuentra en las opciones, intentelo de nuevo.\n ";
			Sleep(3000);
			system("cls");
		}
	} while (op != 0);

}

void InterfazDeUsuario::venSacarCita(ColeccionMascotas* vecMascotas, ColeccionDuenios* vecDuenios, ColeccionDoctores* vecDoctores, ColeccionEspecialidades* vecEspecialidades, ColeccionCita* citas)
{
	std::string id, idm, respuesta, especialidad, idd, diaDeLaSemana, idCita;
	int hora;
	Duenio* duenio;
	Mascota* mascota;
	Especialidad* especialidadDr;
	Doctor* doctor;
	Cita* cita;

	if (vecDuenios->cantidadDeDuenios()) {
		std::cout << "(1) Sacar Cita\n\n";
		std::cin.ignore();
		std::cout << vecDuenios->toString();
		std::cout << "Ingrese la cedula del duenio que quiere agendar una cita: "; std::getline(std::cin, id);
		if (vecDuenios->yaExisteElDuenio(id) != true) {
			std::cout << "\nError! Duenio(a) no ha sido registrado en el sistema.\n";
		}
		else {
			duenio = vecDuenios->getDuenio(id);
			if (vecDuenios->cantidadDeMascotas(id)) {
				std::cout << std::endl << vecDuenios->toStringMascotasDeDuenio(id);

				std::cout << "\nSe encuentra la mascota a elegir? (Si/No) "; std::getline(std::cin, respuesta);
				if (respuesta.length() == 2 && std::toupper(respuesta.at(0)) == 'S') {
					std::cout << "Ingrese el numero de identificacion de la mascota: "; std::getline(std::cin, idm);
					
					if (vecDuenios->yaExisteLaMascotaEnDuenio(id, idm)) {
						mascota = vecDuenios->getMascota(id, idm);

						std::cout << "\nEstas son las especialidades registradas:\n";
						std::cout << vecEspecialidades->toString();

						std::cout << "\nLa especialidad del doctor ya se encuentra registrada? (Si/No) "; std::getline(std::cin, respuesta);
						if (respuesta.length() == 2 && std::toupper(respuesta.at(0)) == 'S') {

							std::cout << "\nIngrese la especialidad del doctor: "; std::getline(std::cin, especialidad);

							if (vecEspecialidades->yaExisteEspecialidad(especialidad) && vecEspecialidades->cantidadDeDoctores(especialidad)) {
								especialidadDr = vecEspecialidades->getEspecialidad(especialidad);
								std::cout << vecEspecialidades->toStringDoctoresPorEspecialidad(especialidad);

								std::cout << "\nSe encuentra el doctor a elegir registrado en " << especialidad << "? (Si/No) "; std::getline(std::cin, respuesta);
								if (respuesta.length() == 2 && std::toupper(respuesta.at(0)) == 'S') {
									std::cout << "\nIngrese la cedula de el/la doctor(a): "; std::getline(std::cin, idd);

									if (vecEspecialidades->yaExisteElDoctor(idd)) {
										doctor = vecEspecialidades->getDoctor(especialidad, idd);
										system("cls");

										std::cout << vecEspecialidades->toStringHorarioDocEspecifico(idd, especialidad);
										
										std::cout << "Ingrese el dia de la semana en el que desea agendar su cita: "; std::getline(std::cin, diaDeLaSemana);
										std::cout << "Ingrese la hora en que desea agendar su cita: "; std::cin >> hora;
										if (diaDeLaSemana != "Lunes" || diaDeLaSemana != "Martes" || diaDeLaSemana != "Miercoles" || diaDeLaSemana != "Jueves" || diaDeLaSemana != "Viernes" || diaDeLaSemana != "Sabado") {
											if (hora >= 8 || hora <= 18) {
												hora -= 8;
												if (vecEspecialidades->getHoraCita(hora, diaDeLaSemana, idd, especialidad) == false) {
													hora += 8;
													vecEspecialidades->sacarCita(hora, diaDeLaSemana, idd, especialidad);
													cita = new Cita(doctor, especialidadDr, duenio, mascota, diaDeLaSemana, hora);
													if (citas->agregarCita(cita)) {
														std::cout << "Cita agendada exitosamente!\n";
													}
													else {
														std::cout << "Error al agendar la cita.\n";
													}
												}
												else {
													std::cout << "El horario elegido esta ocupado, solo debe elegir horarios disponibles.\n";
												}
											}
											else {
												std::cout << "Error! Hora ingresada no se encuentra entre las opciones.\n";
											}
										}
										else if (diaDeLaSemana == "Domingo") {
											std::cout << "Lo sentimos, la clinica veterninaria se encuentra cerrada los domingos. Intente agendar su cita otro dia de la semana!\n";
										}
										else {
											std::cout << "Error! Debes ingresar un dia de la semana.\n";
										}
									}
									else {
										std::cout << "\nAntes de asignar una cita, debe registar el doctor(a) a elegir.\n";
									}
								}
								else if (respuesta.length() == 2 && std::toupper(respuesta.at(0)) == 'N') {
									std::cout << "\nAntes de asignar una cita, debe registar el doctor(a) a elegir.\n";
								}
								else {
									std::cout << "\nError, respuesta no valida. Solo responder: Si/No.\n";
								}
							}
							else {
								std::cout << "\nAntes de asignar una cita, debe registar la especialidad a elegir.\n";
							}
						}
						else if (respuesta.length() == 2 && std::toupper(respuesta.at(0)) == 'N') {
							std::cout << "\nAntes de asignar una cita, debe registar la especialidad a elegir.\n";
						}
						else {
							std::cout << "\nError, respuesta no valida. Solo responder: Si/No.\n";
						}
					}
					else {
						std::cout << "Antes de asignar una cita, deben haber mascotas, duenios(as) y doctores(ras) en el sistema.\n";

					}
				}
				else if (respuesta.length() == 2 && std::toupper(respuesta.at(0)) == 'N') {
					std::cout << "\nAntes de asignar una cita, debe registar la mascota a elegir.\n";
				}
				else {
					std::cout << "\nError, respuesta no valida. Solo responder: Si/No.\n";
				}
				}
			else{
				std::cout << "\nAntes de asignar una cita, debe registar la mascota a elegir.\n";
			}
		}
	}
	else {
		std::cout << "Antes de asignar una cita, deben haber mascotas, duenios(as) y doctores(ras) en el sistema.\n";
	}
	Sleep(4000);
	system("cls");
}

void InterfazDeUsuario::venCancelarCita() {
	std::string cedula, numMascota, idDoc, diaDeLaSemana, especialidad;
	int hora;

	if (vecDuenios->cantidadDeDuenios()) {
		std::cout << "(2) Cancelar Cita\n";
		std::cin.ignore();
		std::cout << vecDuenios->toString();
		std::cout << "Ingrese la cedula del duenio que quiere cancelar una cita: "; std::getline(std::cin, cedula);
		if (vecDuenios->yaExisteElDuenio(cedula) != true) {
			std::cout << "\nError! Duenio(a) no ha sido registrado en el sistema.\n";
		}
		else {
			vecDuenios->toStringMascotasDeDuenio(cedula);
			std::cout << "Ingrese el numero de identificacion de la mascota de la que desee cancelar la cita: "; std::getline(std::cin, numMascota);

			if (vecDuenios->yaExisteLaMascotaEnDuenio(cedula, numMascota) != true) {
				std::cout << "\nError! Mascota no ha sido registrado en el sistema.\n";
			}
			else {
				if (citas->existenCitasPorDuenio(cedula, numMascota)) {
					std::cout << citas->toStringCitasPorDuenio(cedula, numMascota);
					std::cout << "Ingrese la especialidad del doctor: "; std::getline(std::cin, especialidad);
					std::cout << "Ingrese la cedula del doctor: "; std::getline(std::cin, idDoc);
					if (vecEspecialidades->yaExisteElDoctor(idDoc) != true && vecEspecialidades->yaExisteEspecialidad(especialidad) != true) {
						std::cout << "\nError! Doctor no ha sido registrado en el sistema.\n";
					}
					else {

						std::cout << "Ingrese el dia de la semana de la cita a elegir: "; std::getline(std::cin, diaDeLaSemana);
						std::cout << "Ingrese la hora de su cita: "; std::cin >> hora;
						if (diaDeLaSemana != "Lunes" || diaDeLaSemana != "Martes" || diaDeLaSemana != "Miercoles" || diaDeLaSemana != "Jueves" || diaDeLaSemana != "Viernes" || diaDeLaSemana != "Sabado") {
							if (hora >= 8 || hora <= 18) {
								hora -= 8;
								if (vecEspecialidades->getHoraCita(hora, diaDeLaSemana, idDoc, especialidad) == true) {
									hora += 8;
									vecEspecialidades->cancelarCita(hora, diaDeLaSemana, idDoc, especialidad);
									if (citas->cancelarCita(cedula, numMascota, idDoc, especialidad, hora, diaDeLaSemana)) {
										std::cout << "Cita cancelada exitosamente!\n";
									}
									else {
										std::cout << "Error al cancelar la cita.\n";
									}
								}
								else {
									std::cout << "El horario elegido esta disponible, solo debe elegir horarios ocupados.\n";
								}
							}
							else {
								std::cout << "Error! Hora ingresada no se encuentra entre las opciones.\n";
							}
						}
						else if (diaDeLaSemana == "Domingo") {
							std::cout << "Lo sentimos, la clinica veterninaria se encuentra cerrada los domingos. Intente cancelar su cita otro dia de la semana!\n";
						}
						else {
							std::cout << "Error! Debes ingresar un dia de la semana.\n";
						}
					}
				}
				else {
					std::cout << "La mascota elegida no cuenta con citas disponibles!\n";
				}
			}
		}
	}
	else {
		std::cout << "Antes de cancelar una cita, deben haber mascotas, duenios(as) y doctores(ras) en el sistema.\n";
	}
	Sleep(4000);
	system("cls");
}

void InterfazDeUsuario::venMostrarCitasPorDuenio() {
	std::string id, numId;

	if (citas->existenCitas()) {
		std::cout << "Mostrando Citas por Duenio...\n";
		Sleep(3000);
		system("cls");
		std::cout << vecDuenios->toString();
		std::cin.ignore();
		std::cout << "Ingrese la cedula del duenio del que desee visualizar la cita: "; std::getline(std::cin, id);

		std::cout << std::endl << vecDuenios->toStringMascotasDeDuenio(id);
		std::cout << "Ingrese el numero de identificacion de la mascota de la que desee visualizar la cita: "; std::getline(std::cin, numId);
		if (citas->existenCitasPorDuenio(id, numId)) {
			std::cout << citas->toStringCitasPorDuenio(id, numId);
		}
		else {
			std::cout << "Mascota no tiene citas disponibles.\n";
		}
	}
	else {
		std::cout << "No existen citas aun." << std::endl;
	}
}

void InterfazDeUsuario::submenuBusquedasYListados()
{
	int op;

	std::cout << "Ingresando al submenu busquedas y listados...\n";
	Sleep(3000);
	system("cls");

	do {
		std::cout << "---------Busquedas y Listados-------------------\n";
		std::cout << "(1) Mostrar Listado de Especialidades\n";
		std::cout << "(2) Mostrar Listado de Doctores por Especialidad\n";
		std::cout << "(3) Mostrar Duenios con sus Mascotas\n";
		std::cout << "(4) Mostrar Pacientes por Doctor\n";
		std::cout << "(0) Regresar  al Menu Principal\n";
		std::cout << "------------------------------------------------\n";
		std::cout << "Ingrese la opcion: "; std::cin >> op;
		system("cls");

		if (op >= 0 && op <= 4) {
			switch (op) {
			case 1:
				std::cout << "Mostrando Listado de Especialidades...\n\n";
				Sleep(3000);
				system("cls");
				std::cout << vecEspecialidades->toString();
				system("pause");
				system("cls");
				break;
			case 2:
				std::cout << "Mostrando Listado de Doctores por Especialidad...\n\n";
				Sleep(3000);
				system("cls");
				std::cout << vecEspecialidades->toStringCompleto();
				system("pause");
				system("cls");
				break;
			case 3:
				std::cout << "Mostrando Duenios con sus Mascotas...\n\n";
				Sleep(3000);
				system("cls");
				std::cout << vecDuenios->toStringCompleto();
				system("pause");
				system("cls");
				break;
			case 4:
				venMostrarPacientesPorDoctor();
				system("pause");
				system("cls");
				break;
			case 0:
				std::cout << "Regresando al menu principal...\n";
				Sleep(3000);
				system("cls");
				break;
			}
		}
		else {
			std::cout << "Error! Numero ingresado no se encuentra en las opciones, intentelo de nuevo.\n ";
			Sleep(3000);
			system("cls");
		}
	} while (op != 0);

}

void InterfazDeUsuario::venMostrarPacientesPorDoctor()
{
	std::string id;
	std::cout << "(4) Mostrar Pacientes por Doctor...\n";
	Sleep(3000);
	system("cls");
	if (citas->existenCitas()) {
		std::cout << vecEspecialidades->toStringCompleto();
		std::cin.ignore();
		std::cout << "Ingrese la cedula del doctor del que desee visualizar sus pacientes: "; std::getline(std::cin, id);

		if (citas->existenCitasPorDoctor(id)) {
			std::cout << citas->toStringCitasPorDoctor(id);
		}
		else {
			std::cout << "El doctor no cuenta con citas registradas aun.\n";
		}
	}
	else {
		std::cout << "No existen citas aun." << std::endl;
	}
}
