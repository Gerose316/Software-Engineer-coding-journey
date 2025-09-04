#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <deque>
#include <algorithm>

template <typename T>
class Quque {
private:
    T* data;
    int capacity;
    int size;

    void resize(int new_capacity) {
        T* new_data = new T[new_capacity];
        for (int i = 0; i < size; ++i) {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
        capacity = new_capacity;
    }

public:
    Quque() : data(nullptr), capacity(0), size(0) {}

    ~Quque() {
        delete[] data;
    }

    void push_back(const T& value) {
        if (size == capacity) {
            resize(capacity == 0 ? 1 : capacity * 2);
        }
        data[size++] = value;
    }

    void pop_front() {
        if (size == 0) {
            throw std::out_of_range("Quque is empty");
        }
        for (int i = 1; i < size; ++i) {
            data[i - 1] = data[i];
        }
        --size;
    }

    T& front() {
        if (size == 0) {
            throw std::out_of_range("Quque is empty");
        }
        return data[0];
    }

    bool empty() const {
        return size == 0;
    }

    int get_size() const {
        return size;
    }
};









void ferryWheel(int testcase){
    
    std::vector<int> vec;

    for(int i = 0; i < testcase; i++){
        int j;
        int m;
        std::cin >> j >> m;
        Quque<int> left;
        Quque<int> right;

        j *= 100;

        for(int k = 0; k < m; k++){
            std::string leftorRight;
            int cars;
            std::cin >> cars >> leftorRight;

            if(leftorRight == "left"){
                left.push_back(cars);
            }else if(leftorRight == "right"){
                right.push_back(cars);
            }
            
            

        }
        
    

    int carCounter = 0;
    bool onLeft = true;

    while(!left.empty() || !right.empty()){
        int currentLoad = 0;

        if(onLeft){
            while(!left.empty() && currentLoad + left.front() <= j){
                currentLoad += left.front();
                left.pop_front();
            }
        }else{
            while(!right.empty() && currentLoad + right.front() <= j){
                currentLoad += right.front();
                right.pop_front();
            }
        }
        carCounter++;
        onLeft = !onLeft;
    }
    vec.push_back(carCounter);

    

    }
    for(int i = 0; i < vec.size(); i++){
        std::cout << vec[i] << std::endl;
    }

}

int main(){
    int testCases;
    std::cin >> testCases;
    ferryWheel(testCases);

   
}