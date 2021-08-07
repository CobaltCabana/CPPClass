// DL2_L11_Teredesai.cpp : Defines the entry point for the application.
/*
  Author:          Rohan Teredesai
  Assignment:      Lab 11
  Topic:           Demonstrate Ch 11: This, operator overload, static members, friends
  Course/Section:  COSC 1337 DL2
  Due Date:        July 27
  Instructor:      Thayer
  Purpose:		   Combine two of the Programming Challenges at the end of Chapter 11:
						2) Day of the Year; and 3) Day of the Year Modification
*/

#include <iostream>
#include <algorithm>

using namespace std;

class Day
{
private:
	int dayOfYear = 1;

public:
	static const int daysInMonth[12];
	static const int startDay[12];
	static const int endDay[12];
	static const string month[12];

	//Pre and Post Operators Implemented as per: https://docs.microsoft.com/en-us/cpp/cpp/increment-and-decrement-operator-overloading-cpp?view=msvc-160
	// Declare prefix and postfix increment operators.
	Day& operator++()       // Prefix increment operator.
	{
		dayOfYear++;
		if (dayOfYear == 366) {
			dayOfYear = 1;
		}
		return *this;
	}
	Day operator++(int)     // Postfix increment operator.
	{
		Day temp = *this;
		++* this;
		return temp;
	}
	// Declare prefix and postfix decrement operators.
	Day& operator--() // Prefix decrement operator.
	{
		dayOfYear--;
		if (dayOfYear == 0) {
			dayOfYear = 365;
		}
		return *this;
	}
	Day operator--(int)     // Postfix decrement operator.
	{
		Day temp = *this;
		--* this;
		return temp;
	}

	friend ostream& operator<<(ostream& os, const Day& aDay)
	{
		os << "operator<< overload for Day: " << month[aDay.getMonth()] << ", " << aDay.getDay() << endl;
		return os;
	}

	void print() {
		cout << month[getMonth()] << ", " << getDay() << endl;
	}

	int getMonth() const {
		for (int i = 0; i < 12; i++)
		{
			if (dayOfYear >= startDay[i] && dayOfYear <= endDay[i]) {

				return i;
			}
		}
		return -1;
	}
	int getDay() const {
		int localMonth = getMonth();
		return (dayOfYear - startDay[localMonth] + 1);
	}
	// Ctor 1
	Day(int currentDay) {
		if (currentDay > 0) {
			// safeguards against values above 365
			dayOfYear = (currentDay % 365);
			if (dayOfYear == 0) {
				dayOfYear = 365;
			}
		}
		if (dayOfYear < 1) {
			//default to January 1st if bad value is inputted
			dayOfYear = 1;
		}
	}
	// Ctor 2
	Day(string currentMonth, int currentDay) {
		currentDay--;
		std::transform(currentMonth.begin(), currentMonth.end(), currentMonth.begin(), ::tolower);
		//find Month, defaulting to january if month isn't found
		int indexOfCurrentMonth = 0;
		for (int i = 0; i < 12; i++)
		{
			if (currentMonth == month[i]) {
				indexOfCurrentMonth = i;
			}
		}
		if (currentDay >= daysInMonth[indexOfCurrentMonth] || currentDay < 0) {
			dayOfYear = 1;
		}
		else {
			dayOfYear = startDay[indexOfCurrentMonth] + currentDay;
		}
	}
};

void test_operators(Day bday) {

	cout << "start at: "; bday.print(); cout << endl;
	for (int i = 0; i < 5; ++i) { cout << " "; (--bday).print(); } cout << endl;
	for (int i = 0; i < 5; ++i) { cout << " "; (++bday).print(); } cout << endl;
	for (int i = 0; i < 5; ++i) { cout << " "; (bday++).print(); } cout << endl;
	for (int i = 0; i < 5; ++i) { cout << " "; (bday--).print(); } cout << endl;
	cout << "end at: "; bday.print(); cout << endl;
}

void variousTests() {
	Day test1("Dec", 31);
	cout << test1;
	Day test2("Jan", 1);
	cout << test2;
	Day test3("Dec", 32);
	cout << test3;
	Day test4("Jan", 0);
	cout << test4;
	Day test5("Invalid Month", 23);
	cout << test5;
	Day test6("Feb", 29);
	cout << test6;

	test_operators(test2);
}

