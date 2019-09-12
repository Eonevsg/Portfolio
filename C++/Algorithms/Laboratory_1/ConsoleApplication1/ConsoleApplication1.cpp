// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <fstream>

using namespace std;

long long vs = 0;
clock_t t, t2, t3;

void taskone(int n);
long long factorial(int n);
long double tasktwo(int n);
long double taskthree_start(int n);
long double taskthree(int n, double &a);



int main()
{
	int n, veiksmusk = 0;
	double suma = 0;
	cout.precision(20);
	cout << "Iveskite n\n";

	cin >> n;

	///*
	cout << "Pirmas budas\n";
	
	for (int z = 1; z <= n; z++) {
		t = clock();
		for (int j = 0; j < 100000; j++) {
			suma = 0;
			//veiksmusk = 0;

			for (int i = 1; i <= z; i++) {
				suma += pow(3, i) / factorial((2 + i));
				veiksmusk += (i - 1) +  i + 1;
				//cout << veiksmusk << endl;
			}

			//cout << "Veiksmu skaicius = " << veiksmusk << endl;
		}
		
		t = clock() - t;

		cout << " Tiesine suma " << suma << " Laikas " << ((float)t) / (float)(CLOCKS_PER_SEC) <<" vs "<< veiksmusk/100000 << endl;
		veiksmusk = 0;
	}
	//*/

	//**********************************

	///*
	cout << "Antras budas:" << endl;
	
	for (int j = 1; j <= n; j++) {
	   t2 = clock();
		suma = 0;
		for (int i = 0; i < 100000; i++) {
			suma = tasktwo(j);
		}
		t2 = clock() - t2;
		
		cout << " Rekursine suma " << suma << " Laikas " << ((float)t2) / (float)(CLOCKS_PER_SEC) << " Veiksmu skaicius = " << vs/100000 << endl;
		vs = 0;
	}
	

	//**********************************
	///*
	cout<<"Trecias budas\n";
	
	suma = 0;
	for (int z = 1; z <= n; z++) {
		t3 = clock();
		for (int i = 0; i < 100000; i++) {
			suma = taskthree_start(z);
		}
		t3 = clock() - t3;
		cout << " Rekursine suma2 " << suma << " Laikas " << ((float)t3) / (float)(CLOCKS_PER_SEC) << " Veiksmu skaicius = " << vs/100000 << endl;
		vs = 0;
	}
	//*/
	//taskone(n);
	system("pause");
	return 0;
}

void taskone(int n)
{
	long double fact = 1, sum = 0;
	long long j;

	for (int i = 1; i <= n; i++)
	{
		j = i + 2;
		while (j  > 1)
		{
			fact *= j;
			j--;
		}

		sum = sum + pow(3., (double)i) / fact;
		cout << "I = " << setw(3) << i << "; (3^n) = " << setw(15) << pow(3., (double)i) << "; Fact = " << setw(20) << fact;
		cout << fixed << setprecision(15) << "; Calculation = " << setw(20) << pow(3., (double)i) / fact << "; Suma: " << setw(20) << sum; //<< " Time " << (float)t / CLOCKS_PER_SEC << endl;
		cout << setprecision(0);
		fact = 1;
	}

}

long long factorial(int n)
{

	if (n < 2)
		return 1;
	else
		return n*factorial(n - 1);
}

long double tasktwo(int n)
{
	long double result, f;
	f = n + 2;
	if (n < 1)
		return 0;

	
	else
	{
		vs += 1 + n - 1 + n - 1 + 1 + 1;
		result = pow(3., (double)n) / factorial(f);
		return result + tasktwo(n - 1);
	}
}
long double taskthree_start(int n)
{
	double temp = 0;
	return taskthree(n, temp);

}
long double taskthree(int n, double &a)
{
	if (n <= 1) {
		a = 0.5;
		return 0.5;
		//cout << "Kai n = " << n << " Veiksmu skaicius yra: " << 0 << endl;
	}
	vs += 4;
	//cout << "Kai n = " << n << " Veiksmu skaicius yra: " << vs << endl;
	double S = taskthree(n - 1, a);
	a = a*(double)3.0 / (n + 2); // 
	return S + a;
}