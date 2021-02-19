#define _CRT_SECURE_NO_WARNINGS
#include "CHora.h"
#include "utils.h"
using namespace utils;

CHora::CHora(int h, int m, int s, std::string f)
{
	m_nHoras = h; m_nMinutos = m; m_nSegundos = s; m_pszFormato = f; //m_pszFormato = NULL;
	//AsignarFormato(f);
	CUtils::ConverMayus(m_pszFormato);
}

bool CHora::EsHoraCorrecta() const
{
	// Verifica si una hora es correcta:
	// 1) verificar que el formato es 24 HORAS, AM o PM
	// 2) y verificar que las horas, minutos y segundos están dentro
	// de los límites según el formato sea o no 24 HORAS.
	// Devuelve true si es correcta y false en otro caso.
	bool VC, AMPM = 0, hora = 0, min, seg, correcto;
	VC = Formato24();
	if ((m_pszFormato.compare("AM") == 0) ^ (m_pszFormato.compare("PM") == 0))
		AMPM = 1;
	if (VC == 1)
	{
		hora = (m_nHoras >= 0 && m_nHoras <= 23);
	}
	if (VC == 0)
	{
		hora = (m_nHoras >= 0 && m_nHoras <= 12);
	}
	min = (m_nMinutos >= 0 && m_nMinutos <= 59);
	seg = (m_nSegundos >= 0 && m_nSegundos <= 59);
	correcto = (VC ^ AMPM);
	return correcto && hora && min && seg;
}

bool CHora::Formato24() const
{
	if (m_pszFormato.compare("24 HORAS") == 0) //con m_pszFormato = " " me devueleve 0
		return true;
	else return false;
}

void VisualizarHora(const CHora& hora)
{
	int h, m, s;
	string formato;
	hora.ObtenerHora(h, m, s, formato);
	//if (formato == NULL)
		//cout << "No hay datos" << endl; return;
	cout << " " << h << ":" << m << ":" << s << " " << formato << "" << endl;
}

void CHora::ObtenerHora(int& nHoras, int& nMinutos, int& nSegundos, string& pszFormato) const
{
	// Obtener una hora. Permite obtener los datos hora,
	// minutos, segundos y formato correspondientes
	// al objeto que recibe el mensaje.
	//if (m_pszFormato == NULL)
	//	cout << "No hay datos introducidos" << endl; return;
	//int y = 0;
	//y = strlen(pszFormato); 
	//strcpy_s(pszFormato, y, m_pszFormato);
	//cout << " " << nHoras << ":" << nMinutos << ":"<< nSegundos <<" " << m_pszFormato <<"" << endl;
	int x;
	nHoras = m_nHoras;
	nMinutos = m_nMinutos;
	nSegundos = m_nSegundos;
	//x = strlen(m_pszFormato) + 1; 
	//pszFormato = (char*) new (nothrow) char[x]; 
	pszFormato = m_pszFormato;
}

CHora& CHora::operator=(const CHora& c)
{
	if (this == &c) return *this;
	m_nHoras = c.m_nHoras;
	m_nMinutos = c.m_nMinutos;
	m_nSegundos = c.m_nSegundos;
	m_pszFormato = c.m_pszFormato;
	//cout << "Operador asignacion" << endl;
}

CHora::CHora(const CHora& c) :
	m_nHoras{ c.m_nHoras }, m_nMinutos{ c.m_nMinutos }, m_nSegundos{ c.m_nSegundos }, m_pszFormato{ c.m_pszFormato }
{
	//m_nHoras; { ca.m_nHoras; }; m_nMinutos; {ca.m_nMinutos; }; m_nSegundos; {ca.m_nSegundos; }; m_pszFormato; {ca.m_pszFormato; };
	//*this = c;
	//cout << "Constructor copia" << endl;
}

CHora::~CHora()
{
	//cout << "Objeto destruido" << endl;

}

bool CHora::AsignarHora(int nHoras, int nMinutos, int nSegundos, string pszFormato)
{
	// Recibe 4 argumentos, correspondientes a una hora,
	// y los almacena en las variables
	// m_nHoras, m_nMinutos, m_nSegundos y m_pszFormato
	// correspondientes al objeto que recibe el mensaje.
	// Invoca a AsignarFormato y a EsHoraCorrecta.
	// Devuelve false si no pudo ser asignado el formato
	// o el valor retornado por EsHoraCorrecta.
	bool c2;
	//ConverMayus(pszFormato);
	m_nHoras = nHoras;
	m_nMinutos = nMinutos;
	m_nSegundos = nSegundos;
	m_pszFormato = pszFormato;
	CUtils::ConverMayus(m_pszFormato);
	c2 = EsHoraCorrecta();
	return c2;
}