/*
  Author:          Rohan Teredesai
  Assignment:      Lab 10
  Topic:           memory diagram with stack, heap structures
  Course/Section:  COSC 1337
  Due Date:        See syllabus or blackboard
  Instructor:      Thayer
  Purpose:
  This lab is on pointers. It covers: values, addresses, pointers, the heap,
  dynamic memory allocation using new, delete, delete [].
  It also has a brief introduction to linked lists, a basic data structure.

  Create a program that uses memory as shown in the memory diagram provided.
  Start with this startup code, which has useful macros to display variables.
*/
#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

class Number { // modify class Number if desired to provide constructors, etc.
public:
	string name;     // name of the Number
	Number* next = nullptr;    // pointer to the next Number in the list
};

// Helpful macros to make it easier to output name, address, and value of a variable
// You may use these, or write your own function that does something similar
#define show_addr_value(var, width) \
  cout<<"address of " <<setw(width)<<left<<#var<<" is: &"<<&var<<"  "     \
      <<"contents of "<<setw(width)<<left<<#var<<" is: "<<var<<endl;

#define show_addr(var, width) \
  cout<<"address of " <<setw(width)<<left<<#var<<" is: &"<<&var<<endl;

int main() {
	cout << "Output from Lab10 memory diagram on pointers:\n\n";



	float price = 0;
	float* p_price = &price;
	*p_price = 18.65;
	show_addr_value(price, 8);
	show_addr_value(p_price, 8);
	cout << "The contents of *p_price is: " << *p_price << endl;
	cout << endl;

	double PI = 0;
	double* p_PI = &PI;
	*p_PI = M_PI;
	double PI_div_2 = (*p_PI) / 2.0;
	show_addr_value(PI, 8);
	show_addr_value(PI_div_2, 8);
	show_addr_value(p_PI, 8);
	cout << "The contents of *p_PI is:    " << *p_PI << endl;
	cout << endl;

	//1) As an integer to store on the stack as one int; 
	int ACCeID = 1949598;
	int* p_ACCeID = &ACCeID;
	show_addr_value(ACCeID, 8);
	show_addr_value(p_ACCeID, 8);
	cout << "The contents of *p_ACCeID is: " << *p_ACCeID << endl;
	cout << endl;



	// 2) As the number of elements in an array of double allocated on the heap;
	int* p_amount = new int;
	*p_amount = 2468;

	show_addr_value(p_amount, 8);
	cout << "The contents of *p_amount is: " << (dec) << *p_amount << endl;
	delete p_amount;
	cout << "After delete, the contents of p_amount is: " << p_amount << endl;
	p_amount = nullptr;
	cout << "After reset to nullptr, the contents of p_amount is: " << p_amount << endl;
	cout << endl;

	int* pArray1 = new int[3];
	pArray1[0] = 100;
	pArray1[1] = 200;
	pArray1[2] = 300;
	show_addr_value(pArray1, 8);
	show_addr_value(pArray1[0], 8);
	show_addr_value(pArray1[1], 8);
	show_addr_value(pArray1[2], 8);
	delete[] pArray1;
	cout << "After delete [], the contents of pArray is: " << pArray1 << endl;
	pArray1 = nullptr;
	cout << "After reset to nullptr, the contents of pArray1 is: " << pArray1 << endl;
	cout << endl;

	int Array2[2];
	Array2[0] = 1111;
	Array2[1] = 2222;
	int* pArray2 = Array2;
	show_addr_value(pArray2, 8);
	show_addr_value(pArray2[0], 8);
	show_addr_value(pArray2[1], 8);
	cout << "No need to delete Array2, it is on the stack, not the heap" << endl;
	cout << endl;

	double* big_buffer = new double[ACCeID];
	show_addr_value(big_buffer, 8);
	delete[] big_buffer;
	cout << "After delete [], the contents of big_buffer is: " << big_buffer << endl;
	big_buffer = nullptr;
	cout << "After reset to nullptr, the contents of big_buffer is: " << big_buffer << endl;
	cout << endl;

	Number* emptyList = nullptr;
	Number zed;
	zed.name = "zero";
	zed.next = nullptr;
	cout << "static (uses: Number zed):\n";
	show_addr(zed, 8);
	show_addr_value(zed.name, 8);
	show_addr_value(zed.next, 8);
	cout << endl;

	// 3) For the linked list of Number names, use the names of the first two digits in your ACCeID;
	Number one;
	one.name = "one";

	Number nine;
	nine.name = "nine";

	one.next = &nine;
	nine.next = nullptr;
	Number* pNatural = &one;

	cout << "dynamic (uses: p_natural, Number(\"one\"), Number(\"two\"):\n";
	while (pNatural != nullptr) //testing the print out of my link list
	{
		cout << pNatural->name << endl;
		show_addr_value(pNatural, 8);
		show_addr_value(pNatural->name, 8);
		show_addr_value(pNatural->next, 8);
		pNatural = pNatural->next; // <follow link to next Number on p_natural>
	}

	/* Useful output comments, describes results, use as desired.
	   You can use show_addr_value and show_addr to show addresses and values;
	   You can use cout messages below to provide more detailed messages.
	   See sample of full solution output in the instructions.
	*/

	return 0;
} // end of main

