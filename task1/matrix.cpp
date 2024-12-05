#include "matrix.hpp"
#include <iostream>

Matrix::Matrix(int numRows, int numCols) 
    : m_row(numRows), m_col(numCols) {
    AllocateMemory();
}

Matrix::~Matrix() { 
    DeallocateMemory();
}

void Matrix::Reset(int numRows, int numCols) {
    DeallocateMemory();  // Освобождаем старую память
    
    if (numRows <= 0 || numCols <= 0) {
        m_row = 0;
        m_col = 0;
    } else {
        m_row = numRows;
        m_col = numCols;
        AllocateMemory();
    }
}

int& Matrix::At(int row, int col) {
    CheckBounds(row, col);
    return numbers[row][col];
}

const int& Matrix::At(int row, int col) const {
    CheckBounds(row, col);
    return numbers[row][col];
}

int Matrix::GetRows() const {
    return m_row;
}

int Matrix::GetCols() const {
    return m_col;
}

bool Matrix::operator==(const Matrix& m2) const {
    if (m_row != m2.m_row || m_col != m2.m_col) return false;
    for (int i = 0; i < m_row; ++i) {
        for (int j = 0; j < m_col; ++j) {
            if (numbers[i][j] != m2.numbers[i][j]) {
                return false;
            }
        }
    }
    return true;
}

bool Matrix::operator!=(const Matrix& m2) const {
    return !(*this == m2);
}

Matrix Matrix::operator+(const Matrix& m2) const {
    if (m_row != m2.m_row || m_col != m2.m_col) {
        throw std::invalid_argument("Matrices dimensions do not match");
    }

    Matrix sum_matrix(m_row, m_col);
    for (int i = 0; i < m_row; ++i) {
        for (int j = 0; j < m_col; ++j) {
            sum_matrix.At(i, j) = this->At(i, j) + m2.At(i, j);
        }
    }
    return sum_matrix;
}

void Matrix::AllocateMemory() {
    if (m_row > 0 && m_col > 0) {
        numbers = new int*[m_row]; // Выделяем память для массива
        for (int i = 0; i < m_row; ++i) {
            numbers[i] = new int[m_col]{0};  // Инициализация нулями
        }
    } else {
        numbers = nullptr; // Указываем на nullptr, если размеры некорректны
    }
}

void Matrix::DeallocateMemory() {
    if (numbers) {
        for (int i = 0; i < m_row; ++i) {
            delete[] numbers[i]; // Освобождаем каждый из массивов
        }
        delete[] numbers; // Освобождаем массив
        numbers = nullptr; // Устанавливаем указатель в nullptr для безопасности
    }
}

void Matrix::CheckBounds(int row, int col) const {
    if (row < 0 || row >= m_row || col < 0 || col >= m_col) {
        throw std::out_of_range("Index out of range");
    }
}
