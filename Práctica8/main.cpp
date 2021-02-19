#include <iostream>
#include "CLista.h"
#include "CContrato.h"
#include "CSiniestroUrgente.h"
#include "CSiniestroNormal.h"
#include "CCliente.h"
#include "utils.h"
#include "MemoryManager.h"

using namespace std;
using namespace utils;

const int MAX_CLIENTES = 10;

int main()
{
  {
    static const char * OpMenu[]={" 1. Vaciar() de CLista.",
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
    const int numopciones = sizeof(OpMenu)/sizeof(char *);
    int opcion=0;

    do
    {
      opcion = CUtils::CrearMenu(OpMenu,numopciones);
      switch(opcion)
      {
      case 1:
        {
          // Crear una lista para despu�s vaciarla
          CLista<string> miLista;
          string nombres[]={"Nombre 1", "Nombre 2", "Nombre 3", "Nombre 4", "Nombre 5",
            "Nombre 6", "Nombre 7", "Nombre 8", "Nombre 9", "Nombre 10"};
          // Rellenar la lista con nombres

          // Mostrar la lista. Preveer execepci�n CIndiceIncorrecto.


          // Vaciar la lista y verificar despu�s que est� vac�a.


          cout << "Respuestas a las preguntas: ..." << endl;
          system("pause");
          break;
        }
      case 2:
        {
          // Ejemplo operador [] con lista de enteros
          // Crear un objeto lista que almacene 10 datos de tipo int


          // Sumar todos los n�meros de la lista y provocar la excepci�n CIndiceIncorrecto


          system("pause");
          break;
        }
      case 3: // Pregunta 1
        {
          // Crear e iniciar objeto CContrato a copiar
          CContrato original(12345,"Prueba constructor copia","11-01-16",123456789,987654321);
          // Rellenar objeto original
          TSituacion situacion = local;
          original.AgregarSiniestro(CSiniestroUrgente(local,"siniestro 1"));
          original.AgregarSiniestro(CSiniestroNormal("siniestro 2"));
          original.AgregarSiniestro(CSiniestroNormal("siniestro 3"));
          cout << " CONTRATO ORIGINAL: " << endl << endl << original;

          cout << "\n Constructor copia de CContrato ejecutado con exito." << endl << endl;
          CContrato copia(original);
          original = copia;
          cout << " CONTRATO ORIGINAL: " << copia << endl;
          system("pause");
          break;
        }
      case 4:
        {
          CContrato prueba(12345);
          // Agregar a "prueba" un siniestro urgente y otro normal


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


          // Mostrar datos
          cout << " Datos del cliente: \n" << endl << cli << endl;
          system("pause");

          cout << "Llamada expl�cita:\n" << ...;
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
          CSiniestroUrgente MiSiniestroUrgente(internacional,"Siniestro Urgente Ejemplo");
          MiSiniestroUrgente.Presupuestar(7,3);
          CSiniestroNormal MiSiniestroNormal("Siniestro Normal Ejemplo");
          MiSiniestroNormal.Presupuestar(9,4);

          cout << "Respuestas a las preguntas: ..." << endl;
          system("pause");
          break;
        }
      case 8:
        {
          // Crear un cliente cli


          // Agregar a cli un contrato con siniestros



          // Mostrar cli


          system("pause");
          break;
        }
      case 9:
        {
          // Crear una matriz din�mica de tipo CCliente apuntada por "seguros"


          // Agregar contratos a los clientes de la matriz "seguros"



          // Contar el n�mero total de contratos
          long total = 0;
          for(int i=0; i < MAX_CLIENTES; i++)
            total += seguros[i];
          cout << "\n El numero total de contratos de los clientes asciende a: ";
          cout << total << " contratos\n";
          system("pause");
          delete [] seguros;
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
          CContrato c(12345, "Cafetera C1Z","2/1/2016", 100, 1000);
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


          // Crear empresa2 como copia de empresa1


          // Mostrar la empresa2
          cout << "\n CLIENTES DE LA EMPRESA: \n" << endl;



          system("pause");
          break;
        }
      case 15:
        {
          // Crear empresa
          CEmpresa<CCliente> empresa1;
          // Rellenar empresa
          
          // Guardar los nombres en un fichero (escribir)

          cout << "\nCLIENTES DE LA EMPRESA GUARDADOS.\n";

          // Verificar la informaci�n almacenada en el fichero (leer)

          system("pause");
          break;
        }
      }
    }
    while(opcion < numopciones);
  }
  MemoryManager::dumpMemoryLeaks();
  //system("pause");
}

