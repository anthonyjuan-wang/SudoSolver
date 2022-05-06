
/**
 File: sudoSolver.c
 Function designed to solve a sudoku 
*/

#include <stdio.h>


int isAvailable(int puzzle[][9], int row, int col, int num)
{
    int rowStart = (row/3) * 3;
    int colStart = (col/3) * 3;
    for(int i=0; i<9; ++i)
    {
        if (puzzle[row][i] == num) return 0;
        if (puzzle[i][col] == num) return 0;
        if (puzzle[rowStart + (i%3)][colStart + (i/3)] == num) return 0;
    }
    return 1;
}

int fillSudoku(int puzzle[][9], int row, int col)
{
   
    if(row<9 && col<9)
    {
        if(puzzle[row][col] != 0)
        {
            if((col+1)<9) return fillSudoku(puzzle, row, col+1);
            else if((row+1)<9) return fillSudoku(puzzle, row+1, 0);
            else return 1;
        }
        else
        {
            for(int i=0; i<9; ++i)
            {
                if(isAvailable(puzzle, row, col, i+1))
                {
                    puzzle[row][col] = i+1;
                    if((col+1)<9)
                    {
                        if(fillSudoku(puzzle, row, col +1)) return 1;
                        else puzzle[row][col] = 0;
                    }
                    else if((row+1)<9)
                    {
                        if(fillSudoku(puzzle, row+1, 0)) return 1;
                        else puzzle[row][col] = 0;
                    }
                    else return 1;
                }
            }
        }
        return 0;
    }
    else return 1;
}

void print_board(int board[][9]){
  // Rows
  for (int i = 0; i < 9; i++){
    if (i % 3 == 0 && i != 0){
      printf("- - - - - - - - - - - -\n");
    }
    // Columns
    for (int j = 0; j < 9; j++){
      if (j % 3 == 0 && j != 0){
        printf(" | ");
      }
      if (j == 8){
        printf("%d", board[i][j]);
      }
      else{
        printf("%d ", board[i][j]);
      }
    }
    printf ("\n");
  }
  printf("- - - - - - - - - - - -\n\n");
}


void print_empty(){
 for (int i = 0; i < 9; i++){
    if (i % 3 == 0 && i != 0){
      printf("- - - - - - - - - - - -\n");
    }
   for (int j = 0; j < 9; j++){
     if (j % 3 == 0 && j != 0){
        printf(" | ");
      }
     else if (j == 8){
        printf(" ");
      }
     else{
     printf ("  ");
     }
   }
   printf ("\n");
 }
printf("- - - - - - - - - - - -\n\n");  
}
