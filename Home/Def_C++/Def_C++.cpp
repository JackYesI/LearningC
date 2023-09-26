#include <iostream>
#include <cmath>

using std::cout;
using std::endl;
using std::cin;



int Pow(int x, int a)
{
    if (a == 1) return x;
    if (a == 0) return 1;
    if (a > 1)
    {
        int y = 1;
        for (int i = 0; i < a; i++)
            y = y * x;
        return y;
    }
    else
    {
        cout << "Error" << endl;
        return 0;
    }
}
double Pow(double x, int a)
{
    if (a == 1) return x;
    if (a == 0) return 1;
    if (a > 1)
    {
        double y = 1;
        for (int i = 0; i < a; i++)
            y = y * x;
        return y;
    }
    else if (a < 0)
    {
        double y = 1;
        for (int i = a; i < 0; i++)
            y = y * x;
        return 1 / y;
    }
}


int Check_division(int num, int den)
{
    for (int i = 2; i < 11; i++)
        if (num % i == 0 and den % i == 0)
            return i;
    return -1;
}


int curtailment(int num, int den)
{
    int dele = 0, chel_dele = 1;
    dele = Check_division(num, den);
    while (dele != -1)
    {
        chel_dele = chel_dele * dele;
        num = num / dele;
        den = den / dele;
        dele = Check_division(num, den);
    }
    return chel_dele;
}

double SQRT(double x, int a) // значення не точне наприклад для чисел 5 6 7 8 корінь буде рівний 2.5
{
    for (int i = 1; i < x / 2 + 1; i++)
    {
        int A = Pow(i, a), B = Pow(i + 1, a);
        if (A == x) return double(i);
        if (A < x and x < B)
        {
            double C = double(B - A + 1), c = 0;
            // c / C
            for (int j = A; j < B + 1; j++)
            {
                c = c + 1;
                if (x == j) break;
            }
            c = c / C;
            return double(double(i) + c);
        }
    }
}

double Pow(double x, double a)
{
    int Z, num, den, dele, X;
    double I;
    Z = int(a);
    I = a - int(a);
    num = I * 10;
    den = 10;
    dele = curtailment(num, den);
    num = num / dele;
    den = den / dele;
    X = Pow(x, Z);
    x = Pow(x, num);
        /*SQRT(x, den)*/
    return SQRT(x, den) * X;
}

// 2
int Sum_Range(int a, int b)
{
    int sum = 0;
    for (int i = a + 1; i < b; i++) sum = sum + i;
    return sum;
}

// 3
void excelent_number(int a, int b)
{
    for (int i = a; i < b + 1; i++)
    {
        int sum = 0;
        for (int j = 1; j < i / 2 + 1; j++)
        {
            if (i % j == 0) sum = sum + j;
        }
        if (sum == i) cout << sum << "\t";
    }
}

// 5 
bool Happy_number(int number)
{
    int k = 1, num = number;
    while (num / 10 != 0)
    {
        num = num / 10;
        k = k + 1;  
    }
    if (k == 6)
    {
        int First_number, Second_number, Thirth_number, Fourth_number, Fifth_number, Sixth_number;
        Sixth_number = number % 10;
        number = number / 10;
        Fifth_number = number % 10;
        number = number / 10;
        Fourth_number = number % 10;
        number = number / 10;
        Thirth_number = number % 10;
        number = number / 10;
        Second_number = number % 10;
        First_number = number / 10;
        if (First_number + Second_number + Thirth_number == Fourth_number + Fifth_number + Sixth_number) return true;
        else
            return false;
    }
    else
    {
        cout << "nmber not sixth" << endl;
        return 0;
    }
    
}


int main()
{
    /*int x = 2, a = 2;
    cout << sqrt(-4) << endl;
    excelent_number(0, 100);
    cout << Happy_number(123411);*/
    cout << Pow(2, 2) << endl;
    cout << Pow(2.2, 2) << endl;
    cout << Pow(2., -2) << endl;
    cout << Pow(2., 2.2) << endl; // як зміг :) проблема в тому що sqrt важко реалізувати 
    
  
}

