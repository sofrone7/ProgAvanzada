#include <iostream>
#include <fstream>
#include <string>
#include "CLista.h"
#include "CContrato.h"
#include "CSiniestroUrgente.h"
#include "CSiniestroNormal.h"
#include "CCliente.h"
//#include "CIndiceIncorrecto.h"
#include "CEmpresa.h"
#include "utils.h"
#include "MemoryManager.h"

using namespace std;
using namespace utils;

const int MAX_CLIENTES = 10;

int main()
{
	{
		static const char* OpMenu[] = { " 1. Vaciar() de CLista.",
						 " 2. Operador [] CLista.",
						 " 3. Constructor copia de CContrato.",
						 " 4. AgregarSiniestro() de CContrato.",
						 " 5. Operador << CCliente.",
						 " 6. m_pSigCodigo static.",
						 " 7. Presupuestar() de CSiniestro y derivadas",
						 " 8. AgregarContrato() de CCliente",
						 " 9. total += seguros[i]",
						 "10. Constructor CSiniestro y CSiniestroNormal",
						 "11. const_cast<CLista<T>*>(this)->",
						 "12. GetCoste()?",
						 "13. c.AgregarSiniestro()",
						 "14. Plantilla CEmpresa.",
						 "15. Guardar empresa.",
						 "16. Salir."
		};
		const int numopciones = sizeof(OpMenu) / sizeof(char*);
		int opcion = 0;

		do
		{
			opcion = CUtils::CrearMenu(OpMenu, numopciones);
			switch (opcion)
			{
			case 1:
			{
				// Crear una lista para después vaciarla
				CLista<string> miLista;
				string nombres[] = { "Nombre 1", "Nombre 2", "Nombre 3", "Nombre 4", "Nombre 5",
				  "Nombre 6", "Nombre 7", "Nombre 8", "Nombre 9", "Nombre 10" };
				// Rellenar la lista con nombres
				for (int i = 0; i < 10; i++)
					miLista.AgregarObjeto(nombres[i]);
				// Mostrar la lista. Preveer execepción CIndiceIncorrecto.
				try
				{
					while (miLista.TieneMas())
					{
						cout << miLista.GetActual() << endl;
					} 
				}
				catch (CIndiceIncorrecto& fallo)
				{
					cout << fallo.what() << endl;
				}
				cout << endl;
				// Vaciar la lista y verificar después que está vacía.
				miLista.Vaciar();
				if (miLista.EstaVacia())
					cout << "La lista se ha vaciado correctamente" << endl;
				else
					cout << "La lista no se ha vaciado correctamente" << endl;
				cout << endl;
				cout << "Respuestas a las preguntas: ..." << endl;
				system("pause");
				break;
			}
			case 2:
			{
				// Ejemplo operador [] con lista de enteros
				// Crear un objeto lista que almacene 10 datos de tipo int
				int acum = 0;
				CLista<int> miLista;
				int datos[] = {0,1,2,3,4,5,6,7,8,9};
				for (int i = 0; i < 10; i++)
					miLista.AgregarObjeto(datos[i]);
				// Sumar todos los números de la lista y provocar la excepción CIndiceIncorrecto
				try
				{
					for (int i = 0; i < 11; i++)
						acum += miLista[i].GetDato();
				}
				catch (CIndiceIncorrecto& fallo)
				{
					cout << fallo.what() << endl;
				}
				cout << "Resultado: " << acum << endl;
				cout << endl;
				system("pause");
				break;
			}
			case 3: // Pregunta 1
			{
				// Crear e iniciar objeto CContrato a copiar
				CContrato original(12345, "Prueba constructor copia", "11-01-16", 123456789, 987654321);
				// Rellenar objeto original
				TSituacion situacion = local;
				original.AgregarSiniestro(CSiniestroUrgente(local, "siniestro 1"));
				original.AgregarSiniestro(CSiniestroNormal("siniestro 2"));
				original.AgregarSiniestro(CSiniestroNormal("siniestro 3"));
				cout << " CONTRATO ORIGINAL: " << endl << endl << original;

				cout << "\n Constructor copia de CContrato ejecutado con exito." << endl << endl;
				CContrato copia(original);
				original = copia;
				
				
				cout << " CONTRATO ORIGINAL: " << copia << endl;
				//copia.CContrato::~CContrato();
				//original.CContrato::~CContrato();
				system("pause");
				break;
			}
			case 4:
			{
				CContrato prueba(12345);
				// Agregar a "prueba" un siniestro urgente y otro normal
				prueba.AgregarSiniestro(CSiniestroUrgente(local, "siniestro 1"));
				prueba.AgregarSiniestro(CSiniestroNormal("siniestro 2"));

				prueba.MostrarSiniestros();
				cout << endl;
				cout << "Respuestas a las preguntas: ..." << endl;
				system("pause");
				break;
			}
			case 5:
			{
				// Crear cliente
				CCliente cli("Juan");
				// Agregar un contrato con dos siniestros, urgente y normal, a cli
				CContrato original(12345, "Prueba constructor copia", "11-01-16", 123456789, 987654321);
				
				original.AgregarSiniestro(CSiniestroUrgente(local, "siniestro 1"));
				original.AgregarSiniestro(CSiniestroNormal("siniestro 2"));
				cli.AgregarContrato(original);
				// Mostrar datos
				cout << " Datos del cliente: \n" << endl << cli << endl;
				system("pause");


				cout << "Llamada explicita:\n" << endl;
				operator<<(operator<<(operator<<(operator<<(cout, "Datos del cliente: \n"), "\n"), cli), "\n");
				system("pause");
				break;
			}
			case 6:
			{
				cout << "Respuestas a las preguntas: ..." << endl;
				system("pause");
				break;
			}
			case 7:
			{
				
				CSiniestroUrgente MiSiniestroUrgente(internacional, "Siniestro Urgente Ejemplo");
				MiSiniestroUrgente.Presupuestar(7, 3);
				CSiniestroNormal MiSiniestroNormal("Siniestro Normal Ejemplo");
				MiSiniestroNormal.Presupuestar(9, 4);
				float a = MiSiniestroUrgente.GetPresupuesto();
				float b = MiSiniestroNormal.GetPresupuesto();
				cout << "Presupuesto de siniestro urgente: " << a << endl;
				cout << "Presupuesto de siniestro normla: " << b << endl;
				cout << "Respuestas a las preguntas: ..." << endl;
				system("pause");
				break;
			}
			case 8:
			{
				// Crear un cliente cli
				CCliente yo("Silviu");

				// Agregar a cli un contrato con siniestros
				CContrato original(12345, "Contrato de Silviu", "11-01-16", 123456789, 987654321);
				original.AgregarSiniestro(CSiniestroUrgente(local, "siniestro 1"));
				yo.AgregarContrato(original);


				// Mostrar cli
				cout << yo << endl;

				system("pause");
				break;
			}
			case 9:
			{
				// Crear una matriz dinámica de tipo CCliente apuntada por "seguros"
				CCliente* seguros = new (nothrow) CCliente[10];
				string nombres[] = { "Nombre 1", "Nombre 2", "Nombre 3", "Nombre 4", "Nombre 5",
				  "Nombre 6", "Nombre 7", "Nombre 8", "Nombre 9", "Nombre 10" };
				// Agregar contratos a los clientes de la matriz "seguros"
				for (int i = 0; i < 10; i++)
				{
					seguros[i].SetNombre(nombres[i]);				
					seguros[i].AgregarContrato(CContrato(i + 1));	
				}


				// Contar el número total de contratos
				long total = 0;
				for (int i = 0; i < MAX_CLIENTES; i++)
					total += seguros[i];
				cout << "\n El numero total de contratos de los clientes asciende a: ";
				cout << total << " contratos\n";
				system("pause");
				delete[] seguros;
				break;
			}
			case 10:
			{
				CSiniestroNormal s("Rotura de tambor");
				cout << endl;
				s.Mostrar(); cout << endl;

				cout << "Respuesta a la pregunta: ..." << endl;
				system("pause");
				break;
			}
			case 11:
			{
				cout << "Respuesta a la pregunta: ..." << endl;
				system("pause");
				break;
			}
			case 12:
			{
				cout << "Respuesta a la pregunta: ..." << endl;
				system("pause");
				break;
			}
			case 13:
			{
				CContrato c(12345, "Cafetera C1Z", "2/1/2016", 100, 1000);
				CSiniestroUrgente s(nacional, "Fallo general");
				c.AgregarSiniestro(s);

				cout << "Respuestas a las preguntas: ..." << endl;
				system("pause");
				break;
			}
			case 14:
			{
				// Crear empresa1
				CEmpresa<CCliente> empresa1;
				// Agregar elementos a la empresa
				CCliente yo("Silviu");
				CContrato original(12345, "Contrato de Silviu", "11-01-16", 123456789, 987654321);
				original.AgregarSiniestro(CSiniestroUrgente(local, "siniestro 1"));
				yo.AgregarContrato(original);
				empresa1.AgregarElemento(yo);
				// Crear empresa2 como copia de empresa1
				CEmpresa<CCliente>empresa2(empresa1); // constructor copia 
				empresa2 = empresa1;	// operador de asignación

				// Mostrar la empresa2
				cout << "\n CLIENTES DE LA EMPRESA: \n" << endl;
				try
				{
					for (int i = 0; i < empresa2.Tamanyo(); i++)
						cout << empresa2[i] << endl;
				}
				catch (CIndiceIncorrecto& fallo)
				{
					cout << fallo.what() << endl;
				}


				system("pause");
				break;
			}
			case 15:
			{
				// Crear empresa
				CEmpresa<CCliente> empresa1;
				// Rellenar empresa
				CCliente yo("Silviu");
				CContrato original(12345, "Contrato de Silviu", "11-01-16", 123456789, 987654321);
				original.AgregarSiniestro(CSiniestroUrgente(local, "siniestro 1"));
				yo.AgregarContrato(original);
				empresa1.AgregarElemento(yo);
				// Guardar los nombres en un fichero (escribir)
				fstream fs("clientes.txt", ios::out|ios::in|ios::trunc);
				if (!fs)
					cout << "No se pudo abrir el archivo";
				try
				{
					for (int i = 0; i < empresa1.Tamanyo(); i++)
						fs << empresa1[i] << "\n";
				}
				catch (CIndiceIncorrecto& fallo)
				{
					cout << fallo.what() << endl;
				}
				cout << "\nCLIENTES DE LA EMPRESA GUARDADOS.\n";
				
				// Verificar la información almacenada en el fichero (leer)
				char car;
				fs.seekg(ios::beg); //me posiciono al principio del archivo
				while (fs.get(car)) cout << car;
				fs.close();
				system("pause");
				break;
			}
			}
		} while (opcion < numopciones);
	}
	MemoryManager::dumpMemoryLeaks();
	system("pause");
}

/*#include <iostream>
#include "CLista.h"
#include "MemoryManager.h"

using namespace std;

int main()
{
	CLista<int> lista;
	lista.AgregarObjeto(10);
	lista.AgregarObjeto(20);
	
	int n = lista.GetPrimero();
	cout << n << endl;
	try
	{
		while (lista.TieneMas())
		{
			n = lista.GetActual();
			cout << n << endl;
		}
		//lista[-1];
		lista[0];
		lista[1];
		lista[2];
	}
	catch (CIndiceIncorrecto& incorrecto)
	{
		cout << incorrecto.what() << endl;
	}
	lista.~CLista();
	MemoryManager::dumpMemoryLeaks();
	system("pause");
}*/