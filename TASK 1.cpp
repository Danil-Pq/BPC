1-ая Практическая работа 
  
#include <iostream>
#include <string>

using namespace std;

// Структура для хранения информации о студенте
struct Student {
    string name;   // Имя студента
    int age;       // Возраст студента
    float gpa;     // Средний балл
    string faculty; // Название факультета
};

// Структура для хранения информации о городе
struct City {
    string cityName;     // Название города
    string countryName;  // Название страны
    int population;      // Население города
};

// Структура для хранения информации о университете
struct University {
    string universityName; // Название университета
    City location;         // Местоположение университета
    Student students[3];   // Список студентов (массив из 3-х объектов типа Student)
};

int main() {
    // Создаем объект структуры University и инициализируем его значениями
    University university;

    university.universityName = "Примерный Университет";
    university.location.cityName = "Москва";
    university.location.countryName = "Россия";
    university.location.population = 12000000; // Примерное население

    // Инициализация студентов
    university.students[0] = {"Иван Иванов", 20, 4.5, "Факультет компьютерных наук"};
    university.students[1] = {"Мария Петрова", 22, 4.7, "Факультет экономики"};
    university.students[2] = {"Сергей Сидоров", 21, 4.2, "Факультет математики"};

    // Вывод информации о университете
    cout << "Название университета: " << university.universityName << endl;
    cout << "Город: " << university.location.cityName << ", Страна: " << university.location.countryName << endl;
    cout << "Население города: " << university.location.population << endl;
    cout << "Студенты:" << endl;

    for (int i = 0; i < 3; ++i) {
        cout << "Имя: " << university.students[i].name << ", Возраст: " << university.students[i].age
             << ", Средний балл: " << university.students[i].gpa << ", Факультет: " << university.students[i].faculty << endl;
    }

    return 0;
}

2-ая Практическая работа 

#include <iostream>
#include <cmath>
#include <string>

struct Point {
    int x; // координата x
    int y; // координата y
    std::string color; // цвет точки
    Point* next; // указатель на следующую точку

    Point(int x_val, int y_val, const std::string& col)
        : x(x_val), y(y_val), color(col), next(nullptr) {}
};

// Функция для вычисления расстояния между двумя точками
double distance(Point* p1, Point* p2) {
    return std::sqrt(std::pow(p2->x - p1->x, 2) + std::pow(p2->y - p1->y, 2));
}

// Функция для получения указателя на точку с наименьшими координатами
Point* getMinPoint(Point* head) {
    if (!head) return nullptr;

    Point* minPoint = head;
    Point* current = head;

    do {
        if ((current->x < minPoint->x) || (current->x == minPoint->x && current->y < minPoint->y)) {
            minPoint = current;
        }
        current = current->next;
    } while (current != head);

    return minPoint;
}

// Функция для вычисления периметра многоугольника
double calculatePerimeter(Point* head) {
    if (!head) return 0.0;

    double perimeter = 0.0;
    Point* current = head;

    do {
        Point* nextPoint = current->next;
        if (nextPoint == nullptr) break; // На случай если указатель указывает на ноль

        perimeter += distance(current, nextPoint);
        current = nextPoint;
    } while (current != head);

    return perimeter;
}

// Функция для вывода информации о цвете точки
void printPointColor(Point* point) {
    if (point) {
        std::cout << "Цвет точки: " << point->color << std::endl;
    }
}

int main() {
    // Создание точек и их связывание
    Point* p1 = new Point(1, 2, "red");
    Point* p2 = new Point(3, 4, "green");
    Point* p3 = new Point(0, 1, "blue");

    p1->next = p2;
    p2->next = p3;
    p3->next = p1; // Циклический список

    // Результаты работы функций
    std::cout << "Расстояние между p1 и p2: " << distance(p1, p2) << std::endl;
    
    Point* minPoint = getMinPoint(p1);
    if (minPoint) {
        std::cout << "Точка с минимальными координатами: (" << minPoint->x << ", " << minPoint->y << ")" << std::endl;
    }

    double perimeter = calculatePerimeter(p1);
    std::cout << "Периметр многоугольника: " << perimeter << std::endl;

    // Вывод цвета точки
    printPointColor(p1);
    printPointColor(p2);
    printPointColor(p3);

    return 0;
}

3 Практическая работа 

#include <iostream>

struct Person {
    char gender;  // Пол (1 байт)
    int age;      // Возраст (4 байта)
    double gpa;   // Средний балл (8 байт)
};

int main() {
    Person person; // Создание объекта структуры
    person.gender = 'M'; // Инициализация поля gender
    person.age = 21;     // Инициализация поля age
    person.gpa = 4.5;    // Инициализация поля gpa

    // Вывод размеров структуры и её полей
    std::cout << "Размер структуры Person: " << sizeof(person) << " байт" << std::endl;
    std::cout << "Сумма размеров полей: " 
              << sizeof(person.gender) + sizeof(person.age) + sizeof(person.gpa) 
              << " байт" << std::endl;

    // Изменение порядка полей в структуре
    struct PersonReordered {
        double gpa;   // Средний балл (8 байт)
        char gender;  // Пол (1 байт)
        int age;      // Возраст (4 байта)
    };

    std::cout << "Размер структуры PersonReordered: " << sizeof(PersonReordered) << " байт" << std::endl;

    return 0;
}
