#pragma once

#include <vector>
#include <iostream>

class Matrix {
public:
    Matrix() = default;
    Matrix(int numRows, int numCols);
    Matrix(const Matrix& other);
    Matrix(Matrix&& other) noexcept;
    ~Matrix() = default;

    Matrix& operator=(const Matrix& other);
    Matrix& operator=(Matrix&& other) noexcept;

    void Reset(int numRows, int numCols);
    int& At(int row, int col);
    const int& At(int row, int col) const;
    int GetRows() const;
    int GetCols() const;

    bool operator==(const Matrix& m2) const;
    bool operator!=(const Matrix& m2) const;
    Matrix operator+(const Matrix& m2) const;

    friend std::istream& operator>>(std::istream& is, Matrix& matrix);
    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix);

private:
    std::vector<std::vector<int>> data;
    int rows = 0;
    int cols = 0;
};

std::istream& operator>>(std::istream& is, Matrix& matrix);
std::ostream& operator<<(std::ostream& os, const Matrix& matrix);