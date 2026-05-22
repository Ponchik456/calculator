cmake_minimum_required(VERSION 3.10)
project(SimpleCalculator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Основной исполняемый файл калькулятора
add_executable(calculator main.cpp calculator.cpp)

# Исполняемый файл для тестов
add_executable(tests tests.cpp calculator.cpp)

# Указываем CMake, где искать заголовочные файлы Google Test
target_include_directories(tests PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/googletest/googletest/include
)

# Связываем библиотеки GoogleTest
target_link_libraries(tests PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/googletest/build/lib/Release/gtest.lib
    ${CMAKE_CURRENT_SOURCE_DIR}/googletest/build/lib/Release/gtest_main.lib
)

# Включаем тестирование
enable_testing()
add_test(NAME CalculatorTests COMMAND tests)
