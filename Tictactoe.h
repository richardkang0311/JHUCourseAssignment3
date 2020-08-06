/*
 * Tictactoe.h
 *
 *  Created on: Feb 17, 2018
 *      Author: Richard Kang
 *      Header file for class Tictactoe
 */

#ifndef TICTACTOE_H_
#define TICTACTOE_H_

#include <cstdlib>	//allows program to use rand
#include <ctime>		//allows program to use time

class Tictactoe{

public:
	//constructor to initialize the entire board with _ characters
	explicit Tictactoe ();


	//initialize public member methods
	char getValue(int row, int col) const;	//getter for a specific row,col's value
														//either x, o, or _
	bool getGameOn() ;	//getter for GameOn
	char getWinner() const;	//getter for winner
	int getMaxRowSize() const;	//getter for the max row size
	int getMaxColSize() const;	//getter for the max col size
	void placeUnit(int row, int col);	//places the unit after user enters info, or
													//computer creates random numbers
	void winCondition();	//checks if there is a winner after every turn
	void computerPlayer();	//computer player method that randomly creates row,col values
	void playGame(int row, int col);	//method to be called by the main function

private:
	//initialize private member variables
	const int MAX_ROW_SIZE = 3;	//constant variable for the max row size
	const int MAX_COL_SIZE = 3;	//constant variable for the max col size
	const int MIN_ROW_SIZE = 0;	//constant variable for the min row size
	const int MIN_COL_SIZE = 0;	//constant variable for the min col size
	const int TOTAL_NUM_TURNS = MAX_ROW_SIZE * MAX_COL_SIZE;	//constant variable
																		//for the total turns in a game
	char board[3][3] = {0};	//array of board characters, 3x3
	char winner = '_';	//initialize winner to _ (aka nothing)
	bool gameOn = true;	//game is on (aka true) when an object is created
	bool xturn = true;	//keeps track of the turn. defaults to x going first
	int turnCounter = 0;	//counter to keep track of turns taken
	bool compTurnDone = false;	//check to see if the computer finished it's turn
										//need this variable in case the computer's randomly
										//generated numbers point to a location already taken
};

#endif /* TICTACTOE_H_ */
