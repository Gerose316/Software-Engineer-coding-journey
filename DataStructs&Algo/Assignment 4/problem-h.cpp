#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int main(){
    std::vector<std::string> v;
    std::vector<std::string>in;
    std::vector<std::string> h;
    std::string n;

    std::vector<int> max;
    while (getline(std::cin, n)) { 
        int t = 0;
        int len = n.length();
        for (int i = 0; i < n.length(); i++) { 
            t += (n[i] - '0');  
        }
    
        double num = double(t) / len;
        if (num != (int)num) {
            in.push_back(n);
            v.push_back(": invalid # of balls");

            continue;
        }
        std::vector<int> s(len, 0);
        bool check = true;
        for(int i = 0; i < len; i++){
            int cl = n[i] - '0';
            int land = (i + cl ) % len;
            if(s[land]){
                
                in.push_back(n);
                v.push_back(": invalid pattern");

                check = false;
                break;
            
            }
            s[land] = 1;

        }
        if(check){
            in.push_back(n);
             v.push_back(": valid with");
             h.push_back(std::to_string((int)num));

           
        }

        


 


    }
    for (size_t i = 0, h_idx = 0; i < v.size(); i++) {
        if (v[i] == ": valid with") {
            std::cout << in[i] << v[i] << " " << h[h_idx++] << " balls" << std::endl;
        } else {
            std::cout << in[i] << v[i] << std::endl;
        }
    }
    return 0;

    
}

