#include <iostream>
#include "Array_func.h"
using namespace std;

/*
    �������� �������� ��� ������ � �������������� ��������
    1) ��������� ������
    2) ���������� ������
    3) ���� ������
    4) ������� ��������� ����� � �����
    5) ������� ��������� ����� �� �������
    6) ������� ��������� ����� �� ��������
    7) ������� ��������� ������� � �����
    8) ������� ��������� ������� �� �������
    9) ������� ��������� ������� �� ��������
    10) ������� ����������� ������������� ��������
    11) ������� ����������� ���������� ��������
    12) �������� ��������, ��� ������� � ����������� ������, ����������� ����������� �������, �����, �� ������ ������ ��������.

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
