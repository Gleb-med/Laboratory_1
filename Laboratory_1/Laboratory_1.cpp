#include <iostream>
#include <fstream>
using namespace std;
#include <locale.h>
#include <vector>
#include <iomanip>

void WriteFile(ostream& fout, int &n);
void SearchDublicatNumber(istream& fin, ostream& fout, int&k);
void SortByQuantity(istream& fin, ostream& fout, int& j);

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	int n = rand() % 1001;

	// 1. сделать 2 вектора увеличивать второй вектор, если елемент из первого вектора встретился повторно
	// 2. при сортировке меняем индексы местами и в первом и во втором векторе, они синхронизированы

	ofstream finfout("input.txt");
	WriteFile(finfout, n);
	finfout.close();

	int k;
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	SearchDublicatNumber(fin, fout, k);

	ofstream gout("out.txt");

	SortByQuantity(fin, gout, k);

	fin.close(); fout.close();

	// отлично, главный костяк готов! Осталось 1: сделать сортировку по убыванию частоты, 2: заменить текстовые файлы на бинарные, везде
}

void WriteFile(ostream& fout, int &n) {
	for (int i = 0; i < n; i++) {
		//if (i % 50 == 0) fout << endl;
		int number = -100 + rand() % (201);
		fout << number << " ";
	}
}

void SearchDublicatNumber(istream& fin, ostream& fout, int& j) {
	int k; int cnt = 0;
	while (fin >> k) {
		cnt++;
	}

	fin.seekg(0);
	vector <int> numbers;
	vector <int> quantities(cnt);
	for (int i = 0; i < size(quantities); i++)
		quantities[i] = 1;
	j = 0;

	while (fin >> k) {
		bool flag = true;
		for (int i = 0; i < size(numbers); i++)
		{
			if (numbers[i] == k) {
				quantities[i]++;
				flag = false;
				break;
			}
		}
		if (flag) {
			numbers.push_back(k);
			fout << setw(4) << k << " ";
		}
		j++;
	}
	fout << endl;
	for (int j = 0; j < size(quantities); j++)
		fout << setw(4) << quantities[j] << " ";
}

void SortByQuantity(istream& fin, ostream& fout, int& j) {
	vector <int> array(j);
	int counter = 0; int h;

	fin.seekg(j);
	while (fin >> h) {
		array.push_back(j);
	}

	int min = 100;
	for (int i = 0; i < size(array); i++) {
		if (array[i] < min) {
			min = array[i];
			counter = i;
		}
	}
	//
	/*
	for (int i = 0; i < size(array); i++) {
		if (array[i] < min) {
			min = array[i];
			counter = i;
		}
	}*/


	fout << array[counter] << ":" << endl;
}