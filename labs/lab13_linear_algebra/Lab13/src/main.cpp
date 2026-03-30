#include <iostream>
#include <cstdlib>

float eps = 0.000001;
int system(int n, float** A, float* X)
{
	int i, j, k, v;
	for (i = 0; i < n - 1; i++)
	{   /*выбор ведущего элемента A[v][i]*/
		v = i;             /*выбор ведущего элемента: A[v][i]*/
		for (j = i + 1; j < n; j++)
			if (abs(A[j][i]) > abs(A[v][i])) v = j;
		if (abs(A[v][i]) < eps) return 0;
		else
		{/*перестановка  i–го уравнения с  v–м*/
			if (v != i)   /*перестановка  i–го уравнения с  v–м*/
				for (j = i; j <= n; j++)
				{
					int z = A[i][j]; A[i][j] = A[v][j]; A[v][j] = z;
				}
		 /*вычитание уравнений*/
			for (k = i + 1; k < n; k++) /*вычитание уравнений*/
			{
				int c = A[k][i] / A[i][i];
				for (j = i; j <= n; j++)
					A[k][j] -= c * A[i][j];
			}
		}
	}
	/*обратный ход*/
	for (i = n - 1; i >= 1; i--)
	{
		for (k = 0; k < i - 1; k++)     /*вычитание уравнений*/
		{
			int c = A[k][i] / A[i][i];
			A[k][n] -= c * A[i][n];
			A[k][i] = 0;
		}
	}
	/*вычисление неизвестных*/
	for (i = 0; i < n; i++)
		X[i] = A[i][n] / A[i][i];
	return 1;
}

int main() {


	int n = 3;
	float** D = new float* [n];
	for (int i = 0; i < n; i++) {
		D[i] = new float[n];
		for (int j = 0; j < n; j++) {
			D[i][j] = rand()%100;
		}
	}

	float* X = new float[3] {1, 1, 1};

	for (int i = 0; i < n; i++) {
		std::cout << "[";
		for (int j = 0; j < n; j++) {
			std::cout << D[i][j] << " ";
		}
		std::cout << "]" << std::endl;
	}

	printf("\n");

	int g = system(n, D, X);

	if (g)           /* Единственное решение существует */
	{
		for (int i = 0; i < n; i++) printf("%8.3f", X[i]);
		printf("\n");
	}
	else printf("ERROR\n");
	/*for (int i = 0; i < n - 1; i++) {
		int v = i;             /*выбор ведущего элемента: A[v][i]*
		for (int j = i + 1; j < n; j++)
			if (abs(D[j][i]) > abs(D[v][i])) v = j;
		if (v != i)   /*перестановка  i–го уравнения с  v–м*
			for (int j = i; j <= n; j++)
			{
				int z = D[i][j]; 
				D[i][j] = D[v][j]; 
				D[v][j] = z;
			}
		for (int k = i + 1; k < n; k++) /*вычитание уравнений*
		{
			int c = D[k][i] / D[i][i];
			for (int j = i; j <= n; j++)
				D[k][j] -= c * D[i][j];
		}
	}
   */

	for (int i = 0; i < n; i++) {
		std::cout << "[";
		for (int j = 0; j < n; j++) {
			std::cout << D[i][j] << " ";
		}
		std::cout << "]" << std::endl;
	}

	printf("\n");


    return 0;
}
