#include "Funciones.h"
#include "utils.h"
using namespace utils;

int main()
{
	{
		CHora Copia2;
		//Copia.Destruir();
		//Copia2.Destruir();
		CHora* Din = 0;
		CUtils a;
		int h, m, s;
		char formato[15];
		bool asignar = 0, asignar2 = 0;
		int opcion, opcion2;
		static const char* opciones[] = { "Crear un objeto local", "Crear un objeto dinamicamente", "Constructor copia", "Operador de asignacion", "Terminar" };
		static const char* opciones2[] = { "Con una hora predeterminada", "Introduciendo la hora", "Introduciendo la hora y los minutos", "Introduciendo la hora, los minutos y los segundos", "Introduciendo la hora, los minutos, los segundos y el formato", "Volver al menu principal" };
		const int num_opciones = sizeof(opciones) / sizeof(char*);
		const int num_opciones2 = sizeof(opciones2) / sizeof(char*);
		enum op { local = 1, dinamico, constructor, asignacion, Finalizar };
		enum op2 { predeterminada = 1, hs, hm, hms, hmsformato, Volver };
		do
		{
			system("cls");
			opcion = CUtils::CrearMenu(opciones, num_opciones);
			switch (opcion)
			{
			case local:
				do
				{
					system("cls");
					opcion2 = CUtils::CrearMenu(opciones2, num_opciones2);
					switch (opcion2)
					{
					case predeterminada:
					{
						CHora hora;
						VisualizarHora(hora);
						system("pause");
						break;
					}
					case hs:
					{

						do
						{
							do
							{
								cout << "Introduzca la hora: ";
								CUtils::LeerDato(h);
							} while (h < 0);
							CHora hora(h);
							asignar = hora.EsHoraCorrecta();
							if (asignar == 0)
								cout << "Datos incorrectos, pruebe otra vez" << endl;
							else
								VisualizarHora(hora);
						} while (asignar == 0);
						
						system("pause");
						break;
					}
					case hm:
					{
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
							CHora hora{ h, m };
							asignar = hora.EsHoraCorrecta();
							if (asignar == 0)
								cout << "Datos incorrectos, pruebe otra vez" << endl;
							else
								VisualizarHora(hora);
						} while (asignar == 0);
						system("pause");
						break;
					}
					case hms:
					{
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
							CHora hora{ h, m, s };
							asignar = hora.EsHoraCorrecta();
							if (asignar == 0)
								cout << "Datos incorrectos, pruebe otra vez" << endl;
							else
								VisualizarHora(hora);
						} while (asignar == 0);
						system("pause");
						break;
					}
					case hmsformato:
					{
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
							CHora hora{ h, m, s, formato };
							asignar = hora.EsHoraCorrecta();
							if (asignar == 0)
								cout << "Datos incorrectos, pruebe otra vez" << endl;
							else
								VisualizarHora(hora);
						} while (asignar == 0);
						system("pause");
						break;
					}
					case Volver:
						//VisualizarHora(hora);
						break;
					}
				} while (opcion2 != Volver);
				system("pause");
				break;
			case dinamico:
			{	
				if (Din != 0)
					delete Din;
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
					Din = new CHora(h, m, s, formato);					
					//Din->AsignarHora(h,m,s,formato);					
					asignar2 = Din->EsHoraCorrecta();
					if (asignar2 == 0)
					{
						cout << "Datos incorrectos, pruebe otra vez" << endl;
						delete Din;
					}
					else						
						VisualizarHora(*Din);
				} while (asignar2 == 0);
				system("pause");
				break;
			}
			case constructor:
			{
				if (Din != 0)
				{
					//CHora Copia(*Din);
					CHora Copia;
					Copia = *Din;
					
					VisualizarHora(Copia);
					
				}
				else cout << "No hay datos, debe introducirlos" << endl;
				system("pause");
				break;
			}
			case asignacion:
			{
				if (Din != 0)
				{
					//CHora Copia2.operator=(*Din);
					Copia2.operator=(*Din);
					//{CHora Copia2 = (*Din); }
					VisualizarHora(Copia2);
					
				}
				else cout << "No hay datos, debe introducirlos" << endl;
				system("pause");
				break;
			}
			case Finalizar:
				if (Din != 0)
					delete Din;				
				//Copia.Destruir();
				//Copia2.Destruir();
				//hora.Destruir();
				//delete Copia2;
				break;
			
			}
		} while (opcion != Finalizar);
	}
	MemoryManager::dumpMemoryLeaks();
}