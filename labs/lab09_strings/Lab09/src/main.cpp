#include <iostream>
#include <string>
#include <vector>

// Lab 09
// TODO: реализуйте решение по заданию в labs/lab09_strings/README.md
//
// Рекомендация по выводу:
// - без лишнего текста
// - числа через пробел
// - если несколько строк — в фиксированном порядке
void zadanie_1()
{
                                                        //C++
    std::string a;                                      
    getline(std::cin, a);                               //1
    std::cout << a <<std::endl;

    std::cout << a.length() << std::endl;               //2

    if (a.empty())                                      //3
        std::cout << "empty\n";
    else
        std::cout << "not empty\n";
    
                                                        //C
    char str_1[30]="Hallo ";                            
    std::cout << strlen(str_1) << std::endl;            //1

    char str_2[30];
    strcpy_s(str_2, str_1);                             //2
    std::cout << str_2 << std::endl;

    char subs[] = "ll";
    char* subs_ptr = strstr(str_1, subs);               //3
    std::cout << subs_ptr - str_1 << std::endl;
}



int main() {
    // Упражнения 1–3: демонстрация/анализ строковых функций (без ввода).
    // TODO: добавьте примеры и вывод результатов.
    zadanie_1();

    // Упражнение 4: ввод количества слов и самих слов.
    int word_count = 0;
    if (!(std::cin >> word_count)) {
        return 0;
    }

    std::vector<std::string> words;
    words.reserve(word_count);
    for (int i = 0; i < word_count; ++i) {
        std::string word;
        std::cin >> word;
        words.push_back(word);
    }
    for (int i = 2; i < word_count; i += 2)             //задание 4
        std::cout << words[i] << std::endl;

    // TODO: выведите слова с четными номерами (2, 4, 6, ...), по одному в строке.
    return 0;
}
