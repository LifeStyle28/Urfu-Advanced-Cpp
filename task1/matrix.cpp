#include "matrix.hpp"

#include <stdexcept>

Matrix::Matrix(int numRows, int numCols)
{
    Reset(numRows, numCols); // your implementation here
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
    }// your implementation here
}

int& Matrix::At(int row, int col)
{
    if (row < 0 || col < 0 || row >= numRows || col >= numCols)
    {
    	throw out_of_range("Error: Out of range");
    }
    return data[row][col];// your implementation here
}

const int& Matrix::At(int row, int col) const
{
    if (row < 0 || col < 0 || row >= numRows || col >= numCols)
    {
    	throw out_of_range("Error: Out of range");
    }
    return data[row][col];// your implementation here
}

int Matrix::GetRows() const
{
   return(numRows); // your implementation here
}

int Matrix::GetCols() const
{
   return(numCols); // your implementation here
}

bool Matrix::operator==(const Matrix& m2)
{
    if (numCols != other.numCols || numRows != other.numRows)
	    return false;
    for (int i = 0; i < numRows; i++)
    	for (int j = 0; j < numCols; j++)
	    	if (At(i, j) != other.At(i, j))
		    	return false;
    return true;// your implementation here
}

bool Matrix::operator!=(const Matrix& m2)
{
    return !(*this == m2);// your implementation here
}

Matrix Matrix::operator+(const Matrix& m2)
{
    if (numRows != other.num_rows || numCols != other.num_cols)
	    throw invalid_argument("Error: Different matrix");
    Matrix result(numRows, numCols);
    for (int i = 0; i < numRows; i++)
	    for (int j = 0; j < numCols; j++)
	    	result.At(i, j) = At(i, j) + other.At(i, j);
    return result; // your implementation here
}
