#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <unordered_set>
using ll = long long;

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int Query;
    long long factor;
    std::cin >> Query >> factor;

    int currentTime = 0;
    std::unordered_set<std::string> s;  
    std::priority_queue<std::pair<long long, std::string>, std::vector<std::pair<long long, std::string>>, std::greater<std::pair<long long, std::string>>> pq;  

    auto query = [&]() -> std::string {
        while (!pq.empty()) {
            auto [p, m] = pq.top(); pq.pop(); 
            if (s.count(m)) {
                return m;  
            }
        }
        return "doctor takes a break"; 
    };



    while(Query--){
        int que;
        int time;
        std::cin >> que >> time;

        if(que == 1){
            std::string name;
            long long  severity;
            std::cin >> name >> severity;
            s.insert(name);
            pq.emplace(-(severity - time * factor), std::move(name));

        }else if(que == 2){
         std::cout << query() << std::endl;
            
        } else if (que == 3) {
            std::string name;
            std::cin >> name;
            s.erase(name);
           
    
        }

    } 
   

    
    
   
  
    return 0;
}



