// firstProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
	// first
	int year, days;
	cout << "Enter year: ";
	cin >> year;
	auto result = 365.5 - (double)(year % 4) / 10;
	cout << "In " << year << " = " << round(result) << " days" << endl;
	system("pause");
	// secont
	int result_uan, result_coint;
	int uan, coint;
	cout << "Enter uan: " << endl;
	cin >> uan;
	cout << "Enter coint: " << endl;
	cin >> coint;
	result_uan = coint / 100 + uan;
	result_coint = coint % 100;
	cout << "uan --> " << result_uan << " coint --> " << result_coint << endl;
	system("pause");
	// Thirt
	float line_1, line_2, line_3;
	cout << "Volume of paralelepipeda." << endl;
	cout << "Enter date:" << endl;
	cout << "height: " << endl;
	cin >> line_1;
	cout << "wight: " << endl;
	cin >> line_2;
	cout << "lengts: " << endl;
	cin >> line_3;
	cout << "Volume: " << line_1 * line_2 * line_3 << " cube.sm." << endl;
	// Fourth
	float map, distence;
	cout << "Calculation of the distance between settlements.\nEnter date:\n";
	cout << "Enter map scale:" << endl;
	cin >> map;
	cout << "Enter distence:" << endl;
	cin >> distence;
	cout << "distance between settlements = " << map * distence << " km." << endl;
	// Fifth
	float R;
	float pi = 3.14;
	cout << "Enter radiys: " << endl;
	cin >> R;
	cout << "Volume of sphere: " << double(4 * pi * R * R * R / 3);

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menuz

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
