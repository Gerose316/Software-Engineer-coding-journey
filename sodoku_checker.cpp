#include <iostream>
#include <vector>


// this needs to go to the row
bool rowe(const std::vector<std::vector<int>>& board, int col, int row){
    for(int i =  0; i  < 9; i++){
        if(col == i){
            continue;
        }else if(board[row][col] == board[row][i]){
                return false;

            

        }
        
        
        
    }
    return true;

}

/// this meeds to go through the column
bool column(const std::vector<std::vector<int>>& board, int col, int row){
   for(int i = 0; i < 9 ; i++){
        if(row == i){
            continue;
        }else if (board[row][col] == board[i][col]){
             return false;

;
        }
        
    }
    return true;
}//your first if shouldn't have an || board[row][i] should be in row function and board[i][column] in the column function

bool boxChecker(const std::vector<std::vector<int>>& board, int col, int row ){
    
    int sinrow = (row - (row % 3));
    int sincol = (col - (col % 3));
    for (int i = sinrow; i < sinrow + 3; i++){
        
        for (int j = sincol; j < sincol + 3; j++){

            if (board[i][j] == board[row][col] && i != row && j != col){
                    return false;

               
            }
    
    }

    }
    return true;
 }
       
 



// this needs to go to the row and column



// recursively check
bool sodokuchecker( std::vector<std::vector<int>>& board, int row , int col ){
 if (boxChecker(board , col,row) == false || column(board, col , row) == false || rowe(board, col , row) == false){
    return false;
    
 }else if (row == 8 && col == 8){
        return  true;

// leave this alone
 }else if(col + 1 == 9 || row >= 9) {
    return sodokuchecker(board,row + 1, 0);



 }else{
     return sodokuchecker(board, row, col + 1);
 }




}
   


    

int main(){
    std::vector<std::vector<int>> board(9, std::vector<int>(9));
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            std::cin >> board[i][j];

        }

    }
    bool result = sodokuchecker(board, 0 , 0);
    if (result){
        std::cout << "Solution is good!" << std::endl;
    }else{
        std::cout << "Wrong solution!" << std::endl;
    }




}







