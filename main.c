#include <stdio.h>
#include "sudoSolver.h"

int main() {
  int puzzle[9][9]={{0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0}};
  int col = 0; 
  int row = 0;
  printf ("Welcome to sudoSolver! \nEnter F for instructions.\n");
  char c = 0;
  while (1){
    scanf ("%c" , &c);
    if (c == 'F'){
      printf ("Enter numbers 1-9 to enter a number into the sudoku.\nThe entries go from left to right, row by row.\nTo enter an empty cell, enter 0.\nOnce you are finished entering values, type X.\nTo begin, enter S.\nIf you would like to restart, enter R, then S again.\nOnce you are finished filling in the sudoku, enter X to exit.\n");
    }

    else if (c == 'S'){
      print_board (puzzle);
      while (1){
        scanf ("%c" , &c);
        if (c == 'R'){
          for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
              puzzle[i][j] = 0; 
            }
          }
          break;
        }
        
        else if (c == 'X'){
           goto LOOP;
        }
        else if (c <= '9' && c >= '0'){
          puzzle[row][col] = c - 48;
          if (col == 8){
            col = 0;
            row++;
          }
          else{
            col++;
          }
          print_board (puzzle);
          if (row == 9 && col == 0){
            goto LOOP;
          }
        }
      }
    }
  }
  LOOP: printf ("Solving...\n");
  if(fillSudoku(puzzle, 0, 0))
  {
 
    print_board (puzzle);
  }

  else printf("NO SOLUTION\n\n");

  return 0;
}
