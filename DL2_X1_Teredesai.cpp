/*
  Name: Rohan Teredesai
  COSC 1337
  Exam 1, Programming portion
  When complete: Change course designator in filename from DLS to DL<section number>
				 Change "Lastname" to your lastname.
  Upload file DL(sec#)_X1_Lastname.cpp to BlackBoard.
*/
#define _USE_MATH_DEFINES


#include <cmath>
#include <iostream>
#include <iomanip>
#include <vector>


using namespace std;

/* INSTRUCTIONS:
  There are 4 regular steps (40 points) and 2 extra credit steps (4 points).
  Some algorithms and IPOs (Input, Processing, Output) are provided.
  The term: "input" may refer to keyboard input from the user; OR
  "input" may refer to input to a function as a function parameter.

  Step 1. (10 points)
  A common task in geometry is to find the area of a shape.
  Example areas: square (side * side); rectangle (height * width);
  circle (pi * radius_squared); triangle (1/2 * base * height)

  Write 4 overloaded functions, all called area,
  that return the area of different shapes: (the return is type double)
	area(side)   one parameter, assume shape is a square
	area(radius) one parameter, assume shape is a circle
	area(height, width) two parameters, assume shape is a rectangle
	area(base, height)  two parameters, assume shape is a triangle
  The return type of all area functions is type double

  To help the compiler decide WHICH area function to call, use
  different numeric types for the parameters. Choose from: float, double.
  For example, side has to be one numeric type, radius has to be a different numeric type.
  It doesn't matter which types (float or double), but they have to be different.

  Similarly, for area of rectangle, the types for height and width must be
  different than the types for triangle base and height. That way, the compiler
  can call the correct function. The parameter types help decide which
  kind of shape is involved.

  For the value of pi (3.1415926...) use M_PI. To make this useful constant
  available, put the following two lines in the correct place in the program:
  #define _USE_MATH_DEFINES
  #include <cmath>

  After the area functions are complete, test them. (See test code below in main.)
  To get the compiler to call the desired area function, use arguments
  of the correct type. Testing code is provided below in main. Some changes are needed.

  (2) points for each area function (4*2=8), (2) points for testing, total (10) points.
*/

double area() { // provided for step 1, step 2 so initial test code compiles; leave this unchanged
	return 123.456;
}

// provide 4 overloaded area() functions for step 1 here:

//one parameter, assume shape is a square
double area(double side) {
	return pow(side, 2.0);
}
//one parameter, assume shape is a circle
double area(float radius) {
	return (M_PI * pow(radius, 2.0));

}
//two parameters, assume shape is a rectangle
double area(double height, double width) {
	return (height * width);
}
//two parameters, assume shape is a triangle
double area(float base, float height) {
	return (0.5 * height * base);

}


/*
  Step 2. (10 points)
  Another strategy to compute the area for a particular shape is to
  just tell the function what kind of shape it is, then use the provided
  parameters as expected for that shape. Using default parameters, the
  area for each shape can be computed, provided the type of shape and the
  one or two parameters needed to compute that shape's area.

  Create a function: area(type-of-shape, dimension1, dimension2)
  Use type double for the return, dimension1, and dimension2
  Use the table below to write the function body:

  type-of-shape  | dimension1  |  dimension2  |  area
  ---------------|-------------|--------------|--------
  Square         |    side     |  not-needed  | size*side
  Rectangle      |   height    |    width     | height*width
  Circle         |   radius    | not-needed   | PI*radius_squared
  Triangle       |    base     |    height    | 1/2 * base * height

  To create the type-of-shape, use an enumerated type, enum, for shapes.
  Hint: recall enum direction_t{North, South, East, West}
  Use a switch to switch on the type-of-shape, then provide a case
  for each valid shape. Based on the shape, return the proper area.


  This adds one more overloaded function, also called area, which
  can be easier to use.

  (8) points for area function, (2) points for testing, total (10) points.
*/

// Create the shape type and area function here:

enum Shape { Square, Rectangle, Circle, Triangle };
double area(const Shape shapeType, double dimension1, double dimension2 = 0) {
	switch (shapeType) {

	case Square:
		return area(dimension1);
	case Rectangle:
		return area(dimension1, dimension2);
	case Circle:
		//to insure insure it will call the circle overload area function.
		return area(static_cast<float>(dimension1));
	case Triangle:
		//to insure insure it will call the triangle overload area function.
		return area(static_cast<float>(dimension1), static_cast<float>(dimension2));
	default:
		cout << "SHould never come here! shapeType = " << shapeType << endl;
		//Area are never negative. So returning an invalid value.
		return -1;
	}

}
/*
  Step 3. (10 points)
  A common group of statistical values are: minimum, maximum, sum, difference, average.
  For short: min, max, sum, dif, avg.
  For example, numbers 10 and 100 produce: min=10, max=100, sum=110, dif=90, avg=55

  Write a single function, stats, that provides all of these values, based on
  two input parameters, num1 and num2; and five output parameters (the results). (5 points.)
  Provide correct types for each parameter.

  Below in main, activate testing code to call this function.
  See testing instructions lower in main.

  (5) points for stats function, (5) points for testing, total (10) points.
*/

