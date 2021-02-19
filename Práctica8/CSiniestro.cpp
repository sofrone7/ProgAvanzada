#include "CSiniestro.h"
using namespace std;

// PREGUNTA 6: iniciar m_SigCodigo





// PREGUNTA 10: CSiniestroNormal s("Rotura de tambor");





// PREGUNTA 12: GetCoste
void CSiniestro::Mostrar(ostream &os) const
{
  os << " Codigo del siniestro: " << m_Codigo << endl
    << " Descripcion de la averia: " << m_Descripcion << endl
    << " Horas de mano de obra: " << m_HorasMO << endl
    << " Coste de las piezas: " << m_CostePiezas << endl
    << " Coste total de reparacion: " << m_Coste << endl;
}
