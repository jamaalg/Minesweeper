#include "Game.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

// GAME CONSTRUCTOR
Game::Game(int &x) : numberofPicks(x), score(0), rowselection(0), columnselection(0) {
	
}

// RETURNS USER SCORE
double Game::getScore(){
	return score;
}

// RETURNS USER PICKS
int Game::getNumPicks(){
	return numberofPicks;
}



// FILLS GRID WITH DEFAULT VALUES
void Game::fill_arr(char arr[row][column]){
	for (int r = 0; r < row; r++){
		for (int c = 0; c < column; c++){
			arr[r][c] = '-';
		}
	}
}

// PRINTS A GRID 
void Game::print_arr(char arr[row][column]){
	std::cout << endl << setw(46) << "------------------GRID----------------" << endl << endl << "      ";
	for (int x = 1; x < row + 1; x++){
		std::cout << setw(4) << x;
	}
	std::cout << endl << "      " << " ________________________________________" << endl << endl;
	for (int r = 0; r < row; r++){
		std::cout << setw(3) << r + 1 << "   |";
		for (int c = 0; c < column; c++){
			std::cout << setw(3) << arr[r][c] << " ";
		}
		cout << endl << setw(7) << "|" << endl;;
	}
	cout << endl;
}

// ------------------MINE GRID COPY & PRINT FUNCTIONS--------------------------------------------
// COPY GRID W/ MINE LOCATIONS ONLY 
void Game::copy_arrayWithMines(char functionArr[row][column]){
	for (int r = 0; r < row; r++){
		for (int c = 0; c < column; c++){
			gameArr[r][c] = functionArr[r][c];
		}
	}
}

void Game::print_arrayWithMines(){
	std::cout << endl << setw(46) << "------------------GRID----------------" << endl << endl << "      ";
	
	for (int x = 1; x < row + 1; x++){
		std::cout << setw(4) << x;
	}
	
	std::cout << endl << "      " << " ________________________________________" << endl << endl;
	
	for (int r = 0; r < row; r++){
		std::cout << setw(3) << r + 1 << "   |";
		for (int c = 0; c < column; c++){
			std::cout << setw(3) << gameArr[r][c] << " ";
		}
		cout << endl << setw(7) << "|" << endl;
	}
	cout << endl;
}

// ------------------ANSWER GRID COPY & PRINT FUNCTIONS--------------------------------------------
// COPY ANSWER GRID ARRAY WITH MINE LOCATIONS AND CELL #'S
void Game::copy_arrayAnswerGrid(char functionArr[row][column]){
	for (int r = 0; r < row; r++){
		for (int c = 0; c < column; c++){
		gameAnswerArr[r][c] = functionArr[r][c];
		}
	}
}

void Game::print_arrayAnswerGrid(){
	std::cout << endl << setw(46) << "-----------ANSWER GRID----------------" << endl << endl << "      ";
	
	for (int x = 1; x < row + 1; x++){
		std::cout << setw(4) << x;
	}
	
	std::cout << endl << "      " << " ________________________________________" << endl << endl;
	
	for (int r = 0; r < row; r++){
		std::cout << setw(3) << r + 1 << "   |";
		for (int c = 0; c < column; c++){
			std::cout << setw(3) << gameAnswerArr[r][c] << " ";
		}
		cout << endl << setw(7) << "|" << endl;
	}
	cout << endl;
}

// ------------------ CELL NUMBER GRID COPY & PRINT FUNCTIONS--------------------------------------------
// COPY GRID W/ CELL #'s INTO  UPDATE ARRAY 
void Game::copy_updateArr(char functionArr[row][column]){
	for (int r = 0; r < row; r++){
		for (int c = 0; c < column; c++){
			 dynamGameArr[r][c]= functionArr[r][c];
		}
	}
}

void Game::print_UpdateArray(){
	std::cout << endl << setw(46) << "------------------GRID----------------" << endl << endl << "      ";
	for (int x = 1; x < row + 1; x++){
		std::cout << setw(4) << x;
	}
	
	std::cout << endl << "      " << " ________________________________________" << endl << endl;
	
	for (int r = 0; r < row; r++){
				std::cout << setw(3) << r + 1 << "   |";
		for (int c = 0; c < column; c++){
			std::cout << setw(3) << dynamGameArr[r][c] << " ";
		}
	cout << endl << setw(7) << "|" << endl;
	}
	cout << endl;
}

// USER INPUT PROMPT FUNCTION
void Game::getUserInput(){
		getUserInputDisplay();
		setPickedTiles(rowselection, columnselection);
		check(rowselection, columnselection);
}

// USER INPUT DISPLAY PROMPT
void Game::getUserInputDisplay(){
	// prompt user input selection row, column
	std::cout << endl  << "Please enter a row (1-10): ";
	std::cin >> setw(2);
	std::cin >> rowselection;
	// check for valid row 
	while (rowselection > 10 || rowselection < 1){
		std::cout << endl << "Invalid input, please re-enter a row (1-10): ";
		std::cin >> setw(2);
		std::cin >> rowselection;
	}
	std::cout << "Please enter a column (1-10): ";
	std::cin >> setw(2);
	std::cin >> columnselection;
	// check for valid column 
	while (columnselection > 10 || columnselection < 1){
		std::cout << endl << "Invalid Input, please re-enter a column (1-10): ";
		std::cin >> setw(2);
		std::cin >> columnselection;
	}
}

// USED TO SET ROW SELECTION AND COLUMN SELECTION
void Game::setSelection(int num1, int num2){
	rowselection = num1;
	columnselection = num2;
}

