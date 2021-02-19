#include "CContrato.h"
#include "MemoryManager.h"
using namespace std;

CContrato::CContrato(int NumSerie, const string& Desc, const string& FF, long Poliza, long ValorCompra)
	: m_NumSerie(NumSerie), m_Descripcion(Desc),
	m_FechaFin(FF), m_Poliza(Poliza), m_ValorCompra(ValorCompra)
{
}

// PREGUNTA 3: constructor copia de la clase CContrato
CContrato::CContrato(const CContrato& c)
{
	*this = c;
}

// CContrato& CContrato::operator =(const CContrato &c)
CContrato& CContrato::operator=(const CContrato& c)
{
	if (this == &c) return *this;
	BorrarSiniestros();			
	//c.m_Siniestros.Restart();

	m_NumSerie = c.m_NumSerie;
	m_Descripcion = c.m_Descripcion;
	m_FechaFin = c.m_FechaFin;
	m_Poliza = c.m_Poliza;
	m_ValorCompra = c.m_ValorCompra;
	while (c.m_Siniestros.TieneMas()) //asignación de m_Siniestros
		m_Siniestros.AgregarObjeto(c.m_Siniestros.GetActual()->Clonar());

	c.m_Siniestros.Restart();
	return *this;
}

// PREGUNTA 4: AgregarSiniestro de la clase CContrato
void CContrato::AgregarSiniestro(const CSiniestro& s)
{
	m_Siniestros.AgregarObjeto(s.Clonar());
}

CContrato::~CContrato()
{
	BorrarSiniestros();
}

// void CContrato::BorrarSiniestros()
void CContrato::BorrarSiniestros()
{
	m_Siniestros.Restart(); 
	//CLista<CSiniestro*> *temp;
	//for (int i = 0; m_Siniestros.TieneMas(); i++)
	while (m_Siniestros.TieneMas())
	{
		//*temp = m_Siniestros.GetActual();
		delete m_Siniestros.GetActual();
		//m_Siniestros = NULL;
	}
	m_Siniestros.Vaciar();
}

void CContrato::MostrarSiniestros(ostream& os)
{
	if (this->m_Siniestros.EstaVacia())
		os << "Contrato sin siniestros" << endl;
	else
	{
		this->m_Siniestros.GetPrimero()->Mostrar(os);
		while (this->m_Siniestros.TieneMas())
			this->m_Siniestros.GetActual()->Mostrar(os);
	}
}


// Necesaria para PREGUNTA 5
ostream& operator<<(ostream& os, CContrato& c)
{
	// ...
	os << "Numero de serie: " << c.m_NumSerie << endl
		<< "Descripcion: " << c.m_Descripcion << endl
		<< "Fecha de finalizacion: " << c.m_FechaFin << endl
		<< "Poliza: " << c.m_Poliza << endl
		<< "Valor de compra: " << c.m_ValorCompra << endl
		<< "Siniestros: " << endl << endl;
	c.MostrarSiniestros(os);
	return os;
}
