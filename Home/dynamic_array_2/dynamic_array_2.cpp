#include <cstdlib>
#include <iostream>
#include <time.h>

using namespace std;

template <typename T>
bool search_element(T*& arr, int size, T element)
{
    for (int i = 0; i < size; i++)
        if (arr[i] == element) return true;
    return false;
}

template <typename T>
T* marge(T*& arr_1, int size_1, T*& arr_2, int size_2, int& size)
{
    size = size_1 + size_2;
    T* tmp = new T[size];
    int j = 0;
    while (true)
    {
        if (j < size_1)
        {
            tmp[j] = arr_1[j];
        }
        if (j < size_2)
        {
            tmp[size - 1 - j] = arr_2[j];
        }
        if (j >= size_1 and j >= size_2) break;
        j = j + 1;
    }
    return tmp;
}

template <typename T>
void add_last(T*& arr, int& size, T element)
{
    size = size + 1;
    T* tmp = new T[size];
    for (int i = 0; i < size - 1; i++)
        tmp[i] = arr[i];
    tmp[size - 1] = element;
    if (arr != nullptr)
        delete[] arr;
    arr = tmp;
}

template <typename T>
int counter(T*& arr, int size)
{
    int counter = 0;
    for (int i = 0; i < size; i++)
    {
        if (!search_element(arr, i, arr[i]))
        {
            counter = counter + 1;
        }
    }
    return counter;
}

template <typename T>
void association(T*& arr, int& size, T*& arr_a, int size_a, T*& arr_b,int size_b)
{
    int size_tmp;
    arr = marge(arr_a, size_a, arr_b, size_b, size);
    size_tmp = counter(arr, size);
    T* tmp = new T[size_tmp];
    int j = 0;
    for (int i = 0; i < size; i++)
    {
        if (!search_element(arr, i, arr[i]))
        {
            tmp[j] = arr[i];
            j = j + 1;
        }
    }
    if (arr != nullptr)
        delete[] arr;
    arr = tmp;
    size = size_tmp;
}

template <typename T>
void association_2(T*& arr, int& size, T*& arr_a, int size_a, T*& arr_b, int size_b)
{
    int size_tmp = 1;
    arr = marge(arr_a, size_a, arr_b, size_b, size);
    T* tmp = new T[size_tmp];
    tmp[0] = arr[0];

    for (int i = 1; i < size; i++)
        if (!search_element(arr, i, arr[i]))
            add_last(tmp, size_tmp, arr[i]);


    if (arr != nullptr)
        delete[] arr;
    arr = tmp;
    size = size_tmp;
}

template <typename T>
void crossing(T*& arr, int& size, T*& arr_a, int size_a, T*& arr_b, int size_b)
{
    size = 0;
    arr = nullptr;
    for (int i = 0; i < size_a; i++)
        if (!search_element(arr_a, i, arr_a[i]) and search_element(arr_b, size_b, arr_a[i]))
            add_last(arr, size, arr_a[i]);
}

template <typename T>
void crossing_not(T*& arr, int& size, T*& arr_a, int size_a, T*& arr_b, int size_b)
{
    size = 0;
    arr = nullptr;
    for (int i = 0; i < size_a; i++)
        if (!search_element(arr_a, i, arr_a[i]) and !search_element(arr_b, size_b, arr_a[i]))
            add_last(arr, size, arr_a[i]);
}

template <typename T>
void marge_not(T*& arr,T*& arr_a, int size_a, T*& arr_b, int size_b, int& size)
{
    T* ptr_1, size_1, * ptr_2, size_2;
    crossing_not(ptr_1, size_1, arr_a, size_a, arr_b, size_b);
    crossing_not(ptr_2, size_2, arr_b, size_b, arr_a, size_a);
    if (arr != nullptr)
        delete[] arr;
    arr = marge(ptr_1, size_1, ptr_2, size_2, size);
    if (ptr_1 != nullptr)
        delete[] ptr_1;
    if (ptr_2 != nullptr)
        delete[] ptr_2;
}

