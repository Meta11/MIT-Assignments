#include <iostream>

#include "TicTacToe.h"

TicTacToe::TicTacToe()
{
	clearScreen();
}

void TicTacToe::playGame() 
{	
	char currentPlayer = 'X';

	int xCoord, yCoord;
	int turn = 1;

	bool isDone1 = false;
	bool isDone2 = false;

	TicTacToe game;

	game.printBoard();

	while (!isDone2) 
	{
		cout << "Turno: " << turn << endl;
		isDone1 = game.getCoordinates(xCoord, yCoord, currentPlayer);
		game.printBoard();
		if (!isDone1) {
			isDone2 = game.checkForWin(turn);
			turn++;
		}	
	}
}

void TicTacToe::clearScreen()
{
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++) {
			board[i][j] = ' ';
		}
	}
}

void TicTacToe::printBoard()
{
	cout << "\n |1 2 3|" << endl;
	for (int i = 0; i < 3; i++) {
		cout << " -------" << endl;
		cout << i + 1;
		for (int j = 0; j < 3; j++) {
			cout << "|" << board[i][j];
		}
		cout << "|" << endl;
	}
}

bool TicTacToe::getCoordinates(int &x, int &y, char &currentPlayer)
{
	cout << "\nQue las " << currentPlayer << " introduzcan la coordenada X: ";
	cin >> x;
	if (x < 1 || x > 3){
		cout << "Coordenada no valida. Inserta la coordenada de nuevo" << endl;
		return true;
	}

	cout << "\nQue las " << currentPlayer << " introduzcan la coordenada Y: ";
	cin >> y;
	if ((y < 1 || y > 3) || board[y-1][x-1] != ' ') {
		cout << "Coordenada no valida. Inserta la coordenada de nuevo" << endl;
		return true;
	}
	else
	{
		if(currentPlayer == 'X')
		{
			board[y-1][x-1] = 'X';
			currentPlayer = 'O';
		}
		else {
			board[y-1][x-1] = 'O';
			currentPlayer = 'X';

		}
		return false;
	}
}

bool TicTacToe::checkForWin(int turn) 
{
	for (int i = 0; i < 3; i++) {
		if ((board[0][i] == board[1][i]) && (board[1][i] == board[2][i]) && board[0][i] != ' ')
		{
			cout << "\nLas " << board[0][i] << " han ganado!\n" << endl;
			return true;
		}
	}

	for (int i = 0; i < 3; i++) {
		if ((board[i][0] == board[i][1]) && (board[i][1] == board[i][2]) && board[i][0] != ' ')
		{
			cout << "\nLas " << board[0][i] << " han ganado!\n" << endl;
			return true;
		}
	}

	if ((board[0][0] == board[1][1]) && (board[1][1] == board[2][2]) && board[0][0] != ' ') 
	{
		cout << "\nLas " << board[0][0] << " han ganado!\n" << endl;
		return true;
	}

	if ((board[0][2] == board[1][1]) && (board[1][1] == board[2][0]) && board[1][1] != ' ')
	{
		cout << "\nLas " << board[1][1] << " han ganado!\n" << endl;
		return true;
	}

	if (turn == 9) {
		cout << "Ha habido un empate" << endl;
		return true;
	}

	return false;
}


