#pragma once
#if !defined(_SINIESTRO_H)
#define _SINIESTRO_H

#include <iostream>
#include <string>

class CSiniestro
{
private:
	int m_Codigo;
	static int m_SigCodigo;
	//float m_Coste;
protected:
	std::string m_Descripcion;
	float m_HorasMO;
	float m_CostePiezas;
	float m_Coste; // PREGUNTA 7
public:
	CSiniestro(const std::string& Desc = "Sin Descripcion");
	virtual ~CSiniestro() {};
	CSiniestro(int Cod = 0, float HorasMO = 0, float CostePiezas = 0, float Coste = 0, const std::string & Desc = "Sin Descripcion");

	virtual float GetPresupuesto() const = 0;
	int GetCodigo() const { return m_Codigo; }
	float GetCoste() const { return m_Coste; } // PREGUNTA 7
	virtual void Presupuestar(float Horas, float Piezas) = 0;
	virtual void Mostrar(std::ostream& os = std::cout) const; // PREGUNTA 12
	virtual CSiniestro* Clonar() const = 0;
};

#endif