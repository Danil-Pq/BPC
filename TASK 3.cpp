Практическая работа 1

#include <iostream>

// Функции для операций
int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
int divide(int a, int b) { return (b != 0) ? a / b : 0; }

int main() {
    // Массив указателей на функции
    int (*operations[4])(int, int) = {add, subtract, multiply, divide};

    int a, b, choice;
    std::cout << "Введите два числа: ";
    std::cin >> a >> b;

    std::cout << "Выберите операцию (0 - сложение, 1 - вычитание, 2 - умножение, 3 - деление): ";
    std::cin >> choice;

    if (choice >= 0 && choice < 4) {
        int result = operations[choice](a, b);
        std::cout << "Результат: " << result << std::endl;
    } else {
        std::cout << "Неверный выбор операции!" << std::endl;
    }

    return 0;

Практическая работа 2

#include <iostream>
#include <vector>
#include <functional>

// Функция, принимающая вектор и указатель на функцию
void processVector(std::vector<int>& vec, std::function<int(int)> func) {
    for (int& val : vec) {
        val = func(val);
    }
}

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // Удвоить значения
    processVector(numbers, [](int x) { return x * 2; });
    std::cout << "Удвоенные значения: ";
    for (int val : numbers) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // Возвести в квадрат
    processVector(numbers, [](int x) { return x * x; });
    std::cout << "Значения в квадрате: ";
    for (int val : numbers) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}

Практическая работа 3

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // Увеличить каждый элемент на 5
    std::for_each(numbers.begin(), numbers.end(), [](int& x) { x += 5; });
    std::cout << "Элементы увеличены на 5: ";
    for (int val : numbers) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // Вывести только чётные элементы
    std::cout << "Чётные элементы: ";
    std::for_each(numbers.begin(), numbers.end(), [](int x) {
        if (x % 2 == 0) {
            std::cout << x << " ";
        }
    });
    std::cout << std::endl;

    return 0;
}

Практическая работа 4

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main() {
    std::vector<std::string> words = {"apple", "banana", "kiwi", "orange"};

    // Сортировка по длине строк
    std::sort(words.begin(), words.end(), [](const std::string& a, const std::string& b) {
        return a.length() < b.length();
    });
    std::cout << "Сортировка по длине: ";
    for (const std::string& word : words) {
        std::cout << word << " ";
    }
    std::cout << std::endl;

    // Сортировка в обратном лексикографическом порядке
    std::sort(words.begin(), words.end(), [](const std::string& a, const std::string& b) {
        return a > b;
    });
    std::cout << "Обратная лексикографическая сортировка: ";
    for (const std::string& word : words) {
        std::cout << word << " ";
    }
    std::cout << std::endl;

    return 0;
}

Практическая работа 5 и 6

    std::function — универсальный контейнер для вызываемых объектов.
    Отличается от указателей на функции гибкостью и безопасностью.
    Сигнатура: std::function<возвращаемый_тип(тип_аргумента1, тип_аргумента2, ...)>.

#include <iostream>
#include <functional>

int main() {
    // Объявление std::function
    std::function<int(int, int)> operation;

    // Присваивание функции
    operation = [](int a, int b) { return a + b; };
    std::cout << "Сложение: " << operation(10, 5) << std::endl;

    operation = [](int a, int b) { return a * b; };
    std::cout << "Умножение: " << operation(10, 5) << std::endl;

    return 0;
}
