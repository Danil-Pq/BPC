#include <iostream>

class LinkedList {
private:
    // Узел списка
    struct Node {
        int data;
        Node* next;

        Node(int value) : data(value), next(nullptr) {}
    };

    Node* head; // Указатель на начало списка

public:
    // Конструктор
    LinkedList() : head(nullptr) {}

    // Деструктор (освобождает память)
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    // Добавление элемента в начало списка
    void pushFront(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Удаление элемента из начала списка
    void popFront() {
        if (head == nullptr) {
            std::cerr << "Список пуст! Невозможно вытащить." << '\n';
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Поиск элемента в списке
    bool find(int value) const {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    // Вывод содержимого списка
    void print() const {
        Node* current = head;
        std::cout << "Список: ";
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << '\n';
    }
};

int main() {
    LinkedList list;

    list.pushFront(10);
    list.pushFront(20);
    list.pushFront(30);

    list.print(); // Список: 30 20 10

    std::cout << "20 есть в списке? " << (list.find(20) ? "Да" : "Нет") << '\n'; // Да
    std::cout << "40 есть в списке? " << (list.find(40) ? "Да" : "Нет") << '\n'; // Нет

    list.popFront();
    list.print(); // Список: 20 10

    return 0;
}

Вывод
Список: 30 20 10 
20 есть в списке? Да
40 есть в списке? Нет
Список: 20 10 
