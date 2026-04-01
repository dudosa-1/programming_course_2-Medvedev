#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>


void print1(double** A, int n, int m) {
	for (int i = 0; i < n; i++) {
		std::cout << "[";
		for (int j = 0; j < m; j++) {
			std::cout << A[i][j] << " ";
		}
		std::cout << "]" << std::endl;
	}

	printf("\n");
}

float eps = 0.000001;
int system(int n, int m, double** A)
{
	int i, j, k, v;
	for (i = 0; i < m - 1; i++)
	{   /*выбор ведущего элемента A[v][i]*/
		v = i;             /*выбор ведущего элемента: A[v][i]*/
		for (j = i + 1; j < n; j++)
			if (abs(A[j][i]) > abs(A[v][i])) v = j;
		if (abs(A[v][i]) < eps) return 0;
		else
		{/*перестановка  i–го уравнения с  v–м*/
			if (v != i)   /*перестановка  i–го уравнения с  v–м*/
				for (j = i; j <= m; j++)
				{
					int z = A[i][j]; A[i][j] = A[v][j]; A[v][j] = z;
				}
		}
	}
	print1(A, n, m);

	for (i = 0; i < n; i++) {
		double a = A[i][i];
		for (j = i; j < m; j++) {
			A[i][j] = A[i][j] / a;
		}
		for (j = i+1; j < n; j++) {
			double b = A[j][i];
			for (k = i; k < m; k++) {
				A[j][k] = A[j][k] - A[i][k] * b;
			}
		}
		print1(A, n, m);
	}
	return 1;
}

void xi(double** matrix, int n, int m) {
	m -= 1;
	double* x = new double[m];

	for (int i = m - 1; i >= 0; i--) {
		x[i] = matrix[i][m];
		for (int j = i + 1; j < m; j++) {
			x[i] -= matrix[i][j] * x[j];
		}
	}
	printf("Result:\n");
	for (int i = 0; i < m; i++) {
		printf("x%d = %.2lf\n", i + 1, x[i]);
	}

	delete[] x;
}

int main() {
	int n;
	int m;

	FILE* file = fopen("C:\\Users\\medve\\source\\repos\\dudosa-1\\programming_course_2-Medvedev\\labs\\lab13_linear_algebra\\Lab13\\text1.txt", "r");
	if (file == NULL) {
		printf("ERROR with FILE\n");
		return 0;
	}

	if (fscanf(file, "%d %d", &n, &m) != 2) {
		fclose(file);
		return 0;
	}

	std::cout << n << " " << m << "\n"; 
	m += 1;
	double** D = new double* [n];
	for (int i = 0; i < n; i++) {
		D[i] = new double[m];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			fscanf(file, "%lf", &D[i][j]);
		}
	}

	fclose(file);


	print1(D, n, m);

	system(n, m, D);
	xi(D, n, m);


	//print1(D, n, m);
	//for (int i = 0; i < n; i++) delete[] D[i];
	delete[]D;

    return 0;
}
