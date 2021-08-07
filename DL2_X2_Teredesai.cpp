/*
  Name:
  COSC 1337
  Exam 2, Programming portion
  When complete: Change course designator "DLS" in filename such that the 'S' is your section number.
				 Change "Lastname" to your lastname.
  Upload file: DLx_X2_Lastname.cpp to BlackBoard Assignment link (x becomes your section number).
*/
#include <iostream>
#include <iomanip>
#include <limits>
#include <string>

using namespace std;

/*
  This exam covers 3 topics: class, array, sort. Each topic has 20 points worth.
  No data input from keyboard or file is required. Write code; use cout to show results.
  Allow a few minutes for testing. 10% deduction if no test results shown at bottom.

  Part 1: class (20 points as follows):
	Step 1 (5 points)
	  Create a class Student. Create private data for: first name, last name, ID; where first
	  name and last name are string, ID is int. The ID does NOT contain a first letter. The
	  ID is only the number portion of a student ACCeID.

	Step 2a (2 points)
	  Create a default constructor for class Student. By default, the student is you!
	  Use your first name, last name and number part of your ACCeID for the default Student.

	Step 2b (3 points)
	  Create another constructor for class Student that requires a parameter for first_name,
	  last_name, and ID. It constructs a student using the information as provided, EXCEPT
	  if the ID provided is negative, make it positive.

	Step 3 (5 points)
	  Create a show method, to display the Student. This outputs the first name, last name and
	  ID of the student to the display. You can return a string and later cout the string, OR
	  you can use cout to directly display the Student.

	Step 4a (2 points)
	  Create a default instance of Student using the default constructor from step 2a and display it
	  using the show method. It will display your firstname, lastname and ID to the screen.

	Step 4b (3 points)
	  Create a "made up" Student of your choice using the constructor from step 2b. Use any first
	  name and last name you want. Use a negative ID value (it should be stored as a positive).
	  Use the show method created in step 3 to display firstname, lastname and ID to the screen.

	Time saving hint: Do not create any unnecessary setters and getters. Only create 2 constructors
	and the show method. Only create 2 instances.


  Part 2: array (20 points as follows):
	Step 1: (5 points)
	  Create an array of int and fill it with the odd numbers from 1 to 29.
	  Do not "hard code" the values, instead, use the following information to create and
	  fill the array: const int START{1}; const int STOP{29}; const int BY{2};
	  Note: If BY{1} makes: 1, 2, 3, ...; BY{2} makes: 1, 3, 5, ...; BY{3} makes: 1, 4, 7, ...
	  The size of the array should be just large enough to hold the numbers.

	Step 2: (5 points)
	  In a loop, display all numbers on one line in the array from step 1 to look like this:
	  1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29

	Step 3: (5 points)
	  Create an array or vector of 5 default Students. Each instance of Student has your information.

	Step 4: (5 points)
	  In a for loop or range for loop, display the information of the 5 students, one per line, in the
	  array or vector created in step 3. (Your first name, last name and ID will appear 5 times.)


  Part 3: sort
	Step 1: (5 points)
	  Write a function: void sort3(a, b, c) such that:
	  The numbers a, b, c are sorted from smallest to largest. Example:
	  if a = 3, b = 1, c = 2, after sort3(a, b, c), then a == 1, b == 2, c == 3
	  Provide the parameter types and code as needed. It only has to sort 3 numbers, no more.
	  Hint: This is similar to swap(a, b) as discussed in class, but it sorts 3 numbers.

	Step 2: (5 points)
	  Write a function that generates and returns a random integer number from small to large, inclusive
	  int rand_range(small, large) // provide the correct types for small, large

	Step 3: (5 points)
	  Write a function, bool is_sorted(a, b, c) that returns true if a, b, c are in
	  ascending sorted order, from smallest to largest; otherwise, return false.

	Step 4: (5 points)
	  Write a loop to test the code above ten times. It looks like this:
	  for 10 test cycles:
		 generate three random numbers: a, b, c, in the range 10 to 99, inclusive.
		 (Use the function written in step 2, by calling rand_range(10, 99) three times.)
		 display a, b, and c in their original unsorted order.
		 call sort3(a, b, c) written in step 1.
		 display a, b, and c in their order AFTER being (hopefully) sorted
		 call is_sorted(a, b, c) on the (hopefully) sorted values
		   if is_sorted returns true, display: "sorted"
		   if is_sorted returns false, display: "not sorted"
	  Format the test cycle data to be easy to examine: Did the number triplets sort correctly?

  Extra credit: Attempt only if time remains! Do NOT let time expire without submitting!
  Part 1 Step 5: (3 points, 5% extra credit)
	  Enhance show method in class Student to show ID as the full ACCeID, which is the first letter
	  of the firstname, lowercase, followed by the numeric ID number.
	  Example: if firstname=Jo lastname=Austin ID=1234567, show ID as ACCeID: j1234567.
*/

