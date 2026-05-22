#include <iostream>
#include <windows.h>
#include <string>
#include "calculator.h"

int main() {
    Calculator calc;
    std::string expression;
    SetConsoleOutputCP(1251);  // Устанавливаем кодировку для вывода (Windows-1251)
    SetConsoleCP(1251);        // Устанавливаем кодировку для ввода (чтобы ввод с клавиатуры тоже работал)


    std::cout << "Простой калькулятор (введите 'exit' для выхода)\n";
    std::cout << "Поддерживаемые операции: +, -, *, /, (), ^ (возведение в степень)\n";

    while (true) {
        std::cout << "> ";
        std::getline(std::cin, expression);

        if (expression == "exit") {
            break;
        }

        try {
            double result = calc.calculate(expression);
            std::cout << "Результат: " << result << "\n";
        } catch (const std::exception& e) {
            std::cout << "Ошибка: " << e.what() << "\n";
        }
    }

    return 0;
}
