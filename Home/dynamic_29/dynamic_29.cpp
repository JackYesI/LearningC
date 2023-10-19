#include <iostream>
using namespace std;

template <typename T>
void swap(T* a, T* b)
{
    int z = *a;
    a = *b;
    b = z;
}

template <typename T>
void transponetion_matrix(T*& arr, const int row, const int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (j > i) 
                swap(arr[i][j], arr[j][i]);
        }
    }
}

template <typename T>
void deleteArray(T**& arr, const int& row)
{
    for (size_t i = 0; i < row; i++)
    {
        delete[] arr[i];
    }

    delete[] arr;
    arr = nullptr;
}

template<typename T>
void createArray(T**& arr, int row, int col)
{
    int** tmp = new int* [row];
    for (size_t i = 0; i < row; i++)
    {
        tmp[i] = new int[col] {};
    }
    arr = tmp;
}

template<typename T>
void fillArray(T** arr, const int& row, const int& col, int min, int max)
{
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            arr[i][j] = min + rand() % (max - min + 1);
        }
    }
}

template<typename T>
void printArray(T** arr, const int& row, const int& col, string text)
{
    cout << text << endl;
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

int search_phone(string** arr, int size, string name)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[0][i] == name) {
            return i;
        }
    }
    return -1;
}

int search_name(string** arr, int size, string phone)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[1][i] == phone) {
            return i;
        }
    }
    return -1;
}

void replace(string** arr, int index)
{
    cout << "Enter name ";
    cin >> arr[0][index];
    cout << "Enter phone ";
    cin >> arr[1][index];
}

void add_member(string**& arr, int& size, int index)
{
    string* tmp_0 = new string[size + 1];
    string* tmp_1 = new string[size + 1];
    cout << "Index new name ";
    cin >> tmp_0[index];
    cout << "Index new phone ";
    cin >> tmp_1[index];
    for (int i = 0; i < size + 1; i++)
    {
        if (i > index)
        {
            tmp_0[i] = arr[0][i - 1];
        }
        else if (i == index)
            continue;
        else
            tmp_0[i] = arr[0][i];
        if (i >= index)
        {
            tmp_1[i] = arr[1][i - 1];
        }
        else if (i == index)
            continue;
        else
            tmp_1[i] = arr[1][i];
    }
    delete[] arr[0];
    delete[] arr[1];
    arr[0] = tmp_0;
    arr[1] = tmp_1;
    size = size + 1;
}


int main()
{
    int row_ = 5;
    int col_ = 5;
    int** array_;
    createArray(array_, row_, col_);
    fillArray(array_, row_, col_, 1, 9);
    printArray(array_, row_, col_, "start");
    transponetion_matrix(array_, row_, col_);
    printArray(array_, row_, col_, "result");

    string** arr = new  string*[2];
    int size = 4;
    arr[0] = new string[]{ "petro", "denys", "Max", "Oksana"};
    arr[1] = new string[]{ "0964457442", "0965878222", "0683457324", "0964452441" };
    printArray(arr, 2, size, "Start");
    cout << search_name(arr, size, "0964452441") << endl;
    cout << search_phone(arr, size, "denys") << endl;
    replace(arr, 0);
    printArray(arr, 2, size, "Start");
    add_member(arr, size, 3);
    printArray(arr, 2, size, "finish");

    deleteArray(array_, row_);
    deleteArray(arr, 2);
}


