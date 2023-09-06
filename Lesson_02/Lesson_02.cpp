// Lesson_02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

int main()
{
    /*std::cout << "Hello World!\n";
    const double PI = 3.14;
    int day;
    cout << "Entrer number day :: ";
    cin >> day;

    if (day == 1) {
        cout << "Monday" << endl;
    }
    else if (day == 2) {
        cout << "Tuesday" << endl;
    }
    else if (day == 3) {
        cout << "Wendesday" << endl;
    }
    else
    {
        cout << "Error" << endl;
    }*/
    /*int day;
    cin >> day;
    if (0 <= day and day <= 20) {
        cout << "True";
    }
    else {
        cout << "False";
    }*/
    /*int month;
    cout << "Enter number mounth :: ";
    cin >> month;

    switch (month)
    {
    case 1:
        cout << "31 days" << endl;
        break;
    case 2:
        int year;
        cout << "Enter year: ";
        cin >> year;
        if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0) {
            cout << "29 days" << endl;
        } 
        else {
            cout << "28 days" << endl;
        }
        cout << "28 or 29" << endl;
        break;
    case 3:
        cout << "31" << endl;
        break;
    case 4:
        cout << "31" << endl;
        break;
    case 5:
        cout << "31" << endl;
        break;
    case 6:
        cout << "31" << endl;
        break;
    case 7: 
    case 8:
    case 9: 
    case 10: 
    case 11: 
    case 12:
        cout << "31" << endl;
        break;
    default:
        cout << "Error" << endl;
    }*/

    cout << "\t 1 - Red; \n\t 2- Green; \n\t 3 - Blue; \n\t 4 - Yellow; \n\t 5 - Purple; \n\t Enter :: ";
    int number;
    bool x = 1;
    while (x) {


        cin >> number;

        switch (number)
        {
        case 1:
            system("Color 40");
            break;
        case 2:
            system("Color 20");
            break;
        case 3:
            system("Color 10");
            break;
        case 4:
            system("Color 60");
            break;
        case 5:
            system("Color 50");
            break;
        default:
            x = 0;
            break;
        }
    }


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
