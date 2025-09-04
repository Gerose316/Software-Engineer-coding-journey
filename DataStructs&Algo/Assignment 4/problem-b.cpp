#include <iostream>
#include <queue>
#include <vector>
#include <string>





int stockmarket(int testCase)
{   std::vector<std::string> ask;
    std::vector<std::string> bid;
    std::vector<std::string> last;

    
    for(int i = 0; i < testCase; i++){
    std::priority_queue<std::pair<int, int>> maxHeap;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, 
    std::greater<std::pair<int, int>>> minHeap;
    
    int set;
    std::cin >> set;
    int stockPrice = -1;




    for(int j = 0; j < set; j++){
            int shares,prices;
            std::string command, unit, at;
            std::cin >> command >> shares >> unit >> at >> prices;
            if(command == "buy"){
                    maxHeap.push(std::make_pair(prices,shares));
            }else if(command == "sell"){
                    minHeap.push(std::make_pair(prices,shares));
            }

            while(!maxHeap.empty() && !minHeap.empty() && maxHeap.top().first >= minHeap.top().first) {
                
                auto buy = maxHeap.top();
                maxHeap.pop();
                
                auto sell = minHeap.top();
                minHeap.pop();
                
                stockPrice = sell.first;
                
                int sharesExchanged = std::min(buy.second, sell.second);
                
                if(buy.second > sharesExchanged) {
                    maxHeap.push(std::make_pair(buy.first, buy.second - sharesExchanged));
                }
                
                if(sell.second > sharesExchanged) {
                    minHeap.push(std::make_pair(sell.first, sell.second - sharesExchanged));
                }
            }

            if(minHeap.empty()) {
                ask.push_back("-");
            } else {
                ask.push_back(std::to_string(minHeap.top().first));
            }
            
            if(maxHeap.empty()) {
                bid.push_back("-");
            } else {
                bid.push_back(std::to_string(maxHeap.top().first));
            }
            
            if(stockPrice == -1) {
                last.push_back("-");
            } else {
                last.push_back(std::to_string(stockPrice));
            } 


            
              
               
            
           

        }

    }
    for(int i = 0; i < ask.size(); i++){
        std::cout << ask[i] << " " << bid[i] << " " << last[i] << std::endl;
    }

    
 

    
return 0;

   
}




int main() {
    int testCase;
    std::cin >> testCase;
    stockmarket(testCase);

    return 0;
  
}