#include "MemoryManager.h"
#include "Funciones.h"

int main()
{
	{
		int opcion, f , c;
		vector<vector<float>> m;
		static const char* opciones[] = { "Construir matriz", "Introducir datos matriz", "Mostrar matriz", "Terminar" };
		const int num_opciones = sizeof(opciones) / sizeof(char*);
		enum op { Construir = 1, Introducir, Mostrar1, Finalizar };
		do
		{
			system("cls");
			opcion = CrearMenu(opciones, num_opciones);
			switch (opcion)
			{
			case Construir:
				cout << "Consruir matriz" << endl;
				do
				{
					cout << "Introduzca numero de filas de la matriz: "; //cin >> f;
					f = LeerInt();
				} while (f < 1);
				do
				{
					cout << "Introduzca numero de columnas de la matriz: "; //cin >> c;
					c = LeerInt();
				} while (c < 1);
				m = ConstruirMatriz(f, c);
				cout << "Matriz construida" << endl;
				system("pause");
				break;
			case Introducir:
				cout << "Introducir matriz" << endl;
				IntroducirDatos(m);
				system("pause");
				break;
			case Mostrar1:
				cout << "Mostrar matriz" << endl;
				Mostrar(m);
				system("pause");
				break;
			case Finalizar:
				break;
			}
		} while (opcion != Finalizar);
	}
	MemoryManager::dumpMemoryLeaks();
}