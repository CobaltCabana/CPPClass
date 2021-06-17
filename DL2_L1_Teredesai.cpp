// DL2_L1_Teredesai.cpp : Defines the entry point for the application.
//
// Author: Rohan Teredesai;  Course: COSC 1337 Summer 2021 DL2;  Instructor: Thayer
// Lab: 01  Purpose:  solve restaurant related questions: advice, BMI (body mass index), calorie-counter, dollars-due (payment due with tax and tip)
// https://acconline.austincc.edu/webapps/blackboard/content/listContent.jsp?course_id=_851776_1&content_id=_18095372_1
/*
* Output from my program:
Options (enter one letter): a)dvice b)mi c)alories d)ue q)uit: a
User entered a
Lowercase value of input: a
I recommend the fish! For a cheap, healthy, low calorie meal
Options (enter one letter): a)dvice b)mi c)alories d)ue q)uit: b
User entered b
Lowercase value of input: b
Enter you weight in pounds: 120
Your weight is:120
Enter you height in inches: 69
Your height is:69
Your BMI is: 17.72
Options (enter one letter): a)dvice b)mi c)alories d)ue q)uit: c
User entered c
Lowercase value of input: c
Please input your list of calories, type 0 to end.
Add another calorie:
350
Running total = 350.00
Add another calorie:
20
Running total = 370.00
Add another calorie:
30
Running total = 400.00
Add another calorie:
0
Running total = 400.00
Total calories entered = 400.00
Options (enter one letter): a)dvice b)mi c)alories d)ue q)uit: d
User entered d
Lowercase value of input: d
Enter the food cost in dollars and cents: 50.5
Your food cost is:50.50
Your food cost with tax of 8.25% is:54.67
Enter the tip percentage: 13
Your Tip is:7.11
Your total dollars due is: 61.77
Options (enter one letter): a)dvice b)mi c)alories d)ue q)uit: L
User entered L
Lowercase value of input: l
Invalid Input
Options (enter one letter): a)dvice b)mi c)alories d)ue q)uit: q
User entered q
*/
#include <iostream>
#include <string>
#include <stdlib.h>
#include <cmath>
#include <iomanip>      // std::setprecision

using namespace std;

void advice() {
	cout << "I recommend the fish! For a cheap, healthy, low calorie meal" << endl;
}

//BMI = (weight in pounds / (height in inches x height in inches) ) x 703
//a) Ask for and get the user's data. Use data type int for both.
//b) Calculate the BMI.For the result, use data type double.
//c) Display the BMI.Hint: you may have to cast int to double.
//


double calculateBMI() {
	int weight = 0;
	while (weight == 0) {
		cout << "Enter you weight in pounds: ";
		string userInput = "";
		cin >> userInput;
		weight = atoi(userInput.c_str());
	}
	double d_weight = (double)weight;
	cout << "Your weight is:" << d_weight << endl;

	int height = 0;
	while (height == 0) {
		cout << "Enter you height in inches: ";
		string userInput = "";
		cin >> userInput;
		height = atoi(userInput.c_str());
	}
	double d_height = (double)height;
	cout << "Your height is:" << d_height << endl;

	double BMI = (d_weight / (d_height * d_height)) * (double)703;

	return BMI;
}

//calorie counter - write code that adds up a list of numbers and displays the sum:
//a) Ask for list of numbers, ending in 0 for the sentinel.Use data type float.
//          Assuming we are asking for seperate inputs, until user types 0.
//b) Add up all numbers entered, display the sum.

float calorieCounter() {
	float totalCalories = 0;
	float newInput = 0.0;
	cout << "Please input your list of calories, type 0 to end." << endl;
	string userInput = "";

	while (userInput != "0") {
		cout << "Add another calorie: " << endl;
		cin >> userInput;
		newInput = atof(userInput.c_str());
		totalCalories = totalCalories + newInput;
		cout << "Running total = " << totalCalories << endl;
	}
	return totalCalories;
}

//d) dollars due - write code that calculates dollars due given cost of food and tip percentage:
//a) Ask for and get the cost of food.Use data type double.
//b) Ask for and get the tip percentage.Use data type double.
//c) Internally, declare the tax rate : const double TAX_RATE{ 0.0825 }; Do not ask for tax rate.
//d) Compute the total check, using the: food cost, TAX_RATEand tip percentage.
//		(What should the tip be ? Based on food cost ? Food cost and tax ? You decide; provide comments.)
//e) Print out the total dollars due.
double computeDollarsDue() {

	const double TAX_RATE = 0.0825;

	double foodCost = 0.0;
	while (foodCost == 0.0) {
		cout << "Enter the food cost in dollars and cents: ";
		string userInput = "";
		cin >> userInput;
		foodCost = atof(userInput.c_str());
	}

	double afterTaxFoodCost = (foodCost + (foodCost * TAX_RATE));
	cout << "Your food cost is:" << foodCost << endl;
	//Ensures that set fixed always prints decimals and set precision sets how many places
	cout << "Your food cost with tax of "
		 << std::fixed << std::setprecision(2) << (TAX_RATE * 100) << "% is:" << afterTaxFoodCost << endl;

	double tip = 0.0;
	while (tip == 0.0) {
		cout << "Enter the tip percentage: ";
		string userInput = "";
		cin >> userInput;
		tip = atof(userInput.c_str());
	}

	// I am calculating tip on after tax food cost based on my real life habits
	double tipAmount = (tip * afterTaxFoodCost) / 100.00;
	cout << "Your Tip is:" << tipAmount << endl;
	double finalBill = afterTaxFoodCost + tipAmount;

	return finalBill;
}

int main()
{

	while (true) {
		cout << "Options (enter one letter): a)dvice b)mi c)alories d)ue q)uit: ";
		char option = ' ';
		cin >> option;
		cout << "User entered " << option << endl;
		option = tolower(option);
		cout << "Lowercase value of input: " << option << endl;

		if (option == 'a') {
			// provide advice.
			advice();
		}
		else if (option == 'b') {
			// compute and display the BMI
			cout << "Your BMI is: " << std::fixed << std::setprecision(2)
				<< calculateBMI() << endl;

		}
		else if (option == 'c') {
			// compute and display sum of calories
			cout << "Total calories entered = " << calorieCounter() << endl;

		}
		else if (option == 'd') {
			// compute and dollars due
			cout << "Your total dollars due is: "
				<< std::fixed << std::setprecision(2)
				<< computeDollarsDue() << endl;
		}
		else if (option == 'q') {
			cout << "I'm quitting, goodbye\n";
			break; // drops out of while loop
		}
		else {
			// invalid option entered, display an error message
			cout << "Invalid Input\n";
		}
	}
}
