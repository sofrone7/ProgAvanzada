#pragma once
#if !defined (_CINDICEINCORRECTO_H)
#define _CINDICEINCORRECTO_H

#include <string>
#include <iostream>

using namespace std;

class CIndiceIncorrecto // PAG 411 // 
{
private:
	string mensajeDeError;

public:
	CIndiceIncorrecto(string mensaje = "Valor incorrecto") : mensajeDeError(mensaje) {}
	string what() const { return mensajeDeError; }
};

#endif