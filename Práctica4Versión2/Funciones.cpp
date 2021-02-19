#define _CRT_SECURE_NO_WARNINGS
#include "Funciones.h"
#include "utils.h"
using namespace utils;

CHora::CHora(int h, int m, int s, std::string f)
{
	m_nHoras = h; m_nMinutos = m; m_nSegundos = s; m_pszFormato = f; //m_pszFormato = NULL;
	//AsignarFormato(f);
	CUtils::ConverMayus(m_pszFormato);
}

/*CHora::~CHora()
{
	//cout << "Objeto destruido"<< endl;
	delete[] m_pszFormato;
}*/

/*bool CHora::AsignarFormato(char* pszFormato)
{
	int x = 0, y = 0, z = 0;
	CUtils a;
	//if (pszFormato == NULL)
	//{
		//y = strlen("24 HORAS") + 1;
		//m_pszFormato = (char*) new (nothrow) char[y];
		//if (m_pszFormato == NULL)
			//return false;
		//strcpy(m_pszFormato, "24 HORAS");
		//return true;
	//}
	//else
	//{
	if (m_pszFormato != NULL)
		//Destruir();
		delete[] m_pszFormato;
	x = strlen(pszFormato) + 1; //si previamente se ha hecho el delete, porq se borra tambien pszFormato
	m_pszFormato = (char*) new (nothrow) char[x]; //antes de copiar asigno memoria? 
	if (m_pszFormato == NULL)
		return false;
	strcpy(m_pszFormato, pszFormato);
	a.ConverMayus(m_pszFormato);
	return true;
	//}
}*/

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
}

CHora::CHora(const CHora& c) :
	m_nHoras{ c.m_nHoras }, m_nMinutos{ c.m_nMinutos }, m_nSegundos{ c.m_nSegundos }, m_pszFormato{ c.m_pszFormato }
{
	//m_nHoras; { ca.m_nHoras; }; m_nMinutos; {ca.m_nMinutos; }; m_nSegundos; {ca.m_nSegundos; }; m_pszFormato; {ca.m_pszFormato; };
	//*this = c;
}

/*void CHora::Destruir()
{
	// Libera la memoria reservada dinámicamente para un objeto y
	// pone el puntero m_pszFormato a cero.
	//if (m_pszFormato == NULL)
	//{
	//	cout << "Debes introducir una hora";
	//	return;
	//}
	delete[] m_pszFormato; //con "am" *m_pszFormato se queda en "a"
	m_pszFormato = NULL;
}*/



/*bool CHora::AsignarHora(int nHoras, int nMinutos, int nSegundos, char* pszFormato)
{
	// Recibe 4 argumentos, correspondientes a una hora,
	// y los almacena en las variables
	// m_nHoras, m_nMinutos, m_nSegundos y m_pszFormato
	// correspondientes al objeto que recibe el mensaje.
	// Invoca a AsignarFormato y a EsHoraCorrecta.
	// Devuelve false si no pudo ser asignado el formato
	// o el valor retornado por EsHoraCorrecta.
	bool c1, c2;
	m_nHoras = nHoras;
	m_nMinutos = nMinutos;
	m_nSegundos = nSegundos;
	c1 = AsignarFormato(pszFormato);
	c2 = EsHoraCorrecta();
	return c1 && c2;
}*/