class Student // complete as specified in Part 1
{

	// Part 1 Step 1 (5 points)  Create a class Student. Complete as specified.
private:
	string first_name;
	string last_name;
	int student_id;


public:
	// Part 1 Step 2a (2 points) Create a default constructor
	Student() {
		first_name = "Rohan";
		last_name = "Teredesai";
		student_id = 1949598;
	}
	// Part 1 Step 2b (3 points) Create another constructor
	Student(string f_name, string l_name, int id) {
		first_name = f_name;
		last_name = l_name;
		student_id = abs(id); //ensures if the ID provided is negative, make it positive.
	}
	// Part 1 Step 3 (5 points)  Create a show method
	// Part 1, Step 5 (3 points) Extra credit: Enhance show method to show ACCeID
	void show() {
		cout << " First name is " << first_name
			 << " Last name is " << last_name 
			 << " Student ID is " << static_cast<char>(tolower(first_name.at(0))) << student_id << endl;
	}
};


// Part 3 functions go here, will be called later in main in Part 3, Step 4
// Part 3 Step 1: (5 points) Write function: void sort3(a, b, c)
// Using reference parameters so that calling function cam see the updates.
void sort3(int& a, int& b, int& c) {
	//  before sorting
	// To repeat lop to ensure all three numbers are sorted.
	for (int i = 0; i < 2; i++)
	{
		if (a > b) {
			int temp = a;
			a = b;
			b = temp;
		}
		if (b > c) {
			int temp = b;
			b = c;
			c = temp;
		}

	}
	//  after sorting
}
// Part 3 Step 2: (5 points) Write function int rand_range(small, large)
int rand_range(int small, int large) {
	int value = rand() % large;
	if (value < small) {
		value = small;
	}
	return value;
}
// Part 3 Step 3: (5 points) Write function bool is_sorted(a, b, c)
bool is_sorted(int a, int b, int c) {
	if (a > b) {
		return false;
	}
	if (b > c) {
		return false;
	}
	return true;
}
int main() {
	cout << "COSC 1337 Exam 2: class, array, sort" << endl;
	// Part 1 class
	Student me; // This tests the default constructor for class Student
	// Part 1 Step 4a (2 points) Create a default Student and display
	cout << "This is me..." << endl;
	me.show();
	// Part 1 Step 4b (3 points) Create a "made up" Student and display
	cout << "This is my friend..." << endl;
	Student myFriend{ "Kamrey", "Windham", -1234567 };
	myFriend.show();
	// Part 2 array
	const int START{ 1 };
	const int STOP{ 29 };
	const int BY{ 2 };
	//maximum size of array if by
	int array[(STOP - START) + 1];
	// Part 2 Step 1: (5 points)  Create an array of int and fill from START to STOP BY number 2 (odds).
	int value = START;
	int i = 0;
	while (value <= STOP)
	{
		array[i] = value;
		i++;
		value += BY;
	}
	// Part 2 Step 2: (5 points) In loop display all numbers on one line
	cout << array[0];
	for (int j = 1; j < i; j++)
	{
		cout << ", " << array[j];
	}
	cout << endl;
	// Part 2 Step 3: (5 points) Create an array or vector of 5 default Students
	//printing five students
	cout << "Printing student array of size 5" << endl;
	Student studentArray[5];
	// Part 2 Step 4: (5 points) In loop, display the 5 students in array or vector, one per line
	for (size_t i = 0; i < 5; i++)
	{
		studentArray[i].show();
	}
	// Part 3 sort
	srand(time(0)); // Called once and only once so numbers from rand_range() will be different
	// Part 3 Step 1: (5 points) Write a function: void sort3(a, b, c) (* above *)
	// Part 3 Step 2: (5 points) Write function int rand_range(small, large) (* above *)
	// Part 3 Step 3: (5 points) Write function bool is_sorted(a, b, c) (* above *)

	// Part 3 Step 4: (5 points) Write a loop to test sort3, rand_range, is_sorted 10 times. here
	for (int i = 0; i < 10; i++)
	{
		int a = rand_range(10, 99);
		int b = rand_range(10, 99);
		int c = rand_range(10, 99);
		cout << "========================" << endl;
		cout << "Before sorting" << endl;
		cout << " a = " << a;
		cout << " b = " << b;
		cout << " c = " << c << endl;

		sort3(a, b, c);
		if (is_sorted(a, b, c)) {
			cout << "Sorted";
		}
		else {
			cout << "Not Sorted";
		}
		cout << " a = " << a;
		cout << " b = " << b;
		cout << " c = " << c << endl;
	}

	cout << endl << "Goodbye!" << endl; // this should appear as the last line of your output
	return EXIT_SUCCESS; // Use return 0 if EXIT_SUCCESS is undefined
}


