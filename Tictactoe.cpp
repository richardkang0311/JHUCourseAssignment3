/*
 * Tictactoe.cpp
 *
 *  Created on: Feb 17, 2018
 *      Author: Richard Kang
 *      Implementation file for class Tictactoe
 */

#include <cstdlib>	//allows program to use rand
#include <ctime>		//allows program to use time
#include <iostream> 	//allows program to perform input and output
#include "Tictactoe.h"	//include definition of class Tictactoe

Tictactoe::Tictactoe (){
	for (int x = 0; x < MAX_ROW_SIZE; ++x){
		for (int y = 0; y < MAX_COL_SIZE; ++y){
			board[x][y] = '_';
		}
	}
}

//function to get a location's value
char Tictactoe::getValue(int row, int col) const
{
	return this->board[row][col];
}//end function getValue

//function to get if the game is on
bool Tictactoe::getGameOn()
{
	//check if there is a winner
	if (winner == 'x' || winner == 'o')
	{
		gameOn = false;
	}
	else
	{
		//if there isn't a winner, but the board is full, then end the game
		if (turnCounter >= TOTAL_NUM_TURNS)
		{
			gameOn = false;
		}
		else
		{
			gameOn = true;
		}
	}
	return this->gameOn;
}//end function getGameOn

//function to get the winner
char Tictactoe::getWinner() const
{
	return this->winner;
}//end function getWinner

//function to get the max row size
int Tictactoe::getMaxRowSize() const
{
	return this->MAX_ROW_SIZE;
}//end function getMaxRowSize

//function to get the max col size
int Tictactoe::getMaxColSize() const
{
	return this->MAX_COL_SIZE;
}//end function getMaxColSize

//function to place an x or o onto the board
void Tictactoe::placeUnit(int row, int col)
{
	int displayUserRow = 0;
	int displayUserCol = 0;
	int displayCompRow = 0;
	int displayCompCol = 0;
	//if the row and col entered is out of bounds
	if (row > MAX_ROW_SIZE || col > MAX_COL_SIZE || row < MIN_ROW_SIZE || col < MIN_COL_SIZE)
	{
		std::cout << "That location is out of bounds. \n";
	}
	else
	{
		//if the location is already occupied
		if (((getValue(row, col)) == 'x') || (getValue(row, col) == 'o'))
		{
			if (xturn)
			{
				//if it's the user's turn, reprompt the user to enter a valid location
				std::cout << "That location is already taken. \n";
			}
			else
			{
				//if it's the computer's turn, make it create new random numbers
				compTurnDone = false;
			}
		}
		else
		{
			//if the location is not occupied,
			if (xturn)
			{
				//place an x in the location if it's x's turn
				board[row][col] = 'x';
				//display where the computer moved
				displayUserRow = row + 1;
				displayUserCol = col + 1;
				std::cout << "You entered placed " << displayUserRow << " " << displayUserCol << std::endl;
			}
			else if (!xturn)
			{
				//place an o in the location if it's o's turn
				board[row][col] = 'o';
				//computer's turn is done
				compTurnDone = true;
				//display where the computer moved
				displayCompRow = row + 1;
				displayCompCol = col + 1;
				std::cout << "The computer placed " << displayCompRow << " " << displayCompCol << std::endl;
			}
			++turnCounter;		//increment the turnCounter if a unit was placed
			winCondition();	//check if either side won
			xturn = !xturn;	//change xturn to the opposite
		}
	}
}

