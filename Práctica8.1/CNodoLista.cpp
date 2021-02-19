#if !defined(_CNODOLISTA_CPP)
#define _CNODOLISTA_CPP

//#include <iostream>
using namespace std;

#include "CNodoLista.h"
#include "CLista.h"

template<class T>
CNodoLista<T>::CNodoLista(const T& Obj, CNodoLista<T> *pNodo)
: m_Dato(Obj), m_pSigNodo(pNodo)
{
}

template<class T>
CNodoLista<T>::CNodoLista(const CNodoLista<T> &NodoLista)
{
  *this = NodoLista;
}

template<class T>
CNodoLista<T>& CNodoLista<T>::operator=(const CNodoLista<T>& NodoLista)
{
}

#endif