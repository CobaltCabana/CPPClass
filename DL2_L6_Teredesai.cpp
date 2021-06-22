// Author: Rohan Teredesai;  Course: COSC 1337 Summer 2021 DL2;  Instructor: Thayer
// Lab: 06  Purpose:   Calculate the distance between two things. The two “things”: two letters in the alphabet, two numbers on a number line or two points on a graph

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

bool is_number(const std::string& s)
{
	std::string::const_iterator it = s.begin();
	while (it != s.end() && std::isdigit(*it)) ++it;
	return !s.empty() && it == s.end();
}

void display(const string& msg, char ch1, char ch2) // display letters and letter distance
{
	cout << msg << ch1 << " and " << ch2 << endl;
}
void display(const string& msg, double d1, double d2) // display numbers and number distance
{
	cout << msg << d1 << " and " << d2 << endl;

}
void display(const string& msg, double x1, double y1, double x2, double y2) // display points and point distance.
{
	cout << msg << "(" << x1 << "," << y1 << ")" << " and " << "(" << x2 << "," << y2 << ")" << endl;
}
double calculateDistanceBetween(double p1, double p2) { // return the distance between two numbers
	return (p1 - p2);
}
int calculateDistanceBetween(char c1, char c2) { // return the distance between two letters (a-z)
	int dist = (c1 - c2);
	return dist;
}
double calculateDistanceBetween(double x1, double y1, double x2, double y2) { // return distance between two points.
	double dist = pow(pow((x2 - x1), 2.0) + pow((y2 - y1), 2.0), 0.5);
	return dist;
}

// handles char input
char input(string prompt_text, string error_message_text) {
	char letterInput1;
	do
	{
		cout << prompt_text << endl;
		cin >> letterInput1;
		if (!isalpha(letterInput1)) {
			cout << error_message_text << endl;
		}
		letterInput1 = tolower(letterInput1);
	} while (!isalpha(letterInput1));
	return letterInput1;
}

double input(double min_number, double max_number, string prompt_text, string error_message_text) // for getting a number
{
	double input_number;
	string input1;

	do
	{
		cout << prompt_text << "(" << min_number << ", " << max_number << ") : " << endl;
		cin >> input1;
		input_number = atof(input1.c_str());

		if (input_number < min_number || input_number > max_number) {
			cout << error_message_text << "(" << min_number << ", " << max_number << ")" << endl;
		}
	} while (input_number < min_number || input_number > max_number);

	return input_number;
}

void input(double& x, double& y, string prompt_text) // for getting a point (x, y)
{
	string input1;
	string input2;

	cout << prompt_text << "(x)" << endl;
	cin >> input1;
	x = atof(input1.c_str());

	cout << prompt_text << "(y)" << endl;
	cin >> input2;
	y = atof(input2.c_str());
}

int main()
{
	char option;

	cout << "Display the distance between two items: letters, numbers, or points." << endl;
	while (true)
	{
		// 1) and 2): Example of function overloading = same function name, different signature
		cout << "Options: l)etter; n)umber; p)oint; q)uit: " << endl;
		cin >> option;
		if (option == 'l') {
			char letterInput1 = input("Give your first letter (a to z): ", "Invalid! I said a letter between (a to z)");
			char letterInput2 = input("Give me your next letter (a to z): ", "Invalid! I said a letter between (a to z)");
			char returnChar = abs(calculateDistanceBetween(letterInput1, letterInput2));
			const string dist = "Distance = " + std::to_string(returnChar) + " between ";
			display(dist, letterInput1, letterInput2);

		}
		else if (option == 'n') {
			double d1 = input(-100, 100, "Enter 1st number between ", "Invalid! I said a number between ");
			double d2 = input(-100, 100, "Enter next number between ", "Invalid! I said a number between ");
			double returnDouble = abs(calculateDistanceBetween(d1, d2));
			const string dist = "Distance = " + std::to_string(returnDouble) + " between ";
			display(dist, d1, d2);

		}
		else if (option == 'p') {
			double x1;
			double x2;
			double y1;
			double y2;

			input(x1, y1, "Enter the first point");
			input(x2, y2, "Enter the second point");

			double returnDouble = abs(calculateDistanceBetween(x1, y1, x2, y2));
			const string dist = "Distance = " + std::to_string(returnDouble) + " between ";
			display(dist, x1, y1, x2, y2);

		}
		else if (option == 'q') {
			cout << "See Ya, Space Programmer" <<endl;
			break;
		}
		else {
			cout << "invalid input" << endl;
		}
	}
}
/*
Display the distance between two items: letters, numbers, or points.
Options: l)etter; n)umber; p)oint; q)uit:
l
Give your first letter (a to z):
u
Give me your next letter (a to z):
1
Invalid! I said a letter between (a to z)
Give me your next letter (a to z):
m
Distance = 8 between u and m
Options: l)etter; n)umber; p)oint; q)uit:
n
Enter 1st number between (-100, 100) :
-25
Enter next number between (-100, 100) :
123
Invalid! I said a number between (-100, 100)
Enter next number between (-100, 100) :
25
Distance = 50.000000 between -25 and 25
Options: l)etter; n)umber; p)oint; q)uit:
p
Enter the first point(x)
8
Enter the first point(y)
5
Enter the second point(x)
7
Enter the second point(y)
3
Distance = 2.236068 between (8,5) and (7,3)
Options: l)etter; n)umber; p)oint; q)uit:
p
Enter the first point(x)
8
Enter the first point(y)
3
Enter the second point(x)
4
Enter the second point(y)
7
Distance = 5.656854 between (8,3) and (4,7)
Options: l)etter; n)umber; p)oint; q)uit:
q
See Ya, Space Programmer

C:\Users\rohan\Desktop\CPP\DL2_L6_Teredesai\out\build\x64-Debug\DL2_L6_Teredesai\DL2_L6_Teredesai.exe (process 7656) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .
*/