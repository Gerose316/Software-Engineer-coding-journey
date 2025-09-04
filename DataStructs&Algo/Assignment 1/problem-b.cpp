#include <iostream>
#include <vector>


int main(){
    int n;
    int d;
    std::vector<int> v;
    std::cin >> n;
    for(int i = 0; i < n; i++){
       std::cin >> d;
       v.push_back(d);
    
    }
    int count = 0;
    for(int i = 0; i < v.size(); i++){
        if(v[i] % 2 != 0){
            count++;
            
        } 
    }
    std::cout << count << std::endl;
}