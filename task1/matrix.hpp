#define MATRIX_HPP

#include <vector>
#include <stdexcept>
#include <iostream>

class Matrix {
public:
    Matrix() : numRows(0), numCols(0) {}
    Matrix(int numRows, int numCols);

    void Reset(int numRows, int numCols);
    int& At(int row, int col);
    const int& At(int row, int col) const;
    int GetRows() const { return numRows; }
    int GetCols() const { return numCols; }

    bool operator==(const Matrix& m2) const;
    Matrix operator+(const Matrix& m2) const;

    friend std::istream& operator>>(std::istream& is, Matrix& matrix);
    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix);

private:
    int numRows;
    int numCols;
    std::vector<std::vector<int>> data;
};

