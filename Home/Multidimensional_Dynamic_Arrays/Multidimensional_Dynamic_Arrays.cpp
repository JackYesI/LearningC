#include <iostream>
#include <conio.h>

using namespace std;

int** createArray(const int& row, const int& col)
{
    int** arr = new int* [row];

    for (int i = 0; i < row; i++)
    {
        arr[i] = new int[col];
    }
    return arr;
}

int* createArray(const int& col)
{
    int* arr = new int[col];
    return arr;
}

void fill(int* arr, const int& col, int min = 1, int max = 10)
{
    for (size_t i = 0; i < col; i++)
    {
        arr[i] = min + rand() % (max - min + 1);
    }
}

void fill(int** arr, const int& row, const int& col, int min = 1, int max = 10)
{
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++) {
            arr[i][j] = min + rand() % (max - min + 1);
        }
    }
}

void print(int* arr, int col, string text = "")
{
    cout << text << endl;
    for (size_t i = 0; i < col; i++)
        cout << arr[i] << "\t";
    cout << endl;
}

void print(int** arr, int row, int col, string text = "")
{
    cout << text << endl;
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

void deleteArray(int** arr, int row, int col)
{
    for (int i = 0; i < row; i++)
        delete[] arr[i];
    delete[] arr;
}

void add_col(int**& arr_col_row,const int& row, int& col, int*& arr_col,int col_ , int index)
{
    if ((index <= 0 or index > col + 1) or (col_ != row)) return;
    col = col + 1;
    int** arr_col_row_new = createArray(row, col);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (j == index - 1)
            {
                arr_col_row_new[i][j] = arr_col[i];
            }
            if (j < index - 1)
            {
                arr_col_row_new[i][j] = arr_col_row[i][j];
            }
            if (j > index - 1)
            {
                arr_col_row_new[i][j] = arr_col_row[i][j - 1];
            }
        }
    }
    if (arr_col_row != nullptr)
        deleteArray(arr_col_row, row, col - 1);
    arr_col_row = arr_col_row_new;
}

void del_col(int**& arr_col_row, const int& row, int& col, int*& arr_col, int col_, int index)
{
    if ((index <= 0 or index > col) or (col_ != row)) return;
    col = col - 1;
    int** arr_col_row_new = createArray(row, col);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (j < index - 1)
            {
                arr_col_row_new[i][j] = arr_col_row[i][j];
            }
            if (j >= index - 1)
            {
                arr_col_row_new[i][j] = arr_col_row[i][j + 1];
            }
        }
    }
    if (arr_col_row != nullptr)
        deleteArray(arr_col_row, row, col - 1);
    arr_col_row = arr_col_row_new;
}

void left(int**& arr, const int row, const int col, int left)
{
    int** tmp = createArray(row, col);
    int k = left % col;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (j + k >= col)
                tmp[i][j] = arr[i][j + k - col];
            else
                tmp[i][j] = arr[i][j + k];
        }
    }
    if (arr != nullptr)
        deleteArray(arr, row, col);
    arr = tmp;
}

void right(int**& arr, const int row, const int col, int right)
{
    int** tmp = createArray(row, col);
    int k = right % col;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (j - k < 0)
                tmp[i][j] = arr[i][col + (j - k)];
            else
                tmp[i][j] = arr[i][j - k];
        }
    }
    if (arr != nullptr)
        deleteArray(arr, row, col);
    arr = tmp;
}

void top(int**& arr, const int row, const int col, int top)
{
    int** tmp = createArray(row, col);
    int k = top % row;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (i + k >= row)
                tmp[i][j] = arr[i + k - row][j];
            else
                tmp[i][j] = arr[i + k][j];
        }
    }
    if (arr != nullptr)
        deleteArray(arr, row, col);
    arr = tmp;
}

void bottom(int**& arr, const int row, const int col, int bottom)
{
    int** tmp = createArray(row, col);
    int k = bottom % row;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (i - k < 0)
                tmp[i][j] = arr[row + (i - k)][j];
            else
                tmp[i][j] = arr[i - k][j];
        }
    }
    if (arr != nullptr)
        deleteArray(arr, row, col);
    arr = tmp;
}

int main()
{
    int row = 2;
    int col = 2;
    int size = 2;
    int* array_ = createArray(2);
    int** arr = createArray(2, 2);
    fill(arr, row, col);
    fill(array_, row);
    print(arr, row, col, "test array");
    print(array_, size, "test array 2");
    add_col(arr, row, col, array_, size, 1);
    print(arr, row, col, "change array add");
    left(arr, row, col, 1);
    print(arr, row, col, "change array +");
    del_col(arr, row, col, array_, size, 1);
    print(arr, row, col, "change array del");

    left(arr, row, col, 13);
    print(arr, row, col, "change array +");

    add_col(arr, row, col, array_, size, 1);
    print(arr, row, col, "change array add");

    right(arr, row, col, 3);
    print(arr, row, col, "change array -");

    top(arr, row, col, 3);
    print(arr, row, col, "change array top");

    bottom(arr, row, col, 3);
    print(arr, row, col, "change array bottom");
}


