#include "matrix.hpp"
#include <stdexcept>

Matrix::Matrix(int num_rows, int num_cols) {
  if (num_rows < 0 || num_cols < 0) {
    throw std::out_of_range("");
  }
  if (rows == 0 || cols == 0) {
    rows = 0;
    cols = 0;
    data.clear();
  } else {
    rows = num_rows;
    cols = num_cols;
    data.assign(rows, std::vector<int>(cols, 0));
  }
}

void Matrix::Reset(int num_rows, int num_cols) {
  if (num_rows < 0 || num_cols < 0) {
    throw std::out_of_range("");
  }
  if (num_rows == 0 || num_cols == 0) {
    rows = 0;
    cols = 0;
    data.clear();
  } else {
    rows = num_rows;
    cols = num_cols;
    data.assign(rows, std::vector<int>(cols, 0));
  }
}

int Matrix::At(int row, int col) const {
  if (row < 0 || row >= rows || col < 0 || col >= cols) {
    throw std::out_of_range("");
  }
  return data[row][col];
}

int &Matrix::At(int row, int col) {
  if (row < 0 || row >= rows || col < 0 || col >= cols) {
    throw std::out_of_range("");
  }
  return data[row][col];
}

int Matrix::GetRows() const { return rows; }

int Matrix::GetCols() const { return cols; }

bool operator==(const Matrix &lhs, const Matrix &rhs) {
  return lhs.rows == rhs.rows && lhs.cols == rhs.cols && lhs.data == rhs.data;
}

bool operator!=(const Matrix &lhs, const Matrix &rhs) { return !(lhs == rhs); }

Matrix operator+(const Matrix &lhs, const Matrix &rhs) {
  if (lhs.GetRows() != rhs.GetRows() || lhs.GetCols() != rhs.GetCols()) {
    throw std::invalid_argument("");
  }
  Matrix result(lhs.GetRows(), lhs.GetCols());
  for (int i = 0; i < lhs.GetRows(); ++i) {
    for (int j = 0; j < lhs.GetCols(); ++j) {
      result.At(i, j) = lhs.At(i, j) + rhs.At(i, j);
    }
  }
  return result;
}
