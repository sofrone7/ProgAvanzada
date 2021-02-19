#include "CPolinomio.h"

CPolinomio::CPolinomio(double dCoef, int nExp)
{
	CMonomio m(dCoef, nExp);
	m_monomios.push_back(m);
}

CPolinomio::CPolinomio(vector<CMonomio>& mon)
{
	for (int i = 0; i < mon.size(); i++)
		*this << mon[i];
}

CPolinomio::CPolinomio(const CMonomio& mon)
{
	m_monomios.push_back(mon);
}

void CPolinomio::MostrarPoli(std::ostream& os) const
{
	if (!m_monomios.empty())
	{
		for (int i = 0; i < m_monomios.size(); i++)
			os << m_monomios[i] << ' ';
	}
	else
		os << "0 ";
}

CPolinomio& CPolinomio::operator<<(const CMonomio& mon)
{
	CMonomio aux;
	if (mon.GetCoef() != 0)
	{
		if (m_monomios.empty())
		{
			m_monomios.push_back(mon);
		}
		else
		{
			m_monomios.insert(m_monomios.begin(), 1, mon);	
			for (int i = 0; i + 1 < m_monomios.size(); i++)
			{
				if (m_monomios[i].GetExp() <= m_monomios[i + 1].GetExp())
				{
					//m_monomios.insert(m_monomios.begin(),1,mono);	
					if (m_monomios[i].GetExp() < m_monomios[i + 1].GetExp())
					{
						aux = m_monomios[i];
						m_monomios[i] = m_monomios[i + 1];
						m_monomios[i + 1] = aux;
					}
					else//mismo exponente
					{
						aux.SetCoef(m_monomios[i].GetCoef() + m_monomios[i + 1].GetCoef());
						aux.SetExp(m_monomios[i].GetExp());
						m_monomios[i] = aux;
						m_monomios.erase(m_monomios.begin() + (i + 1));
						if (m_monomios[i].GetCoef() == 0) //si tras la suma queda un 0 se borra
							m_monomios.erase(m_monomios.begin() + i);

					}
				}

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

CPolinomio::operator int()
{
	if (!m_monomios.empty())
		return m_monomios.begin()->GetExp();
	return 0;
}

int CPolinomio::grado(const CPolinomio& poli)
{
	if (!m_monomios.empty())
		return poli.m_monomios.begin()->GetExp();
	return 0;
}

bool CPolinomio::operator> (CPolinomio& poli) const
{
	return m_monomios.begin()->GetExp() > poli.m_monomios.begin()->GetExp();
}

bool CPolinomio::operator== (CPolinomio& poli) const
{
	return m_monomios.begin()->GetExp() == poli.m_monomios.begin()->GetExp();
}

CPolinomio CPolinomio::operator-()
{
	CPolinomio poli;
	CMonomio mon;
	for (int i = 0; i < m_monomios.size(); i++)
	{
		mon = -m_monomios[i];
		poli << mon;
	}
	return poli;
}

CPolinomio CPolinomio::operator+(CPolinomio& poli) const
{
	CPolinomio resultado;
	for (int i = 0; i < m_monomios.size(); i++)
	{
		resultado << m_monomios[i];
	}
	for (int j = 0; j < poli.m_monomios.size(); j++)
	{
		resultado << poli.m_monomios[j];
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
	for (int i = 0; i < m_monomios.size(); i++)
	{
		if (m_monomios[i].GetExp() == nExp)
			return m_monomios[i].GetCoef();
	}
	return 0;
}

double CPolinomio::operator()(double x) const
{
	double resultado = 0;
	for (int i = 0; i < m_monomios.size(); i++)
	{
		double acum = 1;
		for (int j = 0; j < m_monomios[i].GetExp(); j++)
			acum *= x;
		acum *= m_monomios[i].GetCoef();
		resultado += acum;
	}
	return resultado;
}

CPolinomio CPolinomio::operator*(CPolinomio& poli) const
{
	CPolinomio resultado;
	for (int i = 0; i < poli.m_monomios.size(); i++)
	{
		for (int j = 0; j < m_monomios.size(); j++)
		{
			double nCoef = m_monomios[j].GetCoef() * poli.m_monomios[i].GetCoef();
			int nExp = m_monomios[j].GetExp() + poli.m_monomios[i].GetExp();
			CMonomio mon(nCoef, nExp);
			resultado << mon;
		}
	}
	return resultado;
}

CPolinomio CPolinomio::operator*=(CPolinomio& poli) const
{
	return *this * poli;
}