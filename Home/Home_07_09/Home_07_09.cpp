// Home_07_09.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
	// First

	/*int number, first_num, second_num, thirth_num, fourth_num, fifth_num, sixth;
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
	}*/

	// Second

	/*int number, first_num, second_num, thirth_num, fourth_num;
	cout << "Enter number :: ";
	cin >> number;
	if (number / 10000 == 0 and number / 1000 != 0) {
		fourth_num = number % 10;
		number /= 10;
		thirth_num = number % 10;
		number /= 10;
		second_num = number % 10;
		number /= 10;
		first_num = number;
		number = second_num * 1000 + first_num * 100 + fourth_num * 10 + thirth_num;
		cout << number;
	}
	else {
		cout << "number is't fourth" << endl;
	}*/

	// Thirth

	/*int max, number;
	cout << "Enter first number :: ";
	cin >> number;
	max = number;
	cout << "Enter Second number :: ";
	cin >> number;
	if (max < number) {
		max = number;
	}
	cout << "Enter Thirth number :: ";
	cin >> number;
	if (max < number) {
		max = number;
	}
	cout << "Enter Fourth number :: ";
	cin >> number;
	if (max < number) {
		max = number;
	}
	cout << "Enter Fifth number :: ";
	cin >> number;
	if (max < number) {
		max = number;
	}
	cout << "Enter Sixth number :: ";
	cin >> number;
	if (max < number) {
		max = number;
	}
	cout << "Enter Seventh number :: ";
	cin >> number;
	if (max < number) {
		max = number;
	}
	cout << "\nMax from first to seventh is " << max << endl;*/

	// Fourth

	//int distance_A_B, distance_B_C, weight, consumption_fuel, used, will_used, remained, refueling;
	//double distance_on_fuel;
	//cout << "Enter distance from A to B :: ";
	//cin >> distance_A_B;
	//cout << "Enter distance from B to C :: ";
	//cin >> distance_B_C;
	//cout << "Enter weight of bagage :: ";
	//cin >> weight;
	//if (weight < 500) {
	//	consumption_fuel = 1;
	//}
	//else if (weight < 1000) {
	//	consumption_fuel = 4;
	//}
	//else if (weight < 1500) {
	//	consumption_fuel = 7;
	//}
	//else if (weight < 2000) {
	//	consumption_fuel = 9;
	//}
	//else if (weight >= 2000) {
	//	cout << "Airplane do not fly up\n";
	//	return 0;
	//}
	//distance_on_fuel = 300 / consumption_fuel;
	///*cout << "distance_on_fuel = " << distance_on_fuel << endl;*/
	//if (distance_on_fuel < distance_A_B) {
	//	cout << "Airplane do not to arrive\n";
	//}
	//else if (distance_on_fuel >= (distance_A_B + distance_B_C)) {
	//	cout << "refueling is not required\n";
	//}
	//else {
	//	used = distance_A_B * consumption_fuel;
	//	/*cout << "Used = " << used << endl;*/
	//	will_used = distance_B_C * consumption_fuel;
	//	/*cout << "will_used = " << will_used << endl;*/
	//	remained = 300 - used;
	//	/*cout << "remained = " << remained << endl;*/
	//	refueling = will_used - remained;
	//	cout << "refueling in point B --> " << refueling << endl;
	//}
	return 0;
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
