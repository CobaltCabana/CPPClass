// DL2_L3_Teredesai.cpp : Defines the entry point for the application.
// Author: Rohan Teredesai;  
// Course: COSC 1337 Summer 2021 DL2;  
// Instructor: Thayer
// Lab: 03  
// Purpose: A program to check if students understand how to convert inches into feet and inches.

#include <iostream>

#include <stdlib.h>     
#include <time.h>       
#include <string>


using namespace std;


int generateQuestion() {
	int iSecret = rand() % 73;
	if (iSecret < 12) {
		iSecret += 12;
	}

	return iSecret;
}
string convertToFeetAndInches(int inches) {
	int remainder = inches % 12;
	int feet = inches / 12;

	return "" + to_string(feet) + "'" + to_string(remainder) + "''";
}
void generatePosAnswers(int question, int answer[]) {
	cout << "Which distance is the same as: " << question << "''" << endl;
	//cout << "True Answer: " << convertToFeetAndInches(question) << endl; //used for scenario debug purposes
	//PosAnswer1 is the correct question
	int PosAnswer1 = question;
	int PosAnswer2 = question - (rand() % 7);
	//Making sure it is not equal to PosAnswer 1
	while (PosAnswer2 == PosAnswer1) {
		PosAnswer2 = question - (rand() % 7);
	}
	int PosAnswer3 = question + (rand() % 7);
	//Making sure it is not equal to PosAnswer1 or PosAnswer2
	while (PosAnswer3 == PosAnswer1 || PosAnswer3 == PosAnswer2) {
		PosAnswer3 = question - (rand() % 7);
	}

	int order = rand() % 3;
	if (order == 0) {
		cout << "a)" << convertToFeetAndInches(PosAnswer1) << endl;
		cout << "b)" << convertToFeetAndInches(PosAnswer2) << endl;
		cout << "c)" << convertToFeetAndInches(PosAnswer3) << endl;

		answer[0] = PosAnswer1;
		answer[1] = PosAnswer2;
		answer[2] = PosAnswer3;
		return;
	}
	else if (order == 1) {
		cout << "a)" << convertToFeetAndInches(PosAnswer3) << endl;
		cout << "b)" << convertToFeetAndInches(PosAnswer1) << endl;
		cout << "c)" << convertToFeetAndInches(PosAnswer2) << endl;

		answer[0] = PosAnswer3;
		answer[1] = PosAnswer1;
		answer[2] = PosAnswer2;
		return;
	}
	else if (order == 2) {
		cout << "a)" << convertToFeetAndInches(PosAnswer3) << endl;
		cout << "b)" << convertToFeetAndInches(PosAnswer2) << endl;
		cout << "c)" << convertToFeetAndInches(PosAnswer1) << endl;

		answer[0] = PosAnswer3;
		answer[1] = PosAnswer2;
		answer[2] = PosAnswer1;
		return;
	}
}

double percentCorrect(int score, int questionsAnswered) {
	double percent = ((double(score) / double(questionsAnswered)) * 100);
	return percent;
}

int main()
{
	int scoreKeeper = 0;
	int numberOfQuestions = 0;
	int userQuestionInput = 0;
	bool invalidinput = false;
	/* initialize random seed: */
	srand(time(NULL));

	cout << "Welcome to the distance conversion test!\nHow many questions would you like ? (0 to quit)? ";
	cin >> userQuestionInput;
	if (userQuestionInput == 0) {
		cout << "Goodbye coward.";
		return 0;
	}

	for (int i = 0; i < userQuestionInput; i++) {

		int answerSelected = -1;
		int correctAnswer = generateQuestion();
		numberOfQuestions++;
		int answers[3] = { 0,0,0 };
		generatePosAnswers(correctAnswer, answers);


		// Stay within the same question with invalid input
		do {
			cout << "Question " << numberOfQuestions << " of " << userQuestionInput
				<< ": (enter one letter): a), b), and, c). Or enter q) to quit: " << endl;
			char option = ' ';
			cin >> option;
			if (option == 'a') {
				answerSelected = 0;
				invalidinput = false;
			}
			else if (option == 'b') {
				answerSelected = 1;
				invalidinput = false;
			}
			else if (option == 'c') {
				answerSelected = 2;
				invalidinput = false;
			}
			else if (option == 'q') {
				numberOfQuestions--;
				// ends the program if 0 questions are completed
				// inorder to avoid dividing by 0
				if (numberOfQuestions == 0) {
					cout << "No questions attempted, goodbye.";
					return 0;
				}
				cout << "Goodbye, your score is: " << scoreKeeper << " out of " << numberOfQuestions << ". Which is "
					<< percentCorrect(scoreKeeper, numberOfQuestions) << "% " << endl << endl;
				return 0; // ends the program

			}
			else {
				cout << "Invalid input, try again! \n";
				invalidinput = true;
				continue;
			}

		} while (invalidinput);

		cout << "You Picked " << convertToFeetAndInches(answers[answerSelected]) << endl;
		if (answers[answerSelected] == correctAnswer) {
			scoreKeeper++;
			cout << "Correct! Your score now is = " << scoreKeeper << " out of " << numberOfQuestions << ". Which is "
				<< percentCorrect(scoreKeeper, numberOfQuestions) << "% " << endl << endl;
		}
		else {
			cout << "Your answer is incorrect! The correct answer was: " << convertToFeetAndInches(correctAnswer)
				<< " Your score now is = " << scoreKeeper << " out of " << numberOfQuestions << ". Which is "
				<< percentCorrect(scoreKeeper, numberOfQuestions) << "% " << endl << endl;
		}


	}




}
/* TEST OUTPUT:
Welcome to the distance conversion test!
How many questions would you like ? (0 to quit)? 6
Which distance is the same as: 44''
a)3'8''
b)3'7''
c)3'9''
Question 1 of 6: (enter one letter): a), b), and, c). Or enter q) to quit:
a
You Picked 3'8''
Correct! Your score now is = 1 out of 1. Which is 100%

Which distance is the same as: 20''
a)1'10''
b)1'8''
c)1'7''
Question 2 of 6: (enter one letter): a), b), and, c). Or enter q) to quit:
b
You Picked 1'8''
Correct! Your score now is = 2 out of 2. Which is 100%

Which distance is the same as: 24''
a)2'3''
b)2'0''
c)1'11''
Question 3 of 6: (enter one letter): a), b), and, c). Or enter q) to quit:
y
Invalid input, try again!
Question 3 of 6: (enter one letter): a), b), and, c). Or enter q) to quit:
c
You Picked 1'11''
Your answer is incorrect! The correct answer was: 2'0'' Your score now is = 2 out of 3. Which is 66.6667%

Which distance is the same as: 48''
a)4'0''
b)3'11''
c)4'3''
Question 4 of 6: (enter one letter): a), b), and, c). Or enter q) to quit:
a
You Picked 4'0''
Correct! Your score now is = 3 out of 4. Which is 75%

Which distance is the same as: 33''
a)2'9''
b)2'5''
c)3'3''
Question 5 of 6: (enter one letter): a), b), and, c). Or enter q) to quit:
q
Goodbye, your score is: 3 out of 4. Which is 75%


C:\Users\rohan\Desktop\CPP\DL2_L3_Teredesai\out\build\x64-Debug\DL2_L3_Teredesai\DL2_L3_Teredesai.exe (process 23192) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .

*/