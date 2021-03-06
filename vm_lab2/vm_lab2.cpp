// vm_lab2.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <iomanip>

const int N = 4;
using namespace std;

void show_matrix(double* a, double b[])
{
	cout << "MATRIX" << endl;
	cout.precision(5);
	cout << endl << endl;
	for (size_t i = 0; i < N; i++) {
		for (size_t j = 0; j < N; j++)
			cout << setw(5) << *(a + i * N + j) << " ";
		cout << "|";
		cout << setw(3) << b[i];
		cout << endl;
	}
	cout << endl << endl;
}


int main()
{
	setlocale(LC_ALL, "Russian");
	double A[N][N] = { {20 ,2 ,3 ,7}, {1 ,12 ,-2 ,-5},{5 ,-3 ,13 ,0}, {0, 0, -1, 15} };
	double B[N] = { 5, 4, -3, 7 };

	show_matrix(&A[0][0], B);
	
	double X[N] = {0, 0, 0, 0};
	double XX[N] = {0, 0, 0, 0};
	double eps = 0.00001;//точность вычисления

	bool s0, s1, s2, s3;
	s0 = abs(A[0][0]) > (abs(A[0][1]) + abs(A[0][2]) + abs(A[0][3]));
	s1 = abs(A[1][1]) > (abs(A[1][0]) + abs(A[1][2]) + abs(A[1][3]));
	s2 = abs(A[2][2]) > (abs(A[2][0]) + abs(A[2][1]) + abs(A[2][3]));
	s3 = abs(A[3][3]) > (abs(A[3][0]) + abs(A[3][1]) + abs(A[3][2]));
	
	if (s0 = s1 = s2 = s3 != 1) {
		cout << "условие сходимости не выполняется" << endl;
		return 0;
	}

	cout << "  ITERATIONS:" << endl;
	int k = 0;
	do {
		for (int i = 0; i < 4; i++)
			XX[i] = X[i];

		X[0] = (B[0] - A[0][1] * XX[2] - A[0][2] * XX[2] - A[0][3] * XX[3]) / A[0][0];
		X[1] = (B[1] - A[1][1] * XX[0] - A[1][2] * XX[2] - A[1][3] * XX[3]) / A[1][1];
		X[2] = (B[2] - A[2][0] * XX[0] - A[2][1] * XX[1] - A[2][3] * XX[3]) / A[2][2];
		X[3] = (B[3] - A[3][0] * XX[0] - A[3][1] * XX[1] - A[3][2] * XX[2]) / A[3][3];

		s0 = abs(X[0] - XX[0]) > eps;
		s1 = abs(X[1] - XX[1]) > eps;
		s2 = abs(X[2] - XX[2]) > eps;
		s3 = abs(X[3] - XX[3]) > eps;
		
		cout << "k = " << k << endl;
		for (int i = 0; i < 4; i++)
			cout << setw(10) << fixed << setprecision(5) << " " << X[i] << " ";
		cout << endl << endl;
		k++;
	} while (s0 == s1 == s2 == s3 == 1);
	cout << endl << endl;

    return 0;
}

