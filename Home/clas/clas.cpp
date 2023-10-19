#include <iostream>
#include "Array_func.h"
using namespace std;

/*
    Створити бібліотеку для роботи з багатовимірними масивами
    1) Створення масиву
    2) Заповнення масиву
    3) Вивід масиву
    4) функція додавання рядка в кінець
    5) функція додавання рядка на початок
    6) функція додавання рядка за індексом
    7) функція додавання стовпця в кінець
    8) функція додавання стовпця на початок
    9) функція додавання стовпця за індексом
    10) функція знаходження максимального значення
    11) функція знаходження мінімального значення
    12) Написати програму, яка видаляє з двовимірного масиву, заповненого випадковими числами, рядки, що містять нульові елементи.

*/


int main()
{
    int row = 4, col = 5, ** ptr;
    createArray(ptr, row, col);
    fillArray(ptr, row, col);
    printArray(ptr, row, col);
    insertCol(ptr, row, col, 2);
    cout << endl;
    printArray(ptr, row, col, "print insert col");
    cout << endl;
    removeCol(ptr, row, col, 2);
    printArray(ptr, row, col, "print remove col");
    cout << endl;
    insertFirstCol(ptr, row, col);
    printArray(ptr, row, col, "print insert First col");
    cout << endl;
    insertLastCol(ptr, row, col);
    printArray(ptr, row, col, "print insert last col");
    cout << endl;
    removeFirstCol(ptr, row, col);
    printArray(ptr, row, col, "print remove first col");
    cout << endl;
    removeLastCol(ptr, row, col);
    printArray(ptr, row, col, "print remove last col");
    cout << endl;

    insert_row(ptr, row, col, 3);
    printArray(ptr, row, col, "print insert row");
    insertFirstrow(ptr, row, col);
    printArray(ptr, row, col, "print remove first row");
    insertLastrow(ptr, row, col);
    printArray(ptr, row, col, "print remove last row");

    delete_row_zero(ptr, row, col);
    printArray(ptr, row, col, "print remove zero row");


}
