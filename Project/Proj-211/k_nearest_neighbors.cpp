#include <iostream>
#include <cmath>
#include <vector>



int main(){
    std::vector<double> Rteam;
    std::vector<char> Colors;
    int n,k;
    double x,y;
    int  claim = 0;
    double neighborx, neighbory;
   

    char buf;
   
    std::cin >> n >> k;
    for(int i = 0; i < n; i++){
        std::cin >> x >> y >> buf;
        Rteam.push_back(x);
        Rteam.push_back(y);
        Colors.push_back(buf);
    }
    
    std::cin >> neighborx >> neighbory  ;
    std::vector<double> utube;
    for (int i = 0; i < n; i ++){
        double diameter =  pow(neighborx -  Rteam[2 * i],2) + pow(neighbory - Rteam[2 * i + 1],2);
        utube.push_back(std::sqrt(diameter));


        }
    
    
    std::vector<int> index;
      for (int j = 0; j < k; j++){
            double smallest = 1e9;
            int smallestIndex = -1;
            for (int i = 0; i < utube.size(); i++){
             if (smallest > utube[i]){
                smallest = utube[i];
                smallestIndex = i;
                
                 }
        
            }
            if (smallestIndex != -1){
                index.push_back(smallestIndex);
                utube[smallestIndex] = 200000;
            }


    }
    int countR = 0;
    int countB = 0;

    for (int i = 0; i < index.size(); i++){
        int f = index[i];
        if (Colors[f] == 'R'){
            countR++;

        }else{
            countB++;
        }


    }

    if (countR > countB ){
        std::cout << 'R';
    }else{
        std::cout << 'B';


    }

}


    
   
 


    
   
        

    

   



    



   

    