//function to check if there's a winner
void Tictactoe::winCondition()
{
	//check if the rows have 3 x's in sequence
	if ((getValue(0, 0) == 'x') && (getValue(0, 1) == 'x') && (getValue(0, 2) == 'x'))
	{
		gameOn = false;	//if it does, then end the game
	}
	else if ((getValue(1, 0) == 'x') && (getValue(1, 1) == 'x') && (getValue(1, 2) == 'x'))
	{
		gameOn = false;
	}
	else if ((getValue(2, 0) == 'x') && (getValue(2, 1) == 'x') && (getValue(2, 2) == 'x'))
	{
		gameOn = false;
	}
	//check if the columns have 3 x's in sequence
	else if ((getValue(0, 0) == 'x') && (getValue(1, 0) == 'x') && (getValue(2, 0) == 'x'))
	{
		gameOn = false;
	}
	else if ((getValue(0, 1) == 'x') && (getValue(1, 1) == 'x') && (getValue(2, 1) == 'x'))
	{
		gameOn = false;
	}
	else if ((getValue(0, 2) == 'x') && (getValue(1, 2) == 'x') && (getValue(2, 2) == 'x'))
	{
		gameOn = false;
	}
	//check if the diagonals have 3 x's in sequence
	else if ((getValue(0, 0) == 'x') && (getValue(1, 1) == 'x') && (getValue(2, 2) == 'x'))
	{
		gameOn = false;
	}
	else if ((getValue(2, 0) == 'x') && (getValue(1, 1) == 'x') && (getValue(0, 2) == 'x'))
	{
		gameOn = false;
	}

	//check if the rows have 3 o's in sequence
	if ((getValue(0, 0) == 'o') && (getValue(0, 1) == 'o') && (getValue(0, 2) == 'o'))
	{
		gameOn = false;	//if it does, then end the game
	}
	else if ((getValue(1, 0) == 'o') && (getValue(1, 1) == 'o') && (getValue(1, 2) == 'o'))
	{
		gameOn = false;
	}
	else if ((getValue(2, 0) == 'o') && (getValue(2, 1) == 'o') && (getValue(2, 2) == 'o'))
	{
		gameOn = false;
	}
	//check if the columns have 3 o's in sequence
	else if ((getValue(0, 0) == 'o') && (getValue(1, 0) == 'o') && (getValue(2, 0) == 'o'))
	{
		gameOn = false;
	}
	else if ((getValue(0, 1) == 'o') && (getValue(1, 1) == 'o') && (getValue(2, 1) == 'o'))
	{
		gameOn = false;
	}
	else if ((getValue(0, 2) == 'o') && (getValue(1, 2) == 'o') && (getValue(2, 2) == 'o'))
	{
		gameOn = false;
	}
	//check if the diagonals have o x's in sequence
	else if ((getValue(0, 0) == 'o') && (getValue(1, 1) == 'o') && (getValue(2, 2) == 'o'))
	{
		gameOn = false;
	}
	else if ((getValue(2, 0) == 'o') && (getValue(1, 1) == 'o') && (getValue(0, 2) == 'o'))
	{
		gameOn = false;
	}
	//if there is a winner
	if (!gameOn)
	{
		//set winner to x if it's x's turn
		if (xturn)
		{
			winner = 'x';
		}
		//set winner to o if it's o's turn
		else
		{
			winner = 'o';
		}
	}
}

//function computer logic
void Tictactoe::computerPlayer()
{
	//declare and initialize computer row and col variables
	int computerRow = 0;	//variable to hold the computer's randomly generated row
	int computerCol = 0;	//variable to hold the computer's randomly generated column

	//create a random seed with the time of day
	std::srand(std::time(0));


	//create a random number between 0 and 2 for the
	//computer's row and column
	computerRow = MIN_ROW_SIZE + std::rand() % MAX_ROW_SIZE;
	computerCol = MIN_COL_SIZE + std::rand() % MAX_COL_SIZE;

	//use the generated row and column to place a unit
	placeUnit(computerRow, computerCol);

}//end function computerPlayer

//function to play the game
void Tictactoe::playGame(int row, int col)
{
	//if the game is on, and it is x's turn
	if (xturn && getGameOn())
	{
		placeUnit(row, col);	//place the user entered values on the board
	}

	//if the game is on and it is o's turn
	if (!xturn && getGameOn())
	{
		//loop until the computer finds an empty valid location
		while (!compTurnDone)
		{
			computerPlayer();
		}

		//reset computer's turn after the computer finishes its turn
		compTurnDone = false;
	}
}//end function playGame





