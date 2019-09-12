// LD3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <stdlib.h> //srand, rand
#include <vector>
#include <time.h>
#include <algorithm>

void Preparations(std::vector<unsigned int> &numbers, int N);
void GenerateNumbers(std::vector<unsigned int> &numbers, int N);
void ShowArray(std::vector<unsigned int> numbers);
void WriteToFile(std::vector<unsigned int> numbers);
void ReadFromFile(std::vector<unsigned int> &numbers);
void BubbleSort(std::vector<unsigned int> numbers);
void SelectionSort(std::vector<unsigned int> numbers);
void Merge(std::vector<unsigned int> &numbers, int left, int middle, int right, int &comparisons, int &copies);
void MergeSort(std::vector<unsigned int> &numbers, int left, int right, int &comparisons, int &copies);
void MergeStart(std::vector<unsigned int> numbers, int left, int right);

int  comparisons = 0, copies = 0;

int main()
{
	std::vector<unsigned int> numbers;
	int N = 4000;

	
	for (int i = 0; i < 5; i++)
	{
		Preparations(numbers, N);
		//SelectionSort(numbers);
		BubbleSort(numbers);
		//ShowArray(numbers); std::cout << std::endl;
		//MergeStart(numbers, 0, N);
		N *= 2;
		//std::cout << "\n\n";
	}


	system("pause");
	return 0;
}



//****************************************************************************************

void Preparations(std::vector<unsigned int> &numbers, int N)
{
	GenerateNumbers(numbers, N);
	/*std::cout << "Array of numbers [ ";
	ShowArray(numbers); std::cout << "]\n";*/

	WriteToFile(numbers); //std::cout << "Numbers have been written to the file\n";
	numbers.clear();
	/*std::cout << "Array of numbers after clearing [ ";
	ShowArray(numbers); std::cout << "]\n";*/

	ReadFromFile(numbers);
	/*std::cout << "Array of numbers after reading from file [ ";
	ShowArray(numbers); std::cout << "]\n";*/

}
void GenerateNumbers(std::vector<unsigned int> &numbers, int N)
{
	srand(time(NULL));
	for (int i = 0; i < N; i++)
	{
		unsigned int temp;
		temp = rand() % 1000 + 1;
		numbers.push_back(temp);
	}
}
void ShowArray(std::vector<unsigned int> numbers)
{

	for (int i = 0; i < size(numbers); i++)
		std::cout << numbers[i] << " ";
}
void WriteToFile(std::vector<unsigned int> numbers)
{
	std::ofstream fout;

	fout.open("output.txt", std::ios_base::out | std::ios_base::trunc);

	for (int i = 0; i < size(numbers); i++)
	{
		fout << numbers[i] << " ";
	}

	fout.close();
}
void ReadFromFile(std::vector<unsigned int> &numbers)
{
	std::ifstream fin;

	fin.open("output.txt");
	unsigned int temp;


	while (!fin.eof())
	{
		fin >> temp;
		numbers.push_back(temp);

	}
	numbers.pop_back();//???
	fin.close();

}
void SelectionSort(std::vector<unsigned int> numbers)
{

	std::cout << "\n*****************************************************\n";
	std::cout << "SELECTION SORT\n";
	//std::cout << "The process of sorting array\n";
	for (int i = 0; i < size(numbers) - 1; i++)
	{
		for (int j = i + 1; j < size(numbers); j++)
		{

			comparisons++;
			if (numbers[i] > numbers[j])
			{
				std::swap(numbers[i], numbers[j]);
				copies++;
			}


		}

		//ShowArray(numbers);std::cout << "\n"; // A visual representation of how selection sort works

	}
	std::cout << "\nSorted array of numbers [ ";
	ShowArray(numbers); std::cout << "]\n";
	std::cout << "Number of comparisons : " << comparisons << std::endl;
	std::cout << "Number of copies : " << copies << std::endl;
	std::cout << "\n*****************************************************\n";
}
void BubbleSort(std::vector<unsigned int> numbers)
{
	/*std::cout << "\n*****************************************************\n";
	std::cout << "BUBBLE SORT\n";
	std::cout << "The process of sorting array\n";*/

	int counter = size(numbers)-1;
	int j;
	while (counter > 0)
	{
		j = 0;
		for (int i = 0; i < counter; i++)
		{
			comparisons++;
			if (numbers[i] > numbers[i + 1])
			{
				j = i;
				std::swap(numbers[i], numbers[i + 1]);
				copies++;
			}
		}
		counter = j;
		//ShowArray(numbers);std::cout << "\n"; // A visual representation of how bubble sort works
	}

	/*std::cout << "\nSorted array of numbers [ ";
	ShowArray(numbers); std::cout << "]\n";
	std::cout << "Number of comparisons : " << comparisons << std::endl;
	std::cout << "Number of copies : " << copies << std::endl;
	std::cout << "\n*****************************************************\n";*/

	
	std::cout << comparisons << " " << copies << std::endl;

}
void Merge(std::vector<unsigned int> &numbers, int left, int middle, int right, int &comparisons, int &copies)
{
	int i, j, k;
	int n1 = middle - left + 1;
	int n2 = right - middle;

	/* create temp arrays */
	int *L = new int[n1];
	int	*R = new int[n2];

	/* Copy data to temp arrays LEFT[] and RIGHT[] */
	for (i = 0; i < n1; i++)
		L[i] = numbers[left + i];
	for (j = 0; j < n2; j++)
		R[j] = numbers[middle + 1 + j];
	copies += n1 + n2;

	/* Merge the temp arrays */
	i = 0; // Initial index of first subarray
	j = 0; // Initial index of second subarray
	k = left; // Initial index of merged subarray
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			numbers[k] = L[i];
			comparisons++;
			copies++;
			i++;
		}
		else
		{
			numbers[k] = R[j];
			comparisons++;
			copies++;
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of L[], if there
	are any */
	while (i < n1)
	{
		numbers[k] = L[i];
		copies++;
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there
	are any */
	while (j < n2)
	{
		numbers[k] = R[j];
		copies++;
		j++;
		k++;
	}
	delete[] L;
	delete[] R;
}
void MergeSort(std::vector<unsigned int> &numbers, int left, int right, int &comparisons, int &copies)
{
	if (left < right)
	{
		// Same as (l+r)/2, but avoids overflow for
		// large l and h
		int middle = left + (right - left) / 2;

		// Sort first and second halves
		MergeSort(numbers, left, middle, comparisons, copies);
		MergeSort(numbers, middle + 1, right, comparisons, copies);

		Merge(numbers, left, middle, right, comparisons, copies);

	}
}
void MergeStart(std::vector<unsigned int> numbers, int left, int right)
{
	comparisons = 0, copies = 0;

	MergeSort(numbers, 0, right - 1, comparisons, copies);

	/*std::cout << "MERGE SORT\n\n";
	std::cout << "Sorted array of numebrs [ ";
	ShowArray(numbers); std::cout << "]\n";
	std::cout << "Comparisons : " << comparisons << std::endl;
	std::cout << "Copies : " << copies << std::endl;
	std::cout << "\n*****************************************************\n";*/

	std::cout << comparisons << " " << copies << std::endl;
}


