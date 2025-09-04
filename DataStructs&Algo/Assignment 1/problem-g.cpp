#include<iostream>
#include <vector>


int main(){
    int n,r;
    std::cin >> n >> r;
    std::vector<int> v;
    std::vector<int> v2;

    int q;  

    for(int i = 1; i <= n; i++ ){
        v.push_back(i);
    }





    for(int i=0;i<r;i++){
        std::cin >> q;
        v2.push_back(q);
        
    }
    for(int i = 0; i < v2.size(); i++){
        for(int j = 0; j < v.size(); j++){
            if(v2[i] == v[j]){
                v.erase(v.begin()+j);
            }
        }
    }

    if (v.size() == 0){
        std::cout << "too late" << std::endl;
    }else{
        for(int i = 0; i < v.size(); i++){

        std::cout << v[i];
        break;
    }
    }

    
    
    
   

    
}
