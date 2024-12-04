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

    bool operator==(const Matrix& m2);
    bool operator!=(const Matrix& m2);
    Matrix operator+(const Matrix& m2);

private:
    std::vector<std::vector<int>> data;
    int numRows = 0;
    int numCols = 0;
};
