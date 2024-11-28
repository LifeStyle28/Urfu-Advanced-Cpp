#include "matrix.hpp"
#include <stdexcept>

Matrix::Matrix()
{
    rows = 0;
    cols = 0;
    Mat = std::vector<int>(rows * cols, 0);
}
Matrix::Matrix(int numRows, int numCols)
{
    if (numRows <= 0 || numCols <= 0)
    {
        throw std::out_of_range("");
    }
    cols = numCols;
    rows = numRows;
    Mat = std::vector<int>(cols * rows, 0);
}
void Matrix::Reset(int numRows, int numCols)
{
    if (numRows < 0 || numCols < 0)
    {
        throw std::out_of_range("The size of the matrix must be greater than zero");
    }
    rows = numRows;
    cols = numCols;
    Mat.clear();
    Mat.resize(rows * cols);
}

int& Matrix::At(int row, int col)
{
    if (row < 0 || col < 0 || row > rows || col > cols)
    {
        throw std::out_of_range("Out of range");
    }
    int &number = Mat[cols * (row - 1) + col - 1];
    return number;
}

const int& Matrix::At(int row, int col) const
{
    if (row < 0 || col < 0 || row > rows || col > cols)
    {
        throw std::out_of_range("Out of range");
    }
    int number = Mat[cols * (row - 1) + col - 1];
    return number;
}

int Matrix::GetRows() const
{
    return rows;
}

int Matrix::GetCols() const
{
    return cols;
}

bool Matrix::operator==(const Matrix& m2)
{

    bool F = true;
    for (int i = 0; i < this->rows; ++i)
    {
        for (int y = 0; y < this->cols; ++y)
        {
            if (this->Mat[this->cols * (i - 1) + y - 1] != m2.Mat[this->cols * (i - 1) + y - 1])
            {
                F = false;
            }
        }
    }
    if (((this->rows == m2.rows) || (this->cols == m2.cols)) && (F == true))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Matrix::operator!=(const Matrix& m2)
{
    bool F = true;
    for (int i = 0; i < this->rows; ++i)
    {
        for (int y = 0; y < this->cols; ++y)
        {
            if (this->Mat[this->cols * (i - 1) + y - 1] != m2.Mat[this->cols * (i - 1) + y - 1])
            {
                F = false;
            }
        }
    }
    if (((this->rows == m2.rows) || (this->cols == m2.cols)) && (F == true))
    {
        return false;
    }
    else
    {
        return true;
    }
}

Matrix Matrix::operator+(const Matrix& m2)
{
    if (this->rows != m2.rows || this->cols != m2.cols)
    {
        throw std::invalid_argument("Matrices must be of the same dimension");
    }
    Matrix sumM(m2.rows, m2.cols);
    for (int i = 0; i < this->rows; ++i)
    {
        for (int y = 0; y < this->cols; ++y)
        {
            sumM.Mat[sumM.cols * (i - 1) + y - 1] = m2.Mat[sumM.cols * (i - 1) + y - 1] + this->Mat[sumM.cols * (i - 1) + y - 1];
        }
    }
    return sumM;
}
