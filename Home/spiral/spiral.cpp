#include <iostream>

using namespace std;

template <int COL>
void input(int arr[][COL], int N)
{
    int n = 1, k = 0, k_2 = 1;
    while (true)
    {
        for (size_t i = 0 + k; i < N - k; i++)
        {
            arr[k][i] = n;
            n = n + 1;
        }
        if (n == N * N + 1) return;
        for (size_t j = 0 + k_2; j < N - k; j++)
        {
            arr[j][N - 1 - k] = n;
            n = n + 1;
        }
        for (int j = N - 1 - k_2; j > -1 + k; j--)
        {
            arr[N - 1 - k][j] = n;
            n = n + 1;
        }
        if (n == N * N + 1) return;
        for (int j = N - 1 - k_2; j > 0 + k; j--)
        {
            arr[j][0 + k] = n;
            n = n + 1;
        }
        k = k + 1;
        k_2 = k_2 + 1;
    }
}

template <typename T, int COL>
void print(T arr[][COL], int size)
{
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
            cout << arr[i][j] << "\t";
        cout << endl;
    }
    cout << endl;
}

int main()
{
    int array[3][3], array_1[6][6];
    input(array, 3);
    print(array, 3);
    input(array_1, 6);
    print(array_1, 6);
    
}


