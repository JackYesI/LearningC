#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	// first
	/*int array[5][5];
	int number;
	cout << "Enter number :: ";
	cin >> number;
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			if (i == 0 and j == 0) array[i][j] = number;
			else
				if (j == 0 and i != 0) array[i][j] = array[i - 1][4] * 2;
				else
					if (j != 0) array[i][j] = array[i][j - 1] * 2;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
			cout << array[i][j] << "\t";
		cout << endl;
	}*/
	//
	
	// 	second
	/*int array[5][5];
	int number;
	cout << "Enter number :: ";
	cin >> number;
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			if (i == 0 and j == 0) array[i][j] = number;
			else
				if (j == 0 and i != 0) array[i][j] = array[i - 1][4] + 1;
				else
					if (j != 0) array[i][j] = array[i][j - 1] + 1;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
			cout << array[i][j] << "\t";
		cout << endl;
	}*/
	// 	

	// Thirth
	
	int array[2][6], arr[2][6];
	int number, k, k_i, size_i = 2, size_j = 6;
	char direction;
	srand((unsigned)time(NULL));
	// 1 + (rand() % 9);
	for  (int i = 0; i < size_i; i++)
	{
		for (int j = 0; j < size_j; j++)
		{
			array[i][j] = 0 + (rand() % 11);
			cout << array[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "Enter number :: ";
	cin >> number;
	k = number % size_j;
	k_i = number % size_i;
	cout << "Enter direction (t - top; l - left; r - right; b - bottom;) ";
	cin >> direction;
	if (direction == 'r')
	{
		for (int i = 0; i < size_i; i++)
		{
			for (int j = 0; j < size_j; j++)
			{
				if (j - k < 0)
					arr[i][j] = array[i][size_j + (j - k)];
				else
					arr[i][j] = array[i][j - k];
				cout << arr[i][j] << "\t";
			}
			cout << endl;
		}
	}
	else if (direction == 'l')
	{
		for (int i = 0; i < size_i; i++)
		{
			for (int j = 0; j < size_j; j++)
			{
				if (j + k > size_j - 1)
					arr[i][j] = array[i][abs(size_j - (j + k))];
				else
					arr[i][j] = array[i][j + k];
				cout << arr[i][j] << "\t";
			}
			cout << endl;
		}
	}
	else if (direction == 'b')
	{
		for (int i = 0; i < size_i; i++)
		{
			for (int j = 0; j < size_j; j++)
			{
				if (i + k_i > size_i - 1)
					arr[i][j] = array[abs(size_i - (i + k_i))][j];
				else
					arr[i][j] = array[i + k_i][j];
				cout << arr[i][j] << "\t";
			}
			cout << endl;
		}
	}
	else if (direction == 't')
	{
		for (int i = 0; i < size_i; i++)
		{
			for (int j = 0; j < size_j; j++)
			{
				if (i - k_i < 0)
					arr[i][j] = array[size_i + (i - k_i)][j];
				else
					arr[i][j] = array[i - k_i][j];
				cout << arr[i][j] << "\t";
			}
			cout << endl;
		}
	}
	


	//
}

