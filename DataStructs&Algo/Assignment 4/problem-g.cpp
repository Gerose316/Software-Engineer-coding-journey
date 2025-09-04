#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>






int main(){
    std::string n;
   
    std::priority_queue<long> maxHeap;
    std::priority_queue<long, std::vector<long>, std::greater<long>> minHeap;
    std::vector<long> collector;

    for(int i = 0; std::cin >> n; ++i){
       
        if(n == "#"){
            if(!maxHeap.empty()){
                long tar;
                if(minHeap.empty() || maxHeap.size() > minHeap.size()){
                    tar = maxHeap.top();
                    maxHeap.pop();
                }else{
                    tar = minHeap.top();
                    minHeap.pop();
                }



                collector.push_back(tar);
                if(maxHeap.size() < minHeap.size()){
                    maxHeap.push(minHeap.top());
                    minHeap.pop();
                }
            }
            
           
        }else{
            long dia = std::stoi(n);
            if( maxHeap.empty() || dia <= maxHeap.top()){
                maxHeap.push(dia);
        }else{
            minHeap.push(dia);
        }

        if(maxHeap.size() > minHeap.size() + 1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();

        }else if(minHeap.size() > maxHeap.size()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
    }
        }
        
    }
    for(int i = 0; i < collector.size(); i++){
        std::cout << collector[i] << std::endl;
    }


 return 0;
}


