#include "matrix.hpp"
#include <stdexcept>

using namespace std;

Matrix::Matrix(int rows, int cols) {
    if (rows < 0 || cols < 0) {
        throw out_of_range("");
    }
    if (rows == 0 || cols == 0) {
        num_rows = 0;
        num_cols = 0;
        data.clear();
    } else {
        num_rows = rows;
        num_cols = cols;
        data.assign(rows, vector<int>(cols, 0));
    }
}

void Matrix::Reset(int rows, int cols) {
    if (rows < 0 || cols < 0) {
        throw out_of_range("");
    }
    if (rows == 0 || cols == 0) {
        num_rows = 0;
        num_cols = 0;
        data.clear();
    } else {
        num_rows = rows;
        num_cols = cols;
        data.assign(rows, vector<int>(cols, 0));
    }
}

int Matrix::At(int row, int col) const {
    if (row < 0 || row >= num_rows || col < 0 || col >= num_cols) {
        throw out_of_range("");
    }
    return data[row][col];
}

int& Matrix::At(int row, int col) {
    if (row < 0 || row >= num_rows || col < 0 || col >= num_cols) {
        throw out_of_range("");
    }
    return data[row][col];
}

int Matrix::GetRows() const {
    return num_rows;
}

int Matrix::GetCols() const {
    return num_cols;
}

bool operator==(const Matrix& m1, const Matrix& rhs) {
    return m1.num_rows == rhs.num_rows && m1.num_cols == rhs.num_cols && m1.data == rhs.data;
}

bool operator!=(const Matrix& m1, const Matrix& rhs) {
    return !(m1 == rhs);
}

Matrix operator+(const Matrix& m1, const Matrix& rhs) {
    if (m1.GetRows() != rhs.GetRows() || m1.GetCols() != rhs.GetCols()) {
        throw invalid_argument("");
    }
    Matrix result(m1.GetRows(), m1.GetCols());
    for (int i = 0; i < m1.GetRows(); ++i) {
        for (int j = 0; j < m1.GetCols(); ++j) {
            result.At(i, j) = m1.At(i, j) + rhs.At(i, j);
        }
    }
    return result;
}
