#include <iostream>
#include <regex>
#include <string>

void findEmails(const std::string& input) {
    // Регулярное выражение для поиска email-адресов
    std::regex emailRegex(R"(\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Z|a-z]{2,}\b)");
    auto words_begin = std::sregex_iterator(input.begin(), input.end(), emailRegex);
    auto words_end = std::sregex_iterator();

    std::cout << "Найденные email-адреса:" << std::endl;
    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
        std::smatch match = *i;
        std::string match_str = match.str();
        std::cout << match_str << std::endl;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    std::string input;
    std::cout << "Введите строку для поиска email-адресов: ";
    std::getline(std::cin, input);

    findEmails(input);

    return 0;
}
