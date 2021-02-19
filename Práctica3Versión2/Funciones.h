#pragma once
#include "MemoryManager.h"
#include <iostream>
#include <cstring>
#include <string>
using namespace std;


class CHora
{
private:
	int m_nHoras; // AM/PM: 1 a 12, 24 HORAS: 0 a 23
	int m_nMinutos; // AM/PM/24 HORAS: 0 a 59
	int m_nSegundos; // AM/PM/24 HORAS: 0 a 59
	std::string m_sFormato; //almacena los valores "AM", "PM" o "24 HORAS"
	bool Formato24() const;
	// Devuelve true si el formato es "24 HORAS".
	// En otro caso, devuelve false.
protected:
	bool EsHoraCorrecta() const;
	// Verifica si una hora es correcta:
	// 1) verificar que el formato es 24 HORAS, AM o PM
	// 2) y verificar que las horas, minutos y segundos están dentro
	// de los límites según el formato sea o no 24 HORAS.
	// Devuelve true si es correcta y false en otro caso.
public:
	void Iniciar();
	// Será invocada cada vez que se defina un objeto.
	// Pone a 0 todos los atributos de CHora.
	bool AsignarHora(int nHoras,
		int nMinutos,
		int nSegundos,
		string pszFormato);
	// Recibe 4 argumentos, correspondientes a una hora,
	// y los almacena en las variables
// m_nHoras, m_nMinutos, m_nSegundos y m_pszFormato
// correspondientes al objeto que recibe el mensaje.
// Invoca a AsignarFormato y a EsHoraCorrecta.
// Devuelve false si no pudo ser asignado el formato
// o el valor retornado por EsHoraCorrecta.
	void ObtenerHora(int& nHoras,
		int& nMinutos,
		int& nSegundos,
		string& pszFormato) const;
	// Obtener una hora. Permite obtener los datos hora,
	// minutos, segundos y formato correspondientes
	// al objeto que recibe el mensaje.
};
void VisualizarHora(const CHora& hora);