//===========================================================================
// Name        : CourseModule3_Assignment.cpp
// Author      : Richard Kang
// Version     :
// Copyright   : N/A
// Description : Create a tic tac toe game with a computer opponent
//===========================================================================

#include <iostream> 	//allows program to perform input and output
#include <string> 	//allows program to use string variables
#include "Tictactoe.h" //allows program to use Tictactoe class

//function main begins main program execution
int main() {

	//initialize variables
	Tictactoe game1;	//create object data of type Tictactoe

	int row = 0;		//user input for row
	int col = 0;		//user input for column
	bool invalidNumber = false;	//value true when user enters an invalid number to the data set
											//value false when user enters a valid number to the data set
	std::string dummy = ""; //empty string required to clean out std::cin if the user
									//enters an invalid number to the data set

	//while game1 is on, ask for user input, and play the game
	while (game1.getGameOn()){

		//do-while invalidNumber loops true if the input is invalid
		do {
			//ask the user for their new number to put into the data set
			std::cout << "Enter your input: row column. (eg 2 1 would signify row 2, column 1)" << std::endl;
			std::cin >> row >> col;
			//if the previous line's cin is not a double, then that is an invalid number
			if (!std::cin.fail()){ 	//cin.fail returns true if the previous cin was not a double
											//cin.fail returns false if the previous cin was a double
				invalidNumber = false; //set false to exit the do-while loop
			}
			else {
				std::cin.clear(); //clear the invalid cin value
				std::cin >> dummy; //input the empty string to clean out the cin value
				std::cout << "That is not a valid number.\n"; //tell the user it is not valid
				row = 0;
				col = 0;
				invalidNumber = true; //set true to reenter the do-while loop
			}
		} while (invalidNumber); 	//check invalidNumber
											//exit if the user enters a valid number

		--row; //decrement row and column to match class array bounds
		--col;

		game1.playGame (row, col);	//run the class functions

		//print the board when the user and computer finish their moves
		for (int x = 0; x < game1.getMaxRowSize(); ++x)
		{
			for (int y = 0; y < game1.getMaxColSize(); ++y)
			{
				std::cout << "| " << game1.getValue(x, y) << " ";
			}
			std::cout << "|" << std::endl;

			if (x < game1.getMaxRowSize() - 1)
			{
				std::cout << "-------------\n";
			}

		}	//end printing the board

	}

	//Display the winner, or tie, if it is a tie
	if (game1.getWinner() == 'x' || game1.getWinner() == 'o')
	{
		std::cout << "The game has ended. " << game1.getWinner() << " has won the game!" << std::endl;
	}
	else
	{
		std::cout <<"Tie!";
	}

	return 0;	//return 0 to end the main program
}	//end main
