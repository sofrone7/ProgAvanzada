#include "CRegistroDiario.h"

CRegistroDiario::CRegistroDiario(int nElem)
{
	const char* sdato = "El numero de elementos es <= 0";
	nElementosMax = nElem;
	try
	{
		if (nElementosMax <= 0) throw sdato;
	}
	catch (const char* e)
	{
		cout << e << endl;
		system("pause");
		exit(-1);
	}
	{
		personas = (CFicha**) new (nothrow) CFicha* [nElem];
		if (personas == NULL)
		{
			cout << "Error de asignacion de memoria";
			return; 
		}
		for (int i = 0; i < nElem; i++)
		{
			//personas[i] = (CFicha*) new CFicha[1]; //en agregar personas 
			personas[i] = NULL;
		}
	}
}

CRegistroDiario::~CRegistroDiario()
{
	if (personas == NULL)
	{
		return;
	}
	for (int i = 0; i < nElementosMax; i++)
		delete personas[i];
	delete[] personas;
	personas = NULL;
}

CRegistroDiario::CRegistroDiario(const CRegistroDiario& cc)
{
	*this = cc;
}

CRegistroDiario& CRegistroDiario::operator=(const CRegistroDiario& c)
{
	if (this == &c) return *this;
	
	CRegistroDiario::~CRegistroDiario();
	nElementosMax = c.nElementosMax;
	personas = (CFicha**) new CFicha*[nElementosMax];
	for (int i = 0; i < nElementosMax; i++)
	{
		//personas[i] = (CFicha*) new CFicha[1]; //en agregar personas 
		personas[i] = NULL;
	}
	//CRegistroDiario aux;
	//personas = c.personas;
	for (int i = 0; i < GetNumElementosMax(c); i++)
	{
		if(c.personas[i] != NULL)
			personas[i] = c.personas[i]->clonar();
	}
	return *this;
}

bool CRegistroDiario::AgregarPersona(CFicha& e)
{
	for (int i = 0; i < nElementosMax; i++)
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
	
	for (int i = 0; i < nElementosMax; i++)
	{
		if (personas[i] == NULL) break;
		personas[i]->Visualizar();
	}
}

bool CRegistroDiario::EsEmpleado(CFicha* p)
{
	return dynamic_cast<CEmpleado *>(p) != (NULL);
}

void CRegistroDiario::VisualizarEmpleados()
{
	for (int i = 0; i < nElementosMax; i++)
	{
		if (personas[i] != NULL && EsEmpleado(personas[i]))
			personas[i]->Visualizar();
	}
}

int CRegistroDiario::GetNumElementosMax(const CRegistroDiario& p)
{
	int aux = 0;
	for (int i = 0; i < nElementosMax; i++)
	{
		if (p.personas[i] != NULL)
			aux++;
		else
			return aux;
	}
}

void CRegistroDiario::BuscarNombre(const CRegistroDiario& p, string nombre)
{
	
	for (int i = 0; i < GetNumElementosMax(p); i++)
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
	cout << "Este nombre no esta registrado" << endl;
}

bool CRegistroDiario::RegistroLleno(const CRegistroDiario& p)
{
	if (GetNumElementosMax(p) == p.nElementosMax)
		return true;
	else
		return false;
}

const CFicha* CRegistroDiario::operator[](int i)
{
	if ((i > -1) && (i <= GetNumElementosMax(*this)) && (personas[i] != NULL))
	{
		//if(personas[i] != NULL)
			//personas[i]->Visualizar();
		return personas[i];
	}
	else cout << "Este indice no esta registrado" << endl;
}