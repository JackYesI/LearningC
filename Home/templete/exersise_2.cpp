#include <iostream>
using namespace std;

template <typename T, int COLS>
void input(T arr[][COLS], int rows, int cols)
{
	for (size_t i = 0; i < rows; i++)
		for (size_t j = 0; j < cols; j++)
		{
			cout << "Enter element :: ";
			cin >> arr[i][j];
		}
}

template <typename T, int COLS>
void print(T arr[][COLS], int rows, int cols)
{
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
			cout << " Element == " << arr[i][j] << "\t";
		cout << endl;
	}
}

template <typename T, int COLS>
T max(T arr[][COLS], int rows, int cols)
{
	T max = arr[0][0];
	for (size_t i = 0; i < rows; i++)
		for (size_t j = 0; j < cols; j++)
			if (max < arr[i][j])
			{
				max = arr[i][j];
			}
	return max;
}

template <typename T, int COLS>
bool row_Up(T arr[][COLS], int cols, int row_up)
{
	int count_ = 0;
	row_up = row_up - 1;
	for (size_t i = 0; i < cols - 1; i++)
		if (arr[row_up][i] < arr[row_up][i + 1]) count_ = count_ + 1;
	if (cols - 1 == count_) return true;
	else return false;
}

template <typename T, int COLS>
bool rows_Up(T arr[][COLS],int rows, int cols)
{
	int count_ = 0;
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols - 1; j++)
			if (arr[i][j] < arr[i][j + 1]) count_ = count_ + 1;
		if (cols - 1 != count_) return false;
		count_ = 0;
	}
	return true;
}

int main()
{
	int array[2][2];
	bool ch;
	input(array, 2, 2);
	print(array, 2, 2);
	cout << "MAx :: " << max(array, 2, 2) << endl;
	ch = row_Up(array, 2, 1);
	cout << bool(ch) << endl;
	cout << rows_Up(array, 2, 2) << endl;

	string array_string[2][2];
	bool ch_2;
	input(array_string, 2, 2);
	print(array_string, 2, 2);
	cout << "MAx :: " << max(array_string, 2, 2) << endl;
	ch_2 = row_Up(array_string, 2, 1);
	cout << bool(ch) << endl;
	cout << rows_Up(array_string, 2, 2) << endl;
	return 0;
}