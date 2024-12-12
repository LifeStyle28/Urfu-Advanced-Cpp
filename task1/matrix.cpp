#include "matrix.hpp"
#include <stdexcept>
Matrix::Matrix(int numRows, int numCols)
{
using namespace std;
Matrix::Matrix(int rows, int cols) {
    if (rows < 0 || cols < 0) {
        throw out_of_range("");
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
void Matrix::Reset(int numRows, int numCols)
{
void Matrix::Reset(int rows, int cols) {
    if (rows < 0 || cols < 0) {
        throw out_of_range("");
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
int Matrix::At(int row, int col) const {
    if (row < 0 || row >= num_rows || col < 0 || col >= num_cols) {
        throw out_of_range("");
    }
    return data[row][col];
}
const int& Matrix::At(int row, int col) const
{
int& Matrix::At(int row, int col) {
    if (row < 0 || row >= num_rows || col < 0 || col >= num_cols) {
        throw out_of_range("");
    }
    return data[row][col];
}
int Matrix::GetRows() const
{
int Matrix::GetRows() const {
    return num_rows;
}
int Matrix::GetCols() const
{
int Matrix::GetCols() const {
    return num_cols;
}
bool Matrix::operator==(const Matrix& m2)
{
bool operator==(const Matrix& lhs, const Matrix& rhs) {
    return lhs.num_rows == rhs.num_rows && lhs.num_cols == rhs.num_cols && lhs.data == rhs.data;
}
bool Matrix::operator!=(const Matrix& m2)
{
bool operator!=(const Matrix& lhs, const Matrix& rhs) {
    return !(lhs == rhs);
}
Matrix Matrix::operator+(const Matrix& m2)
{
Matrix operator+(const Matrix& lhs, const Matrix& rhs) {
    if (lhs.GetRows() != rhs.GetRows() || lhs.GetCols() != rhs.GetCols()) {
        throw invalid_argument("");
    }
    Matrix result(lhs.GetRows(), lhs.GetCols());
    for (int i = 0; i < lhs.GetRows(); ++i) {
        for (int j = 0; j < lhs.GetCols(); ++j) {
            result.At(i, j) = lhs.At(i, j) + rhs.At(i, j);
        }
    }
    return result;
}
