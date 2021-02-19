#include "utils.h"

int CrearMenu(const char* OpMenu[], int num_opciones)
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
		opcion = LeerInt();
		if (opcion < 1 || opcion > num_opciones)
			cout << "Opcion incorrecta\n" << endl;
	} while (opcion < 1 || opcion > num_opciones);
	return opcion;
}

int LeerInt()
{
	int error;
	int num;
	do
	{
		cin >> num;
		error = cin.rdstate() & ios::failbit;
		/* ESCRIBA EL CÓDIGO QUE FALTA */
		cin.clear();
		cin.ignore(numeric_limits<int>::max(), '\n');
	} while (error);
	//cin.ignore(numeric_limits<int>::max(), '\n'); // eliminar '\n'
	return num;
}

float LeerFloat()
{
	int error;
	float num;
	do
	{
		cin >> num;
		error = cin.rdstate() & ios::failbit;
		/* ESCRIBA EL CÓDIGO QUE FALTA */
		cin.clear();
		cin.ignore(numeric_limits<int>::max(), '\n');
	} while (error);
	//cin.ignore(numeric_limits<int>::max(), '\n'); // eliminar '\n'
	return num;
}