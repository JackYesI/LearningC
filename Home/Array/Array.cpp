// Array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <cstdlib>
#include <iostream>
#include <time.h>

int main()
{
    // random
    /*srand((unsigned)time(NULL));
    int random = 1 + (rand() % 9);;

    for (int i =0; i<100; i++)
        std::cout << 5 + (rand() % 95) << std::endl;

    return 0;*/

    ///

    ///
    /*int array[6], sum = 0;
    for (int i = 0; i < 6; i++) {
        std::cout << "Emter amount for " << i + 1 << " mount :: ";
        std::cin >> array[i];
        sum = sum + array[i];
    }
    std::cout << "Sum = " << sum << std::endl;*/
    ///

    ///
    /*int array[10] ,k=0;
    srand((unsigned)time(NULL));
    for (int i = 0; i < 10; i++) {
        array[i] = 1 + (rand() % 100);
        std::cout << i + 1 << " element is :: " << array[i] << std::endl;
    }
    std::cout << std::endl;
    for (int i = 9; i >= 0; i--) {
        k = k + 1;
        std::cout << k << " element is :: " << array[i] << std::endl;
    }*/
    ///

    ///
    /*int array[5], sum = 0;
    for (int i = 0; i < 5; i++) {
        std::cout << "Emter value of " << i + 1 << " side :: ";
        std::cin >> array[i];
        sum = sum + array[i];
    }
    std::cout << "P = " << sum << std::endl; */
    ///

    ///
    /*int array[12], max = -1, min, max_i, min_i;
    for (int i = 0; i < 12; i++) {
        std::cout << "Emter profit of " << i + 1 << " mount :: ";
        std::cin >> array[i];
        if (i == 0) {
            min = array[i];
            min_i = i;
        }
        if (max < array[i]) {
            max = array[i];
            max_i = i + 1;
        }
        if (min > array[i]) {
            min = array[i];
            min_i = i + 1;
        }
    }
    std::cout << "max =  " << max << " mount :: " << max_i << std::endl;
    std::cout << "min =  " << min << " mount :: " << min_i << std::endl;*/
    ///

    /// Homework
    // First
    /*srand((unsigned)time(NULL));
    int array[10], max = -1, min, max_i, min_i;
    for (int i = 0; i < 10; i++) {
        array[i] = 1 + (rand() % 100);
        std::cout << "Emter " << i + 1 << " element of :: " << array[i] << std::endl;
        if (i == 0) {
            min = array[i];
            min_i = i;
        }
        if (max < array[i]) {
            max = array[i];
            max_i = i;
        }
        if (min > array[i]) {
            min = array[i];
            min_i = i;
        }
    }
    std::cout << std::endl;
    std::cout << "max =  " << max << " element :: " << max_i + 1 << std::endl;
    std::cout << "min =  " << min << " element :: " << min_i + 1 << std::endl;*/
    ///

    // second
    /*int a, b;
    int array[12], max = -1, min, max_i, min_i;
    for (int i = 0; i < 12; i++) {
        std::cout << "Emter profit of " << i + 1 << " mount :: ";
        std::cin >> array[i];
    }
    std::cout << "Enter a ";
    std::cin >> a;
    std::cout << "Enter b ";
    std::cin >> b;
    a = a - 1;
    for (int i = a; i < b; i++) {
        if (i == a) {
            min = array[i];
            min_i = i;
        }
        if (max < array[i]) {
            max = array[i];
            max_i = i;
        }
        if (min > array[i]) {
            min = array[i];
            min_i = i;
        }
    }
    std::cout << "max =  " << max << " mount :: " << max_i + 1 << std::endl;
    std::cout << "min =  " << min << " mount :: " << min_i + 1 << std::endl;*/

    /// Thirth
    /*int max_i, min_i, negative_first=-1, negative_last=-1;
    const int n = 10;
    double arr[n];
    double sum_negative = 0, min, max, mult_ = 1, mult_average = 1, sum_average = 0;
    for (int i = 0; i < n; i++) {
        std::cout << "Enter " << i + 1 << " element of array ";
        std::cin >> arr[i];
        if (i == 0) {
            min = arr[i];
            min_i = i;
            max = arr[i];
            max_i = i;
        }
        if (max < arr[i]) {
            max = arr[i];
            max_i = i;
        }
        if (min > arr[i]) {
            min = arr[i];
            min_i = i;
        }
        if (arr[i] < 0) sum_negative = sum_negative + arr[i];
        if ((i + 1) % 2 == 0) mult_ = mult_ * arr[i];
    }
    for (int i = 0; i < n; i++) 
        if (arr[i] < 0) {
            negative_first = i;
            break;
        }
    for (int i = n - 1; i >= 0; i--)
        if (arr[i] < 0) {
            negative_last = i;
            break;
        }

    if (min_i > max_i)
        for (int i = max_i; i < min_i + 1; i++)
            mult_average = mult_average * arr[i];
    else if (max_i > min_i)
        for (int i = min_i; i < max_i + 1; i++)
            mult_average = mult_average * arr[i];
    else if (max_i == min_i)
        mult_average = max_i;

    if (negative_first == -1 or negative_first == negative_last)
        sum_average = 0;
    else
        for (int i = negative_first; i < negative_last + 1; i++)
            sum_average = sum_average + arr[i];

    for (int i = 0; i < n; i++)
        std::cout << i + 1 << " element of array is " << arr[i] << std::endl;
    std::cout << "1) " << sum_negative << std::endl;
    std::cout << "2) " << mult_average << std::endl;
    std::cout << "3) " << mult_ << std::endl;
    std::cout << "4) " << sum_average << std::endl;*/

    /// 

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
