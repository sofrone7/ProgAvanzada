#include "CSiniestro.h"
using namespace std;

CSiniestro::CSiniestro(const std::string& Desc) : m_Descripcion(Desc), m_Codigo(0), m_HorasMO(0), m_CostePiezas(0), m_Coste(0)
{}
// PREGUNTA 6: iniciar m_SigCodigo
int CSiniestro::m_SigCodigo = 1;




// PREGUNTA 10: CSiniestroNormal s("Rotura de tambor");
CSiniestro::CSiniestro(int Cod, float HorasMO, float CostePiezas, float Coste, const std::string& Desc):
	m_Codigo(Cod), m_HorasMO(HorasMO), m_CostePiezas(CostePiezas), m_Coste(Coste), m_Descripcion(Desc)
{

}




// PREGUNTA 12: GetCoste

void CSiniestro::Mostrar(ostream& os) const
{
	os << " Codigo del siniestro: " << m_Codigo << endl
		<< " Descripcion de la averia: " << m_Descripcion << endl
		<< " Horas de mano de obra: " << m_HorasMO << endl
		<< " Coste de las piezas: " << m_CostePiezas << endl
		<< " Coste total de reparacion: " << m_Coste << endl;
	//GetCoste();
}