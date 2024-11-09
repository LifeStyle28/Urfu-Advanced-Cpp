#include "matrix.hpp"
#include <stdexcept>

Matrix::Matrix(int numRows, int numCols) {
    Reset(numRows, numCols);
}

Matrix::Matrix(const Matrix& other) : data(other.data), rows(other.rows), cols(other.cols) {}

Matrix::Matrix(Matrix&& other) noexcept : data(std::move(other.data)), rows(other.rows), cols(other.cols) {
    other.rows = 0;
    other.cols = 0;
}

Matrix& Matrix::operator=(const Matrix& other) {
    if (this != &other) {
        data = other.data;
        rows = other.rows;
        cols = other.cols;
    }
    return *this;
}

Matrix& Matrix::operator=(Matrix&& other) noexcept {
    if (this != &other) {
        data = std::move(other.data);
        rows = other.rows;
        cols = other.cols;
        other.rows = 0;
        other.cols = 0;
    }
    return *this;
}

void Matrix::Reset(int numRows, int numCols) {
    if (numRows < 0 || numCols < 0) {
        throw std::out_of_range("");
    }
    rows = numRows;
    cols = numCols;
    data.assign(rows, std::vector<int>(cols, 0));
}

int& Matrix::At(int row, int col) {
    if (row < 0 || row >= rows || col < 0 || col >= cols) {
        throw std::out_of_range("");
    }
    return data[row][col];
}

const int& Matrix::At(int row, int col) const {
    if (row < 0 || row >= rows || col < 0 || col >= cols) {
        throw std::out_of_range("");
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
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (data[i][j] != m2.data[i][j]) {
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
    if (rows != m2.rows || cols != m2.cols) {
        throw std::invalid_argument("");
    }
    Matrix result(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result.data[i][j] = data[i][j] + m2.data[i][j];
        }
    }
    return result;
}

std::istream& operator>>(std::istream& is, Matrix& matrix) {
    int numRows, numCols;
    is >> numRows >> numCols;
    matrix.Reset(numRows, numCols);
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            is >> matrix.data[i][j];
        }
    }
    return is;
}

std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
    os << matrix.GetRows() << " " << matrix.GetCols() << std::endl;
    for (int i = 0; i < matrix.GetRows(); ++i) {
        for (int j = 0; j < matrix.GetCols(); ++j) {
            os << matrix.data[i][j];
            if (j < matrix.GetCols() - 1) {
                os << " ";
            }
        }
        os << std::endl;
    }
    return os;
}