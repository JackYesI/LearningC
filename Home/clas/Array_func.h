#pragma once
#include <iostream>
using std::cout;
using std::endl;
using std::string;


template<typename T>
void createArray(T**& arr, int row, int col);

template<typename T>
void fillArray(T** arr, const int& row, const int& col, int min = 1, int max = 10);

template<typename T>
void printArray(T** arr, const int& row, const int& col, string text = "");

template<typename T>
void insertCol(T** arr, int row, int& col, int index);

template<typename T>
void removeCol(T** arr, int row, int& col, int index);

template<typename T>
void insertFirstCol(T** arr, int row, int& col);

template<typename T>
void insertLastCol(T** arr, int row, int& col);

template<typename T>
void removeFirstCol(T** arr, int row, int& col);

template<typename T>
void removeLastCol(T** arr, int row, int& col);

template<typename T>
void insert_row(T**& arr, int& row, const int& col, const int index);

template<typename T>
void insertFirstrow(T**& arr, int& row, const int& col);

template<typename T>
void insertLastrow(T**& arr, int& row, const int& col);

template <typename T>
void deleteArray(T**& arr, const int& row);

template <typename T>
T max(T**& arr, const int& row, const int& col);

template <typename T>
T min(T**& arr, const int& row, const int& col);

template <typename T>
void delete_row_zero(T**& arr, int& row, const int& col);

template <typename T>
int chek_row_zero(T**& arr, int& row, const int& col, int previos);

template <typename T>
int chek_row_zero(T**& arr, int& row, const int& col, int previos)
{
	int j_ = 0;
	for (int i = previos; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (arr[i][j] == 0) 
				j_ = j_ + 1;
		}
		if (j_ == col) return i;
		else
			j_ = 0;
	}
	return -1;
}

template <typename T>
void delete_row_zero(T**& arr, int& row, const int& col)
{
	int check = chek_row_zero(arr, row, col, 0);
	while (check != -1)
	{
		insert_row(arr, row, col, check);
		check = chek_row_zero(arr, row, col, check + 1);
	}
}

template<typename T>
inline void createArray(T**& arr, int row, int col)
{
	int** tmp = new int* [row];
	for (size_t i = 0; i < row; i++)
	{
		tmp[i] = new int[col] {};
	}
	arr = tmp;
}

template<typename T>
inline void fillArray(T** arr, const int& row, const int& col, int min, int max)
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
inline void printArray(T** arr, const int& row, const int& col, string text)
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

template<typename T>
inline void insertCol(T** arr, int row, int& col, int index)
{
	if (index < 0 || index > col) return;
	for (size_t i = 0; i < row; i++)
	{
		T* tmp = new T[col + 1];
		tmp[index] = 0;
		for (size_t j = 0; j < col; j++)
		{
			if (j < index) {
				tmp[j] = arr[i][j];
			}
			else {
				tmp[j + 1] = arr[i][j];
			}
		}
		delete[] arr[i];
		arr[i] = tmp;
	}
	col++;
}

template<typename T>
inline void removeCol(T** arr, int row, int& col, int index)
{
	if (index < 0 || index >= col) return;
	col--;
	for (size_t i = 0; i < row; i++)
	{
		T* tmp = new T[col + 1];
		for (size_t j = 0; j < col; j++)
		{
			if (j < index) {
				tmp[j] = arr[i][j];
			}
			else {
				tmp[j] = arr[i][j + 1];
			}
		}
		delete[] arr[i];
		arr[i] = tmp;
	}
}

template<typename T>
inline void insertFirstCol(T** arr, int row, int& col)
{
	insertCol(arr, row, col, 0);
}

template<typename T>
inline void insertLastCol(T** arr, int row, int& col)
{
	insertCol(arr, row, col, col);
}

template<typename T>
inline void removeFirstCol(T** arr, int row, int& col)
{
	removeCol(arr, row, col, 0);
}

template<typename T>
inline void removeLastCol(T** arr, int row, int& col)
{
	removeCol(arr, row, col, col - 1);
}

template<typename T>
void insert_row(T**& arr, int& row, const int& col, const int index)
{
	if (index < 0 || index > row)
	{
		cout << "Error" << endl;
		return;
	}
	int** tmp = new int* [row + 1];
	tmp[index - 1] = new int[col] {};
	for (size_t i = 0; i < row; i++)
	{
		if (i < index - 1)
		{
			tmp[i] = arr[i];
		}
		else {
			tmp[i + 1] = arr[i];
		}
	}
	row++;
	delete[] arr;
	arr = tmp;
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
void insertFirstrow(T**& arr, int& row, const int& col)
{
	insert_row(arr, row, col, 1);
}

template<typename T>
void insertLastrow(T**& arr, int& row, const int& col)
{
	int** tmp = new int* [row + 1];
	tmp[row] = new int[col] {};
	for (size_t i = 0; i < row; i++)
		tmp[i] = arr[i];
	row++;
	delete[] arr;
	arr = tmp;
}

template <typename T>
T max(T**& arr, const int& row, const int& col)
{
	T max = arr[0][0];
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (max < arr[i][j])
				max = arr[i][j];
		}
	}
	return max;
}

template <typename T>
T min(T**& arr, const int& row, const int& col)
{
	T min = arr[0][0];
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (min > arr[i][j])
				min = arr[i][j];
		}
	}
	return min;
}
