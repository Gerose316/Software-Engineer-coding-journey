#include <iostream>
#include <vector>
#include<string>




void ethanol(int c){
    std::string ethanol = "H-C-OH";
    int count = 1;
    std::string CC = "C-";
    if (c == 1){
        for(int i = 0; i < ethanol.size(); i++){
            if(ethanol[i] == 'C'){
                std::cout << "H";
            }else{
                std::cout << " ";
            }
        }
        std::cout << std::endl;




        for(int i = 0; i < ethanol.size(); i++){
            if(ethanol[i] == 'C'){
                std::cout << "|";
            }else{
                std::cout << " ";
            }
        }
            
        
        


        std::cout << std::endl;
        std::cout << ethanol;
         std::cout << std::endl;




          for(int i = 0; i < ethanol.size(); i++){
            if(ethanol[i] == 'C'){
                std::cout << "|";
            }else{
                std::cout << " ";
            }
        }

         std::cout << std::endl;


        if (c == 1){
        for(int i = 0; i < ethanol.size(); i++){
            if(ethanol[i] == 'C'){
                std::cout << "H";
            }else{
                std::cout << " ";
            }
        }
      
    }
    }else{

        for(int i = 0; i < ethanol.size(); i++){
            if(count != c && ethanol[i] == '-' ){
                ethanol.insert(i+1,CC);
                count++;
                 
            }
        }

        for(int i = 0; i < ethanol.size(); i++){
            if(ethanol[i] == 'C'){
                std::cout << "H";
            }else{
                std::cout << " ";
            }
        }
        std::cout << std::endl;




        for(int i = 0; i < ethanol.size(); i++){
            if(ethanol[i] == 'C'){
                std::cout << "|";
            }else{
                std::cout << " ";
            }
        }
            
        
        


        std::cout << std::endl;
        std::cout << ethanol;
         std::cout << std::endl;




          for(int i = 0; i < ethanol.size(); i++){
            if(ethanol[i] == 'C'){
                std::cout << "|";
            }else{
                std::cout << " ";
            }
        }

         std::cout << std::endl;


        
        for(int i = 0; i < ethanol.size(); i++){
            if(ethanol[i] == 'C'){
                std::cout << "H";
            }else{
                std::cout << " ";
            }
        }
      
    















    }






}










          


        




    
        











    
   
   

    

    








int main(){
    int  c;
    std::cin >> c;
    ethanol(c);
    

    

}