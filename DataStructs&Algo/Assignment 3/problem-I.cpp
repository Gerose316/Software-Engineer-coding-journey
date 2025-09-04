#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <deque>
#include <algorithm>

class deque{
    private:
        std::deque<int> front, back;
        void balance() {
            if (front.size() > back.size() + 1) {
                back.push_front(front.back());
                front.pop_back();
            } else if (back.size() > front.size()) {
                front.push_back(back.front());
                back.pop_front();
            }
        }

    public:
       
        void push_front(int);
        void push_back(int);
        void push_middle(int);
        int get  (int) const;
        void teque();
        void resize();
        
    
};

void deque::push_front(int value){
    front.push_front(value);
       
    balance();

}

void deque::push_back(int value){
    back.push_back(value);
    
    balance();

}   

void deque::push_middle(int value){
    if (front.size() < back.size()) {
        front.push_back(value);
    } else {
        back.push_front(value);
    }
    balance();

}

int deque::get(int index) const{
    if(index < front.size()){
        return front[index];
    }else{
        return back[index - front.size()];
    }

}





int main(){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int len;
    std::cin >> len;
   
    deque d;

    std::string comment;
    int temp;
    
    for (int i = 0; i < len; i++) {
        std::cin >> comment >> temp;
        
        if (comment == "push_front") {
            d.push_front(temp);

        } else if (comment == "push_middle") {
            d.push_middle(temp);


        } else if (comment == "push_back") {
            d.push_back(temp);

        } else if (comment == "get") {
            std::cout << d.get(temp) << "\n";
        }
    }
   
    return 0;
}