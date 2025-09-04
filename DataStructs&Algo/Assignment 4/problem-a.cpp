#include<iostream>
#include<queue>
#include<vector>
#include<stack>
#include<sstream>
#include<string>
#include<utility>
#include<fstream>


void gameShow(){
    
    std::vector<std::string> vec3;
    int testCase;
    
    while(std::cin >> testCase){
        std::priority_queue<int> pq;
        std::stack<int> st;
        std::queue<int> q;
        std::vector<int> vec2;
        bool Sflag = true;
        bool Qflag = true;
        bool PQflag = true;
        
        for(int i = 0; i < testCase; i++){
            
            int set, input;
            std::cin >> set;
            if(set == 1){
                std::cin >> input;
                pq.push(input);
                st.push(input);
                q.push(input);
            }else if(set == 2){
                std::cin >> input;
                vec2.push_back(input);
                
                if(st.empty() || st.top() != input) {
                    Sflag = false;
                } else {
                    st.pop();
                }
                
                if(q.empty() || q.front() != input) {
                    Qflag = false;
                } else {
                    q.pop();
                }
                
                if(pq.empty() || pq.top() != input) {
                    PQflag = false;
                } else {
                    pq.pop();
                }
            }

        }
    
        
        
        if(Sflag && !Qflag && !PQflag) {
            vec3.push_back("stack");
        } else if(!Sflag && Qflag && !PQflag) {
            vec3.push_back("queue");
        } else if(!Sflag && !Qflag && PQflag) {
            vec3.push_back("priority queue");
        } else if(!Sflag && !Qflag && !PQflag) {
            vec3.push_back("impossible");
        } else {
            vec3.push_back("not sure");
        }
}

for(int i = 0; i < vec3.size(); i++){
    std::cout << vec3[i] << std::endl;



}



}

int main (){
   
    gameShow();


}