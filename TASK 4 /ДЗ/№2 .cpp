#include <iostream>
#include <cstdlib> // для rand и srand
#include <chrono>  // для измерения времени

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
    const int size = 1000;
    int arr[size];

    // Заполнение массива случайными числами
    std::srand(std::time(0)); // Инициализация генератора случайных чисел
    for (int i = 0; i < size; ++i) {
        arr[i] = std::rand() % 10000; // Случайные числа от 0 до 9999
    }

    // Измерение времени выполнения сортировки
    auto start = std::chrono::high_resolution_clock::now();
    bubbleSort(arr, size);
    auto end = std::chrono::high_resolution_clock::now();

    // Вывод времени выполнения
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Время выполнения сортировки: " << duration.count() << " мс" << std::endl;

    return 0;
}

Вывод
Время выполнения сортировки: 5 мс

Функция srand задает начальную точку для создания ряда псевдослучайных целых чисел в текущем потоке
Функция rand возвращает псевдослучайное целое число в диапазоне от 0 до RAND_MAX (32767)
