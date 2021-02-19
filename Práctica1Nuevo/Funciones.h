#pragma once
#include "MemoryManager.h"
#include <stdio.h>
#include <stdlib.h> //system(cls)
#include <iostream>
using namespace std;

struct MatFloat
{
	int nFilas; // N�mero de filas
	int nColumnas; // N�mero de columnas
	float** ppMatrizF; // Datos de la matriz
};


float** ConstruirMatriz(int nFilas, int nColumnas);
void IntroducirDatos(struct MatFloat* ppMatrizF);
void Mostrar(struct MatFloat mOrigen);
void Destruir(struct MatFloat* pMatFloat);
int LeerInt();
float LeerFloat();
int CrearMenu(const char* OpMenu[], int num_opciones);

