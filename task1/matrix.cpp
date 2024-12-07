#include "matrix.hpp"

#include <stdexcept>

Matrix::Matrix(int rows, int cols) 
{
    if (rows < 0 || cols < 0) 
    {
        throw out_of_range("Error: Out of range");
    }
    if (rows == 0 || cols == 0) 
    {
        num_rows = 0;
        num_cols = 0;
        data.clear();
    } else 
    {
        num_rows = rows;
        num_cols = cols;
        data.assign(rows, vector<int>(cols, 0));
    }
}

void Matrix::Reset(int rows, int cols) 
{
    if (rows < 0 || cols < 0) {
        throw out_of_range("Error: Out of range");
    }
    if (rows == 0 || cols == 0) {
        num_rows = 0;
        num_cols = 0;
        data.clear();
    } else {
        num_rows = rows;
        num_cols = cols;
        data.assign(rows, vector<int>(cols, 0));
    }
}

int& Matrix::At(int row, int col)
{
    if (row < 0 || col < 0 || row >= numRows || col >= numCols)
    {
    	throw out_of_range("Error: Out of range");
    }
    return data[row][col];
}

const int& Matrix::At(int row, int col) const
{
    if (row < 0 || col < 0 || row >= numRows || col >= numCols)
    {
    	throw out_of_range("Error: Out of range");
    }
    return data[row][col];
}

int Matrix::GetRows() const
{
   return(numRows); 
}

int Matrix::GetCols() const
{
   return(numCols);
}

bool operator==(const Matrix& m1, const Matrix& m2) {
    return m1.num_rows == m2.num_rows && m1.num_cols == m2.num_cols && m1.data == m2.data;
}

bool operator!=(const Matrix& m1, const Matrix& m2) {
    return !(m1 == m2);
}

Matrix operator+(const Matrix& , const Matrix& m2) {
    if (m1.GetRows() != m2.GetRows() || m1.GetCols() != m2.GetCols()) {
        throw invalid_argument("");
    }
    Matrix result(m1.GetRows(), m1.GetCols());
    for (int i = 0; i < m1.GetRows(); ++i) {
        for (int j = 0; j < m1.GetCols(); ++j) {
            result.At(i, j) = m1.At(i, j) + m2.At(i, j);
        }
    }
    return result;
}
