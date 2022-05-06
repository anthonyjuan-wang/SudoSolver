/**
Header file for sudoSolver.c
This provides the functions required to solve the sudoku
*/


/* Determines if it is valid to place numbers 1-9 in the current position we are in  */
int isAvailable(int puzzle[][9], int row, int col, int num);

/* Recursive function to solve the sudoku */
int fillSudoku(int puzzle[][9], int row, int col);


// Prints out board
void print_board(int board[][9]);

// Prints board template
void print_empty ();
