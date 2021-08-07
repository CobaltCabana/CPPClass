/*
  COSC 1337 Exam 3 Lab portion
  Name: Rohan Teredesai
  Filename:
	before submitting, change the file name
	  from: DLS_X3_Lastname.cpp
	  to:   <your course designator>_X3_<your last name>.cpp
	  where DLS is Distance Learning Section (example: DL2)

	NOTE: In devcpp, use compiler options (Tools -> Compiler Options) put: -std=c++14
	otherwise, you may get this error:
	[Warning] extended initializer lists only available with -std=c++11 or -std=gnu++11
*/

#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

// Part 1A, 1B, 1C: create function box, box(wide, tall, symbol)

void  box(int wide = 0, int tall = 1, char symbol = '*') { // modify as necessary, then un-comment
	int area = 0;
	area = (wide * tall);
	static	int sumOfAreas;
	sumOfAreas = sumOfAreas + area;

	if (wide == 0 && tall == 1) {
		cout << "Running Sum of Box Areas: " << sumOfAreas << endl;
	}
	for (int i = 0; i < tall; i++)
	{
		cout << endl;

		for (int n = 0; n < wide; n++)
		{
			cout << symbol;
		}
	}
	cout << endl;

}

char isEvenOrOdd(int wide, int tall) {
	if ((wide + tall) % 2 == 0) {
		return 'e';
	}
	else {
		return 'o';
	}
}

void part1() {
	// ------------------ section below is provided for testing, it is called from main

	cout << "part 1:\n";
	// Testing for part 1D, 1 point, code provided
	cout << "part 1D: testing 1 point:\n";

	box(5, 3, '+');
	cout << endl;
	box(7, 2);
	cout << endl;
	box(8);
	cout << endl;
	box();
	cout << endl;

	// --------------section above code is provided for testing, do not change

	cout << "part 1D: testing 4 points:\n";
	const int tests{ 4 }; // provided; testing loop is best: what if tests changed from 4 to 40?
	for (int i = 0; i < tests; i++)
	{
		int sWide = 1 + (2 * i);
		int sTall = 1 + i;
		box(sWide, sTall, isEvenOrOdd(sWide, sTall));
	}
	// box(1, 1, 'e'); box(3, 2, 'o'); box(5, 3, 'e'); box(7, 4, 'o'); // "brute force" testing
	// Testing for part 1D, 4 points, you must provide a loop here (use "brute force" if you must.)

}

// Put your code for part 2A, 2B, 2C here, class Rect
class Rect {
private:
	int wide;
	int tall;
	char symbol = 'g';

public:
	static int rectCount;

	Rect(int width, int height, char aSymbol) {

		rectCount++;

		wide = width;
		tall = height;
		symbol = aSymbol;

		//	box(width, height, symbol);
	}
	Rect(int width, int height) : Rect(width, height, '*') { }
	Rect(int width) : Rect(width, 1, '*') { }
	Rect() : Rect(0, 1, '*') { }

	void show() {
		for (int i = 0; i < tall; i++)
		{
			cout << endl;

			for (int n = 0; n < wide; n++)
			{
				cout << symbol;
			}
		}
		cout << endl;

	}

	Rect& operator++()       // Prefix increment operator.
	{
		wide++;
		tall++;

		return *this;
	}
	Rect& operator+(Rect& other)       // addition operator.
	{
		//use the symbol from the rectangle with the larger area
		if ((wide * tall) < (other.wide * other.tall)) {
			symbol = other.symbol;
		}
		wide += other.wide;
		tall += other.tall;

		return *this;
	}


};

int Rect::rectCount = 0;


void part2() {
	cout << "part 2:\n";
	// Put your code for part 2 here, it will be called from main:

	cout << "part 2D: testing 3 points:\n";
	Rect rect1(10, 3, '='), rect2(15, 4), rect3(30), rect4; // Provided for testing when ready!
	Rect array[] = { rect1, rect2, rect3, rect4 };
	for (int i = 0; i < 4; i++)
	{
		array[i].show();
		cout << Rect::rectCount << endl;

	}
}



