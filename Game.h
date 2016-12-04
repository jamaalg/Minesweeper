
#ifndef GAME_H
#define GAME_H
#include <vector>
#include <string>
using namespace std;

// CONST ROW & COLUMN VARIABLES
static const int row = 10;
static const int column = 10;

class Game {

private:

	vector<string>myPicks;
	double score;
	int rowselection;
	int columnselection;
	int numberofPicks;
	char  gameArr[row][column]; // CONTAINS MINES
	char  gameAnswerArr[row][column]; // CONTAINS MINES & CELL #S
	char  dynamGameArr[row][column]; // CONTAINS CELL #S ONLY

public:

	Game(int&);
	
	void fill_arr(char[row][column]);
	void gen_numbomb(char myarr[row][column]);
	void print_arr(char[row][column]);
	
	void copy_arrayWithMines(char functionArr[row][column]);
	void copy_arrayAnswerGrid(char functionArr[row][column]);
	void copy_updateArr(char functionArr[row][column]);
	void print_arrayWithMines();
	void print_arrayAnswerGrid();
	void print_UpdateArray();

	void getUserInput(); 
	void getUserInputDisplay();
	double getScore();
	int getNumPicks();
	void setSelection(int, int);
	void setPickedTiles(int, int);
	void displayPicks();
	void check(int, int);
};

#endif