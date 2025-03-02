#include <iostream>
#include <cstdlib> // для getenv

int main() {
    const char* userProfile = std::getenv("USERPROFILE");
    if (userProfile) {
        std::cout << "USERPROFILE: " << userProfile << '\n';
    } else {
        std::cerr << "USERPROFILE не найден." << '\n';
    }
    return 0;
}

Вывод:
USERPROFILE не найден.

Функция getenv() возвращает указатель на информацию об окружении, ассоциированную со строкой name в таблице информации окружения
