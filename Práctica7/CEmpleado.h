#pragma once
#include "CHora.h"
#include "CFicha.h"

class CEmpleado : public CFicha 
{
private:
	string m_sCategoria;
	int m_nAntiguedad;
public:
	//CEmpleado(const string& sCat = " ", int nAnt = 0)
		//: m_sCategoria(sCat), m_nAntiguedad(nAnt) {}
	CEmpleado(const string& sNombre = " ", int nEdad = 0, int nHoras = 12, int nMinutos = 0, int nSegundos = 0, const string & sFormato = "AM", const string & sCat = " ", int nAnt = 0)
		:CFicha{ sNombre, nEdad, nHoras, nMinutos, nSegundos, sFormato }, m_sCategoria{ sCat }, m_nAntiguedad{ nAnt }{}

	void SetCategoria(const string& sCategoria) { m_sCategoria = sCategoria; }
	void SetAntiguedad(int nAntiguedad) { m_nAntiguedad = nAntiguedad; }
	void Visualizar() override;
	CEmpleado* clonar() { return new CEmpleado(*this); }
};