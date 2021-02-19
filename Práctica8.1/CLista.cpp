#if !defined(_CLISTA_CPP)
#define _CLISTA_CPP

#include <iostream>
#include "MemoryManager.h"
#include "CLista.h"

#include "CIndiceIncorrecto.h"
using namespace std;

template<class T> 
CLista<T>::CLista()
{
	m_Primero = m_Actual = m_Ultimo = NULL;
}




template<class T>
CLista<T>::CLista(const CLista<T>& Lista)
{
	*this = Lista;
}





template <class T> 
CLista<T>& CLista<T>::operator=(const CLista<T>& Lista)
{
  Vaciar();
  if(!Lista.EstaVacia())
  {
    m_Actual = m_Ultimo = m_Primero = new CNodoLista<T>(Lista.GetPrimero());
    while(Lista.TieneMas())
    {
      m_Actual->SetSigNodo(new CNodoLista<T>(Lista.GetActual()));
      m_Ultimo = m_Actual = m_Actual->GetSigNodo();
    }
  }
  return *this;
}


template <class T>
void CLista<T>::AgregarObjeto(const T& Obj)
{
	if (EstaVacia())
		m_Primero = m_Actual = m_Ultimo = new CNodoLista<T>(Obj);
	else
	{
		m_Ultimo->SetSigNodo(new CNodoLista<T>(Obj));
		m_Ultimo = m_Ultimo->GetSigNodo();
	}
}

template <class T>
T& CLista<T>::GetActual() const
{
  CNodoLista<T> *temp = m_Actual;
  const_cast<CLista<T>*>(this)->m_Actual = m_Actual->GetSigNodo();
  return temp->GetDato();
}

template <class T>
T& CLista<T>::GetPrimero() const
{
  // PREGUNTA 11
  const_cast<CLista<T>*>(this)->m_Actual = m_Primero->GetSigNodo();
  return m_Primero->GetDato();
}


// PREGUNTA 2: operator[] de CLista. Lanza CIndiceIncorrecto.
template <class T>
CNodoLista<T>& CLista<T>::operator[](int i) const
{
	this->Restart();
	if (i < 0)
		throw CIndiceIncorrecto("El indice esta fuera de los limites");
	else
	{
		for (unsigned int j = 0; j < i; j++) 
		{
			const_cast<CLista*> (this)->m_Actual = m_Actual->GetSigNodo();
			if (TieneMas() == false)
				throw CIndiceIncorrecto("El indice esta fuera de los limites");
		}
		CNodoLista<T>* temp = m_Actual;
		this->Restart();
		return *temp;
	}

}

// PREGUNTA 1:
template<class T> void CLista<T>::Vaciar()
{
	CNodoLista<T>* temp;
	if (!EstaVacia())
	{
		m_Actual = m_Primero;

		while (m_Actual) //while (TieneMas())
		{
			temp = m_Actual;
			m_Actual = temp->GetSigNodo();
			delete temp;
		}
		m_Actual = m_Primero = m_Ultimo = NULL;
	}
}

template<class T> void CLista<T>::Restart() const
{
  const_cast<CLista *>(this)->m_Actual = m_Primero;
}


template<class T> CLista<T>::~CLista()
{
  Vaciar();
}

template<class T> bool CLista<T>::EstaVacia() const
{
	return m_Primero == NULL;
}

template<class T> bool CLista<T>::TieneMas() const
{
	return m_Actual != NULL;
}

#endif