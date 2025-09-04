#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>



int conMedian(int testCase){
    
    std::vector<long long> vec2;
    for(int i = 0; i < testCase; i++){
        std::priority_queue<long> maxHeap;
        std::priority_queue<long, std::vector<long>, std::greater<long>> minHeap;
    
        int digits;
        std::cin >> digits;
        long long  sum = 0;
        for(int j = 0; j < digits; j++){
            long long vv;
            std::cin >> vv;
            if (maxHeap.empty() || vv <= maxHeap.top()){
                maxHeap.push(vv);
            }else{
                minHeap.push(vv);
            }
            if(maxHeap.size() > minHeap.size() + 1){
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }else if(minHeap.size() > maxHeap.size()){
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
            int mind = (maxHeap.size() > minHeap.size()) ? maxHeap.top()
            : (maxHeap.top() + minHeap.top()) / 2;
           
            
          
            
            sum += mind;
        }
        vec2.push_back(sum);

    

    }
    for (int l = 0; l < vec2.size(); l++){
        std::cout << vec2[l] << std::endl;
    }
    
return 0;

}



int main(){
    int testCase;
    std::cin >> testCase;
    conMedian(testCase);
    return 0;


}