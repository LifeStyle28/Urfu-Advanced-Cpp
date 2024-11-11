#include "matrix.hpp"
#include <iostream>
#include <vector>
#include <stdexcept>

class Matrix {
public:
    Matrix() = default;
    
    Matrix(int numRows, int numCols) {
        Reset(numRows, numCols);
    }

    void Reset(int numRows, int numCols) {
        if (numRows <= 0 || numCols <= 0) {
            rows_ = 0;
            cols_ = 0;
            data_.clear();
        } else {
            rows_ = numRows;
            cols_ = numCols;
            data_.resize(rows_, std::vector<int>(cols_, 0));
        }
    }

    int& At(int row, int col) {
        if (row < 0 || row >= rows_ || col < 0 || col >= cols_) {
            throw std::out_of_range("Index out of range");
        }
        return data_[row][col];
    }

    const int& At(int row, int col) const {
        if (row < 0 || row >= rows_ || col < 0 || col >= cols_) {
            throw std::out_of_range("Index out of range");
        }
        return data_[row][col];
    }

    int GetRows() const {
        return rows_;
    }

    int GetCols() const {
        return cols_;
    }

    bool operator==(const Matrix& m2) {
        if (rows_ != m2.rows_ || cols_ != m2.cols_) {
            return false;
        }
        return data_ == m2.data_;
    }

    bool operator!=(const Matrix& m2) {
        return !(*this == m2);
    }

    Matrix operator+(const Matrix& m2) {
        if (rows_ != m2.rows_ || cols_ != m2.cols_) {
            throw std::invalid_argument("Matrices must be of the same size for addition");
        }
        Matrix result(rows_, cols_);
        for (int i = 0; i < rows_; ++i) {
            for (int j = 0; j < cols_; ++j) {
                result.At(i, j) = At(i, j) + m2.At(i, j);
            }
        }
        return result;
    }

private:
    int rows_ = 0;                     // Количество строк
    int cols_ = 0;                     // Количество столбцов
    std::vector<std::vector<int>> data_; // Данные матрицы
};
