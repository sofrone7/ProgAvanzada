#pragma once
#include "CMonomio.h"

class CTermino
{
private:
	CMonomio m_Monomio;	// Monomio contenido en el término
	CTermino* m_pSig;	// Puntero al siguiente término

public:
	// Constructores ...
	CTermino(double dCoef = 0, int nExp = 0, CTermino * pSig = NULL):
		m_Monomio(dCoef, nExp), m_pSig(pSig){}
	CTermino(const CMonomio& mMono, CTermino * pSig = NULL):
		m_Monomio(mMono), m_pSig(pSig) {}
	CTermino(const CTermino& ter) :
		m_Monomio(ter.m_Monomio), m_pSig(NULL) {}
	// Métodos Get:
	double GetCoef() const { return m_Monomio.GetCoef(); }
	int GetExp() const { return m_Monomio.GetExp(); }
	CMonomio GetMono() const { return m_Monomio; } 
	CTermino* GetSig() const { return m_pSig; }

	// Métodos Set:
	void SetCoef(double dCoef) { m_Monomio.SetCoef(dCoef); }
	void SetExp(int nExp) { m_Monomio.SetExp(nExp); }
	void SetMono(const CMonomio& mono) { m_Monomio = mono; }
	void SetSig(CTermino* pSig) { m_pSig = pSig; }
};
