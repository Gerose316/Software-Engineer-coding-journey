#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
int main(){
    int n;
   

    while(std::cin >> n && n != 0){
         std::vector<int> list1(n);
         std::vector<int> list2(n);
         
         for(int i = 0; i < n; ++i) {
            std::cin >> list1[i];
        }

         for(int i = 0; i < n; ++i) {
            std::cin >> list2[i];
        }




    std::vector<int> list3 = list1;
    std::vector<int> list4 = list1;


    std::sort(list3.begin(), list3.end());
    std::sort(list2.begin(), list2.end());
    


    std::map<int,int> map;
    for(int i = 0; i < n; ++i){
        map[list3[i]] = list2[i];
    }
    for(int i = 0; i < n; ++i){
        std::cout << map[list1[i]] << std::endl;
    }
    std::cout << std::endl;



    



}

}
    
    

   


    



    













    

    
    

  
   







   

 


    
    

