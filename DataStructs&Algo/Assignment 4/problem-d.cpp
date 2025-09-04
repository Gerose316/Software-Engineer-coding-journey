#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <set>
class Vegetable {
    private:
        float ratio;
        int vegies;
        float minimal;
        struct Comparator {
            bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) {
                return (float)a.first / a.second < (float)b.first / b.second;
            }
        };


    
       std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, Comparator> Creation;






    public:
        

        Vegetable(float r, int v) : ratio(r), vegies(v), minimal(10000000000) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
            std::cout.tie(NULL);
          
        }


        

       void reader() {
            int w;
            for (int i = 0; i < vegies; i++) {
                std::cin >> w;
                Creation.push({w, 1});
                minimal = std::min(minimal, (float)w);
            }
        }
       
        
        
        void solve () {
            int res = 0;
            while (!Creation.empty()) {
                auto top = Creation.top();
               float top_value = (float)top.first / top.second;
                
                if (minimal / top_value >= ratio) {
                    break;
                }
                Creation.pop();
                
                Creation.push({top.first, top.second + 1});
                minimal = std::min(minimal, (float)top.first / (float)(top.second + 1));
                res++;
            }
            
            std::cout << res << std::endl;
            
        }

       


    

    

    
    

};

int main(){
    float ratio;
    int veg;

    while (std::cin >> ratio >> veg) {
        Vegetable boiler(ratio, veg);
        boiler.reader();
        boiler.solve();}

}