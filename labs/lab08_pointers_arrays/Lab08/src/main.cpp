#include <iostream>

// Lab 08
// TODO: реализуйте решение по заданию в labs/lab08_pointers_arrays/README.md
//
// Рекомендация по выводу:
// - без лишнего текста
// - числа через пробел
// - если несколько строк — в фиксированном порядке

int Mass_1[10], Mass_2[10];
int* Mass_3, * Mass_4, * result;


void zadanie_2(int a, int b)
{
    int* x = &a;
    std::cout << *x * 2 << std::endl;
    int& ref = b;
    std::cout << ref + 10 << std::endl;
}

void mass_tip_1()
{
    for (int i = 0; i < 10; i++)
    {
        Mass_1[i] = i * i;
    }
}

void mass_tip_2()
{
    int* p;
    p = Mass_2;
    for (int i = 0; i < 10; i++)
    {
        *p = i * i;
        p++;
    }
}

void mass_tip_3()
{
    for (int i = 0; i < 10; i++)
    {
        Mass_3[i] = i * i;
    }
}

void mass_tip_4()
{
    int* p;
    p = Mass_4;
    for (int i = 0; i < 10; i++)
    {
        *p = i * i;
        p++;
    }
}

void zadanie_3_1()
{
    mass_tip_1();
    for (int i = 0; i < 10; i++)
    {
        std::cout << Mass_1[i] << ' ';
    }
    std::cout << std::endl;

    mass_tip_2();
    for (int i = 0; i < 10; i++)
    {
        std::cout << Mass_2[i] << ' ';
    }
    std::cout << std::endl;

    mass_tip_3();
    for (int i = 0; i < 10; i++)
    {
        std::cout << Mass_3[i] << ' ';
    }
    std::cout << std::endl;

    mass_tip_4();
    for (int i = 0; i < 10; i++)
    {
        std::cout << Mass_4[i] << ' ';
    }
    std::cout << std::endl;
}

void zadanie_3_2(int arr_1[], int size_1, int arr_2[], int size_2, int result[])
{
    int i = 0, j = 0, k = 0;
    while (i < size_1 and j < size_2);
    {
        if (arr_1[i] <= arr_2[j])
        {
            result[k] = arr_1[i];
            i++;
        }
        else
        {
            result[k] = arr_2[j];
            j++;
        }
        k++;
    }
    while (i < size_1)
    {
        result[k] = arr_1[i];
        i++;
        k++;
    }
    while (j < size_2)
    {
        result[k] = arr_2[j];
        j++;
        k++;
    }
}

int main()
{
    
    // Упражнение 1: объяснить использование типов/переменных в коде (без ввода).
    // TODO: при необходимости вывести пояснения/результаты.

    // Упражнение 2: найти ошибки в коде (без ввода).
    // TODO: при необходимости вывести пояснения/результаты.
    zadanie_2(2, 4);
    // Упражнение 3: заполнить массивы (10 элементов) разными способами.
    // TODO: реализуйте 4 варианта заполнения и выведите 10 значений для каждого.
    Mass_3 = new int[10];
    Mass_4 = new int[10];
    zadanie_3_1();
    delete[] Mass_3;
    delete[] Mass_4;

    Mass_3 = new int[15] {1, 1, 3, 5, 6, 7, 9, 10, 10, 11, 12, 14, 14, 15, 16};
    int size_1 = 15;  //sizeof(Mass_3) / sizeof(Mass_3[0]);
    Mass_4 = new int[10] {0, 3, 4, 5, 6, 13, 13, 14, 15, 16};
    int size_2 = 10;  //sizeof(Mass_4) / sizeof(Mass_4[0]);
    int size_3 = size_1 + size_2;
    result = new int[size_3];
    zadanie_3_2(Mass_3, size_1, Mass_4, size_2, result);
    for (int i = 0; i < size_3; i++)
    {
        std::cout << result[i] << ' ';
    }
    std::cout << std::endl;
    delete[] Mass_3;
    delete[] Mass_4;
    delete[] result;
    // Упражнение 4: линейный самоадресуемый список из 10 элементов.
    // TODO: сформируйте список и выведите элементы по порядку.
    return 0;
}

/*
l=10: n=53.14
l=15.7: n=81.64
m=456.8130081300...
sizeof(numbers) / sizeof(numbers[0])
*/