#define _CRT_SECURE_NO_WARNINGS
#include "Funciones.h"

//Funciones


float** ConstruirMatriz(int nFilas, int nColumnas)
{
	int i = 0, f = 0, x = 0;
	float** p = NULL;
	p = (float**)malloc(nFilas * sizeof(float*));
	if (p == NULL) return NULL;
	//Asignar memoria a filas
	for (i = 0; i < nFilas; i++)
	{
		p[i] = (float*)malloc(nColumnas * sizeof(float));
		if (p[i] == NULL)
		{
			//liberar memoria asignada hasta ese instante
			//liberar a filas
			for (f = 0; f < i; f++)
				free(p[f]);
			//liberar la matriz de punteros
			free(p);
			return NULL;
		}
		//Iniciar la fila con ceros
		//doble for con filas y columnas
		for (x = 0; x < nColumnas; x++)
		{
				p[i][x] = 0;
		}


	}
	return p;
}

void IntroducirDatos(struct MatFloat* m)
{
	if (m->ppMatrizF == NULL) return;
	int f = 0, c = 0;
	for (f = 0; f < m->nFilas; f++)
	{
		for (c = 0; c < m->nColumnas; c++)
		{
			printf("Introduzca el valor a [%i][%i]: ", f, c); //con %g me sale un warning que se corrige con %i, porq?
			//scanf_s("%f", &(m->ppMatrizF[f][c]));
			m->ppMatrizF[f][c] = LeerFloat();
		}
	}
}

void Mostrar(struct MatFloat m)
{
	if (m.ppMatrizF == NULL) return;
	int f = 0, c = 0;
	for (f = 0; f < m.nFilas; f++)
	{
		for (c = 0; c < m.nColumnas; c++)
			printf("%f ", m.ppMatrizF[f][c]);
		printf("\n");
	}
}

void Destruir(struct MatFloat* m)
{
	if (m->ppMatrizF == NULL) return;
	int f = 0;
	for (f = 0; f < m->nFilas; f++)
		free(m->ppMatrizF[f]); //liberar filas
	free(m->ppMatrizF); //liberar matriz de punteros
	m->ppMatrizF = NULL;
}

int LeerInt()
{
	int error;
	int num;
	do
	{
		cin >> num;
		error = cin.rdstate() & ios::failbit;
		/* ESCRIBA EL CÓDIGO QUE FALTA */
		cin.clear();
		cin.ignore(numeric_limits<int>::max(), '\n');
	} while (error);
	//cin.ignore(numeric_limits<int>::max(), '\n'); // eliminar '\n'
	return num;
}

float LeerFloat()
{
	int error;
	float num;
	do
	{
		cin >> num;
		error = cin.rdstate() & ios::failbit;
		/* ESCRIBA EL CÓDIGO QUE FALTA */
		cin.clear();
		cin.ignore(numeric_limits<int>::max(), '\n');
	} while (error);
	//cin.ignore(numeric_limits<int>::max(), '\n'); // eliminar '\n'
	return num;
}

int CrearMenu(const char* OpMenu[], int num_opciones)
{
	int opcion;
	system("cls"); // limpiar la pantalla
				   // Presentar el menú
	cout << "\nElija una opcion:\n" << endl;
	for (int i = 0; i < num_opciones; i++)
		cout << "\t" << i + 1 << ". " << OpMenu[i] << endl;
	// Elegir una opción y verificar que es correcta
	do
	{
		opcion = LeerInt();
		if (opcion < 1 || opcion > num_opciones)
			cout << "Opcion incorrecta\n" << endl;
	} while (opcion < 1 || opcion > num_opciones);
	return opcion;
}