/*
Output from Lab10 memory diagram on pointers:

Output from Lab10 memory diagram on pointers:

address of price    is: &0000003F453EF0C4  contents of price    is: 18.65
address of p_price  is: &0000003F453EF0E8  contents of p_price  is: 0000003F453EF0C4
The contents of *p_price is: 18.65

address of PI       is: &0000003F453EF108  contents of PI       is: 3.14159
address of PI_div_2 is: &0000003F453EF148  contents of PI_div_2 is: 1.5708
address of p_PI     is: &0000003F453EF128  contents of p_PI     is: 0000003F453EF108
The contents of *p_PI is:    3.14159

address of ACCeID   is: &0000003F453EF164  contents of ACCeID   is: 1949598
address of p_ACCeID is: &0000003F453EF188  contents of p_ACCeID is: 0000003F453EF164
The contents of *p_ACCeID is: 1949598

address of p_amount is: &0000003F453EF1A8  contents of p_amount is: 000001DB6324D0E0
The contents of *p_amount is: 2468
After delete, the contents of p_amount is: 000001DB6324D0E0
After reset to nullptr, the contents of p_amount is: 0000000000000000

address of pArray1  is: &0000003F453EF1C8  contents of pArray1  is: 000001DB63250D80
address of pArray1[0] is: &000001DB63250D80  contents of pArray1[0] is: 100
address of pArray1[1] is: &000001DB63250D84  contents of pArray1[1] is: 200
address of pArray1[2] is: &000001DB63250D88  contents of pArray1[2] is: 300
After delete [], the contents of pArray is: 000001DB63250D80
After reset to nullptr, the contents of pArray1 is: 0000000000000000

address of pArray2  is: &0000003F453EF208  contents of pArray2  is: 0000003F453EF1E8
address of pArray2[0] is: &0000003F453EF1E8  contents of pArray2[0] is: 1111
address of pArray2[1] is: &0000003F453EF1EC  contents of pArray2[1] is: 2222
No need to delete Array2, it is on the stack, not the heap

address of big_buffer is: &0000003F453EF228  contents of big_buffer is: 000001DB63476070
After delete [], the contents of big_buffer is: 000001DB63476070
After reset to nullptr, the contents of big_buffer is: 0000000000000000

static (uses: Number zed):
address of zed      is: &0000003F453EF248
address of zed.name is: &0000003F453EF248  contents of zed.name is: zero
address of zed.next is: &0000003F453EF270  contents of zed.next is: 0000000000000000

dynamic (uses: p_natural, Number("one"), Number("two"):
one
address of pNatural is: &0000003F453EF338  contents of pNatural is: 0000003F453EF298
address of pNatural->name is: &0000003F453EF298  contents of pNatural->name is: one
address of pNatural->next is: &0000003F453EF2C0  contents of pNatural->next is: 0000003F453EF2E8
nine
address of pNatural is: &0000003F453EF338  contents of pNatural is: 0000003F453EF2E8
address of pNatural->name is: &0000003F453EF2E8  contents of pNatural->name is: nine
address of pNatural->next is: &0000003F453EF310  contents of pNatural->next is: 0000000000000000

C:\Users\rohan\Desktop\CPP\DL2_L10_Teredesai\out\build\x64-Debug\DL2_L10_Teredesai\DL2_L10_Teredesai.exe (process 7456) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .

*/