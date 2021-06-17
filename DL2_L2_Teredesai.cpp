// DL2_L2_Teredesai.cpp : Defines the entry point for the application.
//
// Author: Rohan Teredesai;  Course: COSC 1337 Summer 2021 DL2;  Instructor: Thayer
// Lab: 02  Purpose: draw ‘X’ shape of varying sizes and of specified thickness

#include <iostream>
#include <cmath>

using namespace std;

//controls when to spit out the Star
bool isStar(int i, int j, int numOfStars, int length) {
	int diagonal1 = j - i;// this spits out the top left corner to bottom right
	int diagonal2 = (i + j) - length + 1; // this spits out top right to bottom left
	//cerr << "-->d2 = " << diagonal2 << endl;
	//return diagonal1 == 0 || diagonal2 == 1; // debug thin (X) scenario
	return (diagonal1 >= 0 && diagonal1 < numOfStars) || (diagonal2 >= 0 && diagonal2 < numOfStars);

}
int main()
{
	while (true) {
		int length = 7; // default length of 7
		cout << "How many rows tall to draw an 'X'? (0 to quit):";
		cin >> length;
		//Add a check if lenght is <= 0, don't print (X), print a warning;
		if (length <= 0) {
			cout << "Goodbye";
			break;
		}
		// For every increase in size by 5, increase the thickness by 1 more '*'.
		//Intentionally using int division, so a non-multiple of 5, such as 17, then
		// 17/5 will print '***'.
		int numOfStars = ceil((float)length / (float)5);
		for (int i = 0; i < length; i++)
		{
			// length+numstars-1 because we spit out 1 extra star every next multiple of 5
			for (int j = 0; j < length + (numOfStars - 1); j++) {
				if (isStar(i, j, numOfStars, length)) {
					cout << "*";
				}
				else {
					//cout << "."; // for ease of counting during debugging
					cout << " ";

				}
			}
			cout << endl;
		}
	}
	cout << endl << "-------------------";
}

/*
How many rows tall to draw an 'X'? (0 to quit):1
*
How many rows tall to draw an 'X'? (0 to quit):2
**
**
How many rows tall to draw an 'X'? (0 to quit):3
* *
 *
* *
How many rows tall to draw an 'X'? (0 to quit):4
*  *
 **
 **
*  *
How many rows tall to draw an 'X'? (0 to quit):5
*   *
 * *
  *
 * *
*   *
How many rows tall to draw an 'X'? (0 to quit):6
**   **
 ** **
  ***
  ***
 ** **
**   **
How many rows tall to draw an 'X'? (0 to quit):7
**    **
 **  **
  ****
   **
  ****
 **  **
**    **
How many rows tall to draw an 'X'? (0 to quit):12
***        ***
 ***      ***
  ***    ***
   ***  ***
	******
	 ****
	 ****
	******
   ***  ***
  ***    ***
 ***      ***
***        ***
How many rows tall to draw an 'X'? (0 to quit):17
****            ****
 ****          ****
  ****        ****
   ****      ****
	****    ****
	 ****  ****
	  ********
	   ******
		****
	   ******
	  ********
	 ****  ****
	****    ****
   ****      ****
  ****        ****
 ****          ****
****            ****
How many rows tall to draw an 'X'? (0 to quit):0
Goodbye
-------------------
C:\Users\rohan\Desktop\CPP\DL2_L2_Teredesai\out\build\x64-Debug\DL2_L2_Teredesai\DL2_L2_Teredesai.exe (process 20344) ex
ited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the conso
le when debugging stops.
Press any key to close this window . . .
*/