#include "MemoryManager.h"
#include "CCliente.h"
#include "utils.h"
#include "CRegistroDiario.h"
using namespace utils;

int main()
{
	{
		CRegistroDiario registro(20), * copia = NULL;
		//int nElem, nElem1;
		int opcion;
		static const char* opciones[] = { "Introducir empleado", "Introducir cliente", "Buscar por nombre", "Mostrar registro diario", "Mostrar empleados", "Copia de seguridad del registro diario", "Restaurar copia de seguridad", "Terminar" };
		const int num_opciones = sizeof(opciones) / sizeof(char*);
		enum op { Introducir = 1, Introducir2, Buscar, Mostrar, Mostrar2, Copia, Restaurar, Finalizar };
		do
		{
			system("cls");
			opcion = CUtils::CrearMenu(opciones, num_opciones);
			switch (opcion)
			{
			case Introducir:
			{
				cout << "Introducir empleado" << endl;
				//CRegistroDiario  Empleados(nElem);

				cout << "Introduzca el nombre del empleado: ";
				string nombre, formato, categoria;
				int antiguedad;
				CUtils::LeerDato(nombre);
				//cout << "Introduzca el formato(AM, PM o 24 HORAS): ";
				//CUtils::LeerDato(formato);
				cout << "Introduzca categoria: ";
				CUtils::LeerDato(categoria);
				cout << "Introduzca antiguedad; ";
				CUtils::LeerDato(antiguedad);
				CEmpleado empleado(nombre, 0, 12, 0, 0, "AM", categoria, antiguedad);
				registro.AgregarPersona(empleado);
				//registro.VisualizarRegistro();
				system("pause");
				break;
			}
			case Introducir2:
			{
				cout << "Introducir cliente" << endl;
				cout << "Introduzca el nombre del cliente: ";
				string nombre, dni;
				CUtils::LeerDato(nombre);
				cout << "Introduzca el DNI del cliente: ";
				CUtils::LeerDato(dni);
				CCliente cliente(nombre, 0, 12, 0, 0, "AM", dni);
				registro.AgregarPersona(cliente);
				system("pause");
				break;
			}
			case Buscar:
			{
				cout << "Buscar por nombre" << endl;
				string busca;
				cout << "Introduzca el nombre del cliente a buscar: ";
				CUtils::LeerDato(busca);
				registro.BuscarNombre(registro, busca);
				system("pause");
				break;
			}
			case Mostrar:
				cout << "Mostar registro diario" << endl;
				registro.VisualizarRegistro();
				system("pause");
				break;
			case Mostrar2:
				cout << "Mostrar empleados" << endl;
				registro.VisualizarEmpleados();
				system("pause");
				break;
			case Copia:
				cout << "Copia de seguridad del registro diario" << endl;
				if (copia != NULL)
					cout << "Ya hay una copia de seguridad, debe borrarla mediante la opcion 7" << endl;
				else
					copia = new CRegistroDiario(registro);
				system("pause");
				break;
			case Restaurar:

				cout << "Restaurar copia de seguridad" << endl;
				if (copia != NULL)
				{
					registro = *copia;
					copia->~CRegistroDiario();
					delete copia;
					copia = NULL;
				}
				else
					cout << "No hay copia de seguridad, debe crear una primero" << endl;
				system("pause");
				break;
			case Finalizar:
				if (copia != NULL)
					delete copia;
				registro.~CRegistroDiario();
				//copia.CRegistroDiario::~CRegistroDiario();
				break;
			}
		} while (opcion != Finalizar);
	}
	MemoryManager::dumpMemoryLeaks();
	system("pause");
}