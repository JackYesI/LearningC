#include <iostream>
#include<cstdlib>
using namespace std;

template <typename T>
void Input(T arr[], int size)
{
    for (size_t i = 0; i < size; i++)
        cin >> arr[i];
}

template <typename T>
void print(T arr[], int size)
{
    for (size_t i = 0; i < size; i++)
        cout << arr[i] << "\t";
    cout << endl;
}

template <typename T>
int Index_Arr_First(T arr[], int size, T search_elem)
{
    for (size_t i = 0; i < size; i++)
        if (arr[i] == search_elem)
            return i;
    return -1;
}

template <typename T>
int Index_Arr_Last(T arr[], int size, T search_elem)
{
    for (size_t i = size - 1; i >= 0; i--)
        if (arr[i] == search_elem)
            return i;
    return -1;
}

template <typename T>
void mixing_elem(T arr[], int size)
{
    int iteration_ = int(size / 4);
    srand((unsigned)time(NULL));
    // 1 + (rand() % 9)
    for (size_t i = 0; i < iteration_; i++)
    {
        T z;
        int random_1 = 0 + (rand() % size);
        int random_2 = 0 + (rand() % size);
        z = arr[random_1];  
        arr[random_1] = arr[random_2];
        arr[random_2] = z;
    }
}

template <typename T>
void Fillin_arr(T arr[], int size, T elem)
{
    for (size_t i = 0; i < size; i++)
        arr[i] = elem;
}

template <typename T>
void bouble_sort_up(T arr[], int size)
{
    for (size_t i = 0; i < size; i++)
        for (size_t j = 0; j < size - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                T z = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = z;
            }
        }
}

template <typename T>
void bouble_sort_down(T arr[], int size)
{
    for (size_t i = 0; i < size; i++)
        for (size_t j = 0; j < size - 1; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                T z = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = z;
            }
        }
}

int Index_Arr_First(char arr[], int size, char first_elem)
{
    first_elem = tolower(first_elem);
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] == first_elem or tolower(arr[i]) == first_elem) return i;
    }
    return -1;
}

int main()
{
    char array[5];
    Input(array, 5);
    print(array, 5);
    mixing_elem(array, 5);
    print(array, 5);
    bouble_sort_up(array, 5);
    print(array, 5);
    bouble_sort_down(array, 5);
    print(array, 5);
    cout << Index_Arr_First(array, 5, 'G') << endl;
    Fillin_arr(array, 5, 'G');
    print(array, 5);

    int array_int[5];
    Input(array_int, 5);
    print(array_int, 5);
    mixing_elem(array_int, 5);
    print(array_int, 5);
    bouble_sort_up(array_int, 5);
    print(array_int, 5);
    bouble_sort_down(array_int, 5);
    print(array_int, 5);
    cout << Index_Arr_First(array_int, 5, 4) << endl;
    cout << Index_Arr_Last(array_int, 5, 4) << endl;
    Fillin_arr(array_int, 5, -1);
    print(array_int, 5);

    double array_double[5];
    Input(array_double, 5);
    print(array_double, 5);
    mixing_elem(array_double, 5);
    print(array_double, 5);
    bouble_sort_up(array_double, 5);
    print(array_double, 5);
    bouble_sort_down(array_double, 5);
    print(array_double, 5);
    cout << Index_Arr_First(array_double, 5, 2.0) << endl;
    cout << Index_Arr_Last(array_double, 5, 4.0) << endl;
    Fillin_arr(array_double, 5, 2.0);
    print(array_double, 5);

    string array_string[5];
    Input(array_string, 5);
    print(array_string, 5);
    mixing_elem(array_string, 5);
    print(array_string, 5);
    bouble_sort_up(array_string, 5);
    print(array_string, 5);
    bouble_sort_down(array_string, 5);
    print(array_string, 5);
    string name = "igor";
    cout << Index_Arr_First(array_string, 5, name) << endl;
    Fillin_arr(array_string, 5, name);
    print(array_string, 5);
}


