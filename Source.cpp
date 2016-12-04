
#include <iostream>
#include <cmath>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <string>
#include "Game.h"
using namespace std;

// CONST ROW AND CELL VARIABLES
const int rw = 10;
const int col = 10;

// FUNCTION PROTOTYPES
void convertArr(char defArr[][col]);
void randomizeMineplacement(char defArray[][col], int );
void rules(const int);

int main(){

	// SEED FOR RANDOM #'S
	srand(time(0)); 
	// ARRAY FOR STANDARD GRID
	char  arr[rw][col]; 
	
	// VARIABLES
	int  max_mines = 0;
	int incrementer = 0;
	
	// PROMPT USER TO CHOOSE NUMBER OF MINES BETWEEN 5 -20
	cout << endl << "WELCOME TO MINESWEEPER!" << endl << endl;
	cout << "How many mines do you want to include, choose between 5 and 20: ";
	do
	{
		cin >> max_mines;
		if ((max_mines <5) || (max_mines > 20) || cin.fail())
		{
			cout << "Invalid number entered, please try again." << endl;
			cin.clear();
			cin.ignore(256, '\n');
		}
	} while ((max_mines < 5) || (max_mines > 20) || cin.fail());

	cout << "You entered: " << max_mines << " mines." << endl;
	
	// DISPLAY RULES TO USER
	rules(max_mines); 
	
	// DECLARE GAME OBJECT
	Game obj(max_mines); 

	// FILL STANDARD GRID WITH DEFAULT VALUE 
	obj.fill_arr(arr); 	

	// PLACES MINES IN  STANDARD GRID
	randomizeMineplacement(arr, max_mines); 

	// COPIES STANDARD GRID WITH MINES INTO  A GAME CLASS GRID
	obj.copy_arrayWithMines(arr); 
	
	// GENERATES CELL #'S FOR STANDARD GRID 
	obj.gen_numbomb(arr); 

	// COPIES STANDARD GRID W/ MINE LOCATIONS AND CELL #'S INTO GAME CLASS GRID 
	obj.copy_arrayAnswerGrid(arr); 

	// CONVERTS STANDARD GRID TO PLAYABLE GRID 
	convertArr(arr);

	// COPIES NOW PLAYABLE STANDARD GRID INTO GAME CLASS GRIB 
	obj.copy_updateArr(arr);

	// DISPLAY GAME GRID, PICKED CELLS ->  GET USER INPUT 
	while (incrementer < max_mines){
		obj.print_UpdateArray();
		obj.displayPicks();
		std::cout << endl << endl << "Score : " << obj.getScore();
		std::cout << endl << "Number of Picks Left : " << obj.getNumPicks() << endl;
		obj.getUserInput();
		incrementer++;
	}

	// PRINT ANSWER GRID LOCATED IN GAME CLASS
	obj.print_arrayAnswerGrid();
	
	// END OF GAME 
	std::cout << "Thank you for playing!" << endl;
	std::cout << "Your final score is " << obj.getScore() << " points out of a possible " << max_mines << "." << endl;

	std::cin.ignore();
	std::cin.get();
	return 0;
}


// DISPLAY RULES & OBJECTIVE
void rules(const int b)
{
	cout << endl <<endl;
	cout << "Objective: The objective of the game is to locate the mines in the empty cells" << endl <<endl;
	cout << "RULES OF THE GAME ARE AS FOLLOWS: " << endl <<endl;
	cout << "1. Using the X and Y coordinate system, choose a cell on the 10 x 10 grid." << endl;
	cout << "2. Each numbered cell describes the # of mines that the cell is adjacent to." << endl;
	cout << "3. Select a cell to place your marker, you will have " << b << " turns to ";
	cout << "complete the game" << endl;
	cout << "4. Cells are considered adjacent if they share either a side or a corner." << endl;
	cout << "5. No cell contains more than one mine, and numbered cells never contain mines." << endl;
	cout << "6. For each correct location of a mine you will earn 1 point, and an 'X' will be placed on the grid." << endl;
	cout << "7. For each wrong answer a '~' will be placed in the cell" << endl;
	cout << endl;
}

// GENERATE PLACEMENT OF MINES IN GRID
void randomizeMineplacement(char defArray[][col], const int m){
	for (int start = 0; start < m; start++){	
		int rand_numRow = rand() % 10 + 0;
		int rand_numCol = rand() % 10 + 0;
		// ASSIGN MINE CHAR VALUE 'x'
		defArray[rand_numRow][rand_numCol] = 'x'; 
	}
}

// CONVERTS STANDARD GRID TO PLAYABLE GRID
void convertArr(char defArr[][col]){
	for (int i = 0; i < row; i++){
		for (int j = 0; j < column; j++){
			if (defArr[i][j] != '1' && defArr[i][j] != '2' && defArr[i][j] != '3' && defArr[i][j] != '4' && defArr[i][j] != '5' && defArr[i][j] != '6' && defArr[i][j] != '7' && defArr[i][j] != '8'){
				defArr[i][j] = '-';
			}
		}
	}
}

