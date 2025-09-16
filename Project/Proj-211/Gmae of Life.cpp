
#include <iostream>
#include <vector>

int countNeighbor(int row, int col, const  std::vector<std::vector<char>>& board,int rows,int cols){
    int count = 0;

    for (int i = row - 1; i <= row + 1; ++i){
        for (int j = col - 1; j <= col + 1; ++j){
            if (i >= 0 && i < rows && j >= 0 && j < cols && !(i == row && j == col)) {
                if (board[i][j] == '*'){
                        ++count;
                }
            }
    
        }

    }
    return count;
 }

   



void generate(int row, int col, int generations, std::vector<std::vector<char>>& board){    
        /*for (int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                     std::cout << board[i][j];
                    if(j < col - 1) std::cout << " ";
                    
                }
                std::cout << std::endl;
        
        }
        std::cout << std::endl;
        */

    for (int gen = 0; gen < generations; ++gen){
        std::vector<std::vector<char>> text = board;
        
        for (int j = 0; j < row; ++j){
            for(int k = 0; k < col; ++k){
                int fin = countNeighbor( j, k, board, row , col);
                if (board[j][k] == '*'){
                    if (fin < 2 ||fin > 3 ){
                        text[j][k] = '.';
                   }else{
                        text[j][k] = '*';

                   }
                }else{
                    if(fin == 3){
                        text[j][k] = '*';
                    }
                }
                    
            }

        }
        board = text;
    }

    
        for (int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                     std::cout << board[i][j];
                    if(j < col - 1) std::cout << " ";
                    
                }
                if(i < row -1)std::cout << std::endl;
 }


}



int main(){
    int row;
    int col;
    int generations;
    std::cin >> row >> col >> generations;
    std::vector<std::vector<char>> board(row,std::vector<char>(col));

     for (int i = 0; i < row; ++i){
        for(int j = 0; j < col; ++j){
           std::cin >> board[i][j];
            
        }
    }





    generate(row, col, generations, board);
    return 0;




}