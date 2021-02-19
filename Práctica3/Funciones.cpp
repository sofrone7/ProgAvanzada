#define _CRT_SECURE_NO_WARNINGS
#include "Funciones.h"
#include "utils.h"

void CHora::Iniciar()
{
	m_nHoras = 0; 
	m_nMinutos = 0; 
	m_nSegundos= 0; 
	m_pszFormato = NULL;
}

bool CHora::Formato24() const
{
	int x;
	x = strlen(m_pszFormato);
	if(strncmp(m_pszFormato, "24 HORAS",x) == 0) //con m_pszFormato = " " me devueleve 0
		return true;
	else return false;
}

bool CHora::AsignarFormato(char* pszFormato)
{
	int x = 0, y = 0, z=0;
	if (pszFormato == NULL)
	{
		cout << "No hay formato";
		return false;
	}
	if (m_pszFormato != NULL)
		//delete[] m_pszFormato;
		Destruir();
	x = strlen(pszFormato)+1; //si previamente se ha hecho el delete, porq se borra tambien pszFormato
	m_pszFormato = (char*) new (nothrow) char[x]; //antes de copiar asigno memoria?
	if (m_pszFormato == NULL)
		return false;
	//y = strlen(m_pszFormato); //y devuelve valores aleatorios superiores a x, no debería devolver el mismo valor que x?
	//strncpy_s(m_pszFormato, y, pszFormato, x);
	//y = strnlen_s(pszFormato, y);
	strcpy(m_pszFormato, pszFormato);
	//z = strlen(m_pszFormato);
	//cout << z << endl;
	//m_pszFormato& operator=(pszFormato&&);
	//m_pszFormato = pszFormato;
	//CHora m_pszFormato(pszFormato);
	ConverMayus(m_pszFormato);
	return true;
}
// Verifica que pszFormato no es nulo.
// Copia en m_pszFormato el formato dado por pszFormato,
// asignando la cantidad de memoria necesaria, y lo convierte
// a mayúsculas. Si fuera necesario, previamente se liberará
// la memoria que hubiera asignada. Devuelve true si la
// operación se realiza con éxito y false en caso contrario.

bool CHora::EsHoraCorrecta() const
{
	// Verifica si una hora es correcta:
	// 1) verificar que el formato es 24 HORAS, AM o PM
	// 2) y verificar que las horas, minutos y segundos están dentro
	// de los límites según el formato sea o no 24 HORAS.
	// Devuelve true si es correcta y false en otro caso.
	bool VC, AMPM = 0, hora = 0, min, seg, correcto;
	int n = 0;
	n = strlen(m_pszFormato);
	VC = Formato24();
	if ((strncmp(m_pszFormato, "AM", n) == 0) ^ (strncmp(m_pszFormato, "PM", n) == 0))
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

bool CHora::AsignarHora(int nHoras, int nMinutos, int nSegundos, char* pszFormato)
{
	
	bool c1, c2;
	m_nHoras = nHoras;
	m_nMinutos = nMinutos;
	m_nSegundos = nSegundos;
	c1 = AsignarFormato(pszFormato);
	c2 = EsHoraCorrecta();
	return c1 && c2;
}

void CHora::ObtenerHora(int& nHoras, int& nMinutos, int& nSegundos, char* pszFormato) const
{
	
	int x;
	nHoras = m_nHoras;
	nMinutos = m_nMinutos;
	nSegundos = m_nSegundos;
	//x = strlen(m_pszFormato) + 1; 
	//pszFormato = (char*) new (nothrow) char[x]; 
	if(pszFormato != 0 && m_pszFormato != 0)
		strcpy(pszFormato, m_pszFormato);
}

void CHora::Destruir()
{
	
	//}
	delete[] m_pszFormato; //con "am" *m_pszFormato se queda en "a"
	m_pszFormato = NULL;
}

void VisualizarHora(const CHora& hora)
{
	int h, m, s;
	char formato[15];
	hora.ObtenerHora(h, m, s, formato);
	//if (formato == NULL)
		//cout << "No hay datos" << endl; return;
	cout << " " << h << ":" << m << ":" << s << " " << formato << "" << endl;
}