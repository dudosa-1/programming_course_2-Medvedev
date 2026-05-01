#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>

void zad_1(const char* infile, const char* outfile) {
    std::ifstream fin(infile);
    std::ofstream fout(outfile);

    int n, m;
    fin >> n >> m;

    int** A = new int* [n];
    for (int i = 0; i < n; i++) {
        A[i] = new int[n];
        for (int j = 0; j < n; j++) {
            A[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        fin >> a >> b;
        a--; b--;
        A[a][b] = 1;
        A[b][a] = 1;
    }

    fin.close();

    fout << n << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fout << A[i][j];
            if (j != n - 1) fout << " ";
        }
        fout << std::endl;
    }

    fout.close();

    for (int i = 0; i < n; i++) delete[] A[i];
    delete[] A;
}

void zad_2(const char* infile, const char* outfile) {
    std::ifstream fin(infile);
    std::ofstream fout(outfile);

    int n;
    fin >> n;

    int** A = new int* [n];
    for (int i = 0; i < n; i++) {
        A[i] = new int[n];
        for (int j = 0; j < n; j++) {
            fin >> A[i][j];
        }
    }

    fin.close();

    int* L = new int[n];
    for (int i = 0; i < n; i++) {
        L[i] = 0;
        for (int j = 0; j < n; j++) {
            if (A[i][j] == 1) L[i]++;
        }
    }

    int* S = new int[n];
    S[0] = 0;
    for (int i = 1; i < n; i++) {
        S[i] = S[i - 1] + L[i - 1];
    }

    int c = 0;
    for (int i = 0; i < n; i++) c += L[i];

    int* D = new int[c];
    int* U = new int[n];//список для коректного заполнения D
    for (int i = 0; i < n; i++) U[i] = S[i];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (A[i][j] == 1) {
                D[U[i]] = j + 1;
                U[i]++;//шагаем на следующий элемент одной вершины
            }
        }
    }

    fout << n << std::endl;

    for (int i = 0; i < n; i++) {
        fout << "L[" << i << "] = " << L[i] << std::endl;
    }
    fout << std::endl;
    for (int i = 0; i < n; i++) {
        fout << "S[" << i << "] = " << S[i] << std::endl;
    }
    fout << std::endl;
    for (int i = 0; i < c; i++) {
        fout << "D[" << i << "] = " << D[i] << std::endl;
    }
    fout.close();

    for (int i = 0; i < n; i++) delete[] A[i];
    delete[] L;
    delete[] S;
    delete[] D;
    delete[] U;
}

void zad_3(const char* infile, const char* outfile) {
    std::ifstream fin(infile);
    std::ofstream fout(outfile);

    char buffer[256];
    int n;
    fin.getline(buffer, 256);
    sscanf(buffer, "%d", &n);

    int* L = new int[n];
    for (int i = 0; i < n; i++) {
        fin.getline(buffer, 256);
        sscanf(buffer, "L[%d] = %d", &i, &L[i]);
    }

    fin.getline(buffer, 256);
    
    int* S = new int[n];
    for (int i = 0; i < n; i++) {
        fin.getline(buffer, 256);
        sscanf(buffer, "S[%d] = %d", &i, &S[i]);
    }

    fin.getline(buffer, 256);

    int c = S[n - 1] + L[n - 1];
    int* D = new int[c];
    for (int i = 0; i < c; i++) {
        fin.getline(buffer, 256);
        sscanf(buffer, "D[%d] = %d", &i, &D[i]);
    }

    fin.close();

    int** A = new int* [n];
    for (int i = 0; i < n; i++) {
        A[i] = new int[n];
        for (int j = 0; j < n; j++) {
            A[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < L[i]; j++) {
            A[i][D[j + S[i]] - 1] = 1;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (A[i][j] == 1) A[j][i] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (A[i][j] == 1) {
                fout << i + 1 << " " << j + 1 << std::endl;
            }
        }
    }

    fout.close();

    for (int i = 0; i < n; i++) delete[] A[i];
    delete[] A;
}

int main() {
    const char* inputfile = "input.txt";
    const char* output_1 = "output_1.txt";
    const char* output_2 = "output_2.txt";
    const char* output_3 = "output_3.txt";

    // Проверяем существование входного файла
    std::ifstream test(inputfile);
    if (!test) {
        std::cout << "FILE NOT" << std::endl;
        return 0;
    }
    test.close();

    zad_1(inputfile, output_1);

    std::cout << "zad_1 comp" << std::endl;

    zad_2(output_1, output_2);

    std::cout << "zad_2 comp" << std::endl;

    zad_3(output_2, output_3);

    std::cout << "zad_3 comp" << std::endl;
    return 0;
}
