#include <iostream>
#include <fstream>
#include <string>

int main() {
    setlocale(LC_CTYPE, "Russian");
    std::ifstream inFile("data.txt");
    if (!inFile) {
        std::cerr << "Ошибка открытии файла!" << std::endl;
        return 1;
    }

    std::string line;
    std::cout << "Строки, содержащие 'C++':" << std::endl;
    while (std::getline(inFile, line)) {
        if (line.find("C++") != std::string::npos) {
            std::cout << line << std::endl;
        }
    }

    inFile.close();
    return 0;
}
Вывод:
  Строки, содержащие 'C++':
  C++ programming language

Текст в файле:
  C++ programming language 
  It allows you to work with files
