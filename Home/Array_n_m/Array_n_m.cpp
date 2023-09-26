#include <cstdlib>
#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	// first
	//int array[10][10];
	//int sum = 0, min, max;
	//double average = 0;
	//srand((unsigned)time(NULL));
	//// 1 + (rand() % 9);
	//for (int i = 0; i < 10; i++)
	//{
	//	for (int j = 0; j < 10; j++)
	//	{
	//		array[i][j] = 1 + (rand() % 10);
	//		cout << array[i][j] << "\t";
	//	}
	//	cout << endl;
	//}
	//
	//min = array[0][0];
	//max = array[0][0];
	//for (int i = 0; i < 10; i++)
	//	for (int j = 0; j < 10; j++)
	//	{
	//		if (min < array[i][j]) min = array[i][j];
	//		if (max > array[i][j]) max = array[i][j];
	//		sum = sum + array[i][j];
	//	}
	//average = double(sum) / 100;
	//cout << "min = " << min << "\nmax = " << max << "\nsum = " << sum << "\naverage = " << average << endl;
	//

	// Second
	/*int array[10][10], arr[10], all_sum = 0;
	srand((unsigned)time(NULL));
	for (int i = 0; i < 10; i++)
			for (int j = 0; j < 10; j++)
			{
				array[i][j] = 1 + (rand() % 10);
				all_sum = all_sum + array[i][j];
			}

	for (int i = 0; i < 10; i++)
	{
		int sum_col = 0, sum_row = 0;
		for (int j = 0; j < 10; j++)
		{
			sum_col = sum_col + array[i][j];
			cout << array[i][j] << "\t";
			sum_row = sum_row + array[j][i];
		}
		arr[i] = sum_row;
		cout << "|\t" << sum_col << endl;
	}
	cout << endl;
	for (int i = 0; i < 10; i++) cout << arr[i] << "\t";
	cout << "\t" << all_sum << endl;*/

	//

	// Thirth
	int array[5][10], arr[5][5];
	srand((unsigned)time(NULL));
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 10; j++) array[i][j] = 0 + (rand() % 51);

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++)
		{
			arr[i][j] = array[i][(j + 1) * 2 - 2] + array[i][(j + 1) * 2 - 1];
			/*cout << array[i][(j + 1) * 2 - 2] << "\t" << array[i][(j + 1) * 2 - 1] << endl;*/
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 10; j++)
			cout << array[i][j] << "\t";
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++)
			cout << arr[i][j] << "\t";
		cout << endl;
	}
	//
}


