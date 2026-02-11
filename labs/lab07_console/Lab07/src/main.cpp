#include <iostream>

// Lab 07
// TODO: реализуйте решение по заданию в labs/lab07_console/README.md
//
// Рекомендация по выводу:
// - без лишнего текста
// - числа через пробел
// - если несколько строк — в фиксированном порядке
int main() {
    // Задание 1: вычисление значений функции.
    // Ввод: x0 — начальная точка интервала.
    // test
    double x0;
    std::cin >> x0;
    if (x0 > 0 and x0 <= 4)
    {
        double a = (4 - x0) / 10;
        for (int i{ 0 }; i < 10; i++)
        {
            std::cout << sin(x0) / x0 << ' ';
            x0 = x0 + a;
        }
    }
    // dfdfdf
    // // dfd/df
    // /dfdfd
    // TODO: вычислите и выведите 10 значений функции на (0, 4].

    // Задание 2: сумма чисел Фибоначчи.
    // Ввод: MAX — ограничение на сумму.
    long long max_value;
    std::cin >> max_value;
    long long x = 0;
    long long y = 1;
    long long z = 0;
    long long sum = 1;
    int n = 1;
    if (max_value < 1)
    {
        std::cout << 0 << ' ' << 0;
    }
    else
    {
        if (max_value < 2)
        {
            std::cout << 1 << ' ' << 1;
        }
        else
        {
            while (sum <= max_value)
            {
                n++;
                z = y;
                y = x + y;
                sum = sum + y;
                x = z;
            }
            std::cout << n - 1 << ' ' << sum-y;
        }
    }
    return 0;
}
    

    // TODO: вычислите N и S (S <= MAX) и выведите результаты.
