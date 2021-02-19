#include "CRegistroDiario.h"

CRegistroDiario::CRegistroDiario(int nElem)
{
	personas.reserve(nElem);
	personas.resize(nElem);
	for (int i = 0; i < personas.size(); i++)
		personas[i] = NULL;
}

CRegistroDiario::~CRegistroDiario()
{
	//personas.clear();
	for (int i = 0; i < personas.size(); i++)
		delete personas[i];
	//delete[] personas;
	//personas = NULL;
}

CRegistroDiario::CRegistroDiario(const CRegistroDiario& cc)
{
	*this = cc;
}

CRegistroDiario& CRegistroDiario::operator=(const CRegistroDiario& c)
{
	if (this == &c) return *this;
	CRegistroDiario::~CRegistroDiario();
	personas.resize(c.personas.size());
	for (int i = 0; i < personas.size(); i++)
	{
		personas[i] = NULL;
	}
	for (int i = 0; i < NumPersonas(c); i++)
	{
		if (c.personas[i] != NULL)
			personas[i] = c.personas[i]->clonar();
	}
	return *this;
}

bool CRegistroDiario::AgregarPersona(CFicha& e)
{
	for (int i = 0; i < personas.size(); i++)
	{
		if (personas[i] == NULL)
		{
			
			personas[i] = e.clonar();
			return true;
		}
	}
	return false;
}

void CRegistroDiario::VisualizarRegistro()
{

	for (int i = 0; i < personas.size(); i++)
	{
		if (personas[i] == NULL) break;
		personas[i]->Visualizar();
	}
}

bool CRegistroDiario::EsEmpleado(CFicha* p)
{
	return dynamic_cast<CEmpleado*>(p) != (NULL);
}

void CRegistroDiario::VisualizarEmpleados()
{
	for (int i = 0; i < personas.size(); i++)
	{
		if (personas[i] != NULL && EsEmpleado(personas[i]))
			personas[i]->Visualizar();
	}
}

void CRegistroDiario::BuscarNombre(const CRegistroDiario& p, string nombre)
{

	for (int i = 0; i < NumPersonas(p); i++)
	{
		if (p.personas[i] != NULL)
		{
			if (p.personas[i]->ObtenerNombre().compare(nombre) == 0)
			{
				p.personas[i]->Visualizar();
				if (EsEmpleado(personas[i]))
				{
					cout << "Es un empleado" << endl;
					return;
				}
				else
				{
					cout << "Es un cliente" << endl;
					return;
				}
			}
		}
	}
	cout << "Este nombre no esta registrado" << endl;
}

int CRegistroDiario::NumPersonas(const CRegistroDiario& p)
{
	int acum = 0;
	for (int i = 0; i < p.personas.size(); i++)
	{
		if (p.personas[i] != NULL)
			acum++;
	}
	return acum;
}