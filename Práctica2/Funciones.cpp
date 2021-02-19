#include "Funciones.h"
#include "utils.h"

void CMatFloat::Iniciar()
{
	m_ppDatosF = NULL;
	m_nFilas = 0;
	m_nColumnas = 0;
}

void CMatFloat::CrearMatriz2D(int nFilas, int nColumnas)
{
	int f = 0, i = 0, x = 0;
	m_nFilas = nFilas;
	m_nColumnas = nColumnas;
	//CrearMatriz1D(nFilas);
	m_ppDatosF = (float**) new (nothrow) float* [nFilas];
	//if (m_ppDatosF == NULL) return NULL;
	for (f = 0; f < nFilas; f++)
	{
		m_ppDatosF[f] = (float*) new (nothrow) float[nColumnas];
		if (m_ppDatosF[f] == NULL)
		{
			for (i = 0; i < f; i++)
				delete[] m_ppDatosF[i];
			delete[] m_ppDatosF;
			return;
		}
		for (x = 0; x < nColumnas; x++)
		{
			m_ppDatosF[f][x] = 0;
		}
	}
}

void CMatFloat::CrearMatriz1D(int nElementos)
{
	CrearMatriz2D(1, nElementos);
}

bool CMatFloat::Existe()
{
	if (m_ppDatosF != NULL)
		return true;
	else
		return false;
}

void CMatFloat::Introducir()
{
	if (m_ppDatosF == NULL)
	{
		cout << "No existe matriz, debes crearla" << endl;
		return;
	}
	int f = 0, c = 0;
	for (f = 0; f < m_nFilas; f++)
	{
		for (c = 0; c < m_nColumnas; c++)
		{
			cout << "Introduzca el valor a [" << f << "]["<< c <<"]: ";
			//cin >> m_ppDatosF[f][c];
			m_ppDatosF[f][c] = LeerFloat();
		}
	}
}

void CMatFloat::Mostrar()
{
	if (m_ppDatosF == NULL)
	{
		cout << "No existe matriz, debes crearla" << endl;
		return;
	}
	int f = 0, c = 0;
	for (f = 0; f < m_nFilas; f++)
	{
		for (c = 0; c < m_nColumnas; c++)
			cout << m_ppDatosF[f][c] << "  ";
		cout << endl;
	}
}

void CMatFloat::Destruir()
{
	if (m_ppDatosF == NULL)
	{
		cout << "No existe matriz, debes crearla" << endl;
		return;
	}
	int f = 0;
	for (f = 0; f < m_nFilas; f++)
		delete[] m_ppDatosF[f];
	delete[] m_ppDatosF;
	cout << "Matriz destruida" << endl;
	Iniciar();
}