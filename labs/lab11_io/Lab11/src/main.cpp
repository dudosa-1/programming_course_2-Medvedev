#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>

// Lab 11
// TODO: реализуйте решение по заданию в labs/lab11_io/README.md
//
// Рекомендация по выводу:
// - без лишнего текста
// - числа через пробел
// - если несколько строк — в фиксированном порядке

bool Root(char* root, char* word) {
    int i = 0;
    while (root[i] != '\0') {
        if (root[i] != word[i]) {
            return false;
        }
        i++;
    }
    return true;
}


int main() {
    char words[50][26];
    int wordCount = 0;

    FILE* fin = fopen("text.txt", "r");
    if (fin == NULL) {
        printf("ERROR with [input] file");
        return 0;
    }

    // пока не конец файла
    while (!feof(fin) and wordCount < 50) {
        if (fscanf(fin, "%25s", words[wordCount]) == 1) {
            wordCount++;
        }
    }
    fclose(fin);

    int longInd = -1;
    int longRoot = -1;

    int mostRootInd = -1;
    int CountMostRoot = -1;


    for (int i = 0; i < wordCount; ++i) {
        int Count = 0; //текущие кол-во слов с этим корнем

        for (int j = 0; j < wordCount; ++j) {
            if ((!(i == j)) and Root(words[i], words[j])) { Count++; }
        }

        if (Count > 0) {
            int currentLength = strlen(words[i]); //текущая длинна слова

            if (currentLength > longRoot) {
                longRoot = currentLength;
                longInd = i;
            }

            if (Count > CountMostRoot) {
                CountMostRoot = Count;
                mostRootInd = i;
            }
        }
    }

    FILE* finish1 = fopen("fin1.txt", "w");
    if (longInd == -1) {
        fprintf(finish1, "NO\n");
    }
    else {
        fprintf(finish1, "%s:\n", words[longInd]);
        for (int j = 0; j < wordCount; ++j) {
            if (longInd != j and Root(words[longInd], words[j])) {
                fprintf(finish1, "%s\n", words[j]);
            }
        }
    }
    fclose(finish1);

    FILE* finish2 = fopen("fin2.txt", "w");
    if (mostRootInd == -1) {
        fprintf(finish2, "NO\n");
    }
    else {
        fprintf(finish2, "%s %d\n", words[mostRootInd], CountMostRoot); //str, целое число
    }
    fclose(finish2);

    std::cout << "completed" << std::endl;

    return 0;
}
