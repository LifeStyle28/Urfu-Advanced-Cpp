#include "Matrix.h"
using namespace std;

Matrix::Matrix(int rows, int cols) {
    if (rows < 0 || cols < 0) {
        throw out_of_range("Number of rows and columns must be non-negative");
    }
    num_rows = rows;
    num_cols = cols;
    data.assign(rows, vector<int>(cols, 0));
}


void Matrix::Reset(int rows, int cols) {
    if (rows < 0 || cols < 0) {
        throw out_of_range("Number of rows and columns must be non-negative");
    }
    num_rows = rows;
    num_cols = cols;
    data.assign(rows, vector<int>(cols, 0));
}

int Matrix::At(int row, int col) const {
    if (row < 0 || row >= num_rows || col < 0 || col >= num_cols) {
        throw out_of_range("Index out of range");
    }
    return data[row][col];
}

int& Matrix::At(int row, int col) {
    if (row < 0 || row >= num_rows || col < 0 || col >= num_cols) {
        throw out_of_range("Index out of range");
    }
    return data[row][col];
}

int Matrix::GetRows() const {
    return num_rows;
}

int Matrix::GetCols() const {
    return num_cols;
}

istream& operator>>(istream& in, Matrix& matrix) {
    int rows, cols;
    in >> rows >> cols;
    matrix.Reset(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            in >> matrix.At(i, j);
        }
    }
    return in;
}

ostream& operator<<(ostream& out, const Matrix& matrix) {
    out << matrix.GetRows() << " " << matrix.GetCols() << "\n";
    for (int i = 0; i < matrix.GetRows(); ++i) {
        for (int j = 0; j < matrix.GetCols(); ++j) {
            out << matrix.At(i, j) << " ";
        }
        out << "\n";
    }
    return out;
}

bool operator==(const Matrix& lhs, const Matrix& rhs) {
    return lhs.num_rows == rhs.num_rows && lhs.num_cols == rhs.num_cols && lhs.data == rhs.data;
}

Matrix operator+(const Matrix& lhs, const Matrix& rhs) {
    if (lhs.num_rows != rhs.num_rows || lhs.num_cols != rhs.num_cols) {
        throw invalid_argument("Matrices must have the same dimensions for addition");
    }
    Matrix result(lhs.num_rows, lhs.num_cols);
    for (int i = 0; i < lhs.num_rows; ++i) {
        for (int j = 0; j < lhs.num_cols; ++j) {
            result.At(i, j) = lhs.At(i, j) + rhs.At(i, j);
        }
    }
    return result;
}
