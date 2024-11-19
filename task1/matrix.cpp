#include "matrix.hpp"

#include <stdexcept>

Matrix::Matrix(int numRows, int numCols) : rows(numRows), cols(numCols), data(numRows * numCols) {
if (numRows < 0 || numCols < 0) {
throw std::invalid_argument("Invalid matrix size");
}
}

void Matrix::Reset(int numRows, int numCols) {
if (numRows < 0 || numCols < 0) {
throw std::invalid_argument("Invalid matrix size");
}
rows = numRows;
cols = numCols;
data.assign(numRows * numCols, 0);
}

int& Matrix::At(int row, int col) {
if (row < 0 || row >= rows || col < 0 || col >= cols) {
throw std::out_of_range("Matrix index out of range");
}
return data[row * cols + col];
}

const int& Matrix::At(int row, int col) const {
if (row < 0 || row >= rows || col < 0 || col >= cols) {
throw std::out_of_range("Matrix index out of range");
}
return data[row * cols + col];
}

int Matrix::GetRows() const {
return rows;
}

int Matrix::GetCols() const {
return cols;
}

bool Matrix::operator==(const Matrix& m2) {
if (rows != m2.rows || cols != m2.cols) {
return false;
}
return data == m2.data;
}

bool Matrix::operator!=(const Matrix& m2) {
return !(*this == m2);
}

Matrix Matrix::operator+(const Matrix& m2) {
if (rows != m2.rows || cols != m2.cols) {
throw std::invalid_argument("Matrices must have the same dimensions for addition");
}
Matrix result(rows, cols);
for (int i = 0; i < data.size(); i++) {
result.data[i] = data[i] + m2.data[i];
}
return result;
}
