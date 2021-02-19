#include "MemoryManager.h"
#include "CHora.h"
#include "CFicha.h"
#include "utils.h"
using namespace utils;

int main()
{
	{
		int h, m, s, edad = -1;
		string nombre, formato;
		//CHora c;
		//CFicha f;
		bool asignar = 0;
		int opcion;
		static const char* opciones[] = { "Crear una ficha", "Visualizar ficha", "Terminar" };
		const int num_opciones = sizeof(opciones) / sizeof(char*);
		enum op { Crear = 1, Visualizar, Finalizar };
		do
		{
			system("cls");
			opcion = CUtils::CrearMenu(opciones, num_opciones);
			switch (opcion)
			{
			case Crear:
			{
				cout << "Introduzca el nombre: ";
				CUtils::LeerDato(nombre);
				do
				{
					cout << "Introduzca la edad: ";
					CUtils::LeerDato(edad);
				} while (edad < 0);
			do
			{
				do
				{
					cout << "Introduzca la hora: ";
					CUtils::LeerDato(h);
				} while (h < 0);
				do
				{
					cout << "Introduzca los minutos: ";
					CUtils::LeerDato(m);
				} while (m < 0);
				do
				{
					cout << "Introduzca los segundos: ";
					CUtils::LeerDato(s);
				} while (s < 0);
				cout << "Introduzca el formato(AM, PM o 24 HORAS): ";
				CUtils::LeerDato(formato);
				CHora c{h, m, s, formato};
				asignar = c.EsHoraCorrecta();
				if (asignar == 0)
					cout << "Datos incorrectos, pruebe otra vez" << endl;
			} while (asignar == 0);
				system("pause");
				break;
			}
			case Visualizar:
			{
				if (edad == -1)
					cout << "No hay datos, debe introducirlos" << endl;
				else
				{
					CFicha ficha1{ nombre, edad, h, m, s, formato };
					VisualizarFicha(ficha1);
				}
				system("pause");
				break;
			}
			case Finalizar:
				break;
			}
		} while (opcion != Finalizar);
		CFicha ficha1;
		CHora hora1; 
		hora1 = ficha1.ObtenerNacio();
	}
	MemoryManager::dumpMemoryLeaks();
}