#include "matrix.hpp"
#include <stdexcept>
#include <vector>

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
            data_.assign(rows_ * cols_, 0);
        }
    }

    int& At(int row, int col) {
        CheckBounds(row, col);
        return data_[row * cols_ + col];
    }

    const int& At(int row, int col) const {
        CheckBounds(row, col);
        return data_[row * cols_ + col];
    }

    int GetRows() const {
        return rows_;
    }

    int GetCols() const {
        return cols_;
    }

    bool operator==(const Matrix& m2) const {
        return rows_ == m2.rows_ && cols_ == m2.cols_ && data_ == m2.data_;
    }

    bool operator!=(const Matrix& m2) const {
        return !(*this == m2);
    }

    Matrix operator+(const Matrix& m2) const {
        if (rows_ != m2.rows_ || cols_ != m2.cols_) {
            throw std::invalid_argument("Matrices dimensions do not match");
        }
        
        Matrix result(rows_, cols_);
        for (int i = 0; i < rows_; ++i) {
            for (int j = 0; j < cols_; ++j) {
                result.At(i, j) = this->At(i, j) + m2.At(i, j);
            }
        }
        
        return result;
    }

private:
    void CheckBounds(int row, int col) const {
        if (row < 0 || row >= rows_ || col < 0 || col >= cols_) {
            throw std::out_of_range("Index out of range");
        }
    }

    int rows_{0};
    int cols_{0};
    std::vector<int> data_;
};
