#pragma once
#include <iostream>
#include <vector>
#include <stdexcept>

class Matrix {
public:
    Matrix() : rows(0), cols(0) {}
    explicit Matrix(int rows, int cols);
    
    Matrix(const Matrix& other) = default;
    Matrix& operator=(const Matrix& other) = default;
    
    Matrix(Matrix&& other) noexcept : num_rows(other.num_rows), num_cols(other.num_cols), data(std::move(other.data)) {
        other.rows = 0;
        other.cols = 0;
    }
    Matrix& operator=(Matrix&& other) noexcept {
        if (this != &other) {
            rows = other.rows;
            cols = other.cols;
            data = std::move(other.data);
            other.rows = 0;
            other.cols = 0;
        }
        return *this;
    }

    void Reset(int rows, int cols);
    int At(int row, int col) const;
    int& At(int row, int col);
    int GetRows() const;
    int GetCols() const;

    friend bool operator==(const Matrix& lhs, const Matrix& rhs);
    friend bool operator!=(const Matrix& lhs, const Matrix& rhs);
    friend Matrix operator+(const Matrix& lhs, const Matrix& rhs);

private:
    int rows;
    int cols;
    std::vector<std::vector<int>> data;
};
