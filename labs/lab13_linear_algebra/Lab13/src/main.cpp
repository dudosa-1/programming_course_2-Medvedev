#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>  // для rand() и srand()
#include <ctime>    // для time()
#include <iomanip>

FILE* file1 = fopen("C:\\Users\\medve\\source\\repos\\dudosa-1\\programming_course_2-Medvedev\\labs\\lab13_linear_algebra\\Lab13\\text2.txt", "w");

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

void print2(double** A, int n, int m) {
	for (int i = 0; i < n; i++) {
		fprintf(file1, "[");
		for (int j = 0; j < m; j++) {
			fprintf(file1, " %.2lf", A[i][j]);
		}
		fprintf(file1, "]\n");
	}
	fprintf(file1, "\n");
}

float eps = 0.000001;

// Функция приведения к ступенчатому виду (метод Гаусса)
// Возвращает ранг матрицы
int system(int n, int m, double** A)
{
	int i, j, k, v;
	int rank = 0;

	for (i = 0; i < m - 1 && rank < n; i++)
	{
		/* выбор ведущего элемента A[v][i] */
		v = rank;
		for (j = rank + 1; j < n; j++)
			if (fabs(A[j][i]) > fabs(A[v][i])) v = j;

		if (fabs(A[v][i]) < eps) {
			continue;  // столбец линейно зависим
		}
		else
		{
			/* перестановка строк */
			if (v != rank)
				for (j = i; j < m; j++)
				{
					double z = A[rank][j];
					A[rank][j] = A[v][j];
					A[v][j] = z;
				}
		}

		// Нормировка ведущей строки
		double a = A[rank][i];
		for (j = i; j < m; j++) {
			A[rank][j] = A[rank][j] / a;
		}

		// Обнуление ниже
		for (j = rank + 1; j < n; j++) {
			double b = A[j][i];
			if (fabs(b) < eps) continue;
			for (k = i; k < m; k++) {
				A[j][k] = A[j][k] - A[rank][k] * b;
			}
		}
		rank++;
		print1(A, n, m);
	}

	print2(A, n, m);
	return rank;
}

// Единственное решение (для квадратной невырожденной системы)
void xi(double** matrix, int n, int m) {
	m -= 1;
	double* x = new double[m];

	for (int i = m - 1; i >= 0; i--) {
		x[i] = matrix[i][m];
		for (int j = i + 1; j < m; j++) {
			x[i] -= matrix[i][j] * x[j];
		}
	}
	fprintf(file1, "Unique solution:\n");
	for (int i = 0; i < m; i++) {
		fprintf(file1, "x%d = %.2lf\n", i + 1, x[i]);
	}
	delete[] x;
}

