#pragma once
#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class Matrix {
private:
    int num_rows;
    int num_cols;
    vector<vector<int>> data;
public:
    Matrix() : num_rows(0), num_cols(0) {}
    Matrix(int rows, int cols);
    Matrix(const Matrix& other) : num_rows(other.num_rows), num_cols(other.num_cols), data(other.data) {}
    Matrix(Matrix&& other) noexcept : num_rows(other.num_rows), num_cols(other.num_cols), data(move(other.data)) {
        other.num_rows = 0;
        other.num_cols = 0;
    }
    void Reset(int rows, int cols);
    int At(int row, int col) const;
    int& At(int row, int col);
    int GetRows() const;
    int GetCols() const;
    friend istream& operator>>(istream& in, Matrix& matrix);
    friend ostream& operator<<(ostream& out, const Matrix& matrix);
    friend bool operator==(const Matrix& lhs, const Matrix& rhs);
    friend Matrix operator+(const Matrix& lhs, const Matrix& rhs);
};