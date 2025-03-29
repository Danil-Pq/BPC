#include <iostream>
#include <algorithm>
#include <clocale>

struct Node {
    int data;
    Node* left;
    Node* right; 
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    Node* root;
    
    Node* insertRecursive(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }
        
        if (value < node->data) {
            node->left = insertRecursive(node->left, value);
        } else if (value > node->data) {
            node->right = insertRecursive(node->right, value);
        }
        
        return node;
    }
    
    bool searchRecursive(Node* node, int value) const {
        if (node == nullptr) {
            return false;
        }
        
        if (value == node->data) {
            return true;
        } else if (value < node->data) {
            return searchRecursive(node->left, value);
        } else {
            return searchRecursive(node->right, value);
        }
    }
    
    void printInOrderRecursive(Node* node) const {
        if (node != nullptr) {
            printInOrderRecursive(node->left);
            std::cout << node->data << " ";
            printInOrderRecursive(node->right);
        }
    }
    
    int getHeightRecursive(Node* node) const {
        if (node == nullptr) {
            return 0;
        }
        return 1 + std::max(getHeightRecursive(node->left), 
                           getHeightRecursive(node->right));
    }
    
    void deleteTree(Node* node) {
        if (node != nullptr) {
            deleteTree(node->left);
            deleteTree(node->right);
            delete node;
        }
    }

public:
    BinaryTree() : root(nullptr) {}
    
    ~BinaryTree() {
        deleteTree(root);
    }
    
    void insert(int value) {
        root = insertRecursive(root, value);
    }
    
    bool search(int value) const {
        return searchRecursive(root, value);
    }
    
    void printInOrder() const {
        std::cout << "Элементы дерева (in-order обход): ";
        printInOrderRecursive(root);
        std::cout << '\n';
    }
    
    int getHeight() const {
        return getHeightRecursive(root);
    }
};

int main() {
    // Устанавливаем русскую локаль для вывода
    setlocale(LC_ALL, "Russian");
    
    BinaryTree tree;
    
    std::cout << "Демонстрация работы бинарного дерева поиска\n";
    std::cout << "------------------------------------------\n";
    
    // Добавление элементов
    std::cout << "Добавляем элементы: 50, 30, 20, 40, 70, 60, 80\n";
    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);
    
    // Вывод элементов in-order
    tree.printInOrder();
    
    // Поиск элементов
    std::cout << "\nПоиск элементов в дереве:\n";
    std::cout << "Элемент 40: " << (tree.search(40) ? "найден" : "не найден") << '\n';
    std::cout << "Элемент 90: " << (tree.search(90) ? "найден" : "не найден") << '\n';
    std::cout << "Элемент 30: " << (tree.search(30) ? "найден" : "не найден") << '\n';
    
    // Высота дерева
    std::cout << "\nВысота дерева: " << tree.getHeight() << '\n';

    return 0;
}

Вывод
Демонстрация работы бинарного дерева поиска
------------------------------------------
Добавляем элементы: 50, 30, 20, 40, 70, 60, 80
Элементы дерева (in-order обход): 20 30 40 50 60 70 80 

Поиск элементов в дереве:
Элемент 40: найден
Элемент 90: не найден
Элемент 30: найден

Высота дерева: 3
