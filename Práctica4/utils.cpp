#include "utils.h"
using namespace utils;

int CUtils::CrearMenu(const char* OpMenu[], int num_opciones)
{
	int opcion;
	system("cls"); // limpiar la pantalla
				   // Presentar el menú
	cout << "\nElija una opcion:\n" << endl;
	for (int i = 0; i < num_opciones; i++)
		cout << "\t" << i + 1 << ". " << OpMenu[i] << endl;
	// Elegir una opción y verificar que es correcta
	do
	{
		LeerDato(opcion);
		if (opcion < 1 || opcion > num_opciones)
			cout << "Opcion incorrecta\n" << endl;
	} while (opcion < 1 || opcion > num_opciones);
	return opcion;
}

bool CUtils::LeerDato(int& dato)
{
	bool fail = false, eof = false;
	do
	{
		cout << ">> "; cin >> dato;
		// Limpiar '\n'. Sólo se ejecuta si no hay error
		cin.ignore(numeric_limits<int>::max(), '\n');
		fail = cin.fail(); eof = cin.eof(); // estado
		if (eof)
		{
			cin.clear();
			return false; // se pulsó Ctrl+Z
		}
		if (fail)
		{
			cout << "error: dato no válido\n";
			cin.clear();
			cin.ignore(numeric_limits<int>::max(), '\n');
		}
	} while (fail);
	return true;
}

bool CUtils::LeerDato(double& dato)
{
	bool fail = false, eof = false;
	do
	{
		cout << ">> "; cin >> dato;
		// Limpiar '\n'. Sólo se ejecuta si no hay error
		cin.ignore(numeric_limits<int>::max(), '\n');
		fail = cin.fail(); eof = cin.eof(); // estado
		if (eof)
		{
			cin.clear();
			return false; // se pulsó Ctrl+Z
		}
		if (fail)
		{
			cout << "error: dato no válido\n";
			cin.clear();
			cin.ignore(numeric_limits<int>::max(), '\n');
		}
	} while (fail);
	return true;
}

bool CUtils::LeerDato(float& dato)
{
	bool fail = false, eof = false;
	do
	{
		cout << ">> "; cin >> dato;
		// Limpiar '\n'. Sólo se ejecuta si no hay error
		cin.ignore(numeric_limits<int>::max(), '\n');
		fail = cin.fail(); eof = cin.eof(); // estado
		if (eof)
		{
			cin.clear();
			return false; // se pulsó Ctrl+Z
		}
		if (fail)
		{
			cout << "error: dato no válido\n";
			cin.clear();
			cin.ignore(numeric_limits<int>::max(), '\n');
		}
	} while (fail);
	return true;
}

bool CUtils::LeerDato(char* dato)
{
	bool fail = false, eof = false;
	int n;
	n = strlen(dato);
	do
	{
		cout << ">> "; cin.getline(dato, 15, '\n');
		// Si se introducen n o más caracteres
		// fail() devuelve true
		fail = cin.fail(); eof = cin.eof(); // estado
		if (eof)
		{
			cin.clear();
			return false; // se pulsó Ctrl+Z
		}
		if (fail)
		{
			cout << "error: dato no válido\n";
			cin.clear();
			cin.ignore(numeric_limits<int>::max(), '\n');
		}
	} while (fail);
	return true;
}

char* CUtils::ConverMayus(char* str)
{
	//if (...) return 0; ¿se comprueba si ya es mayuscula?
	//independientemente de que lo fuese,¿no pasaría nada a la hora de ejecutar la función no?
	while (*str)
	{
		*str = toupper((int)* str);
		str++;
	}
	return str;
}

string& CUtils::ConverMayus(string& str)
{
	for (size_t i = 0; i < str.size(); i++)
		str[i] = toupper(str[i]);
	return str;
}