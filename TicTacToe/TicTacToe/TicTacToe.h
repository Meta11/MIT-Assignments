#pragma once

using namespace std;

class TicTacToe
{
public:
	TicTacToe();

	void playGame();
	void clearScreen();
	void printBoard();

	

private:
	bool getCoordinates(int &x, int &y, char &currentPlayer);
	bool checkForWin(int turn);
	char board[3][3];
};