// STORES PICKED CELLS IN VECTOR 
void Game::setPickedTiles(int num1, int num2 ){
	string final;
	stringstream ss1; 
	ss1 <<  "(" <<num1 << ","  <<num2  << ")" ;  
	string newString = ss1.str();
	final = newString;
	myPicks.push_back(final);
}

// DISPLAYS PICKED CELLS
void Game::displayPicks(){
	std::cout << endl << "Picks: " << endl;
	for (int i = 0; i < myPicks.size(); i++){
		std::cout << myPicks[i] << ", ";
	}
}

// CHECKS TO SEE IF MINE WAS LOCATED
// INCREMENTS SCORE IF FOUND 
// IF NOT CHAR '~' PLACED IN CELL SELECTED
void Game::check(int num1, int num2){
	num1 -= 1;
	num2 -= 1;
	if (gameArr[num1][num2] == 'x'){
		dynamGameArr[num1][num2] = 'X';
		std::cout << endl << "You found a mine!";
		std::cout << "You have earned a point. ";
		score += 1;
		std::cout << endl << "Score: " << score << endl;
		numberofPicks -= 1;
	}
	else if (gameAnswerArr[num1][num2] == '1' || gameAnswerArr[num1][num2] == '2' || gameAnswerArr[num1][num2] == '3' || gameAnswerArr[num1][num2] == '4' || gameAnswerArr[num1][num2] == '5' || gameAnswerArr[num1][num2] == '6' || gameAnswerArr[num1][num2] == '7' || gameAnswerArr[num1][num2] == '8'){
		std::cout << "Invalid Cell entry please pick a cell that is not numbered." << endl;
		
	}
	else{
		numberofPicks -= 1;
		std::cout << "Miss, Try Again!" << endl;
		dynamGameArr[num1][num2] = '~';
	}
}


// GENERATES NUMBERS TO PUT INTO CELLS -  INDICATES NUMBER OF ADJACENT MINES TO CELL
void Game::gen_numbomb(char myarr[row][column]) {
	// COUNTER FOR TILES
	int count = 0; 

	// IF CELL CONTAINS CHAR '-' CHECK ADJACENT CELLS 
	// IF CELLS IS ADJACENT AND CONTAINES A MINE 
	// INCREMENT COUNT BY 1
	for (int r = 0; r < row; r++){
		for (int c = 0; c < column; c++){

			// TOP LEFT CORNER  
			if (r == 0 && c == 0 && myarr[r][c] != 'x'){
				if (myarr[r][c + 1] == 'x')
					count++;
				if (myarr[r + 1][c] == 'x')
					count++;
				if (myarr[r + 1][c + 1] == 'x')
					count++;
			}
			
			// TOP RIGHT CORNER  
			else if (r == 0 && c == column - 1 && myarr[r][c] != 'x'){
				if (myarr[r][c - 1] == 'x')
					count++;
				if (myarr[r + 1][c - 1] == 'x')
					count++;
				if (myarr[r + 1][c] == 'x')
					count++;
			}
			
			// BOTTOM LEFT CORNER  
			else if (r == row - 1 && c == 0 && myarr[r][c] != 'x'){
				if (myarr[r - 1][c] == 'x')
					count++;
				if (myarr[r][c + 1] == 'x')
					count++;
				if (myarr[r - 1][c + 1] == 'x')
					count++;
			}
			
			// BOTTOM RIGHT CORNER  
			else if (r == row - 1 && c == column - 1 && myarr[r][c] != 'x'){
				if (myarr[r - 1][c] == 'x')
					count++;
				if (myarr[r][c - 1] == 'x')
					count++;
				if (myarr[r - 1][c - 1] == 'x')
					count++;
			}
			
			//  CHECK FIRST COLUMN  
			else if (c == 0 && (r != 0 && r != row - 1) && myarr[r][c] != 'x'){
				if (myarr[r - 1][c] == 'x')
					count++;
				if (myarr[r - 1][c + 1] == 'x')
					count++;
				if (myarr[r][c + 1] == 'x')
					count++;
				if (myarr[r + 1][c] == 'x')
					count++;
				if (myarr[r + 1][c + 1] == 'x')
					count++;
			}
			
			// LAST COLUMN 
			else if (c == column - 1 && (r != 0 && r != row - 1) && myarr[r][c] != 'x'){
				if (myarr[r - 1][c - 1] == 'x')
					count++;
				if (myarr[r - 1][c] == 'x')
					count++;
				if (myarr[r][c - 1] == 'x')
					count++;
				if (myarr[r + 1][c - 1] == 'x')
					count++;
				if (myarr[r + 1][c] == 'x')
					count++;
			}
			
			// FULLY SURROUNDED CELL 
			else if (myarr[r][c] != 'x'){
				if (myarr[r - 1][c - 1] == 'x')
					count++;
				if (myarr[r - 1][c] == 'x')
					count++;
				if (myarr[r - 1][c + 1] == 'x')
					count++;
				if (myarr[r][c - 1] == 'x')
					count++;
				if (myarr[r][c + 1] == 'x')
					count++;
				if (myarr[r + 1][c - 1] == 'x')
					count++;
				if (myarr[r + 1][c] == 'x')
					count++;
				if (myarr[r + 1][c + 1] == 'x')
					count++;
			}

			// SETS CELL #
			if (myarr[r][c] != 'x' && count > 0)
				myarr[r][c] = '0' + count;
			count = 0;
		}
	}

}

