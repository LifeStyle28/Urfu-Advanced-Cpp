#include "matrix.hpp"

Matrix::Matrix(int numRows, int numCols) {
    Reset(numRows, numCols);
}

void Matrix::Reset(int numRows, int numCols) {
    if (numRows <= 0 || numCols <= 0) {
        rows = 0;
        cols = 0;
        data.clear();
    } else {
        rows = numRows;
        cols = numCols;
        data.assign(rows, std::vector<int>(cols, 0));
    }
}

int& Matrix::At(int row, int col) {
    if (row < 0 || row >= rows || col < 0 || col >= cols) {
        throw std::out_of_range("Индексы выходят за пределы матрицы");
    }
    return data[row][col];
}

const int& Matrix::At(int row, int col) const {
    if (row < 0 || row >= rows || col < 0 || col >= cols) {
        throw std::out_of_range("Индексы выходят за пределы матрицы");
    }
    return data[row][col];
}

int Matrix::GetRows() const {
    return rows;
}

int Matrix::GetCols() const {
    return cols;
}

bool Matrix::operator==(const Matrix& m2) const {
    if (rows != m2.rows || cols != m2.cols) {
        return false;
    }
    return data == m2.data;
}

bool Matrix::operator!=(const Matrix& m2) const {
    return !(*this == m2);
}

Matrix Matrix::operator+(const Matrix& m2) const {
    if (rows != m2.rows || cols != m2.cols) {
        throw std::invalid_argument("Размеры матриц не совпадают");
    }

    Matrix result(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result.data[i][j] = data[i][j] + m2.data[i][j];
        }
    }
    return result;
}
