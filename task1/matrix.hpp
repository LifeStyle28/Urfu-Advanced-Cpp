#pragma once

#include <vector>
#include <stdexcept>

class Matrix 
{
public:
    Matrix() = default;
    Matrix(int numRows, int numCols);

    void Reset(int numRows, int numCols);
    int& At(int row, int col);
    const int& At(int row, int col) const;
    int GetRows() const;
    int GetCols() const;

    bool operator==(const Matrix& m2) const;
    bool operator!=(const Matrix& m2) const;
    Matrix operator+(const Matrix& m2) const;

private:
    int rows = 0;
    int cols = 0;
    std::vector<std::vector<int>> data;
};
