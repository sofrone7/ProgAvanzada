#define _CRT_SECURE_NO_WARNINGS
#include "Funciones.h"

int main()
{
	{
		int opcion;
		static const char* opciones[] = { "Construir matriz", "Introducir datos matriz", "Mostrar matriz", "Destruir matriz", "Terminar" };
		const int num_opciones = sizeof(opciones) / sizeof(char*);
		enum op { Construir = 1, Introducir, Mostrar1, Destruir1, Finalizar };

		struct MatFloat m;
		m.ppMatrizF = NULL;
		do
		{
			system("cls");
			opcion = CrearMenu(opciones, num_opciones);
			switch (opcion)
			{
			case Construir:
				printf("Construir matriz\n");
				if (m.ppMatrizF != NULL) //Al principio no será siempre diferente de NULL? tendrá contenido basura no?
				{
					printf("Ya hay una matriz, destruyala.\n");
					system("pause");
					break;
				}
				do
				{
					printf("Introduzca el numero de filas:\n");
					//scanf_s("%d", &m.nFilas); //scanf_s??
					m.nFilas = LeerInt();
				} while (m.nFilas < 1);
				do
				{
					printf("Introduzca el numero de columnas:\n");
					//scanf_s("%d", &m.nColumnas);
					m.nColumnas = LeerInt();
				} while (m.nColumnas < 1);
				m.ppMatrizF = ConstruirMatriz(m.nFilas, m.nColumnas);
				system("pause");
				break;
			case Introducir:
				printf("Introducir datos a la matriz\n");
				// Llamar introducir matriz
				IntroducirDatos(&m); //primero le pasaba &m.ppMatrizF, hay alguna diferencia con &m?
				system("pause");
				break;
			case Mostrar1:
				printf("Mostrar matriz\n");
				// Llamar volcar matriz
				Mostrar(m);
				system("pause");
				break;
			case Destruir1:
				printf("Destruir matriz\n");
				// Llamar destruir matriz
				Destruir(&m);
				system("pause");
				break;
			case Finalizar:
				if (m.ppMatrizF != NULL) Destruir(&m);
				break;
			}
		} while (opcion != Finalizar);
	}
	MemoryManager::dumpMemoryLeaks();
}