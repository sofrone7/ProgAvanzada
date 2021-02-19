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
	std::string m_pszFormato; //almacena los valores "AM", "PM" o "24 HORAS"
	//bool AsignarFormato(char* pszFormato);
	// Verifica que pszFormato no es nulo.
	// Copia en m_pszFormato el formato dado por pszFormato,
	// asignando la cantidad de memoria necesaria, y lo convierte
	// a may�sculas. Si fuera necesario, previamente se liberar�
	// la memoria que hubiera asignada. Devuelve true si la
	// operaci�n se realiza con �xito y false en caso contrario.
	bool Formato24() const;
	// Devuelve true si el formato es "24 HORAS".
	// En otro caso, devuelve false.
protected:

public:
	//CHora(int h, int m, int s, char* f); //constructor 
	CHora(int h = 0, int m = 0, int s = 0, std::string = "24 HORAS");
	CHora& operator=(const CHora& c);
	CHora(const CHora& ca);
	~CHora();
	//~CHora();
	//void Iniciar();
	// Ser� invocada cada vez que se defina un objeto.
	// Pone a 0 todos los atributos de CHora.
	bool EsHoraCorrecta() const;
	// Verifica si una hora es correcta:
	// 1) verificar que el formato es 24 HORAS, AM o PM
	// 2) y verificar que las horas, minutos y segundos est�n dentro
	// de los l�mites seg�n el formato sea o no 24 HORAS.
	// Devuelve true si es correcta y false en otro caso.
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
	//void Destruir();
	// Libera la memoria reservada din�micamente para un objeto y
	// pone el puntero m_pszFormato a cero.
};
void VisualizarHora(const CHora& hora);