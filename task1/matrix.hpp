#pragma once

class Matrix {
public:
    Matrix(int numRows = 0, int numCols = 0);
    ~Matrix();

    void Reset(int numRows, int numCols);
    int& At(int row, int col);
    const int& At(int row, int col) const;

    int GetRows() const;
    int GetCols() const;
    bool operator==(const Matrix& m2) const;
    bool operator!=(const Matrix& m2) const;
    Matrix operator+(const Matrix& m2) const;

private:
    int m_row;    // Количество строк
    int m_col;    // Количество столбцов
    int** numbers; // Динамический массив для хранения элементов матрицы

    void AllocateMemory();
    void DeallocateMemory();
    void CheckBounds(int row, int col) const;
};
