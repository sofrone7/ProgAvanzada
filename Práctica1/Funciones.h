#pragma once
#include "MemoryManager.h"
#include <stdio.h>
#include <stdlib.h> //system(cls)

struct MatFloat
{
	int nFilas; // N�mero de filas
	int nColumnas; // N�mero de columnas
	float** ppMatrizF; // Datos de la matriz
};



int menu(); //declaracion funcion menu
float** ConstruirMatriz(int nFilas, int nColumnas);
void IntroducirDatos(struct MatFloat *ppMatrizF);
void Mostrar(struct MatFloat mOrigen);
void Destruir(struct MatFloat *pMatFloat);


