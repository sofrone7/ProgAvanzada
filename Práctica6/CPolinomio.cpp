#include "CPolinomio.h"

CPolinomio::CPolinomio(const CPolinomio& poli) :
	m_pCabecera(NULL)
{
	(*this) = poli;
}

CPolinomio::CPolinomio(double dCoef, int nExp)
{
	m_pCabecera = NULL;
	if (dCoef != 0)
	{
		m_pCabecera = new CTermino(dCoef, nExp);
	}
}

CPolinomio::CPolinomio(vector<CMonomio>& mon)
{
	int i = 0;
	m_pCabecera = NULL;
	for (i = 0; i < mon.size(); i++)
	{
		(*this) << CMonomio(mon[i].GetCoef(), mon[i].GetExp());
	}
}

CPolinomio::CPolinomio(const CMonomio& mon)
{
	m_pCabecera = NULL;
	if (mon.GetCoef() != 0)
	{
		m_pCabecera = new CTermino(mon);
	}
}

CPolinomio::~CPolinomio()
{
	while (m_pCabecera != NULL) //mientras no sea el último monomio
	{
		CTermino* pPos = m_pCabecera;
		m_pCabecera = m_pCabecera->GetSig();
		delete pPos;
	}
}

const CPolinomio& CPolinomio::operator= (const CPolinomio& poli)
{
	if (this == &poli) //evitar auto-asignaciión
	{
		return *this;
	}
	//poli.CPolinomio::~CPolinomio(); //llamada explícita al destructor
	while (m_pCabecera != NULL) //en caso de que no esté vacío? mientras no sea el último monomio
	{
		CTermino* pPos = m_pCabecera;
		m_pCabecera = m_pCabecera->GetSig();
		delete pPos;
	}
	CTermino* p = poli.m_pCabecera;
	while (p != NULL)
	{
		*this << p->GetMono(); //this apunta a A
		p = p->GetSig();
	}
	return poli; //en caso de estar vacío
}

void CPolinomio::MostrarPoli(ostream& os) const
{
	const CTermino* pPos = m_pCabecera;

	if (pPos) do
	{
		os << pPos->GetMono() << ' '; 
		pPos = pPos->GetSig();
	} while (pPos); else
		os << "0 ";
}

CPolinomio& CPolinomio::operator<<(const CMonomio& mon)
{
	double suma;
	if (mon.GetCoef() != 0)
	{
		if (m_pCabecera == NULL)
		{
			m_pCabecera = new CTermino(mon);
		}
		else
		{
			bool fin = false;
			CTermino* pPos = m_pCabecera;
			CTermino* pPosAnt = m_pCabecera;

			while (!fin && (pPos != NULL))
			{
				if (mon.GetExp() > pPos->GetExp())
				{
					CTermino* p_new = new CTermino(mon);
					if (pPos == pPosAnt) //si es mayor que el primer mon se coloca al principio
					{
						m_pCabecera = p_new;
						p_new->SetSig(pPos);
					}
					else {
						p_new->SetSig(pPos);
						pPosAnt->SetSig(p_new);
					}
					fin = true;

				}
				else

					if (mon.GetExp() == pPos->GetExp())
					{
						suma = pPos->GetCoef() + mon.GetCoef();
						if (suma != 0)
						{
							pPos->SetCoef(suma); //se queda en la misma posición pero con nuevo coeficiente de la suma
						}
						else //si la suma es 0
						{
							if (pPos == pPosAnt) //si los exp que coinciden son del grado del primer mon y la suma da 0 se borrará el primer mon, por lo tanto:
							{
								m_pCabecera = m_pCabecera->GetSig(); //el primer mon pasa a ser al que estaba apuntando el borrado (el siguiente)
								delete pPos;
								pPos = NULL;
							}
							else
							{
								pPosAnt->SetSig(pPos->GetSig()); //si la suma da 0 se borrará dicho mon, así que el anterior debe apuntar al que apuntaba el mon borrado
								delete pPos;
								pPos = NULL;
							}
						}
						fin = true;

					}
					else //exp menor que el comparado, se apunta al siguiente mon para seguir comparando
					{
						pPosAnt = pPos;
						pPos = pPos->GetSig();
					}
			}
			if ((pPos == NULL) && (!fin)) //si comparamos hasta el final y no se cumple ninguna condición significa que el mon es el más bajo en exp, así que se coloca al final
			{
				CTermino* p_new = new CTermino(mon);
				pPosAnt->SetSig(p_new); //el mon anterior (el que antes era el último) apunta al nuevo por ser el último
			}
		}
	}
	return *this;
}

