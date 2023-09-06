#include <iostream>

using std::cout;
using std::endl;
using std::cin;

enum MyEnum
{
	ONE = 1, TWO, THREE, FOUR
};

int main() {
	//// First
	//cout << "First exersise" << endl;
	//int number;
	//cout << "Enter number :: ";
	//cin >> number;
	//if (number % 2 == 0) {
	//	cout << number << " is couple" << endl;
	//}
	//else {
	//	cout << number << " is't couple" << endl;

	//}
	//cout << endl;
	//// Second
	//cout << "Second exersise" << endl;
	//int a, b;
	//cout << "Enter a :: ";
	//cin >> a;
	//cout << "Enter b :: ";
	//cin >> b;
	//if (a < b) {
	//	cout << "a < b";
	//}
	//else if (a > b) {
	//	cout << "a > b";
	//}
	//else {
	//	cout << " a = b";
	//}
	//cout << endl;
	//cout << endl;
	//// Thirth
	//int num;
	//cout << "Thirth exersise" << endl;
	//cout << "Enterr number :: ";
	//cin >> num;
	//if (num > 0) {
	//	cout << "number is positive";
	//}
	//else if (num < 0) {
	//	cout << "number is negative";
	//}
	//else {
	//	cout << "number equal zero";
	//}
	//cout << endl;
	//cout << endl;
	//// Fourth
	//cout << "Fourth exersise" << endl;
	//int first_num, second_num;
	//cout << "enter first number :: ";
	//cin >> first_num;
	//cout << "Enter second number :: ";
	//cin >> second_num;
	//if (first_num > second_num) {
	//	cout << second_num << endl << first_num;
	//}
	//else if (first_num < second_num) {
	//	cout << first_num << endl << second_num;
	//}
	//else {
	//	cout << "number are equal";
	//}
	//cout << endl;
	//cout << endl;
	//// Second part
	//cout << "First exersise" << endl;
	//int first_mark, second_mark, thirth_mark, fourth_mark, fifth_mark;
	//double average_mark;
	//cout << "Enter five marks : ";
	//cin >> first_mark >> second_mark >> thirth_mark >> fourth_mark >> fifth_mark;
	//average_mark = (first_mark + second_mark + thirth_mark + fourth_mark + fifth_mark) / 5;
	//if (average_mark < 4) {
	//	cout << "not allowed for examination";
	//}
	//else {
	//	cout << "allowed for examination";
	//}
	//cout << endl;
	//cout << endl;
	//// second exersise
	//cout << "Second exersise" << endl;
	//int number_for_cheking;
	//cout << "Enter number :: ";
	//cin >> number_for_cheking;
	//if (number_for_cheking % 2 == 0) {
	//	cout << number_for_cheking * 3 << endl;
	//}
	//else if (number_for_cheking == 0) {
	//	cout << "equal zero" << endl;
	//}
	//else {
	//	cout << double(double(number) / 2) << endl;

	//}
	//cout << endl;
	//// Thirth exersise
	//int x, y, choose;
	//cout << "thirth exersise" << endl;
	//cout << "Enter x :: ";
	//cin >> x;
	//cout << "Enter y :: ";
	//cin >> y;
	//cout << "Choose your variant\n\t1) add\n\t2) diferent\n\t3) multiplication\n\t4) division\n";
	//cin >> choose;

	//switch (choose)
	//{
	//case ONE:
	//	cout << x + y << endl;
	//	break;
	//case TWO:
	//	cout << x - y << endl;
	//	break;
	//case THREE:
	//	cout << x * y << endl;
	//	break;
	//case FOUR:
	//	cout << double(double(x) / double(y)) << endl;
	//	break;
	//default:
	//	cout << "Error\n";
	//	break;
	//}
	int number, first_num, second_num, thirth_num, fourth_num, fifth_num, sixth;
	cout << "Enter number :: ";
	cin >> number;
	if (number / 1000000 == 0 and number / 100000 != 0) {
		sixth = number % 10;
		number /= 10;
		fifth_num = number % 10;
		number /= 10;
		fourth_num = number % 10;
		number /= 10;
		thirth_num = number % 10;
		number /= 10;
		second_num = number % 10;
		number /= 10;
		first_num = number;
		if (first_num + second_num + thirth_num == fourth_num + fifth_num + sixth) {
			cout << "number is happy :)" << endl;
		}
		else {
			cout << "number is't happy :)" << endl;
		}
	}
	else {
		cout << "number is't sixth" << endl;
	}
}