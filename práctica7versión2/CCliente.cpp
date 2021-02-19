#include "CCliente.h"

void CCliente::Visualizar()
{
	CFicha::Visualizar();
	cout << "DNI: " << m_sDNI << endl;
	cout << endl;
}

CCliente* CCliente::clonar()
{
	CCliente* p = new CCliente(*this);
	return p;
}