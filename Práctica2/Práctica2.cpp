#include "Funciones.h"
#include "utils.h"

int main()
{
	{
		CMatFloat m;
		int opcion, f, c, e; 
		static const char* opciones[] = {"Construir matriz 1D", "Construir matriz 2D", "Introducir matriz", "Mostrar matriz", "Destruir matriz", "Terminar"};
		const int num_opciones = sizeof(opciones) / sizeof(char*);
		enum op { Construir1D = 1, Construir2D, Introducir, Mostrar, Destruir, Finalizar };
		m.Iniciar();

		do
		{
			system("cls");
			opcion = CrearMenu(opciones, num_opciones);
			switch (opcion)
			{
			case Construir1D:
				cout << "Construir matriz 1D" << endl;
				if (m.Existe() != false)
				{
					cout << "Ya hay una matriz, debes destruirla.\n" << endl;
					system("pause");
					break;
				}
				cout << "Introduzca numero de elementos de la matriz: "; 
				e = LeerInt();
				m.CrearMatriz1D(e);
				cout << "Matriz1D construida\n";
				system("pause");
				break;
			case Construir2D:
				cout << "Construir matriz 2D" << endl;
				if (m.Existe() != false)
				{
					cout << "Ya hay una matriz, debes destruirla.\n" << endl;
					system("pause");
					break;
				}
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
				cout << "Matriz2D construida" << endl;
				system("pause");
				break;
			case Introducir:
				cout << "Introducir matriz" << endl;
				m.Introducir();
				system("pause");
				break;
			case Mostrar:
				cout << "Mostrar matriz" << endl;
				m.Mostrar();
				system("pause");
				break;
			case Destruir:
				cout << "Destruir matriz" << endl;
				m.Destruir();
				system("pause");
				break;
			case Finalizar:
				if (m.Existe() != false) m.Destruir();
				break;
			}
		} while (opcion != Finalizar);
	}
	MemoryManager::dumpMemoryLeaks();
}