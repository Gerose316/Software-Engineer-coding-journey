#include <iostream>

class queue{
    private:
        int *array;
        int length; 
        int front;
        int count;
        int base;
    public:
        queue(int len);
        ~queue();
        void enqueue(int);
        int dequeue();
        int severResponse();
    

};

queue::queue(int len){
    length = len;
    array = new int[length];
    front = 0;
    count = 0;
    base = 0;
}

queue::~queue(){
    delete [] array;
}

void queue::enqueue(int value){
    if(count == length){
        throw std::out_of_range("full");
    } 
        array[base] = value;
        base = (base + 1) % length;
        count++;
    
}

int queue::dequeue(){
    if(count == 0){
        throw std::out_of_range("empty");
    } else {
        int val = array[front];
        front = (front + 1) % length;
        count--;
        return val;
    }
}

int queue::severResponse(){
    int len;
    int sum = 0;
    int totalMins = 0;
    std::cin >> len >> totalMins;
    queue q(len);
    for(int i = 0; i < len; i++){
        int temp;
        std::cin >> temp;
        q.enqueue(temp);
    }
    for(int i = 0; i < len; i++){
        sum += q.dequeue();
        
        if(sum > totalMins){
            
            return i;
        }
       
    }
    return len;

}

int main(){
    queue q(1);
    std::cout << q.severResponse();
}