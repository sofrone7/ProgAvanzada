#include "CContrato.h"
#include "MemoryManager.h"
using namespace std;

CContrato::CContrato(int NumSerie, const string& Desc, const string& FF, long Poliza, long ValorCompra)
  : m_NumSerie(NumSerie), m_Descripcion(Desc),
  m_FechaFin(FF), m_Poliza(Poliza), m_ValorCompra(ValorCompra)
{
}

// PREGUNTA 3: constructor copia de la clase CContrato




// CContrato& CContrato::operator =(const CContrato &c)





// PREGUNTA 4: AgregarSiniestro de la clase CContrato





CContrato::~CContrato()
{
  BorrarSiniestros();
}

// void CContrato::BorrarSiniestros()




void CContrato::MostrarSiniestros(ostream& os)
{
  if (this->m_Siniestros.EstaVacia())
    os << "Contrato sin siniestros." << endl;
  else
  {
    this->m_Siniestros.GetPrimero()->Mostrar(os);
    while (this->m_Siniestros.TieneMas())
      this->m_Siniestros.GetActual()->Mostrar(os);
  }
}


// Necesaria para PREGUNTA 5
ostream& operator<<(ostream& os,  CContrato& c)
{
  // ...


  c.MostrarSiniestros();
  return os;
}
