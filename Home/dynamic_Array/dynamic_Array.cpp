#include <iostream>
using namespace std;

template <typename T>
bool search_element(T* &arr, int size, T element)
{
    for (int i = 0; i < size; i++)
        if (arr[i] == element) return true;
    return false;
}

template <typename T>
int counter(T*& arr, int size)
{
    T* tmp = new T[size];
    int counter = 0;
    for (int i = 0; i < size; i++)
    {
        if (!search_element(tmp, size, arr[i]))
        {
            tmp[counter] = arr[i];
            counter = counter + 1;
        }
    }
    delete[] tmp;    
    return counter;
}

template <typename T>
T* marge(T*& A, T*&B, int len_a,int len_b, int& len)
{
    len = len_a + len_b;
    T* array_ = new T[len];
    int j = 0, i = 0;
    while (true)
    {
        if (i < len_a) array_[i] = A[i];
        if (i < len_b)
        {
            array_[len - 1 - j] = B[i];
            j = j + 1;
        }
        if (i >= len_a and i >= len_b) break;
        i = i + 1;
    }
    return array_;
}

template <typename T>
T* delete_repeat(T* arr, int size_ar, int size_new)
{
    T* tmp = new T[size_new];
    int j = 0;
    for (int i = 0; i < size_ar; i++)
    {
        if (!search_element(tmp, size_new, arr[i]))
        {
            tmp[j] = arr[i];
            j = j + 1;
        }
    }
    return tmp;
}

template <typename T>
T* association(T*& A, T*& B,int len_a,int len_b, int &len_c)
{
    T* tmp = marge(A, B, len_a, len_b, len_c);
    len_c = counter(tmp, len_c);
    T* tmp_last = delete_repeat(tmp, len_a + len_b, len_c);
    delete[] tmp;
    return tmp_last;
}

template <typename T>
T* crossing_marge(T*& A, T*& B, int len_a, int len_b, int& len)
{
    len = len_a;
    T* array_ = new T[len_a];
    int j = 0;
    for (int i = 0; i < len_a; i++)
    {
        if (search_element(B, len_b, A[i]))
        {
            array_[j] = A[i];
            j = j + 1;
        }
    }
    /*len = j;*/
    return array_;
}

template <typename T>
int crossing_counter(T*& A, T*& B, int len_a, int len_b)
{
    int j = 0;
    for (int i = 0; i < len_a; i++)
    {
        if (search_element(B, len_b, A[i]))
        {
            
            j = j + 1;
        }
    }
    return j;
}

template <typename T>
int crossing_counter_not(T*& A, T*& B, int len_a, int len_b)
{
    int j = 0;
    for (int i = 0; i < len_a; i++)
    {
        if (!search_element(B, len_b, A[i]))
        {
            
            j = j + 1;
        }
    }
    return j;
}

template <typename T>
T* crossing(T*& A, T*& B, int len_a, int len_b, int& len_c)
{
    len_c = crossing_counter(A, B, len_a, len_b);
    T* tmp = crossing_marge(A, B, len_a, len_b, len_c);
    int len = len_c;
    len_c = counter(tmp, len_c);
    T* tmp_last = delete_repeat(tmp, len, len_c);
    delete[] tmp;
    return tmp_last;
}

template <typename T>
T* A_not_B(T*& A, T*& B, int size_a, int size_b, int& size_c)
{
    size_c = crossing_counter_not(A, B, size_a, size_b);
    T* tmp_ = new T[size_c];
    int j = 0;
    for (int i = 0; i < size_a; i++)
        if (!search_element(B, size_b, A[i]))
        {
            tmp_[j] = A[i];
            j = j + 1;
        }
    /*size_c = j;*/
    return tmp_;
}

template <typename T>
T* do_not_meet_in_B_Main(T*& A, T*& B, int size_a, int size_b, int& size)
{

    T* tmp = A_not_B(A, B, size_a, size_b, size);
    size = counter(tmp, size);
    T* tmp_last = delete_repeat(tmp, size_a, size);
    delete[] tmp;
    return tmp_last;
}

template <typename T>
void print(T* &array_,int size_array)
{
    for (int i = 0; i < size_array; i++)
        cout << array_[i] << "\t";
    cout << endl;
}

int main()
{
    int* ptr_a, * ptr_b, * ptr_c, * ptr_d, * ptr_f,* ptr_o, size_a = 5, size_b = 6, size_c, size_d, size_f, size_o;
    ptr_a = new int[size_a] {1, 2, 3, 10,6};
    ptr_b = new int[size_b] {1, 6, 2, 3, 9, -1};
    ptr_c = association(ptr_a, ptr_b, size_a, size_b, size_c);
    print(ptr_c, size_c);
    ptr_d = crossing(ptr_a, ptr_b, size_a, size_b, size_d);
    print(ptr_d, size_d);
    ptr_f = do_not_meet_in_B_Main(ptr_a, ptr_b, size_a, size_b, size_f);
    print(ptr_f, size_f);
    ptr_o = do_not_meet_in_B_Main(ptr_b, ptr_a, size_b, size_a, size_o);
    print(ptr_o, size_o);
    return 1;
}


