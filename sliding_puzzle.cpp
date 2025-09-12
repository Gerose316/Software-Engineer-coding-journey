#include <iostream>
#include <vector>
#include <string>





bool workShop(std::vector<int>& result, std::vector<char>& direct,const int goalState[3][3], int index){

    std::vector<std::vector<int>> board(3,std::vector<int>(3));
   

    for(int i=0; i < 9; i++){
        board[i / 3][i % 3] = result[i];
    }

    
    for(int i = 0 ; i < direct.size(); i++){
       if (direct[i] == 'U'){
            if(index / 3 > 0){
                std::swap(board[index / 3][index % 3],board[(index/3) -1 ][index % 3]);
                index = index - 3;
            }
        }else if(direct[i] == 'D'){
            if (index / 3 < 2){
                 std::swap(board[index / 3][index % 3],board[(index / 3) + 1][index % 3]);
                 index = index + 3;
            }

       }else if(direct[i] == 'L'){
            if(index % 3 > 0){
                 std::swap(board[index / 3][index % 3],board[index / 3][(index % 3) - 1]);
                 index = index - 1;
            }
           

       }else if(direct[i] == 'R'){
            if(index % 3 < 2){
                 std::swap(board[index / 3][index % 3],board[index / 3][(index % 3) + 1]);
                index = index + 1;
            }
           
       }
    }

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(board[i][j] != goalState[i][j]){
                 return false;
        }
    }

}
    return true;






 }

   




int main(){
    int index = 0;
    int number;
    std::vector<int> grandNumber;
    char direction;
    std::vector<char> direct;

    int goalState[3][3] = {{1,2,3},
                         {4,5,6},
                         {7,8,0},};
for (int i = 0; i < 9; i++){
     std::cin >> number;
      if (number >= 0 && number <= 8){
         grandNumber.push_back(number);
         if(number == 0 ){
            index = i;
         }
    }
    
}

while(std::cin >> direction){

    direct.push_back(direction);
}

bool final = workShop(grandNumber, direct, goalState, index);





if(final){
    std::cout << "Solution is good!";
}else{
    std::cout << "Wrong solution!";
}
    

    
}