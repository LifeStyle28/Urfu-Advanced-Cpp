#include "matrix.hpp"
#include <vector>
#include <stdexcept>

class Matrix
{
private:
    int rows = 0;
    int cols = 0;
    std::vector<std::vector<int>> data;

public:
    Matrix::Matrix(int numRows, int numCols)
    {
        Reset(numRows, numCols);
    }

    void Matrix::Reset(int numRows, int numCols)
    {
        if (numRows <= 0 || numCols <= 0) {
            rows = 0;
            cols = 0;
            data.clear();
        } else {
            rows = numRows;
            cols = numCols;
            data.assign(rows, std::vector<int>(cols, 0));
        }
    }

    int& Matrix::At(int row, int col)
    {
        if (row < 0 || row >= rows || col < 0 || col >= cols) {
            throw std::out_of_range("");
        }
        return data[row][col];
    }

    const int& Matrix::At(int row, int col) const
    {
        if (row < 0 || row >= rows || col < 0 || col >= cols) {
            throw std::out_of_range("");
        }
        return data[row][col];
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
        return (rows == m2.rows && cols == m2.cols && data == m2.data);
    }

    bool Matrix::operator!=(const Matrix& m2)
    {
        return !(*this == m2);
    }

    Matrix Matrix::operator+(const Matrix& m2)
    {
        if (rows != m2.rows || cols != m2.cols) {
            throw std::invalid_argument("");
        }
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] + m2.data[i][j];
            }
        }
        return result;
    }
};
