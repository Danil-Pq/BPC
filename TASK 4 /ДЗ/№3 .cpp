#include <iostream>
#include <fstream>
#include <cstdlib> // для rand и srand
#include <chrono>  // для измерения времени
#include <vector>
#include <algorithm> // для sort

int main() {
    setlocale(LC_ALL, "Russian");
    const std::string filename = "numbers.txt";
    const int count = 10;

    // Запись случайных чисел в файл
    std::ofstream outFile(filename);
    if (!outFile) {
        std::cerr << "Ошибка открытия файла для записи." << '\n';
        return 1;
    }

    std::srand(std::time(0)); // Инициализация генератора случайных чисел
    for (int i = 0; i < count; ++i) {
        outFile << std::rand() % 100 << '\n'; // Случайные числа от 0 до 99
    }
    outFile.close();

    // Чтение чисел из файла
    std::ifstream inFile(filename);
    if (!inFile) {
        std::cerr << "Ошибка открытия файла для чтения." << '\n';
        return 1;
    }

    std::vector<int> numbers;
    int number;
    while (inFile >> number) {
        numbers.push_back(number);
    }
    inFile.close();

    // Измерение времени выполнения сортировки
    auto start = std::chrono::high_resolution_clock::now();
    std::sort(numbers.begin(), numbers.end()); // Сортировка
    auto end = std::chrono::high_resolution_clock::now();

    // Вывод отсортированных чисел
    std::cout << "Отсортированные числа: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << '\n';

    // Вывод времени выполнения
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Время выполнения сортировки: " << duration.count() << " мкс" << '\n';

    return 0;
}

Вывод
Отсортированные числа: 8 18 45 47 53 53 60 82 88 99
Время выполнения сортировки: 2 мкс