//To avoid collision with function names, changed the formal parameter names.
void stats(double num1, double num2, double& minimum, double& maximum, double& sumOfTwo, double& difference, double& average)
{
	minimum = num1 < num2 ? num1 : num2;
	maximum = num1 > num2 ? num1 : num2;
	sumOfTwo = num1 + num2;
	difference = num1 - num2;
	average = (num1 + num2) / 2.0;
	return;
}

//utility function to make sure user input is a number
bool is_number(const std::string& s)
{
	return atof(s.c_str()) != 0;
}
/*
  Step 4. (10 points)

  A common programming task is to get numerical input from the user.
  Write a single function "get_num" that will:
	1) Display a prompt
	2) Get user's input (from keyboard)
	3) Verify that the input is numeric
	4) If the input is NOT numeric, display err_msg1, fix cin, and loop up to 1)
	5) Check if the numeric value is within range, min..max, inclusive
	6) If the input is in range, accept it and return
	7) If the input is not in range, display err_msg2 and loop up to 1)

	Create a new function that performs the steps above. Use the following:
	  1) Function name: get_num
	  2) Parameter: prompt      (pass by constant reference)
	  3) Parameter: err_msg1    (pass by constant reference)
	  4) Parameter: err_msg2    (pass by constant reference)
	  5) Parameter: min         (pass by value, type double)
	  6) Parameter: max         (pass by value, type double)
	  7) return: value          (type double)

  (8) points for get_num function, (2) points for testing, total (10) points.
*/

// step 4 (8 of 10 points) function get_num() goes here ---
 // modify as appropriate: add parameters, function body, return value

template <typename T>
T get_num(const string prompt,
	const string err_msg1,
	const string err_msg2,
	T min,
	T max)
{

	while (true)
	{
		string userInput;
		cout << prompt << min << " and " << max << endl;
		cin >> userInput;
		// If not number show error 1
		if (!is_number(userInput)) {
			cout << userInput << err_msg1 << endl;
			continue;
		}
		double inputNum = atof(userInput.c_str());
		// If not within range show error 2
		if (inputNum < min || inputNum > max) {
			cout << inputNum << err_msg2 << min << " and " << max << endl;
			continue;
		}
		return inputNum;
	}
}


/*
  Step 5. (2 points) EXTRA CREDIT, OPTIONAL
	Turn step 4 function "get_num" above into a function template, so it works
	for any numeric type: char, short, int, float, double, etc. instead of just double.
	Hint: template <typename T>


  Step 6. (2 points) EXTRA CREDIT, OPTIONAL
	Use this: {"One", "more", "line", "of", "code", "and", "I", "am", "outta", "here"}
	as an initializer list in a range-for loop, so each word is displayed in a sentence.
	The words should be seperated by spaces and end with a period:
	  One more line of code and I am outta here.
	To implement, put your code in function step6() below, and uncomment step6() at the end of main.
*/

