#pragma once
#include "CCliente.h"

class CRegistroDiario
{
private:
	int nElementosMax;
	CFicha **personas;
public:
	CRegistroDiario(int nElementosMax = 1);
	~CRegistroDiario();
	CRegistroDiario(const CRegistroDiario& cc);
	CRegistroDiario& operator=(const CRegistroDiario& c);
	//CRegistroDiario& AgregarPersona(CEmpleado& Empleado);
	//CRegistroDiario& AgregarPersona(CEmpleado& Empleado);
	bool AgregarPersona(CFicha& ficha);
	//CRegistroDiario& AgregarPersona(CCliente& Cliente);
	void VisualizarRegistro();
	static bool EsEmpleado(CFicha* persona);
	void VisualizarEmpleados();
	int  GetNumElementosMax(const CRegistroDiario& p);
	void BuscarNombre(const CRegistroDiario& p, string nombre);
	bool RegistroLleno(const CRegistroDiario& p);
	const CFicha* operator[](int indice);
};