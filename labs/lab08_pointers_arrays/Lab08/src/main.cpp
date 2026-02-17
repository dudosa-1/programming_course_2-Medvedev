#include <iostream>

// Lab 08
// TODO: реализуйте решение по заданию в labs/lab08_pointers_arrays/README.md
//
// Рекомендация по выводу:
// - без лишнего текста
// - числа через пробел
// - если несколько строк — в фиксированном порядке

int Mass_1[10], Mass_2[10];
int* Mass_3, * Mass_4;


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

void zadanie_3()
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
    zadanie_3();
    delete[] Mass_3;
    delete[] Mass_4;
    // Упражнение 4: линейный самоадресуемый список из 10 элементов.
    // TODO: сформируйте список и выведите элементы по порядку.
    return 0;
}

/*
l=10: n=53.14
l=15.7: n=81.64
m=456.8130081300...
*/