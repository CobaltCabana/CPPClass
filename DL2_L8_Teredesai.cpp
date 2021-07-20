// Author: Rohan Teredesai;  Course: COSC 1337 Summer 2021 DL2;  Instructor: Thayer
// Lab: 08  Purpose:  Write a modular program that allows two players to play a game of tic-tac-toe

#include <iostream>
#include <string>

using namespace std;

class GameBoard
{
public:
	GameBoard::GameBoard()
	{
		initBoard();
	}
	void displayBoard() {
		for (int i = 0; i < BOARD_SIZE; i++)
		{
			for (int j = 0; j < BOARD_SIZE; j++)
			{
				cout << board[i][j];
				cout << " | ";
			}
			cout << endl << "------------";
			cout << endl;
		}
	}
	int gamesPlayed() {
		return player1Win + player2Win + draws;
	}
	void getInput() {
		if (player1Turn) {
			cout << "Player 1 turn: Please enter a valid cell number (1-9) to put an 'X' " << endl;
		}
		else {
			cout << "Player 2 turn: Please enter a valid cell number (1-9) to put an 'O' " << endl;
		}
		int cellNum = -1;
		int row = 0;
		int col = 0;
		do
		{
			cin >> cellNum;
			cout << "You chose cell" << cellNum << endl;
			convertCellNumberToRowCol(cellNum, row, col);
			if (!isValidInput(row, col)) {
				cout << "That's an invalid cell! Try Again." << endl;
			}
			else
			{
				break;
			}
			//For Debug
		} while (true);
		//Update the board when you get valid input
		board[row][col] = player1Turn ? PLAYER1_MARK : PLAYER2_MARK;
	}
	bool isValidInput(int row, int col) {
		return board[row][col] != PLAYER1_MARK && board[row][col] != PLAYER2_MARK;
	}
	bool isGameOver() {
		char playerMark = player1Turn ? PLAYER1_MARK : PLAYER2_MARK;
		bool gameOver = false;
		//checking for row victory
		for (int row = 0; row < BOARD_SIZE; row++)
		{
			int count = 0;
			for (int col = 0; col < BOARD_SIZE; col++)
			{
				if (board[row][col] == playerMark) {
					count++;
				}
			}
			if (count == BOARD_SIZE)
			{
				// cout << "Row number" << row << "has three" << playerMark << endl;
				player1Turn ? player1Win++ : player2Win++;
				return true;
			}
		}
		//checking for column victory
		for (int col = 0; col < BOARD_SIZE; col++)
		{
			int count = 0;
			for (int row = 0; row < BOARD_SIZE; row++)
			{
				if (board[row][col] == playerMark) {
					count++;
				}
			}
			if (count == BOARD_SIZE)
			{
				// cout << "Column number" << col << "has three" << playerMark << endl;
				player1Turn ? player1Win++ : player2Win++;
				return true;
			}
		}
		//checking for right (/) diagnol victory
		int dr_count = 0;
		for (int row = 0; row < BOARD_SIZE; row++)
		{
			for (int col = 0; col < BOARD_SIZE; col++)
			{
				if ((row + col) == (BOARD_SIZE - 1) && board[row][col] == playerMark) {
					dr_count++;
				}
			}
			if (dr_count == BOARD_SIZE)
			{
				// cout << "Row number" << row << "has three" << playerMark << endl;
				player1Turn ? player1Win++ : player2Win++;
				return true;
			}
		}
		//checking for left (\) diagnol victory
		int dl_count = 0;
		for (int row = 0; row < BOARD_SIZE; row++)
		{
			for (int col = 0; col < BOARD_SIZE; col++)
			{
				if (row == col && board[row][col] == playerMark) {
					dl_count++;
				}
			}
			if (dl_count == BOARD_SIZE)
			{
				// cout << "Row number" << row << "has three" << playerMark << endl;
				player1Turn ? player1Win++ : player2Win++;
				return true;
			}
		}
		int emptyCount = 0;
		for (int row = 0; row < BOARD_SIZE; row++)
		{
			for (int col = 0; col < BOARD_SIZE; col++)
			{
				if (isValidInput(row, col)) {
					emptyCount++;
				}
			}
		}
		if (emptyCount == 0)
		{
			draws++;
			return true;
		}
		return gameOver;
	}
	void displayResult() {
		cout << "Game Over! Starting a fresh game" << endl;
		cout << "Player 1 Wins = " << player1Win << "(" << ((player1Win * 100) / (gamesPlayed())) << "%)" << endl;
		cout << "Player 2 Wins = " << player2Win << "(" << ((player2Win * 100) / (gamesPlayed())) << "%)" << endl;
		cout << "Cat Scratches = " << draws << "(" << ((draws * 100) / (gamesPlayed())) << "%)" << endl;
	}
	void togglePlayer() {
		//toggles player turn
		player1Turn = !player1Turn;
	}
	void initBoard() {
		int counter = 1;
		for (int row = 0; row < BOARD_SIZE; row++)
		{
			for (int col = 0; col < BOARD_SIZE; col++)
			{
				//To display the character '1' through '9'
				board[row][col] = '0' + counter;
				counter++;
			}
		}
	}

private:
	const static int BOARD_SIZE = 3;
	const static char PLAYER1_MARK = 'X';
	const static char PLAYER2_MARK = 'O';