/*
  Test code as described. Paste output here. If no tesing, a 10% point penalty (6 points)
  will be deducted from your exam score. Allow some time for testing.
  COSC 1337 Exam 2: class, array, sort
This is me...
 First name is Rohan Last name is Teredesai Student ID is r1949598
This is my friend...
 First name is Kamrey Last name is Windham Student ID is k1234567
1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29
Printing student array of size 5
 First name is Rohan Last name is Teredesai Student ID is r1949598
 First name is Rohan Last name is Teredesai Student ID is r1949598
 First name is Rohan Last name is Teredesai Student ID is r1949598
 First name is Rohan Last name is Teredesai Student ID is r1949598
 First name is Rohan Last name is Teredesai Student ID is r1949598
========================
Before sorting
 a = 10 b = 10 c = 12
Sorted a = 10 b = 10 c = 12
========================
Before sorting
 a = 15 b = 88 c = 73
Sorted a = 15 b = 73 c = 88
========================
Before sorting
 a = 19 b = 82 c = 31
Sorted a = 19 b = 31 c = 82
========================
Before sorting
 a = 82 b = 59 c = 28
Sorted a = 28 b = 59 c = 82
========================
Before sorting
 a = 77 b = 47 c = 60
Sorted a = 47 b = 60 c = 77
========================
Before sorting
 a = 65 b = 46 c = 98
Sorted a = 46 b = 65 c = 98
========================
Before sorting
 a = 63 b = 31 c = 98
Sorted a = 31 b = 63 c = 98
========================
Before sorting
 a = 69 b = 29 c = 10
Sorted a = 10 b = 29 c = 69
========================
Before sorting
 a = 85 b = 34 c = 21
Sorted a = 21 b = 34 c = 85
========================
Before sorting
 a = 77 b = 62 c = 78
Sorted a = 62 b = 77 c = 78

Goodbye!

C:\Users\rohan\Desktop\CPP\DL2_X2_Teredesai\out\build\x64-Debug\DL2_X2_Teredesai\DL2_X2_Teredesai.exe (process 23956) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .
*/