ostream& operator<<(ostream& os, const CPolinomio& Poli)
{
	Poli.MostrarPoli(os);
	return os;
}

int CPolinomio::grado(const CPolinomio& poli)
{
	//CTermino* pPos = m_pCabecera;
	if(poli.m_pCabecera != NULL)
		return poli.m_pCabecera->GetExp();
	return 0;
}

CPolinomio::operator int()
{
	if (m_pCabecera != NULL)
		return m_pCabecera->GetExp();
	return 0;
}

bool CPolinomio::operator> (CPolinomio& poli) const
{
	return m_pCabecera->GetExp() > poli.m_pCabecera->GetExp();
}

bool CPolinomio::operator== (CPolinomio& poli) const
{
	return m_pCabecera->GetExp() == poli.m_pCabecera->GetExp();
}

CPolinomio CPolinomio::operator-() 
{
	CPolinomio poli;
	CMonomio mon;
	CTermino* pPos = m_pCabecera;
	//CTermino* pPosAnt = m_pCabecera->GetSig();
	while (pPos != NULL)
	{
		//-pPos->GetCoef();
		mon = -pPos->GetMono();
		poli << mon;
		pPos = pPos->GetSig();
	}
	return poli;
}

CPolinomio CPolinomio::operator+(CPolinomio& poli) const
{
	CPolinomio resultado;
	CMonomio mon1,mon2;
	CTermino* pPos = m_pCabecera;
	CTermino* pPos2 = poli.m_pCabecera;
	while (pPos != NULL)
	{
		mon1 = pPos->GetMono();
		resultado << mon1;
		pPos = pPos->GetSig();
	}
	while (pPos2 != NULL)
	{
		mon2 = pPos2->GetMono();
		resultado << mon2;
		pPos2 = pPos2->GetSig();
	}
	return resultado;
}

CPolinomio CPolinomio::operator-(CPolinomio& poli) const
{
	CPolinomio temp(poli);
	temp = -temp;
	return *this + temp;
}

CPolinomio CPolinomio::operator+=(CPolinomio& poli) const
{
	return *this + poli;
}

CPolinomio CPolinomio::operator-=(CPolinomio& poli) const
{
	return *this - poli;
}

double CPolinomio::operator[](int nExp) const
{
	CTermino* pPos = m_pCabecera;
	while (pPos != NULL)
	{
		if (pPos->GetExp() == nExp)
			return pPos->GetCoef();
		else
			pPos = pPos->GetSig();
	}
	return 0;
}

double CPolinomio::operator()(double x) const
{
	CTermino* pPos = m_pCabecera;
	double resultado = 0;
	while (pPos != NULL)
	{
		double acum = 1;
		for (int i = 0; i < pPos->GetExp(); i++) 
			acum *= x;                           
		acum *= pPos->GetCoef();
		resultado += acum;
		pPos = pPos->GetSig();
	}
	return resultado;
}

CPolinomio CPolinomio::operator*(CPolinomio& poli) const
{
	CPolinomio resultado;
	CTermino* pPos = m_pCabecera;
	CTermino* pPos2 = poli.m_pCabecera;
	while (pPos2 != NULL)
	{
		while (pPos != NULL)
		{
			double nCoef = pPos->GetCoef() * pPos2->GetCoef();
			int nExp = pPos->GetExp() + pPos2->GetExp();
			CMonomio mon(nCoef, nExp);
			resultado << mon;
			pPos = pPos->GetSig();
		}
		pPos = m_pCabecera;
		pPos2 = pPos2->GetSig();
	}
	return resultado;
}

CPolinomio CPolinomio::operator*=(CPolinomio& poli) const
{
	return *this * poli;
}