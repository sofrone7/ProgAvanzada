#include "CMonomio.h"

ostream& operator<<(ostream& os, const CMonomio& mono)
{
	os << showpos;	// Poner + para valores positivos
	if (!mono.GetExp())	// Si la x est� elevada a 0,
		os << mono.GetCoef();	// vale 1 y se muestra s�lo el coef.
	else	// Si no...
	{
		if (mono.GetCoef() != 1)	// Mostrar el coeficiente
			os << mono.GetCoef();	// s�lo si es distinto de 1
		os << noshowpos;	// quitar + para valores positivos
		if (mono.GetExp() == 1)	// Si el exponente es 1,
			os << 'x';	// basta "x"
		else	// Si no,
			os << "x^" << mono.GetExp();	// hay que poner "x^..."
	}
	os << noshowpos;
	return os;	// Devolver ref. al ostream recibido
}	// para permitir encadenamiento: cout << m1 << m2...
