#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
// Lab 10
// TODO: реализуйте решение по заданию в labs/lab10_functions/README.md
//
// Рекомендация по выводу:
// - без лишнего текста
// - числа через пробел
// - если несколько строк — в фиксированном порядке

void komp(int arr[], int size, int d_komp[])
{
    for (int i = 0; i < 18; i++)
    {
        d_komp[i] = 0;
    }
    int i = 0, j = 0;
    while (i < size) 
    {
        if (arr[i] == j)
        {
            d_komp[j]++;
            i++;
        }
        else
        {
            j++;
        }
    }
    

    for (int i = 0; i < 18; i++) std::cout << d_komp[i] << " ";
    std::cout << std::endl;
}

void unpac(int arr_1[], int size_1, int arr_2[], int size_2)
{
    for (int i = 0; i < size_2; i++) arr_2[i] = 0;

    int i = 0, j = 0;
    while (i < size_1)
    {
        if (arr_1[i] != 0)
        {
            arr_2[j] = i;
            arr_1[i] -= 1;
            j++;
        }
        else
        {
            i++;
        }
    }
    for (int i = 0; i < size_2; i++) std::cout << arr_2[i] << " ";
    std::cout << std::endl;
}


int main()
{
    srand(time(NULL));
    int* d_ful;
    int* d_komp;
    d_komp = new int[18];
    int size_ful = 10;// (rand() % 1000) + 1000;
    d_ful = new int[size_ful]; //{17, 0, 1, 2, 3, 3, 3, 6, 10, 17};
    for (int i = 0; i < size_ful; i++) d_ful[i] = rand() % 18;
    std::sort(d_ful, d_ful + size_ful);
    std::cout << size_ful * sizeof(int) << std::endl;
    for (int i = 0; i < size_ful; i++) std::cout << d_ful[i] << " ";
    std::cout<<std::endl;
    komp(d_ful, size_ful, d_komp);
    std::cout << 18 * sizeof(int) << std::endl;
    unpac(d_komp, 18, d_ful, size_ful);
    delete[]d_ful;
    delete[]d_komp;
    std::cout << size_ful;
    // TODO
    return 0;
}

