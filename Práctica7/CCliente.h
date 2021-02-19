#pragma once
#include "CEmpleado.h"

class CCliente : public CFicha
{
private:
	string m_sDNI; //eje: "12345678V"
public:
	//CCliente(const string& sDNI = " ")
		//: m_sDNI(sDNI) {}
	CCliente(const string& sNombre = " ", int nEdad = 0, int nHoras = 12, int nMinutos = 0, int nSegundos = 0, const string & sFormato = "AM", const string & sDNI= " ")
		:CFicha{ sNombre, nEdad, nHoras, nMinutos, nSegundos, sFormato }, m_sDNI{ sDNI }{}

	void SetDNI(const string& sDNI) { m_sDNI = sDNI; }
	void Visualizar() override;
	CCliente* clonar() { return new CCliente(*this); }
};