void step6() {
	cout << "\nstep 6 (EC): Statement of conviction:\n ";
	std::vector<string> wordList = { "One", "more", "line", "of", "code", "and", "I", "am", "outta", "here" };
	// access by const reference
	for (const string& eachWord : wordList)
	{
		cout << eachWord << endl;
	}
}
int main() {
	cout << "COSC 1337 Exam 1 Lab Portion" << endl;

	/*
	  step 1 testing (2 of 10 points) Provide the correct arguments to the area functions
	  below, so they  call the correct area function written above for step 1.
	  You can create temporary variables, use static_cast, or use type literals
	  to get the arguments to be the correct types.
	*/

	cout << "\nstep 1: Area of various shapes, using overloaded functions:\n";
	cout << "  square area for side of 2.2 is: " << area(static_cast <double>(2.2)) << endl;
	cout << "  circle area for radius of 3.3 is: " << area(static_cast<float>(3.3)) << endl;
	cout << "  rectangle area for rectangle of 4.4 height, 5.5 width is: " << area(static_cast <double>(4.4),
		static_cast <double>(5.5)) << endl;
	cout << "  triangle area for triangle of 6.6 wide and 7.7 tall is: " << area(static_cast <float>(6.6),
		static_cast <float> (7.7)) << endl;


	/*
	  step 2 testing (2 of 10 points) Provide the correct arguments to the area function
	  written for step 2, so it computes the correct area. The same area function
	  will be called for all shape types.
	*/

	cout << "\nstep 2: Area of various shapes, based on shape type:\n";
	cout << "  square area for side of 2.2 is: " << area(Square, 2.2) << endl;
	cout << "  circle area for radius of 3.3 is: " << area(Circle, 3.3) << endl;
	cout << "  rectangle area for rectangle of 4.4 height, 5.5 width is: " << area(Rectangle, 4.4, 5.5) << endl;
	cout << "  triangle area for triangle of 6.6 wide and 7.7 tall is: " << area(Triangle, 6.6, 7.7) << endl;


	/*
	  step 3 testing (5 of 10 points) Provide the correct arguments to the stats function
	  written for step 3, so it computes the correct statistical values. Then output
	  the result for the user to see. Use 10 and 100 as the test input numbers.
	*/
	double num1 = 10;
	double num2 = 100;
	double minimum = 0;
	double maximum = 0;
	double sumOfTwo = 0;
	double difference = 0;
	double average = 0;

	stats(num1, num2, minimum, maximum, sumOfTwo, difference, average);
	cout << "\nstep 3: Statistics on a pair of numbers:" << num1 << " and " << num2 << "\n";
	cout << "minimum = " << minimum << endl;
	cout << "maximum = " << maximum << endl;
	cout << "sumOfTwo = " << sumOfTwo << endl;
	cout << "difference = " << difference << endl;
	cout << "average = " << average << endl;


	/*
	  step 4 (2 of 10 points for testing) call to get_num() goes here ---
	  Test get_num. Call get_num once. Get a number within some valid range. Here are some ideas:
	  hour(0..23), month(1..12), inches(1..36), weekday(1..7), temp(-20..120), fingers(1..5)
	  Pick one of these examples, or make up one of your own. Test get_num once.
	  Save a variable containing the return value from get_num, and display that variable.
	  Example: "The month is: 6"
	*/

	double result = get_num("Enter hours between ", " Is not a number, please enter a number", " Is not within range", 0, 23);
	cout << "\nstep 4: Return value from get_num:\n";
	cout << "  The result is: " << result << endl;

	result = get_num("Enter month between ", " Is not a number, please enter a number", " Is not within range", 1, 12);
	cout << "\nstep 4: Return value from get_num:\n";
	cout << "  The result is: " << result << endl;

	result = get_num("Enter month between ", " Is not a number, please enter a number", " Is not within range", 5.5, 12.5);
	cout << "\nstep 4: Return value from get_num:\n";
	cout << "  The result is: " << result << endl;

	step6(); // Uncomment if you do step 6

	cout << endl << "Goodbye!" << endl; // this should appear as the last line of your output

	return EXIT_SUCCESS; // Use return 0 if EXIT_SUCCESS is undefined
}

/*
  Paste your test output below.  2 point DEDUCTION if no test output.

  COSC 1337 Exam 1 Lab Portion

step 1: Area of various shapes, using overloaded functions:
  square area for side of 2.2 is: 4.84
  circle area for radius of 3.3 is: 34.2119
  rectangle area for rectangle of 4.4 height, 5.5 width is: 24.2
  triangle area for triangle of 6.6 wide and 7.7 tall is: 25.41

step 2: Area of various shapes, based on shape type:
  square area for side of 2.2 is: 4.84
  circle area for radius of 3.3 is: 34.2119
  rectangle area for rectangle of 4.4 height, 5.5 width is: 24.2
  triangle area for triangle of 6.6 wide and 7.7 tall is: 25.41

step 3: Statistics on a pair of numbers:10 and 100
minimum = 10
maximum = 100
sumOfTwo = 110
difference = -90
average = 55
Enter hours between 0 and 23
15.5

step 4: Return value from get_num:
  The result is: 15
Enter month between 1 and 12
12

step 4: Return value from get_num:
  The result is: 12
Enter month between 5.5 and 12.5
2.9
2.9 Is not within range5.5 and 12.5
Enter month between 5.5 and 12.5
10.0

step 4: Return value from get_num:
  The result is: 10

step 6 (EC): Statement of conviction:
 One
more
line
of
code
and
I
am
outta
here

Goodbye!

C:\Users\rohan\Desktop\CPP\DL2_X1_Teredesai\out\build\x64-Debug\DL2_X1_Teredesai\DL2_X1_Teredesai.exe (process 35916) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .

*/