#include "cellgrid.h"
#include <iostream>
#include <fstream>
using namespace std;

// reads a file containing 1's and 0's and the dimesnsions to expect and
// creates a Cellgrid object
Cellgrid::Cellgrid(const char *fname, int m, int n) {
    // assign row and col counters
    rows = m;
    cols = n;

    // create the grid on the heap, this will have to be deallocated later in
    // the destructor
    grid = new bool[rows*cols];
    


    // create a file reader stream to read data from a file
    ifstream infile;

    // open a stream to the given file
    infile.open(fname);

    // we are using row-major order in order to store this grid in 1D
    // instead of accessing grid like grid[a][b], we instead do:
    // grid[(a * number of columns) + b]

    
    for(int i = 0; i < rows; i++) {
        // calculate "(a * number of columns)" from above
        // in order to save some unnecessary computation
        int base = i * cols;
        for(int offset = 0; offset < cols; offset++) {
            // read data from filestream and store it in grid
            infile >> grid[base + offset];
        }
    }

    // close the filestream once we are done with it
    infile.close();
}

// destruct object where not implicit to the program
Cellgrid::~Cellgrid() {
    // since we allocated memory on the heap, we must deallocate that memory
    delete[] grid;
}

int Cellgrid::bLOB2(int conn){
    if (rows == 0){
        return 0;
      }
    int counter = 0;
    for(int i = 0; i < rows; i++){
        for (int  j = 0; j < cols; j++){
             if (grid[i * cols + j] == true){
                Helper(i,j,conn);
                counter++;
    }
        }
        
    }
    
  
    
return counter;
    

}

  

int Cellgrid::Helper(int row, int col , int conn){
      if (grid[(row * cols) + col ] == false || row < 0 || row >= rows || col >= cols || col < 0){
        return 0;
      }
      
      grid[(row * cols) + col] = false;
      int counter  = 1;
      counter =  counter + Helper(row, col - 1, conn);
      counter =  counter + Helper(row + 1, col, conn);
      counter =  counter + Helper(row - 1 , col, conn);
      counter =  counter + Helper(row, col + 1, conn);
      if (conn == 8){
        counter  = counter  + Helper(row - 1, col - 1, conn);
        counter  = counter  + Helper(row + 1, col + 1, conn);
        counter  = counter  + Helper(row - 1, col + 1, conn);
        counter  = counter  + Helper(row + 1, col - 1, conn);

      }

      return counter;



}


// this is the function call which will be made by the autograder to test
// your implementation for problem 1. (row, col) is the "start point" for
// counting the cells, conn is the type of connection to consider (4 or 8).

int Cellgrid::countCells(int row, int col, int conn) {
    // TODO:
    // implement solution for problem 1.

  
    row = row - 1;
    col = col - 1;
    int counter = 0;

    counter = counter + Helper(row , col , conn );
    

    return counter;


    // this is where your private helper method which does the
    // backtracking should be called

    // this will prevent a compiler error but should be changed
    // to return the cell count you have found

    
}

// this is the funciton call which will be made by the autograder to test
// your implementation for problem 2. conn is the type of connection
// to consider (4 or 8).
int Cellgrid::countBlobs(int conn) {
    //TODO:
    // implement solution for problem 2

    // this is where your private helper method which does the
    // backtracking should be called

    int counter = 0;
   
    counter = counter + bLOB2(conn);
    // this will prevent compiler error but should be changed
    // to return the blob count which you have found using
    // your helper function

    return counter;
}

// this function prints your cellgrid in 2D format without trailing
// whitespace. Use this function to aid in debugging if you wish
void Cellgrid::print() {
    for(int i = 0; i < rows; i++) {
        int base = i * cols;
        std::cout << grid[base];
        for(int offset = 1; offset < cols; offset++) {
            std::cout << ' ' << grid[base + offset];
        }
        std::cout << std::endl;
    }
}
