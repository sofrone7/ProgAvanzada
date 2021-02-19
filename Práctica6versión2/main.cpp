#include "CPolinomio.h"
#include "MemoryManager.h" 

using namespace std;
int main()
{
	{
		CPolinomio P, Q, R, S, T, U, V, W, X, Y, Z, N;
		CMonomio m1, m2(2, 2), m3(3, 3), m4(4, 4);

		P << m1 << m2 << -m4 << m3; Q << m4 << m1 << m2 << -m3; R << m3 << m4 << -m2;
		S << m2 << m3 << m4 << -m2;  T << -m2 << -m3 << -m4 << m3; U << m2 << m3 << m4 << -m4;
		V << m2 << m3 << m4 << -m2 << -m3 << -m4; W << m2 << m3 << -m2 << -m3;
		X << m2 << -m2;
		Y << m2 << m3 << m4 << m2;
		Z << -m2 << -m3 << -m4 << -m3; N << m2 << m3 << m4 << m4;

		cout << "P = " << P << endl
			<< "Q = " << Q << endl
			<< "R = " << R << endl
			<< "S = " << S << endl
			<< "T = " << T << endl
			<< "U = " << U << endl
			<< "V = " << V << endl
			<< "W = " << W << endl
			<< "X = " << X << endl
			<< "Y = " << Y << endl
			<< "Z = " << Z << endl
			<< "N = " << N << endl;

		cout << endl;
		cout << "prueba constructor copia(CPolinomio A = P):" << endl;
		CPolinomio A = P;
		cout << "A=" << A << endl;
		system("pause");
		cout << endl;

		cout << "prueba operador de asignacion(B = Q);" << endl;
		CPolinomio B;
		B = Q;
		cout << "B=" << B << endl;
		system("pause");
		cout << endl;

		cout << "prueba evitar auto-asignacion(P = P)" << endl;
		P = P;
		cout << "P=" << P << endl;
		system("pause");
		cout << endl;

		cout << "prueba constructor con un coeficiente y un exponente(C = +2.5 y D = +2.5x^5)" << endl;
		CPolinomio C(2.5), D(2.5, 5);
		cout << "C=" << C << endl;
		cout << "D=" << D << endl;
		system("pause");
		cout << endl;

		cout << "prueba constructor con un monomio(Monomio = +4x^4)" << endl;
		CMonomio e(4, 4);
		CPolinomio E(e);
		cout << "E=" << E << endl;
		system("pause");
		cout << endl;

		cout << "prueba grado de un polinomio" << endl;
		int grado = U;
		cout << "el grado de U es: " << grado << endl;
		system("pause");
		cout << endl;

		cout << "pureba con constructor vector" << endl; //cómo meter los monomios al vector
		vector<CMonomio> v;
		v.push_back(m4);
		v.push_back(m3);
		v.push_back(m2);
		CPolinomio F(v);
		cout << "F=" << F << endl;
		system("pause");
		cout << endl;

		cout << "prueba operador > (P > U)" << endl;
		cout << "P=" << P << endl;
		cout << "U=" << U << endl;
		if (P > U)
			cout << "P es de mayor grado que U" << endl;
		else
			cout << "P no es de mayor grado que U" << endl;
		system("pause");
		cout << endl;

		cout << "prueba operador == (P == Q)" << endl;
		cout << "P=" << P << endl;
		cout << "Q=" << Q << endl;
		if (P == Q)
			cout << "P es de igual grado que Q" << endl;
		else
			cout << "P no es de igual grado que Q" << endl;
		system("pause");
		cout << endl;

		cout << "prueba operador - unario con polinomio Q" << endl;
		cout << "Q=" << Q << endl;
		cout << "-Q=" << -Q << endl;
		system("pause");
		cout << endl;

		cout << "prueba operador +(N + U)" << endl;
		cout << "N=" << N << endl;
		cout << "U=" << U << endl;
		cout << "N+U=" << N + U << endl;
		//cout << "N=" << N << endl;
		//cout << "U=" << U << endl;
		system("pause");
		cout << endl;

		cout << "prueba operadores - y +- con R y S" << endl;
		cout << "R=" << R << endl;
		cout << "S=" << S << endl;
		cout << "R-S=" << R - S << endl;
		cout << "R+=S:" << (R += S) << endl;
		system("pause");
		cout << endl;

		cout << "prueba operador -= con N e Y" << endl;
		cout << "N=" << N << endl;
		cout << "Y=" << Y << endl;
		cout << "N-=Y:" << (N -= Y) << endl;
		system("pause");
		cout << endl;

		cout << "prueba operador []" << endl;
		cout << "P=" << P << endl;
		cout << "Coefciente de P[4]=" << P[4] << endl;
		system("pause");
		cout << endl;

		cout << "prueba operador ()" << endl;
		CPolinomio G;
		G << CMonomio(3, 2) << CMonomio(-2, 1);
		cout << "G=" << G << endl;
		cout << "G(0.5)=" << G(0.5) << endl;
		system("pause");
		cout << endl;

		cout << "prueba operador *" << endl;
		cout << "Q=" << Q << endl;
		cout << "S=" << S << endl;
		cout << "Q*S=" << Q * S << endl;
		system("pause");
		cout << endl;

		cout << "prueba operador *=" << endl;
		cout << "P=" << P << endl;
		cout << "Q=" << Q << endl;
		cout << "P*=Q:" << (P *= Q) << endl;
		cout << endl;
	}

	MemoryManager::dumpMemoryLeaks();
	system("pause");
}