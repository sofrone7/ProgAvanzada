#include "CCliente.h"
#include <iostream>
using namespace std;

// PREGUNTA 8: AgregarContrato de CCliente
void CCliente::AgregarContrato(const CContrato& c)
{
	m_Contratos.AgregarObjeto(c); // Usamos el metodo de CLista
}




// PREGUNTA 5: operator<< para resolver: cout << unCliente
ostream& operator<<(ostream& os, CCliente& c)
{
	os << "Nombre del Cliente: " << c.GetNombre() << endl
		<< "Contratos:  " << endl << endl;

	c.m_Contratos.Restart();

	while (c.m_Contratos.TieneMas())
		os << c.m_Contratos.GetActual() << endl;

	return os;
}




// PREGUNTA 9: total += seguros[i]
CCliente::operator long()
{
	long temp = 0;
	m_Contratos.Restart();
	while (m_Contratos.TieneMas())
	{
		m_Contratos.GetActual();
		temp++;
	}
	return temp;
}