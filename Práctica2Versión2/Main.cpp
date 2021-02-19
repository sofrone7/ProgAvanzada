#include "Funciones.h"
#include "utils.h"

int main()
{
	{
		CMatFloat m;
		int opcion, f, c, e;
		static const char* opciones[] = { "Construir matriz1D", "Construir matriz2D", "Introducir datos matriz", "Mostrar matriz", "Terminar" };
		const int num_opciones = sizeof(opciones) / sizeof(char*);
		enum op { Construir = 1, Construir2, Introducir, Mostrar, Finalizar };
		m.Iniciar();
		do
		{
			system("cls");
			opcion = CrearMenu(opciones, num_opciones);
			switch (opcion)
			{
			case Construir:
				cout << "Consruir matriz1D" << endl;
				cout << "Introduzca numero de elementos de la matriz: ";
				e = LeerInt();
				m.CrearMatriz1D(e);
				system("pause");
				break;
			case Construir2:
				cout << "Consruir matriz2D" << endl;
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
				m.CrearMatriz2D(f, c);
				cout << "Matriz construida" << endl;
				system("pause");
				break;
			case Introducir:
				cout << "Introducir datos" << endl;
				m.Introducir();
				system("pause");
				break;
			case Mostrar:
				cout << "Mostrar matriz" << endl;
				m.Mostrar();
				system("pause");
				break;
			case Finalizar:
				break;
			}
		} while (opcion != Finalizar);
	}
	MemoryManager::dumpMemoryLeaks();
}