#include <iostream>

class Stack {
private:
    // Узел списка
    struct Node {
        int data;       // Данные узла
        Node* next;    // Указатель на следующий узел

        Node(int value) : data(value), next(nullptr) {}
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
        newNode->next = top;            // Новый узел указывает на текущую вершину
        top = newNode;                  // Обновляем вершину стека
    }

    // Удаление элемента из стека (pop)
    void pop() {
        if (isEmpty()) {
            std::cerr << "Стек пуст! Невозможно вытолкнуть." << '\n';
            return;
        }
        Node* temp = top; // Сохраняем текущую вершину
        top = top->next;  // Перемещаем вершину на следующий узел
        delete temp;      // Освобождаем память
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
        std::cout << "Куча: ";
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << '\n';
    }
};

int main() {
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    stack.print(); // Куча: 30 20 10 

    std::cout << "Верхний элемент: " << stack.peek() << '\n'; // Верхний элемент: 30

    stack.pop();
    stack.print(); // Куча: 20 10 

    stack.pop();
    stack.pop();
    stack.pop(); // Стек пуст! Невозможно вытолкнуть.

    return 0;
}

Вывод
Куча: 30 20 10 
Верхний элемент: 30
Куча: 20 10 
