1. Шаблонная функция для произведения двух аргументов

#include <iostream>

// Шаблонная функция для произведения двух аргументов
template <typename T1, typename T2>
auto multiply(T1 a, T2 b) -> decltype(a * b) {
    return a * b;
}

int main() {
    // Тестирование с разными типами
    std::cout << "multiply(3, 4.5) = " << multiply(3, 4.5) << std::endl;       // int и double
    std::cout << "multiply(2.5f, 4) = " << multiply(2.5f, 4) << std::endl;     // float и int
    std::cout << "multiply(1.2, 3.4) = " << multiply(1.2, 3.4) << std::endl;   // double и double

    return 0;
}
2. Механизм захвата переменных в лямбда-функциях и std::function
Лямбда-функции могут захватывать переменные из окружающей области видимости:

Захват по значению ([=]): Создаётся копия переменной.

Захват по ссылке ([&]): Переменная используется по ссылке.

std::function может хранить лямбда-функции с захватом переменных, так как он поддерживает вызов любых вызываемых объектов. Указатели на функции не поддерживают захват переменных, так как они работают только с обычными функциями, которые не имеют состояния (контекста).

3. Лямбда с захватом переменных

#include <iostream>

int main() {
    int multiplier = 2;
    int adder = 10;

    // Лямбда с захватом по значению
    auto lambdaByValue = [multiplier, adder](int x) {
        return x * multiplier + adder;
    };

    // Лямбда с захватом по ссылке
    auto lambdaByRef = [&multiplier, &adder](int x) {
        multiplier += 1; // Изменяем переменные по ссылке
        adder += 5;
        return x * multiplier + adder;
    };

    std::cout << "lambdaByValue(5) = " << lambdaByValue(5) << std::endl; // 5 * 2 + 10 = 20
    std::cout << "lambdaByRef(5) = " << lambdaByRef(5) << std::endl; // 5 * 3 + 15 = 30

    std::cout << "После вызова lambdaByRef: multiplier = " << multiplier << ", adder = " << adder << std::endl;

    return 0;
}
4. Сравнение строк через указатель на функцию

#include <iostream>
#include <string>
#include <cctype> // для std::tolower

// Функция сравнения с учётом регистра
bool caseSensitiveCompare(const std::string& a, const std::string& b) {
    return a == b;
}

// Функция сравнения без учёта регистра
bool caseInsensitiveCompare(const std::string& a, const std::string& b) {
    if (a.length() != b.length()) return false;
    for (size_t i = 0; i < a.length(); ++i) {
        if (std::tolower(a[i]) != std::tolower(b[i])) return false;
    }
    return true;
}

int main() {
    std::string str1 = "Hello";
    std::string str2 = "hello";

    // Указатель на функцию
    bool (*compareFunction)(const std::string&, const std::string&);

    // Сравнение с учётом регистра
    compareFunction = caseSensitiveCompare;
    std::cout << "Сравнение с учётом регистра: " << (compareFunction(str1, str2) ? "равны" : "не равны") << std::endl;

    // Сравнение без учёта регистра
    compareFunction = caseInsensitiveCompare;
    std::cout << "Сравнение без учёта регистра: " << (compareFunction(str1, str2) ? "равны" : "не равны") << std::endl;

    return 0;
}
