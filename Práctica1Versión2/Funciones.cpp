#include "Funciones.h"

vector<vector<float>> ConstruirMatriz(int nFilas, int nColumnas)
{
	vector<vector<float>> v(nFilas, vector<float>(nColumnas, 0));
	return v;
}

void IntroducirDatos(vector<vector<float>>& v)
{
	for (size_t f = 0; f < v.size(); f++)
	{
		for (size_t c = 0; c < v[f].size(); c++)
		{
			cout << "Introducir valor al miembro [" << f << "][" << c << "]: ";
			//cin >> v[f][c];
			v[f][c] = LeerFloat();
		}
	}
}

void Mostrar(vector<vector<float>>& v)
{
	for (auto v : v)
	{
		for (auto e : v)
			cout << e << " ";
		cout << endl;
	}
}