void part3() {
	cout << "part 3:\n";
	Rect* ptr = new Rect(1948, 598, 'r'); // P3A, constructing Rect example, using ACCeID: a1234567

	cout << "Rect is at address: " << ptr << endl;
	cout << endl;

	Rect* array = new Rect[5];
	for (int i = 0; i < 5; i++)
	{
		array[i] = Rect(10, 3, '*');
	}
	for (int i = 0; i < 5; i++)
	{
		cout << "Rect array[" << i <<"] = " << &array[i] << endl;
	}

	delete ptr;
	ptr = nullptr;

	delete[] array;
	array = nullptr;

};



void part4() {
	// Below is testing code for part 4; it will be called from main. No changes needed.
	cout << "part 4:\n";
	cout << "part 4: testing operator++\n";

	Rect r(4, 2);
	for (int i{}; i < 3; ++i) {
		r.show();
		cout << endl;
		++r;
	}


	cout << "part 4: testing operator+\n";
	Rect r1(1, 2, 'S');
	Rect r2(3, 4, 'L');
	Rect r3 = r1 + r2;
	r3.show(); // uncomment when ready to test; r3 will be: 4 tall * 6 wide using 'L'
	cout << endl;
};

void part5() { // EXTRA CREDIT
	cout << "part 5: (optional extra credit)\n";
	// ----------------- This section allocates some memory, but never deletes it
	class Horse { // provided to make a list of horses
		string name; double height; Horse* next;
	public:
		Horse(string name, double height, Horse* next = nullptr) {
			this->name = name; this->height = height; this->next = next;
		}
		Horse* get_next() const {
			return next;
		};
	};

	char* p_buffer = new char[1000];
	int* p_int = new int;
	Horse* p_horses = new Horse("Rusty", 50, new Horse("Flicka", 60));
	Horse* p_paddock = new Horse[3]{ Horse("Abe", 70), Horse("Babe", 80), Horse("Cabe", 90) };
	//---------------------------------------------------------------------
	// Put your code for part 5 here: Delete any memory left on the heap above to prevent memory leak
	// Hint: there are 5 new, so there must be 5 delete. No need to set to nullptr. Save time: don't.
	// No need to display anything to output, just provide delete statements.
	delete[] p_buffer;
	p_buffer = nullptr;

	delete p_int;
	p_int = nullptr;

	delete	p_horses->get_next();
	delete p_horses;
	p_horses = nullptr;

	delete[] p_paddock;
	p_paddock = nullptr;

};

int main() {
	// No new code goes in main. Put all new code where designated in the parts above.
	cout << "Exam 3 Part 3 Start...\n\n";
	part1();
	part2();
	part3();
	part4();
	part5();  // EXTRA CREDIT: free up (delete) memory to prevent memory leak
	cout << "\n...end.\n";
	return 0;
}
/* Initial startup code output:
Exam 3 Part 3 Start...

part 1:
part 1D: testing 1 point:
part 1D: testing 4 points:
part 2:
part 2D: testing 3 points:
part 3:

part 4:
part 4: testing operator++
part 4: testing operator+

part 5: (optional extra credit)

...end.

--------------------------------
Process exited after 0.008192 seconds with return value 0
Press any key to continue . . .
*/

/* part 6: 5 points. Final test output. Paste your test output here:
Exam 3 Part 3 Start...

part 1:
part 1D: testing 1 point:

+++++
+++++
+++++


*******
*******


********

Running Sum of Box Areas: 37



part 1D: testing 4 points:

e

ooo
ooo

eeeee
eeeee
eeeee

ooooooo
ooooooo
ooooooo
ooooooo
part 2:
part 2D: testing 3 points:

==========
==========
==========
4

***************
***************
***************
***************
4

******************************
4


4
part 3:
Rect is at address: 000001E946501100

Rect array[0] = 000001E9464FFC80
Rect array[1] = 000001E9464FFC8C
Rect array[2] = 000001E9464FFC98
Rect array[3] = 000001E9464FFCA4
Rect array[4] = 000001E9464FFCB0
part 4:
part 4: testing operator++

****
****


*****
*****
*****


******
******
******
******

part 4: testing operator+

LLLL
LLLL
LLLL
LLLL
LLLL
LLLL

part 5: (optional extra credit)

...end.

C:\Users\rohan\Desktop\CPP\2021s2_DL2_X3_Teredesai\out\build\x64-Debug\2021s2_DL2_X3_Teredesai\2021s2_DL2_X3_Teredesai.exe (process 6284) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .

*/