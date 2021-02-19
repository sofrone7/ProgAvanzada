#pragma once
#include "CLista.h"
//#include "CHora.h"
using namespace std;

namespace utils
{
	class CUtils
	{
	public:
		static bool LeerDato(int& dato);
		static int CrearMenu(const char* OpMenu[], int num_opciones);
		static bool LeerDato(float& dato);
		static bool LeerDato(double& datos);
		static bool LeerDato(char* dato);
		static bool LeerDato(string& dato);
		static char* ConverMayus(char* str);
		static string& ConverMayus(string& str);
	};
};