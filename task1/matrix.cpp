#include "matrix.hpp"

#include <stdexcept>

Matrix::Matrix(int numRows, int numCols)
{
    Reset(numRows, numCols);
}

void Matrix::Reset(int numRows, int numCols)
{
    numRows = nrows;
    numCols = ncols;
    data.assign(nrows, vector<int>(ncols, 0));
    if (nrows <= 0 || ncols <= 0)
    {
    	nrows = 0;
	ncols = 0;
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

bool Matrix::operator==(const Matrix& m2)
{
    if (numCols != other.numCols || numRows != other.numRows)
	    return false;
    for (int i = 0; i < numRows; i++)
    	for (int j = 0; j < numCols; j++)
	    	if (At(i, j) != other.At(i, j))
		    	return false;
    return true;
}

bool Matrix::operator!=(const Matrix& m2)
{
    return !(*this == m2);
}

Matrix Matrix::operator+(const Matrix& m2)
{
    if (numRows != other.num_rows || numCols != other.num_cols)
	    throw invalid_argument("Error: Different matrix");
    Matrix result(numRows, numCols);
    for (int i = 0; i < numRows; i++)
	    for (int j = 0; j < numCols; j++)
	    	result.At(i, j) = At(i, j) + other.At(i, j);
    return result; 
}
