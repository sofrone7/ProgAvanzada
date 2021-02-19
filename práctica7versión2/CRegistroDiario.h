#pragma once
#include "CCliente.h"
#include <vector>

class CRegistroDiario
{
private:
	vector<CFicha *> personas;
public:
	CRegistroDiario(int nElementosMax);
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
	void BuscarNombre(const CRegistroDiario& p, string nombre);
	int NumPersonas(const CRegistroDiario& p);
};