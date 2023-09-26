#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
    // First
    /*int choose, i, j;
    bool i_cycles = 1;
    while (i_cycles)
    {
        cout << "1) a;\n";
        cout << "2) b;\n";
        cout << "3) v;\n";
        cout << "4) g;\n";
        cout << "5) d;\n";
        cout << "6) e;\n";
        cout << "7) j;\n";
        cout << "8) z;\n";
        cout << "9) u;\n";
        cout << "10) k;\n";
        cout << "11) Exit;\n";
        cin >> choose;
        if (choose == 11) {
            break;
        }
        switch (choose)
        {
        case 1:
            for (i = 0; i < 10; i++) {
                for (j = 0; j < 10; j++) {
                    if (j >= i) {
                        cout << "*";
                    }
                    else {
                        cout << " ";
                    }
                }
                cout << endl;
            }
            break;
        case 2:
            for (i = 0; i < 10; i++) {
                for (j = 0; j < 10; j++) {
                    if (j >= i) {
                        cout << " ";
                    }
                    else {
                        cout << "*";
                    }
                }
                cout << endl;
            }
            break;
        case 3:
            for (i = 0; i < 10; i++) {
                if (i > 5) {
                    cout << endl;
                    continue;
                }
                for (j = 0; j < 10; j++) {
                    if (j < i or j > 9 - i) {
                        cout << " ";
                    }
                    else {
                        cout << "*";
                    }
                }
                cout << endl;
            }
            break;
        case 4:
            for (i = 0; i < 10; i++) {
                if (i < 5) {
                    cout << endl;
                    continue;
                }
                for (j = 0; j < 10; j++) {
                    if (j > i or j < 9 - i) {
                        cout << " ";
                    }
                    else {
                        cout << "*";
                    }
                }
                cout << endl;
            }
            break;
        case 5:
            for (i = 0; i < 10; i++) {
                if (i > 4) {
                    for (j = 0; j < 10; j++) {
                        if (j > i or j < 9 - i) {
                            cout << " ";
                        }
                        else {
                            cout << "*";
                        }
                    }
                }
                else {
                    for (j = 0; j < 10; j++) {
                        if (j < i or j > 9 - i) {
                            cout << " ";
                        }
                        else {
                            cout << "*";
                        }
                    }
                }
                cout << endl;
            }
            break;
        case 6:
            for (i = 0; i < 10; i++) {
                if (i > 4) {
                    for (j = 0; j < 10; j++) {
                        if (j > i or j < 9 - i) {
                            cout << "*";
                        }
                        else {
                            cout << " ";
                        }
                    }
                }
                else {
                    for (j = 0; j < 10; j++) {
                        if (j < i or j > 9 - i) {
                            cout << "*";
                        }
                        else {
                            cout << " ";
                        }
                    }
                }
                cout << endl;
            }
            break;
        case 7:
            for (i = 0; i < 10; i++) {
                if (i > 4) {
                    for (j = 0; j < 5; j++) {
                        if (j > i or j < 9 - i) {
                            cout << "*";
                        }
                        else {
                            cout << " ";
                        }
                    }
                }
                else {
                    for (j = 0; j < 5; j++) {
                        if (j < i or j > 9 - i) {
                            cout << "*";
                        }
                        else {
                            cout << " ";
                        }
                    }
                }
                cout << endl;
            }
            break;
        case 8:
            for (i = 0; i < 10; i++) {
                if (i > 4) {
                    for (j = 0; j < 10; j++) {
                        if (j < 5) {
                            cout << " ";
                            continue;
                        }
                        if (j > i or j < 9 - i) {
                            cout << "*";
                        }
                        else {
                            cout << " ";
                        }
                    }
                }
                else {
                    for (j = 0; j < 10; j++) {
                        if (j < 5) {
                            cout << " ";
                            continue;
                        }
                        if (j < i or j > 9 - i) {
                            cout << "*";
                        }
                        else {
                            cout << " ";
                        }
                    }
                }
                cout << endl;
            }
            break;
        case 9:
            j = 10;
            for (i = 0; i < j; i++) {
                if (i + 1 == j) {
                    i = 0;
                    j = j - 1;
                    cout << '*' << endl;
                }
                else if (j == 1) {
                    break;
                }
                cout << '*';
            }
            cout << endl;
            break;
        case 10:
            for (i = 0; i < 10; i++) {
                for (j = 0; j < 10; j++) {
                    if (j > 9 - i) {
                        cout << "*";
                    }
                    else {
                        cout << " ";
                    }
                }
                cout << endl;
            }
            break;
        default:
            break;
        }
    }*/
    
    // Second
    
    /*int number, choose;
    cout << "Enter number ";
    cin >> number;
    int number_k = number, number_, k = 1, sum = 0, zero = 0;
    bool whl = 1;
    if (number == 0) zero++;
    while (whl) {
        cout << "1) count; 2) zero; 3) sum; 4) average; 5) Enter number; 6) Exit" << endl;
        cout << "Enter your choose ";
        cin >> choose;
        double average;
        while (number_k != 0)
        {
            number_ = number_k % 10;
            sum = sum + number_;
            number_k = number_k / 10;
            if (number_k != 0) k++;
            if (number_ == 0) zero++;
        }
        average = double(sum) / k;
        switch (choose)
        {
        case 1:
            cout << "Count --> " << k << endl;
            break;
        case 2:
            cout << "Zero --> " << zero << endl;
            break;
        case 3:
            cout << "Sum --> " << sum << endl;
            break;
        case 4:
            cout << "Average --> " << average << endl;
            break;
        case 5:
            cout << "Enter number ";
            cin >> number;
            sum = 0;
            average = 0;
            if (number == 0) zero = 1;
            else zero = 0;
            k = 1;
            number_k = number;
            break;
        case 6:
            whl = false;
            break;
        default:
            break;
        }
    }*/

    // Thirth
    
    /*int number;
    cout << "Enter number :: ";
    cin >> number;
    for (int i = 1; i < 7; i++) {
        if (i <= 3)
            for (int j = 1; j < 9; j++) 
                if (j % 2 == 0)
                    for (int k = 0; k < number; k++)
                        cout << "_";
                else
                    for (int k = 0; k < number; k++)
                        cout << "*";
        else
            for (int j = 1; j < 9; j++)
                if (j % 2 == 0)
                    for (int k = 0; k < number; k++)
                        cout << "*";
                else
                    for (int k = 0; k < number; k++)
                        cout << "_";
        cout << endl << endl;
    }*/


}