// ============= 3-е задание: ОБЩЕЕ РЕШЕНИЕ со случайными числами =============
void general_solution(double** A, int n, int m, int rank) {
	int vars = m - 1;  // количество переменных
	int free_vars = vars - rank;  // количество свободных переменных

	if (free_vars < 0) {
		fprintf(file1, "System has no solution (inconsistent).\n");
		return;
	}

	if (free_vars == 0) {
		fprintf(file1, "System has a unique solution (see above).\n");
		return;
	}

	// Инициализация генератора случайных чисел
	srand((unsigned int)time(NULL));

	// Найдём, какие столбцы — ведущие (базисные переменные)
	int* pivot_cols = new int[rank];
	int pivot_idx = 0;
	for (int j = 0; j < vars && pivot_idx < rank; j++) {
		for (int i = pivot_idx; i < n; i++) {
			if (fabs(A[i][j] - 1.0) < eps) {
				pivot_cols[pivot_idx++] = j;
				break;
			}
		}
	}

	// Массив для хранения свободных переменных
	double* free_vals = new double[vars];

	// Заполняем свободные переменные случайными числами от 0 до 9
	// По умолчанию все переменные считаем свободными, потом пометим базисные
	bool* is_free = new bool[vars];
	for (int j = 0; j < vars; j++) {
		is_free[j] = true;  // изначально считаем свободными
	}
	for (int p = 0; p < rank; p++) {
		is_free[pivot_cols[p]] = false;  // базисные переменные — не свободные
	}

	fprintf(file1, "Rank: %d\n", rank);
	//fprintf(file1, "free variables: %d\n", free_vars);

	/*// Вывод аналитического вида общего решения
	fprintf(file1, "Analytical form (general solution):\n");
	for (int i = 0; i < rank; i++) {
		int var = pivot_cols[i];
		fprintf(file1, "x%d = %.2lf", var + 1, A[i][vars]);

		for (int j = 0; j < vars; j++) {
			if (is_free[j] && fabs(A[i][j]) > eps) {
				if (A[i][j] > 0)
					fprintf(file1, " + (%.2lf)*x%d", -A[i][j], j + 1);
				else
					fprintf(file1, " - (%.2lf)*x%d", A[i][j], j + 1);
			}
		}
		fprintf(file1, "\n");
	}*/

	fprintf(file1, "\nFree variables: ");
	for (int j = 0; j < vars; j++) {
		if (is_free[j]) {
			fprintf(file1, "x%d ", j + 1);
		}
	}
	fprintf(file1, "\n");

	// ===== ПРИСВАИВАЕМ СЛУЧАЙНЫЕ ЗНАЧЕНИЯ СВОБОДНЫМ ПЕРЕМЕННЫМ =====

	for (int j = 0; j < vars; j++) {
		if (is_free[j]) {
			free_vals[j] = rand() % 10;  // случайное число от 0 до 9
		}
	}

	// Вычисляем значения базисных переменных
	double* basic_vals = new double[vars];
	for (int i = 0; i < rank; i++) {
		int var = pivot_cols[i];
		basic_vals[var] = A[i][vars];  // начинаем со свободного члена

		// Вычитаем вклад свободных переменных
		for (int j = 0; j < vars; j++) {
			if (is_free[j] && fabs(A[i][j]) > eps) {
				basic_vals[var] -= A[i][j] * free_vals[j];
			}
		}
		//fprintf(file1, "x%d = %.2lf\n", var + 1, basic_vals[var]);
	}

	// Вывод полного частного решения
	for (int j = 0; j < vars; j++) {
		if (is_free[j]) {
			fprintf(file1, "x%d = %.0lf\n", j + 1, free_vals[j]);
		}
		else {
			fprintf(file1, "x%d = %.2lf\n", j + 1, basic_vals[j]);
		}
	}

	// Очистка памяти
	delete[] pivot_cols;
	delete[] free_vals;
	delete[] is_free;
	delete[] basic_vals;
}

int main() {
	int n, m;

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

	// Расширенная матрица: m столбцов коэффициентов + 1 столбец свободных членов
	int extended_m = m + 1;
	double** D = new double* [n];
	for (int i = 0; i < n; i++) {
		D[i] = new double[extended_m];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < extended_m; j++) {
			fscanf(file, "%lf", &D[i][j]);
		}
	}
	fclose(file);

	print1(D, n, extended_m);

	// Приводим к ступенчатому виду и получаем ранг
	int rank = system(n, extended_m, D);

	// Проверка на совместность (последний столбец не должен создавать противоречие)
	bool consistent = true;
	for (int i = rank; i < n; i++) {
		bool all_zero = true;
		for (int j = 0; j < extended_m - 1; j++) {
			if (fabs(D[i][j]) > eps) {
				all_zero = false;
				break;
			}
		}
		if (all_zero && fabs(D[i][extended_m - 1]) > eps) {
			consistent = false;
			break;
		}
	}

	if (!consistent) {
		fprintf(file1, "System has no solution.\n");
	}
	else if (rank == m) {
		// Единственное решение
		xi(D, n, extended_m);
	}
	else {
		// Общее решение со случайными числами
		general_solution(D, n, extended_m, rank);
	}

	fclose(file1);

	// Очистка памяти
	for (int i = 0; i < n; i++) delete[] D[i];
	delete[] D;

	return 0;
}