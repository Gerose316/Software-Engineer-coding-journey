#include<iostream>


void fitting(int wc, int hc, int ws, int hs){
     
   
   if(wc == ws && hc == hs){
        std::cout << "0" << std::endl;
   }
   if(wc > ws && hc > hs){
      std::cout << "1" << std::endl;
   }else{
      std::cout << "0" << std::endl;
   }
   
   

   
}


int main(){
    int wc, hc, ws, hs;
    std::cin >> wc >> hc >> ws >> hs;
    ws = ws + 1;
    hs = hs + 1;
    fitting(wc, hc, ws, hs);


}   