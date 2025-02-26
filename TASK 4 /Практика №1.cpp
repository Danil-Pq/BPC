#include <iostream>
#include <fstream>
#include <string>

int main() {
    setlocale(LC_CTYPE, "Russian");
    std::string filename;
    std::cout << "Введите имя файла для записи (например, output.txt): ";
    std::cin >> filename;

    std::ofstream outFile(filename);
    if (!outFile) {
        std::cerr << "Ошибка открытии файла!" << std::endl;
        return 1;
    }

    std::cin.ignore(); // Игнорировать перенос строки после ввода имени файла

    std::string line;
    std::cout << "Введите 5 строк текста:" << std::endl;
    for (int i = 0; i < 5; ++i) {
        std::getline(std::cin, line);
        outFile << line << std::endl;
    }

    outFile.close();
    std::cout << "Данные успешно записаны в файл " << filename << "." << std::endl;

    return 0;
}
