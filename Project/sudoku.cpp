#include "sudoku.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

// reads a file containing a sudoku puzzle represented as
// 9 rows, each consisting of 9 comma-separated values
Sudoku::Sudoku(const char *fname) {
    // create a file reader stream to read data from a file
    ifstream infile;

    // will store lines and numbers
    string line, number;

    // index to write value to in puzzle
    int i = 0;

    // open a stream to the given file
    infile.open(fname);

    // get a line of input from the file
    while(getline(infile, line)) {
        // store the line inside a stringstream
        stringstream parser(line);
        // use stringstream to split line along ','
        while(getline(parser, number, ',')) {
            // convert string to an integer, store it, and update iterator
            puzzle[i++] = stoi(number);
        }
    }
    // close the filestream once we are done wiht it
    infile.close();
}

// destruct Sudoku object
Sudoku::~Sudoku() {
    // since we never allocated any memory on the heap, we don't need
    // to define behavior for the deconstructor
}




//------------------------------------------------------
bool Sudoku::rowe(int row, int col, int num){
    for(int i =  0; i  < 9; i++){
        if(i != col && num == puzzle[(row * 9) + i]){
                return false;
        }
    }
    return true;
}

/// this meeds to go through the column
bool Sudoku::column( int row, int col, int num){
   for(int i = 0; i < 9 ; i++){
        if (i != row && num == puzzle[(i * 9) + col]){
             return false;

        }
        
    }
    return true;
}//your first if shouldn't have an || board[row][i] should be in row function and board[i][column] in the column function

bool Sudoku::boxChecker(int row, int col, int num){
    
    int sinrow = (row - (row % 3));
    int sincol = (col - (col % 3));
    for (int i = sinrow; i < sinrow + 3; i++){
        
        for (int j = sincol; j < sincol + 3; j++){

            if ((i != row || j != col) && num == puzzle[(i * 9) + j]){
                    return false;

               
            }
    
    }

    }
    return true;
 }
       
 



// this needs to go to the row and column
bool Sudoku::check(int row, int col, int num){
    if(boxChecker(row,col, num) == true && column(row , col, num) == true && rowe(row , col, num) == true){
        return true;
    
    }

    return false;
}       


// recursively check
bool Sudoku::sodokuchecker(int row , int col ){

 if (row == 8 && col == 9){
        return  true;

// leave this alone
 }


 if(col == 9) {
    return sodokuchecker(row + 1, 0);



 }

 if (puzzle[row * 9 + col ] > 0){
     return sodokuchecker(row, col + 1);
 }

 for(int i = 1; i <= 9; i++){
    if (check(row , col, i)){
        puzzle[(row * 9 ) + col ] = i;
        
        if(sodokuchecker(row , col + 1)){
            return true;
        }

    }
    puzzle[(row * 9) + col] = 0;

}
return false;


}
   




//-------------------------------------------------------------------------





// this is the funciton call which will be made by the autograder to test
// your implementation for problem 3. It takes no parameters and
// should overwrite the 0s in puzzle to so that it represents a solved puzzle
void Sudoku::solve() {
    // TODO:
    // implement solution to problem 3

    sodokuchecker(0,0);
    

   
    

    // This is where your private helper method which does the
    // backtracking should be called
}

// this function prints your puzzle in 2D format with commas
// separating your values
void Sudoku::print() {
    for(int i = 0; i < 9; i++) {
        std::cout << puzzle[i*9];
        int base = i*9;
        for(int offset = 1; offset < 9; offset++) {
            std::cout << ',' << puzzle[base + offset];
        }
        std::cout << std::endl;
    }
}