template <typename T>
void print(T* array_, int size_array)
{
    for (int i = 0; i < size_array; i++)
        cout << array_[i] << "\t";
    cout << endl << endl;
}

template <typename T>
void fill_array_rand(T*& arr, int size, int min = 0, int max = 9)
{
    for (int i = 0; i < size; i++)
        arr[i] = min + (rand() % (max - min + 1));
}


int main()
{
    srand((unsigned)time(NULL));
    int* ptr_a, * ptr_b, * ptr_c, size_a = 4, size_b = 5, size_c, *ptr_d, size_d;
    ptr_a = new int[size_a] {1,2,3,9};
    ptr_b = new int[size_b] {1,2,3,5,6};
    cout << "+++++++++++MARGE+++++++++++" << endl;
    association(ptr_c, size_c, ptr_a, size_a, ptr_b, size_b);
    print(ptr_c, size_c);
    cout << "+++++++++++MARGE_2_TRY+++++++++++" << endl;
    association_2(ptr_c, size_c, ptr_a, size_a, ptr_b, size_b);
    print(ptr_c, size_c);
    cout << "+++++++++++CROSSING+++++++++++" << endl;
    crossing(ptr_d, size_d, ptr_a, size_a, ptr_b, size_b);
    print(ptr_d, size_d);
    cout << "+++++++++++IN_A_NOT_B+++++++++++" << endl;
    crossing_not(ptr_d, size_d, ptr_a, size_a, ptr_b, size_b);
    print(ptr_d, size_d);
    cout << "+++++++++++IN_B_NOT_A+++++++++++" << endl;
    crossing_not(ptr_d, size_d, ptr_b, size_b, ptr_a, size_a);
    print(ptr_d, size_d);
    cout << "+++++++++++IN_A_NOT_B_AND_IN_B_NOT_A+++++++++++" << endl;
    marge_not(ptr_d, ptr_a, size_a, ptr_b, size_b, size_d);
    print(ptr_d, size_d);

    cout << endl << endl;
    cout << "++++++++++++Exemple_2+++++++++++++" << endl;
    cout << endl << endl << endl;

    size_a = 5;
    size_b = 5;
    delete[] ptr_a;
    delete[] ptr_b;
    ptr_a = new int[size_a];
    ptr_b = new int[size_b];
    fill_array_rand(ptr_a, size_a);
    print(ptr_a, size_a);
    fill_array_rand(ptr_b, size_b);
    print(ptr_b, size_b);
    cout << "+++++++++++MARGE+++++++++++" << endl;
    association(ptr_c, size_c, ptr_a, size_a, ptr_b, size_b);
    print(ptr_c, size_c);
    cout << "+++++++++++MARGE_2_TRY+++++++++++" << endl;
    association_2(ptr_c, size_c, ptr_a, size_a, ptr_b, size_b);
    print(ptr_c, size_c);
    cout << "+++++++++++CROSSING+++++++++++" << endl;
    crossing(ptr_d, size_d, ptr_a, size_a, ptr_b, size_b);
    print(ptr_d, size_d);
    cout << "+++++++++++IN_A_NOT_B+++++++++++" << endl;
    crossing_not(ptr_d, size_d, ptr_a, size_a, ptr_b, size_b);
    print(ptr_d, size_d);
    cout << "+++++++++++IN_B_NOT_A+++++++++++" << endl;
    crossing_not(ptr_d, size_d, ptr_b, size_b, ptr_a, size_a);
    print(ptr_d, size_d);
    cout << "+++++++++++IN_A_NOT_B_AND_IN_B_NOT_A+++++++++++" << endl;
    marge_not(ptr_d, ptr_a, size_a, ptr_b, size_b, size_d);
    print(ptr_d, size_d);
    
}

