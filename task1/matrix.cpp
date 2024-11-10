#include "matrix.hpp"
#include <stdexcept>
#include <iostream>

Matrix::Matrix(int numRows, int numCols) {
    if (numRows < 0 || numCols < 0) {
        throw std::out_of_range("Matrix dimensions cannot be negative");
    }
    this->numRows = numRows;
    this->numCols = numCols;
    data.assign(numRows, std::vector<int>(numCols, 0));
}

void Matrix::Reset(int numRows, int numCols) {
    if (numRows < 0 || numCols < 0) {
        throw std::out_of_range("Matrix dimensions cannot be negative");
    }
    this->numRows = numRows;
    this->numCols = numCols;
    data.assign(numRows, std::vector<int>(numCols, 0));
}

int& Matrix::At(int row, int col) {
    if (row < 0 || row >= numRows || col < 0 || col >= numCols) {
        throw std::out_of_range("Index out of range");
    }
    return data[row][col];
}

const int& Matrix::At(int row, int col) const {
    if (row < 0 || row >= numRows || col < 0 || col >= numCols) {
        throw std::out_of_range("Index out of range");
    }
    return data[row][col];
}

bool Matrix::operator==(const Matrix& m2) const {
    return numRows == m2.numRows && numCols == m2.numCols && data == m2.data;
}

bool Matrix::operator!=(const Matrix& m2) const {
    return !(*this == m2);
}

Matrix Matrix::operator+(const Matrix& m2) const {
    if (numRows != m2.numRows || numCols != m2.numCols) {
        throw std::invalid_argument("Matrix dimensions must match for addition");
    }
    Matrix result(numRows, numCols);
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            result.data[i][j] = data[i][j] + m2.data[i][j];
        }
    }
    return result;
}

std::istream& operator>>(std::istream& is, Matrix& matrix) {
    int rows, cols;
    is >> rows >> cols;
    matrix.Reset(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            is >> matrix.data[i][j];
        }
    }
    return is;
}

std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
    os << matrix.numRows << " " << matrix.numCols << "\n";
    for (int i = 0; i < matrix.numRows; ++i) {
        for (int j = 0; j < matrix.numCols; ++j) {
            os << matrix.data[i][j] << " ";
        }
        os << "\n";
    }
    return os;
}
