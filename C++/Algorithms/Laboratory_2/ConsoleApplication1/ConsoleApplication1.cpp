#include "stdafx.h"
#include <random>
#include <iomanip>
#include <algorithm>
#include <map>
#include <vector>
#include <time.h>
#include "Tree.h"

using namespace std;

struct Matavimai {
	float laikas;
	float veiksmai;
};

T simpleFind(int id, T *A, int N);
Matavimai demo(int N);

void shuffle(int *A, int N);
void shuffle_almost_sorted(int *A, int N);
void shuffle_weakly_sorted(int *A, int N);



int main()
{
	//srand(777);
	srand(time(NULL));
	Matavimai m;
	int N = 150, numberOFcycles;

	cout << "Enter the number of cycles\n";
	cin >> numberOFcycles;

	
	for (int i = 0; i < numberOFcycles; i++)
	{
		m = demo(N);
		cout << setprecision(3) << N << "  " << m.laikas << " " << m.veiksmai << endl;
		N = 2 * N;
	}
	
	//m = demo(N);
	//cout << setprecision(3) << N << "  " << m.laikas << " " << m.veiksmai << endl;
	return 0;
}

int vs;
T simpleFind(int id, T *A, int N) {
	for (int i = 0; i < N; i++) {
		++vs;
		if (id == A[i].id)
			return A[i];
	}
	T duom;
	duom.id = 0;
	return duom;
}

Matavimai demo(int N) {
	//duomenys nuo 1 iki N
	int *Ids = new int[N];
	for (int i = 0; i < N; i++)
		Ids[i] = i + 1;

	//masyvas
	T *t1 = new T[N];
	//dvejetainis paieskos medis
	Tree t2;
	//subalansuotas dvejetainis paieskos medis
	map< int, T > t3;

	//shuffle(Ids, N);
	shuffle_weakly_sorted(Ids, N);
	//shuffle_almost_sorted(Ids, N);

	//duomenu is masyvo Ids irasymas
	//i masyva
	for (int i = 0; i < N; i++) {
		T data;
		data.id = Ids[i];
		t1[i].id = data.id;
	}
	//i dvejetaini medi
	for (int i = 0; i < N; i++) {
		T data;
		data.id = Ids[i];
		t2.insert(data);
	}
	//i subalansuota stl medi
	for (int i = 0; i < N; i++) {
		T data;
		data.id = Ids[i];
		t3[data.id] = data;
	}
	
	int kart;
	clock_t time = clock();
	//kartojam, kol matavimai nepasieks triju zenklu tikslumo
	//for (kart = 0; clock() - time < 1000; kart++) {

	//arba galime kartojimu skaiciu valdyti tiesiogiai
	kart = 1000;
	for (int i = 0; i < kart; i++) {
		t2.veiksmai = 0;
		vs = 0;
		for (int j = 1; j <= N; j++) {
			//if (simpleFind(j, t1, N).id != j)//MASYVAS
			  if (t2.find(j) == NULL)//DVEJETAINIS MEDIS
				//if (t3[j].id != j)//SUBALANSUOTAS MEDIS
				cout << " klaida: nerado " << j << endl;

		}
	}
	time = clock() - time;
	float sec1 = (float)time / ((float)kart*(float)N*(float)CLOCKS_PER_SEC);

	delete[] t1;
	delete[] Ids;
	Matavimai r;
	r.laikas = sec1;
	r.veiksmai = (float)max(vs, t2.veiksmai) / (float)N;
	return r;
}

void shuffle(int *A, int N) {
	for (int i = 0; i < N - 1; i++) {
		//j = i ... N-1
		int j = i + (rand() % (N - i));
		swap(A[i], A[j]);
	}
}

void shuffle_almost_sorted(int *A, int N) {
	vector<int> V(N);
	for (int i = 0; i < N; i++)
		V[i] = A[i];
	std::sort(V.begin(), V.end());
	for (int i = 0; i < N; i++)
		A[i] = V[i];

	for (int i = 0; i < sqrt(N); i++) {
		int i1 = rand() % N;
		int i2 = rand() % N;
		swap(A[i1], A[i2]);
	}
}

void shuffle_weakly_sorted(int *A, int N) {
	vector<int> V(N);
	for (int i = 0; i < N; i++)
		V[i] = A[i];
	std::sort(V.begin(), V.end());
	for (int i = 0; i < N; i++)
		A[i] = V[i];

	int N2 = N - (int)pow((float)N, 0.9);
	for (int i = 0; i < N2; i++) {
		int i1 = rand() % N;
		int i2 = rand() % N;
		swap(A[i1], A[i2]);
	}
}
