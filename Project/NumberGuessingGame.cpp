#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>
void saveScore(const std::string hardstat, int attempts){\
    std::ofstream file("highscores.csv", std::ios::app);
    if(file.is_open()){
        file << hardstat << "," << attempts << "\n";
        file.close();
    } else {
        std::cout << " error found" << std::endl;
    }
}



int Easy(){
    std::cout << "Great! You have selected the Easy difficulty level." << std::endl;
    std::cout << "Let's start the Game!" << std::endl;
    int guessChamber;
    int count = 0;
    int randomNum = rand() % 101;
    std::cout << randomNum << std::endl;
    for(int i = 0; i < 10; i++){
        std::cout << "Enter your guess:" << std::endl;
        std::cin >> guessChamber;
        count++;
        if( count < 10){
        if(randomNum > guessChamber){
            std::cout << "Incorrect! The number is greater than" << guessChamber << std::endl;
            
        }else if(randomNum < guessChamber){
            std::cout << "Incorrect! The number is less than" << guessChamber << std::endl;
         
        }else{
            std::cout << "Congratulations! You guessed the correct number in " << count << " attempts." << std::endl;
            saveScore("Easy", count);
            return count;

        }

        
        
    }
}
 std::cout << "Game over! nice try " << randomNum << "." << std::endl;
    return -1;


}

int Medium(){
    std::cout << "Great! You have selected the Medium difficulty level." << std::endl;
    std::cout << "Let's start the Game!" << std::endl;
    int guessChamber;
    int count = 0;
    int randomNum = rand() % 101;
    std::cout << randomNum;
    for(int i = 0; i < 5; i++){
        std::cout << "Enter your guess:" << std::endl;
        std::cin >> guessChamber;
        count++;
        if( count < 5){
        if(randomNum > guessChamber){
            std::cout << "Incorrect! The number is greater than " << guessChamber << std::endl;
            
        }else if(randomNum < guessChamber){
            std::cout << "Incorrect! The number is less than " << guessChamber << std::endl;
         
        }else if(randomNum == guessChamber){
            std::cout << "Congratulations! You guessed the correct number in " << count << "attempts." << std::endl;
            break;

        }

        }else{
            std::cout << "Congratulations! You guessed the correct number in " << count << " attempts." << std::endl;
            saveScore("Medium", count);
            return count;

        }
        
    }
     std::cout << "Game over! nice try " << randomNum << "." << std::endl;
    return -1;

}

int Hard(){
    std::cout << "Great! You have selected the Hard difficulty level." << std::endl;
    std::cout << "Let's start the Game!" << std::endl;
    int guessChamber;
    int count = 0;
    int randomNum = rand() % 101;
    std::cout << randomNum;
    for(int i = 0; i < 3; i++){
        std::cout << "Enter your guess:" << std::endl;
        std::cin >> guessChamber;
        count++;
        if( count < 3){
        if(randomNum > guessChamber){
            std::cout << "Incorrect! The number is greater than" << guessChamber << std::endl;
            
        }else if(randomNum < guessChamber){
            std::cout << "Incorrect! The number is less than" << guessChamber << std::endl;
         
        }else{
            std::cout << "Congratulations! You guessed the correct number in " << count << " attempts." << std::endl;
            saveScore("Hard", count);
            return count;

        }

      
        
    }  
    }
    std::cout << "Game over! nice try " << randomNum << "." << std::endl;
    return -1;


 
}


// NEEDS TO BE CSV FILE TRACKING ALL THE HIGHSCORES

// I need to learn or watch a video for this 









int main(){
    std::cout << "Welcome to the Number Guessing Game!" << std::endl;
    std::cout << "I'm thinking of a number between 1 and 100." << std::endl;
    std::cout << "You have 5 chances to guess the correct number." << std::endl;
    std::cout << std::endl;

    std::cout << "Please select the difficulty level" << std::endl;
    std::cout << "1. Easy (10 chances)" << std::endl;
    std::cout << "2. Medium (5 chances)" << std::endl;
    std::cout << "3. Hard (3 chances)" << std::endl;

    int choices;
    int attempts;

    std::cout << "Enter your choice: ";
    while(std::cin >> choices){
        if(choices == 1){
            attempts = Easy();
            break;
        }else if(choices == 2){
            attempts = Medium();
            break;

        }else if(choices == 3){
            attempts = Hard();
            break;
        }

    }

}
