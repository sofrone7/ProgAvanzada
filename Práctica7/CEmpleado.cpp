#include "CEmpleado.h"

//CEmpleado::CEmpleado(const string& sNombre, int nEdad, int nHoras, int nMinutos, int nSegundos, const string & sFormato, const string& sCat, int nAnt) :
	//CFicha{ sNombre, nEdad, nHoras, nMinutos, nSegundos, sFormato }, m_sCategoria{ sCat }, m_nAntiguedad{ nAnt }{} 

void CEmpleado::Visualizar()
{
	CFicha::Visualizar();
	cout << "Categoria: " << m_sCategoria << endl;
	cout << "Antiguedad: " << m_nAntiguedad << endl;
	cout << endl;
}