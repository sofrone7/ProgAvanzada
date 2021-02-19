#pragma once
#if !defined(_EMPRESA_H)
#include "CCliente.h"
#define _EMPRESA_H
using namespace std;

template <class T>
class CEmpresa
{
private:
	CCliente* m_pElem;
	int m_nElem;
public:
	CEmpresa() : m_nElem(0), m_pElem(NULL) {};
	CEmpresa(const CEmpresa& a);
	CEmpresa& operator=(const CEmpresa& a);
	~CEmpresa();
	//void AgregarElemento(const CCliente& elem);
	void AgregarElemento(const T& elem);
	int Tamanyo() const { return m_nElem; }
	//CCliente& GetElemento(int nElem) const;
	T& GetElemento(int nElem) const;
	//CCliente& operator[](int nElem) const;
	T& operator[](int nElem) const;
};


// PREGUNTA 14: plantilla para CEmpresa
#include "Cempresa.cpp"

#endif