#include <iostream>
#include <fstream>


void print1(float** A, int n, int m) {
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
int system(int n, int m, float** A, float* X)
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

int main() {
	int n;
	int m;

	std::ifstream file("text1.txt");
	if (file.is_open()) {
		//int n;
		file >> n;
		//int m;
		file >> m;
	}
	else return 0;

	/*FILE* file = fopen("text1.txt", "r");
	if (file == NULL) {
		printf("ERROR with FILE\n");
		return 0;
	}

	if (fscanf(file, "%d %d", &n, &m) != 2) {
		fclose(file);
		return 0;
	}

	std::cout << n << " " << m << "\n"; */

	float** D = new float* [n];
	for (int i = 0; i < n; i++) {
		D[i] = new float[m];
		for (int j = 0; j < m; j++) {
			file >> D[i][j];
		}
	}

	float* X = new float[3] {1, 1, 1};

	print1(D, n, m);

	int g = system(n, m, D, X);

	if (g)           /* Единственное решение существует */
	{
		for (int i = 0; i < n; i++) printf("%8.3f", X[i]);
		printf("\n");
	}
	else printf("ERROR\n");
	

	print1(D, n, m);
	file.close();
	delete[]D;
	delete[]X;
    return 0;
}
