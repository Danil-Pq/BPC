#include <iostream>
#include <cstdlib> // для rand и srand
#include <chrono>  // для измерения времени

// Функция для вывода массива
void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// Функция пузырьковой сортировки
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    const int size = 1000;
    int arr[size];

    // Заполнение массива случайными числами
    std::srand(static_cast<unsigned int>(std::time(0))); // Инициализация генератора случайных чисел
    for (int i = 0; i < size; ++i) {
        arr[i] = std::rand() % 10000; // Случайные числа от 0 до 9999
    }

    // Вывод массива до сортировки
    std::cout << "Массив до сортировки:" << std::endl;
    printArray(arr, size);

    // Измерение времени выполнения сортировки
    auto start = std::chrono::high_resolution_clock::now();
    bubbleSort(arr, size);
    auto end = std::chrono::high_resolution_clock::now();

    // Вывод времени выполнения
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Время выполнения сортировки: " << duration.count() << " мс" << std::endl;

    // Вывод массива после сортировки
    std::cout << "Массив после сортировки:" << std::endl;
    printArray(arr, size);

    return 0;
}


Вывод
Время выполнения сортировки: 5 мс

Функция srand задает начальную точку для создания ряда псевдослучайных целых чисел в текущем потоке
Функция rand возвращает псевдослучайное целое число в диапазоне от 0 до RAND_MAX (32767)
