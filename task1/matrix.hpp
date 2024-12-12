#pragma once
#include <iostream>
#include <vector>
#include <stdexcept>
class Matrix
{
class Matrix {
public:
    Matrix() = default;
    Matrix(int numRows, int numCols);
    Matrix() : num_rows(0), num_cols(0) {}
    explicit Matrix(int rows, int cols);
    Matrix(const Matrix& other) = default;
    Matrix& operator=(const Matrix& other) = default;
    Matrix(Matrix&& other) noexcept : num_rows(other.num_rows), num_cols(other.num_cols), data(std::move(other.data)) {
        other.num_rows = 0;
        other.num_cols = 0;
    }
    Matrix& operator=(Matrix&& other) noexcept {
        if (this != &other) {
            num_rows = other.num_rows;
            num_cols = other.num_cols;
            data = std::move(other.data);
            other.num_rows = 0;
            other.num_cols = 0;
        }
        return *this;
    }
    void Reset(int numRows, int numCols);
    void Reset(int rows, int cols);
    int At(int row, int col) const;
    int& At(int row, int col);
    const int& At(int row, int col) const;
    int GetRows() const;
    int GetCols() const;
    bool operator==(const Matrix& m2);
    bool operator!=(const Matrix& m2);
    Matrix operator+(const Matrix& m2);
    friend bool operator==(const Matrix& lhs, const Matrix& rhs);
    friend bool operator!=(const Matrix& lhs, const Matrix& rhs);
    friend Matrix operator+(const Matrix& lhs, const Matrix& rhs);
private:
    int num_rows;
    int num_cols;
    std::vector<std::vector<int>> data;
};
