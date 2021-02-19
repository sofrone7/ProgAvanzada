#include "Funciones.h"
#include "utils.h"

void CMatFloat::Iniciar()
{
	vector<vector<float>> m_ppDatosF(0, vector<float>(0, 0));
}

void CMatFloat::CrearMatriz2D(int nFilas, int nColumnas)
{
	vector<vector<float>> x(nFilas, vector<float>(nColumnas, 0));
	m_ppDatosF = x;
}

void CMatFloat::CrearMatriz1D(int nElementos)
{
	CrearMatriz2D(1, nElementos);
}

void CMatFloat::Introducir()
{
	for (size_t f = 0; f < m_ppDatosF.size(); f++)
	{
		for (size_t c = 0; c < m_ppDatosF[f].size(); c++)
		{
			cout << "Introducir valor al miembro [" << f << "][" << c << "]: ";
			//cin >> v[f][c];
			m_ppDatosF[f][c] = LeerFloat();
		}
	}
}

void CMatFloat::Mostrar()
{
	for (auto v : m_ppDatosF)
	{
		for (auto e : v)
			cout << e << " ";
		cout << endl;
	}
}