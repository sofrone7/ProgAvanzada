#if !defined(_CEMPRESA_CPP)
#define _CEMPRESA_CPP
#include "CEmpresa.h"

template<class T>
CEmpresa<T>::CEmpresa(const CEmpresa<T>& a) {
	*this = a;
}

// Operador =
template<class T>
CEmpresa<T>& CEmpresa<T>::operator=(const CEmpresa& a)
{
	m_nElem = a.m_nElem;
	if (m_pElem != NULL)
	{
		delete[] m_pElem;
		m_pElem = NULL;
	}
	m_pElem = new (nothrow) T[m_nElem];
	if (m_pElem == NULL)
		exit(-1); 
	for (int i = 0; i < m_nElem; i++)
		m_pElem[i] = a.m_pElem[i];	
	return *this;
}


// Destructor
template<class T>
CEmpresa<T>::~CEmpresa()
{
	if (m_pElem != NULL)
	{
		delete[] m_pElem;
		m_pElem = NULL;
	}
}


// AgregarElemento
template<class T>
void CEmpresa<T>::AgregarElemento(const T& elem)
{
	T* temp;
	m_nElem++;

	temp = new (nothrow) T[m_nElem];
	if (temp == NULL)
		exit(-1);	
	for (int i = 0; i < (m_nElem - 1); i++) // COPIAMOS TODOS LOS ELEMENTOS
		temp[i] = m_pElem[i];
	temp[m_nElem - 1] = elem; // METEMOS NUEVO ELEMENTO AL FINAL
	delete[] m_pElem;	// Borramos memoria reservada
	m_pElem = temp;		// Apuntamos m_pElem a la nueva memoria reservada
}


// GetElemento
template<class T>
T& CEmpresa<T>::GetElemento(int nElem) const
{
	return m_nElem[nElem];
}


// Operador de indexación: []
template<class T>
T& CEmpresa<T>::operator[](int nElem) const
{
	if (Tamanyo() < nElem || nElem < 0)
		throw CIndiceIncorrecto("Indice no almacenado");
	return m_pElem[nElem];
}
#endif