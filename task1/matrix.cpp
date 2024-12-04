#include "matrix.hpp"

Matrix::Matrix(int numRows, int numCols)
{
    Reset(numRows, numCols);
}

void Matrix::Reset(int numRows, int numCols)
{
    if (numRows <= 0 || numCols <= 0) {
        this->numRows = 0;
        this->numCols = 0;
        data.clear();
    } else {
        this->numRows = numRows;
        this->numCols = numCols;
        data.resize(numRows, std::vector<int>(numCols, 0));
    }
}

int& Matrix::At(int row, int col)
{
    if (row < 0 || row >= numRows || col < 0 || col >= numCols) {
        throw std::out_of_range("Index out of range");
    }
    return data[row][col];
}

const int& Matrix::At(int row, int col) const
{
    if (row < 0 || row >= numRows || col < 0 || col >= numCols) {
        throw std::out_of_range("Index out of range");
    }
    return data[row][col];
}

int Matrix::GetRows() const
{
    return numRows;
}

int Matrix::GetCols() const
{
    return numCols;
}

bool Matrix::operator==(const Matrix& m2)
{
    if (numRows != m2.numRows || numCols != m2.numCols) {
        return false;
    }
    return data == m2.data;
}

bool Matrix::operator!=(const Matrix& m2)
{
    return !(*this == m2);
}

Matrix Matrix::operator+(const Matrix& m2)
{
    if (numRows != m2.numRows || numCols != m2.numCols) {
        throw std::invalid_argument("Matrices must have the same dimensions for addition");
    }

    Matrix result(numRows, numCols);
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            result.At(i, j) = At(i, j) + m2.At(i, j);
        }
    }

    return result; // Возвращаем новую сумму матриц
}
