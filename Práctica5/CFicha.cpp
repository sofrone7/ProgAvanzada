#define _CRT_SECURE_NO_WARNINGS
#include "CHora.h"
#include "CFicha.h"
#include "utils.h"
#include <clocale> 
using namespace utils;

CFicha::CFicha(const string& sNombre, int nEdad, int nHoras, int nMinutos, int nSegundos, const string& sFormato)
{
	//m_sNombre = sNombre; m_nEdad = nEdad; m_horaNacio; { nHoras, nMinutos, nSegundos, sFormato; };
	bool correcto;
	AsignarNombre(sNombre);
	AsignarEdad(nEdad);
	correcto = AsignarNacio(nHoras, nMinutos, nSegundos, sFormato);
	if (correcto == 0)
		cout << "Datos incorrectos, pruebe otra vez" << endl;
}

void CFicha::AsignarNombre(const string& sNombre)
{
	m_sNombre = sNombre;
}

string CFicha::ObtenerNombre() const
{
	return m_sNombre;
}

void CFicha::AsignarEdad(int nEdad)
{
	m_nEdad = nEdad;
}

int CFicha::ObtenerEdad() const
{
	return m_nEdad;
}

bool CFicha::AsignarNacio(int nHoras, int nMinutos, int nSegundos, const string& sFormato)
{
	//m_horaNacio; { nHoras, nMinutos, nSegundos, sFormato; };
	return m_horaNacio.AsignarHora(nHoras, nMinutos, nSegundos, sFormato);

}

CHora& CFicha::ObtenerNacio() 
{
	return m_horaNacio;
}

void VisualizarFicha(CFicha& ficha)
{
	int edad;
	string nombre;
	CHora m;
	nombre = ficha.ObtenerNombre();
	edad = ficha.ObtenerEdad();
	m = ficha.ObtenerNacio();
	cout << "nombre: " << nombre << endl;
	cout << "edad: " << edad << endl;
	cout << "nacio a las";
	VisualizarHora(m);
}
