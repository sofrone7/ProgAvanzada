#define _CRT_SECURE_NO_WARNINGS
#include "Funciones.h"

int main()
{
	//Variables
	int opcion; //opcion elegida del menu
	struct MatFloat m;
	m.ppMatrizF = NULL;

	opcion = menu(); // llama función "menu"
	while (opcion != 5) // sentencia repetitiva
	{
		switch (opcion) 
		{
		case 1:
			// Llamar construir matriz
			
			printf("Construir matriz\n"); 
			if (m.ppMatrizF != NULL) //Al principio no será siempre diferente de NULL? tendrá contenido basura no?
			{
				printf("Ya hay una matriz, destrúyala.\n");
			    system("pause");
				break;
			}
			do
			{
				printf("Introduzca el numero de filas:\n");
				scanf_s("%d", &m.nFilas); //scanf_s??
			} while (m.nFilas < 1);
			do
			{
				printf("Introduzca el numero de columnas:\n");
				scanf_s("%d", &m.nColumnas);
			} while (m.nColumnas < 1);
			m.ppMatrizF=ConstruirMatriz(m.nFilas, m.nColumnas);
			break;
		case 2:
			printf("Introducir datos a la matriz\n");
			// Llamar introducir matriz
			IntroducirDatos(&m); //primero le pasaba &m.ppMatrizF, hay alguna diferencia con &m?
			
			break;
		case 3:
			printf("Mostrar matriz\n");
			// Llamar volcar matriz
			Mostrar(m);
			break;
		case 4:
			printf("Destruir matriz\n");
			// Llamar destruir matriz
			Destruir(&m);
			break;
		default:
			printf("ERROR: Opcion incorrecta.\n");
			break;
		}
		system("pause"); 
		opcion = menu(); 
	}
	
	
	MemoryManager_DumpMemoryLeaks();

	system("pause");
	return 0;
}




