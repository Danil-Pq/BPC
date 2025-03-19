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
            std::cerr << "Stack is empty! Cannot pop." << '\n';
            return;
        }
        Node* temp = top; // Сохраняем текущую вершину
        top = top->next;  // Перемещаем вершину на следующий узел
        delete temp;      // Освобождаем память
    }

    // Получение значения вершины стека (peek)
    int peek() const {
        if (isEmpty()) {
            std::cerr << "Stack is empty! Cannot peek." << '\n';
            return -1; // Возвращаем -1 в случае ошибки
        }
        return top->data; // Возвращаем данные вершины
    }

    // Вывод содержимого стека
    void print() const {
        Node* current = top;
        std::cout << "Stack: ";
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

    stack.print(); // Stack: 30 20 10

    std::cout << "Top element: " << stack.peek() << '\n'; // Top element: 30

    stack.pop();
    stack.print(); // Stack: 20 10

    stack.pop();
    stack.pop();
    stack.pop(); // Stack is empty! Cannot pop.

    return 0;
}

Вывод 
Stack: 30 20 10 
Top element: 30
Stack: 20 10 
