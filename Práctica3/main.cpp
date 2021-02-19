#include "Funciones.h"
#include "utils.h"

int main()
{
	{
		CHora c;
		int opcion, h, m, s;
		bool asignar = 0;
		char formato[15];
		static const char* opciones[] = { "Introducir hora", "Visualizar hora", "Terminar" };
		const int num_opciones = sizeof(opciones) / sizeof(char*);
		enum op { Introducir = 1, Visualizar, Finalizar };
		c.Iniciar();
		do
		{
			system("cls");
			opcion = CrearMenu(opciones, num_opciones);
			switch (opcion)
			{
			case Introducir:
				do
				{
					cout << "Introducir hora" << endl;
					do
					{
						cout << "Introduzca la hora: ";
						h = LeerInt();
					} while (h < 0);
					do
					{
						cout << "Introduzca los minutos: ";
						m = LeerInt();
					} while (m < 0);
					do
					{
						cout << "Introduzca los segundos: ";
						s = LeerInt();
					} while (s < 0);
					cout << "Introduzca el formato que desea utilizar(AM, PM o 24 HORAS): ";
					LeerCadena(formato, sizeof(formato));
					asignar = c.AsignarHora(h, m, s, formato);
					if (asignar == 0)
						cout << "Datos incorrectos, pruebe otra vez" << endl;
				} while (asignar == 0); 
				system("pause");
				break;
			case Visualizar:
				cout << "Visualizar hora" << endl;
				if (asignar == 0)
					cout << "No hay datos, debe introducirlos primero" << endl;
				else
					VisualizarHora(c);
				system("pause");
				break;
			case Finalizar:
				c.Destruir();
				break;
			}
		} while (opcion != Finalizar);
	}
	MemoryManager::dumpMemoryLeaks();
}