	char board[BOARD_SIZE][BOARD_SIZE];
	bool player1Turn = true;
	int player1Win = 0;
	int player2Win = 0;
	int draws = 0;

	void convertCellNumberToRowCol(int cellNum, int& row, int& col) {
		cellNum--;
		row = cellNum / BOARD_SIZE;
		col = cellNum % BOARD_SIZE;
		cout << row << "," << col << endl;
	}

};
int main()
{
	char userInput = ' ';
	GameBoard myBoard;
	while (true)
	{
		myBoard.displayBoard();
		myBoard.getInput();
		if (myBoard.isGameOver()) {
			myBoard.displayBoard();
			myBoard.displayResult();
			cout << "New Game? (Y)es or (N)o" << endl;
			cin >> userInput;

			if (tolower(userInput) == 'y') {
				cout << "starting a fresh game" << endl;
				myBoard.initBoard();
			}
			else {
				cout << "goodbye!";
				break;
			}
		}
		else {
			myBoard.togglePlayer();
		}
	}
}
/*
1 | 2 | 3 |
------------
4 | 5 | 6 |
------------
7 | 8 | 9 |
------------
Player 1 turn: Please enter a valid cell number (1-9) to put an 'X'
1
You chose cell1
0,0
X | 2 | 3 |
------------
4 | 5 | 6 |
------------
7 | 8 | 9 |
------------
Player 2 turn: Please enter a valid cell number (1-9) to put an 'O'
2
You chose cell2
0,1
X | O | 3 |
------------
4 | 5 | 6 |
------------
7 | 8 | 9 |
------------
Player 1 turn: Please enter a valid cell number (1-9) to put an 'X'
3
You chose cell3
0,2
X | O | X |
------------
4 | 5 | 6 |
------------
7 | 8 | 9 |
------------
Player 2 turn: Please enter a valid cell number (1-9) to put an 'O'
4
You chose cell4
1,0
X | O | X |
------------
O | 5 | 6 |
------------
7 | 8 | 9 |
------------
Player 1 turn: Please enter a valid cell number (1-9) to put an 'X'
5
You chose cell5
1,1
X | O | X |
------------
O | X | 6 |
------------
7 | 8 | 9 |
------------
Player 2 turn: Please enter a valid cell number (1-9) to put an 'O'
6
You chose cell6
1,2
X | O | X |
------------
O | X | O |
------------
7 | 8 | 9 |
------------
Player 1 turn: Please enter a valid cell number (1-9) to put an 'X'
7
You chose cell7
2,0
X | O | X |
------------
O | X | O |
------------
X | 8 | 9 |
------------
Game Over! Starting a fresh game
Player 1 Wins = 1(100%)
 Player 2 Wins = 0(0%)
 Cat Scratches = 0(0%)
New Game? (Y)es or (N)o
y
starting a fresh game
1 | 2 | 3 |
------------
4 | 5 | 6 |
------------
7 | 8 | 9 |
------------
Player 1 turn: Please enter a valid cell number (1-9) to put an 'X'
1
You chose cell1
0,0
X | 2 | 3 |
------------
4 | 5 | 6 |
------------
7 | 8 | 9 |
------------
Player 2 turn: Please enter a valid cell number (1-9) to put an 'O'
2
You chose cell2
0,1
X | O | 3 |
------------
4 | 5 | 6 |
------------
7 | 8 | 9 |
------------
Player 1 turn: Please enter a valid cell number (1-9) to put an 'X'
3
You chose cell3
0,2
X | O | X |
------------
4 | 5 | 6 |
------------
7 | 8 | 9 |
------------
Player 2 turn: Please enter a valid cell number (1-9) to put an 'O'
5
You chose cell5
1,1
X | O | X |
------------
4 | O | 6 |
------------
7 | 8 | 9 |
------------
Player 1 turn: Please enter a valid cell number (1-9) to put an 'X'
8
You chose cell8
2,1
X | O | X |
------------
4 | O | 6 |
------------
7 | X | 9 |
------------
Player 2 turn: Please enter a valid cell number (1-9) to put an 'O'
4
You chose cell4
1,0
X | O | X |
------------
O | O | 6 |
------------
7 | X | 9 |
------------
Player 1 turn: Please enter a valid cell number (1-9) to put an 'X'
7
You chose cell7
2,0
X | O | X |
------------
O | O | 6 |
------------
X | X | 9 |
------------
Player 2 turn: Please enter a valid cell number (1-9) to put an 'O'
6
You chose cell6
1,2
X | O | X |
------------
O | O | O |
------------
X | X | 9 |
------------
Game Over! Starting a fresh game
Player 1 Wins = 1(50%)
 Player 2 Wins = 1(50%)
 Cat Scratches = 0(0%)
New Game? (Y)es or (N)o
y
starting a fresh game
1 | 2 | 3 |
------------
4 | 5 | 6 |
------------
7 | 8 | 9 |
------------
Player 2 turn: Please enter a valid cell number (1-9) to put an 'O'
1
You chose cell1
0,0
O | 2 | 3 |
------------
4 | 5 | 6 |
------------
7 | 8 | 9 |
------------
Player 1 turn: Please enter a valid cell number (1-9) to put an 'X'
2
You chose cell2
0,1
O | X | 3 |
------------
4 | 5 | 6 |
------------
7 | 8 | 9 |
------------
Player 2 turn: Please enter a valid cell number (1-9) to put an 'O'
3
You chose cell3
0,2
O | X | O |
------------
4 | 5 | 6 |
------------
7 | 8 | 9 |
------------
Player 1 turn: Please enter a valid cell number (1-9) to put an 'X'
4
You chose cell4
1,0
O | X | O |
------------
X | 5 | 6 |
------------
7 | 8 | 9 |
------------
Player 2 turn: Please enter a valid cell number (1-9) to put an 'O'
5
You chose cell5
1,1
O | X | O |
------------
X | O | 6 |
------------
7 | 8 | 9 |
------------
Player 1 turn: Please enter a valid cell number (1-9) to put an 'X'
6
You chose cell6
1,2
O | X | O |
------------
X | O | X |
------------
7 | 8 | 9 |
------------
Player 2 turn: Please enter a valid cell number (1-9) to put an 'O'
7
You chose cell7
2,0
O | X | O |
------------
X | O | X |
------------
O | 8 | 9 |
------------
Game Over! Starting a fresh game
Player 1 Wins = 1(33%)
 Player 2 Wins = 2(66%)
 Cat Scratches = 0(0%)
New Game? (Y)es or (N)o
y
starting a fresh game
1 | 2 | 3 |
------------
4 | 5 | 6 |
------------
7 | 8 | 9 |
------------
Player 2 turn: Please enter a valid cell number (1-9) to put an 'O'

1
You chose cell1
0,0
O | 2 | 3 |
------------
4 | 5 | 6 |
------------
7 | 8 | 9 |
------------
Player 1 turn: Please enter a valid cell number (1-9) to put an 'X'
2
You chose cell2
0,1
O | X | 3 |
------------
4 | 5 | 6 |
------------
7 | 8 | 9 |
------------
Player 2 turn: Please enter a valid cell number (1-9) to put an 'O'
3
You chose cell3
0,2
O | X | O |
------------
4 | 5 | 6 |
------------
7 | 8 | 9 |
------------
Player 1 turn: Please enter a valid cell number (1-9) to put an 'X'
4
You chose cell4
1,0
O | X | O |
------------
X | 5 | 6 |
------------
7 | 8 | 9 |
------------
Player 2 turn: Please enter a valid cell number (1-9) to put an 'O'
9
You chose cell9
2,2
O | X | O |
------------
X | 5 | 6 |
------------
7 | 8 | O |
------------
Player 1 turn: Please enter a valid cell number (1-9) to put an 'X'
8
You chose cell8
2,1
O | X | O |
------------
X | 5 | 6 |
------------
7 | X | O |
------------
Player 2 turn: Please enter a valid cell number (1-9) to put an 'O'
7
You chose cell7
2,0
O | X | O |
------------
X | 5 | 6 |
------------
O | X | O |
------------
Player 1 turn: Please enter a valid cell number (1-9) to put an 'X'
5
You chose cell5
1,1
O | X | O |
------------
X | X | 6 |
------------
O | X | O |
------------
Game Over! Starting a fresh game
Player 1 Wins = 2(50%)
 Player 2 Wins = 2(50%)
 Cat Scratches = 0(0%)
New Game? (Y)es or (N)o
y
starting a fresh game
1 | 2 | 3 |
------------
4 | 5 | 6 |
------------
7 | 8 | 9 |
------------
Player 1 turn: Please enter a valid cell number (1-9) to put an 'X'
1
You chose cell1
0,0
X | 2 | 3 |
------------
4 | 5 | 6 |
------------
7 | 8 | 9 |
------------
Player 2 turn: Please enter a valid cell number (1-9) to put an 'O'
9
You chose cell9
2,2
X | 2 | 3 |
------------
4 | 5 | 6 |
------------
7 | 8 | O |
------------
Player 1 turn: Please enter a valid cell number (1-9) to put an 'X'
3
You chose cell3
0,2
X | 2 | X |
------------
4 | 5 | 6 |
------------
7 | 8 | O |
------------
Player 2 turn: Please enter a valid cell number (1-9) to put an 'O'
2
You chose cell2
0,1
X | O | X |
------------
4 | 5 | 6 |
------------
7 | 8 | O |
------------
Player 1 turn: Please enter a valid cell number (1-9) to put an 'X'
7
You chose cell7
2,0
X | O | X |
------------
4 | 5 | 6 |
------------
X | 8 | O |
------------
Player 2 turn: Please enter a valid cell number (1-9) to put an 'O'
4
You chose cell4
1,0
X | O | X |
------------
O | 5 | 6 |
------------
X | 8 | O |
------------
Player 1 turn: Please enter a valid cell number (1-9) to put an 'X'
6
You chose cell6
1,2
X | O | X |
------------
O | 5 | X |
------------
X | 8 | O |
------------
Player 2 turn: Please enter a valid cell number (1-9) to put an 'O'
8
You chose cell8
2,1
X | O | X |
------------
O | 5 | X |
------------
X | O | O |
------------
Player 1 turn: Please enter a valid cell number (1-9) to put an 'X'
4
You chose cell4
1,0
That's an invalid cell! Try Again.
5
You chose cell5
1,1
X | O | X |
------------
O | X | X |
------------
X | O | O |
------------
Game Over! Starting a fresh game
Player 1 Wins = 3(60%)
 Player 2 Wins = 2(40%)
 Cat Scratches = 0(0%)
New Game? (Y)es or (N)o
y
starting a fresh game
1 | 2 | 3 |
------------
4 | 5 | 6 |
------------
7 | 8 | 9 |
------------
Player 1 turn: Please enter a valid cell number (1-9) to put an 'X'
5
You chose cell5
1,1
1 | 2 | 3 |
------------
4 | X | 6 |
------------
7 | 8 | 9 |
------------
Player 2 turn: Please enter a valid cell number (1-9) to put an 'O'
1
You chose cell1
0,0
O | 2 | 3 |
------------
4 | X | 6 |
------------
7 | 8 | 9 |
------------
Player 1 turn: Please enter a valid cell number (1-9) to put an 'X'
4
You chose cell4
1,0
O | 2 | 3 |
------------
X | X | 6 |
------------
7 | 8 | 9 |
------------
Player 2 turn: Please enter a valid cell number (1-9) to put an 'O'
6
You chose cell6
1,2
O | 2 | 3 |
------------
X | X | O |
------------
7 | 8 | 9 |
------------
Player 1 turn: Please enter a valid cell number (1-9) to put an 'X'
7
You chose cell7
2,0
O | 2 | 3 |
------------
X | X | O |
------------
X | 8 | 9 |
------------
Player 2 turn: Please enter a valid cell number (1-9) to put an 'O'
3
You chose cell3
0,2
O | 2 | O |
------------
X | X | O |
------------
X | 8 | 9 |
------------
Player 1 turn: Please enter a valid cell number (1-9) to put an 'X'
2
You chose cell2
0,1
O | X | O |
------------
X | X | O |
------------
X | 8 | 9 |
------------
Player 2 turn: Please enter a valid cell number (1-9) to put an 'O'
8
You chose cell8
2,1
O | X | O |
------------
X | X | O |
------------
X | O | 9 |
------------
Player 1 turn: Please enter a valid cell number (1-9) to put an 'X'
9
You chose cell9
2,2
O | X | O |
------------
X | X | O |
------------
X | O | X |
------------
Game Over! Starting a fresh game
Player 1 Wins = 3(50%)
 Player 2 Wins = 2(33%)
 Cat Scratches = 1(16%)
New Game? (Y)es or (N)o
n
goodbye!
C:\Users\rohan\Desktop\CPP\DL2_L8_Teredesai\out\build\x64-Debug\DL2_L8_Teredesai\DL2_L8_Teredesai.exe (process 25168) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .

*/