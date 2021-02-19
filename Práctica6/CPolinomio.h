#pragma once
#include "CTermino.h"
#include <vector>

class CPolinomio
{
private:
	CTermino* m_pCabecera;	// Primer término (el de mayor grado)

public:
	CPolinomio() :
		m_pCabecera(NULL) {}
	CPolinomio(const CPolinomio& poli);
	CPolinomio(double dCoef, int nExp = 0);
	CPolinomio(vector<CMonomio>& mon);
	CPolinomio(const CMonomio& mon);
	~CPolinomio();
	const CPolinomio& operator= (const CPolinomio& poli);
	void MostrarPoli(std::ostream& os) const;
	CPolinomio& operator<<(const CMonomio& mon);
	operator int();
	int grado(const CPolinomio& poli);
	bool operator> (CPolinomio& poli) const;
	bool operator== (CPolinomio& poli) const;
	CPolinomio operator-();
	CPolinomio operator+(CPolinomio& poli) const;
	CPolinomio operator-(CPolinomio& poli) const;
	CPolinomio operator+=(CPolinomio& poli) const;
	CPolinomio operator-=(CPolinomio& poli) const;
	double operator[](int nExp) const;
	double operator()(double x) const;
	CPolinomio operator*(CPolinomio& poli) const;
	CPolinomio operator*=(CPolinomio& poli) const;
};

ostream& operator<<(ostream& os, const CPolinomio& Poli);
