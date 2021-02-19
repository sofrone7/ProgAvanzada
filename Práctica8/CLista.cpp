#include <iostream>
#include "MemoryManager.h"
// #include "CIndiceIncorrecto.h"
using namespace std;

//template<class T>
//CLista<T>::CLista()




//template <class T>
//CLista<T>::CLista(const CLista<T> &Lista)





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
  if(EstaVacia())
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





// PREGUNTA 1: CLista<T>::Vaciar




template<class T> void CLista<T>::Restart() const
{
  const_cast<CLista *>(this)->m_Actual = m_Primero;
}

template<class T>
CLista<T>::~CLista()
{
  Vaciar();
}
