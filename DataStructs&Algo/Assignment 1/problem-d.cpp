#include <iostream>
#include <vector>

void modChecker(const std::string& rrr) {
    int total = 0; 
    std::vector<int> v2 = {4, 3, 2, 7, 6, 5, 4, 3, 2, 1};
    for(int i = 0; i < rrr.size(); i++){
       int v1 = rrr[i] - '0'; 
       total = total  + v1 * v2[i];
    } 


    if(total % 11 == 0){
        std::cout << "1" << std::endl;
    }else{
        std::cout << "0" << std::endl;
    }

    

}


int main(){
    std::string cpr;
    std::string rrr;
    std::cin >> cpr;
    for(int i = 0; i < cpr.size(); i++){
        if(cpr[i] != '-'){
            rrr += cpr[i];
        }

    
    }
    
    
    
    modChecker(rrr);

    return 0;
    

   
    
    
   
    
    
}