#pragma once
#include "MemoryManager.h"
#include <iostream>
#include <vector>
#include "utils.h"
using namespace std;

vector<vector<float>> ConstruirMatriz(int nFilas, int nColumnas);
void IntroducirDatos(vector<vector<float>>& v);
void Mostrar(vector<vector<float>>& v);