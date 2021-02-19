
#define _CRT_SECURE_NO_WARNINGS
#include "Funciones.h"

//Funciones
int menu()
{
	int op;
	do // sentencia repetitiva
	{
		system("cls");
		printf("\n"
			"\t01.- Construir matriz\n"
			"\t02.- Introducir matriz\n"
			"\t03.- Volcar matriz\n"
			"\t04.- Destruir matriz\n"
			"\t05.- Terminar\n"
			"\n"
			"Elija una opcion: ");
		scanf_s("%d", &op);
		if (op < 1 || op > 5) // sentencia condicional
		{
			// printf("Opción no válida\n");
			printf("Opci%cn no v%clida\n", 0xA2, 0xA0);
			system("pause"); // detenerse hasta pulsar una tecla
		}
	} while (op < 1 || op > 5); // condición
	return op;
}

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
		//for (x = 0; x < nFilas; x++)
			//p[x] = NULL;

		
	}
	return p;
}

void IntroducirDatos(struct MatFloat *m)
{
	if (m->ppMatrizF == NULL) return;
	int f = 0, c = 0;
	for (f = 0; f < m->nFilas; f++)
	{
		for (c = 0; c < m->nColumnas; c++)
		{
			printf("Introduzca el valor a [%i][%i]: ", f, c); //con %g me sale un warning que se corrige con %i, porq?
			scanf_s("%f", &(m->ppMatrizF[f][c]));
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

void Destruir(struct MatFloat *m)
{
	if (m->ppMatrizF == NULL) return;
	int f = 0;
	for (f = 0; f < m->nFilas; f++)
		free(m->ppMatrizF[f]); //liberar filas
	free(m->ppMatrizF); //liberar matriz de punteros
	m->ppMatrizF = NULL;
}