Day monthDayMode() {
	string inputMonth;
	int inputDay = 0;
	Day lastDay(1);
	while (inputDay != -9) {
		cout << "Enter month(mmm) day_of_month(d): (stop -9 to quit):";
		cin >> inputMonth >> inputDay;
		if (inputDay == -9)
		{
			break;
		}
		// pass this value to the day class
		std::transform(inputMonth.begin(), inputMonth.end(), inputMonth.begin(), ::tolower);
		Day aDay(inputMonth, inputDay);
		aDay.print();
		lastDay = aDay;
	}
	return lastDay;
}
const int Day::daysInMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
const int Day::startDay[12] = { 1, 32, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335 };
const int Day::endDay[12] = { 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
const string Day::month[12] = { "jan", "feb", "mar", "apr", "may", "jun", "jul", "aug", "sep", "oct", "nov", "dec" };
int main()
{
	Day bday("jul", 1);
	while (true) {
		char userMode;
		cout << "options: d)ay [#d->m,d];  m)onth+day [m d->#d]; o)perator [+/-5]; v)arious; q)uit: ";
		cin >> userMode;
		if (userMode == 'q') {
			cout << "Goodbye, Quitting" << endl;
			return 0;
		}
		if (userMode == 'd') {
			int inputValue = 0;
			while (inputValue != -9) {
				cout << "Enter day of year# (-9 to quit):";
				cin >> inputValue;
				if (inputValue == -9)
				{
					break;
				}
				// pass this value to the day class
				Day aDay(inputValue);
				aDay.print();
				cout << aDay;
				bday = aDay;
			}
		}
		else if (userMode == 'm') {
			bday = monthDayMode();
		}
		else if (userMode == 'o') {
			test_operators(bday);
		}
		else if (userMode == 'v') {
			variousTests();
		}
	}
}
//Test Code Below
/*
options: d)ay [#d->m,d];  m)onth+day [m d->#d]; o)perator [+/-5]; v)arious; q)uit: d
Enter day of year# (-9 to quit):1
jan, 1
operator<< overload for Day: jan, 1
Enter day of year# (-9 to quit):365
dec, 31
operator<< overload for Day: dec, 31
Enter day of year# (-9 to quit):34
feb, 3
operator<< overload for Day: feb, 3
Enter day of year# (-9 to quit):91
apr, 1
operator<< overload for Day: apr, 1
Enter day of year# (-9 to quit):1000
sep, 27
operator<< overload for Day: sep, 27
Enter day of year# (-9 to quit):-1000
jan, 1
operator<< overload for Day: jan, 1
Enter day of year# (-9 to quit):-9
options: d)ay [#d->m,d];  m)onth+day [m d->#d]; o)perator [+/-5]; v)arious; q)uit: m
Enter month(mmm) day_of_month(d): (stop -9 to quit):May 17
may, 17
Enter month(mmm) day_of_month(d): (stop -9 to quit):JUL 4
jul, 4
Enter month(mmm) day_of_month(d): (stop -9 to quit):Feb 29
jan, 1
Enter month(mmm) day_of_month(d): (stop -9 to quit):Dec 32
jan, 1
Enter month(mmm) day_of_month(d): (stop -9 to quit):Mar 16
mar, 16
Enter month(mmm) day_of_month(d): (stop -9 to quit):stop -9
options: d)ay [#d->m,d];  m)onth+day [m d->#d]; o)perator [+/-5]; v)arious; q)uit: o
start at: mar, 16

 mar, 15
 mar, 14
 mar, 13
 mar, 12
 mar, 11

 mar, 12
 mar, 13
 mar, 14
 mar, 15
 mar, 16

 mar, 16
 mar, 17
 mar, 18
 mar, 19
 mar, 20

 mar, 21
 mar, 20
 mar, 19
 mar, 18
 mar, 17

end at: mar, 16

options: d)ay [#d->m,d];  m)onth+day [m d->#d]; o)perator [+/-5]; v)arious; q)uit: v
operator<< overload for Day: dec, 31
operator<< overload for Day: jan, 1
operator<< overload for Day: jan, 1
operator<< overload for Day: jan, 1
operator<< overload for Day: jan, 23
operator<< overload for Day: jan, 1
start at: jan, 1

 dec, 31
 dec, 30
 dec, 29
 dec, 28
 dec, 27

 dec, 28
 dec, 29
 dec, 30
 dec, 31
 jan, 1

 jan, 1
 jan, 2
 jan, 3
 jan, 4
 jan, 5

 jan, 6
 jan, 5
 jan, 4
 jan, 3
 jan, 2

end at: jan, 1

options: d)ay [#d->m,d];  m)onth+day [m d->#d]; o)perator [+/-5]; v)arious; q)uit: q
Goodbye, Quitting

C:\Users\rohan\Desktop\CPP\DL2_L11_Teredesai\out\build\x64-Debug\DL2_L11_Teredesai\DL2_L11_Teredesai.exe (process 20916) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .
*/