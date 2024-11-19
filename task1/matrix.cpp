#include "matrix.hpp"

#include <stdexcept>

Matrix::Matrix(int numRows, int numCols)
{
if (numRows < 0 || numCols < 0) {
throw std::out_of_range("Number of rows and columns must be non-negative");
}

data_.resize(numRows, std::vector<int>(numCols, 0));
}

void Matrix::Reset(int numRows, int numCols)
{
if (numRows < 0 || numCols < 0) {
throw std::out_of_range("Number of rows and columns must be non-negative");
}


data_.resize(numRows, std::vector<int>(numCols, 0));
}

int& Matrix::At(int row, int col)
{
if (row < 0 || row >= data_.size() || col < 0 || col >= data_[0].size()) {
throw std::out_of_range("Index out of range");
}


return data_[row][col];
}

const int& Matrix::At(int row, int col) const
{
if (row < 0 || row >= data_.size() || col < 0 || col >= data_[0].size()) {
throw std::out_of_range("Index out of range");
}

return data_[row][col];
}

int Matrix::GetRows() const
{
return data_.size();
}

int Matrix::GetCols() const
{
if (data_.empty()) {
return 0;
} else {
return data_[0].size();
}
}

bool Matrix::operator==(const Matrix& m2)
{
return data_ == m2.data_;
}

bool Matrix::operator!=(const Matrix& m2)
{
return data_ != m2.data_;
}

Matrix Matrix::operator+(const Matrix& m2)
{
if (data_.size() != m2.data_.size() || data_[0].size() != m2.data_[0].size()) {
throw std::invalid_argument("Matrices must be of the same size for addition");
}
  
Matrix result(data_.size(), data_[0].size());

for (int i = 0; i < data_.size(); ++i) {
    for (int j = 0; j < data_[0].size(); ++j) {
        result.At(i, j) = data_[i][j] + m2.At(i, j);
    }
}

return result;
}
