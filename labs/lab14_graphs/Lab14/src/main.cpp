#include <iostream>
#include <fstream>

void zad_1(const char* infile, const char* outfile) {
    std::ifstream fin(infile);
    std::ofstream fout(outfile);

    int n, m;
    fin >> n >> m;

    int** D = new int* [n];
    for (int i = 0; i < n; i++) {
        D[i] = new int[n];
        for (int j = 0; j < n; j++) {
            D[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        fin >> a >> b;
        a--; b--;
        D[a][b] = 1;
        D[b][a] = 1;
    }

    fin.close();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fout << D[i][j];
            if (j != n - 1) fout << " ";
        }
        fout << std::endl;
    }

    fout.close();

    for (int i = 0; i < n; i++) delete[] D[i];
    delete[] D;
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

    std::cout << "comp" << std::endl;
    return 0;
}
