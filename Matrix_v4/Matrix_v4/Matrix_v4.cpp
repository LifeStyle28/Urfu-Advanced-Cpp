#include <iostream>
#include <vector>
#include <stdexcept>
#include "Matrix.h"
using namespace std;

int main() {
    try {
        // Создание матрицы по умолчанию
        Matrix m1;
        cout << "Matrix m1 (default):\n" << m1 << "\n";

        // Создание матрицы с заданными размерами
        Matrix m2(2, 3);
        cout << "Matrix m2 (2x3):\n" << m2 << "\n";

        // Установка значений в матрице
        m2.At(0, 0) = 1;
        m2.At(0, 1) = 2;
        m2.At(0, 2) = 3;
        m2.At(1, 0) = 4;
        m2.At(1, 1) = 5;
        m2.At(1, 2) = 6;
        cout << "Matrix m2 after setting values:\n" << m2 << "\n";

        // Использование конструктора копирования
        Matrix m3 = m2;
        cout << "Matrix m3 (copy of m2):\n" << m3 << "\n";

        // Использование оператора перемещения
        Matrix m4 = move(m3);
        cout << "Matrix m4 (moved from m3):\n" << m4 << "\n";

        // Проверка метода Reset
        m4.Reset(3, 2);
        cout << "Matrix m4 after Reset to 3x2:\n" << m4 << "\n";

        // Проверка операторов ввода и вывода
        cout << "Enter a matrix (format: rows cols followed by elements):\n";
        Matrix m5;
        cin >> m5;
        cout << "Matrix m5 (input):\n" << m5 << "\n";

        // Проверка оператора равенства
        cout << "m2 == m5: " << (m2 == m5 ? "true" : "false") << "\n";

        // Проверка оператора сложения
        Matrix m6(2, 3);
        m6.At(0, 0) = 7;
        m6.At(0, 1) = 8;
        m6.At(0, 2) = 9;
        m6.At(1, 0) = 10;
        m6.At(1, 1) = 11;
        m6.At(1, 2) = 12;
        cout << "Matrix m6:\n" << m6 << "\n";

        Matrix m7 = m2 + m6;
        cout << "Matrix m7 (m2 + m6):\n" << m7 << "\n";

    }
    catch (const out_of_range& e) {
        cerr << "Out of range error: " << e.what() << "\n";
    }
    catch (const invalid_argument& e) {
        cerr << "Invalid argument error: " << e.what() << "\n";
    }

    return 0;
}