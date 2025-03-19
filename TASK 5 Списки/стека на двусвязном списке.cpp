#include <iostream>

class Stack {
private:
    // Узел двусвязного списка
    struct Node {
        int data;       // Данные узла
        Node* next;     // Указатель на следующий узел
        Node* prev;     // Указатель на предыдущий узел

        Node(int value) : data(value), next(nullptr), prev(nullptr) {}
    };

    Node* top; // Указатель на вершину стека

public:
    // Конструктор
    Stack() : top(nullptr) {}

    // Деструктор (освобождает память)
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    // Проверка, пуст ли стек
    bool isEmpty() const {
        return top == nullptr;
    }

    // Добавление элемента в стек (push)
    void push(int value) {
        Node* newNode = new Node(value); // Создаем новый узел
        if (isEmpty()) {
            top = newNode; // Если стек пуст, новый узел становится вершиной
        } else {
            newNode->prev = top; // Новый узел ссылается на текущую вершину
            top->next = newNode;  // Текущая вершина ссылается на новый узел
            top = newNode;        // Обновляем вершину стека
        }
    }

    // Удаление элемента из стека (pop)
    void pop() {
        if (isEmpty()) {
            std::cerr << "Стек пуст! Невозможно вытолкнуть." << '\n';
            return;
        }
        Node* temp = top; // Сохраняем текущую вершину
        top = top->prev;  // Перемещаем вершину на предыдущий узел
        if (top != nullptr) {
            top->next = nullptr; // Убираем ссылку на удаляемый узел
        }
        delete temp; // Освобождаем память
    }

    // Получение значения вершины стека (peek)
    int peek() const {
        if (isEmpty()) {
            std::cerr << "Стек пуст! Невозможно заглянуть." << '\n';
            return -1; // Возвращаем -1 в случае ошибки
        }
        return top->data; // Возвращаем данные вершины
    }

    // Вывод содержимого стека
    void print() const {
        Node* current = top;
        std::cout << "Стек (сверху вниз): ";
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->prev; // Идем от вершины вниз
        }
        std::cout << '\n';
    }
};

int main() {
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    stack.print(); // Стек (сверху вниз): 30 20 10

    std::cout << "Верхний элемент: " << stack.peek() << '\n'; // Верхний элемент: 30

    stack.pop();
    stack.print(); // Стопка (сверху вниз): 20 10

    stack.pop();
    stack.pop();
    stack.pop(); // Стек пуст! Невозможно вытолкнуть.

    return 0;
}

Вывод 
Стек (сверху вниз): 30 20 10 
Верхний элемент: 30
Стек (сверху вниз): 20 10 
