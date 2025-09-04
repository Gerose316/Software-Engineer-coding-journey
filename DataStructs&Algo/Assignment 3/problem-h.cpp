
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stdexcept>

class Deque {
private:
   int* data;
    int capacity;
    int front,back, size;
    bool reverse;

    void resize(int newCapacity) {
        int* newData = new int[newCapacity];
        for (int i = 0; i < size; i++) {
            newData[i] = data[(front + i) % capacity];  // Copy elements
        }
        delete[] data;
        data = newData;
        front = 0;
        back = size;
        capacity = newCapacity;
    }

public:
Deque(int initialCapacity = 10)
    :data(new int[initialCapacity]), capacity(initialCapacity), front(0), back(0), size(0), reverse(false) {}

    ~Deque() {
        delete[] data;
    }

    void push_back(int value) {
        if (size == capacity) resize(capacity * 2);
        data[back] = value;
        back = (back + 1) % capacity;
        size++;
    }

    void push_front(int value) {
        if (size == capacity) resize(capacity * 2);
        front = (front - 1 + capacity) % capacity;
        data[front] = value;
        size++;
    }

    void pop_front() {
        if (is_empty()) {
            throw std::runtime_error("error");
        }
        front = (front + 1) % capacity;
        size--;
    }

    void pop_back() {
        if (is_empty()) {
            throw std::runtime_error("error");
        }
        back = (back - 1 + capacity) % capacity;
        size--;
    }

    bool is_empty() const {
        return size == 0;
    }

    int sizeT() const {
        return size;
    }
    int get_front() const { return data[front]; }
    int get_back() const { return data[(back - 1 + capacity) % capacity]; }
    void integerList(int);

    void reverseDeque() { reverse = !reverse; }

    std::vector<int> getElements() {
        std::vector<int> result;
        if (reverse) {
            for (int i = size - 1; i >= 0; i--) {
                int index = (front + i) % capacity;
                result.push_back(data[index]);
            }
        } else {
            for (int i = 0; i < size; i++) {
                int index = (front + i) % capacity;
                result.push_back(data[index]);
            }
        }
        return result;
    }



};





void Deque::integerList(int TestCase){
    std::vector<std::string> champ;
        for(int i = 0; i < TestCase; ++i) {
            std::string command;
            std::cin >> command;

            int elementValues;
            std::cin >> elementValues;




            std::string input;
            std::cin >> input;


            Deque bar;
            std::string temp;

            for(int i = 0; i < input.size(); i++){
                char numbers = input[i];
                if(isdigit(numbers)){
                    temp += numbers;
                }else if(!temp.empty()){
                    bar.push_back(std::stoi(temp));
                    temp.clear();
                }

            }
            
            std::vector<std::string> Copy;
            if (!temp.empty()) {
                bar.push_back(std::stoi(temp));
            }

            bool error = false;
            for(int i = 0; i < command.size(); i++){
                char instructions = command[i];
            try {
                if(instructions == 'D'){
                    if (bar.is_empty()) {
                        error = true;
                        break;
                    }
                    
                    if (bar.reverse) {
                        bar.pop_back();
                    } else {
                        bar.pop_front();
                    }
                } 
                else if(instructions == 'R'){
                    bar.reverseDeque();
                }
            } catch (const std::runtime_error&) {
                error = true;
                break;
            }
        }
        
        if (error) {
            champ.push_back("error");
        } else {
            std::vector<int> cc = bar.getElements();
            std::stringstream ss;
            ss << "[";
            for (size_t j = 0; j < cc.size(); ++j) {
                if (j > 0) ss << ",";
                ss << cc[j];
            }
            ss << "]";
            champ.push_back(ss.str());
        }
    }

    // Print final results
    for (const auto& result : champ) {
        std::cout << result << std::endl;
    }
    

}

int main() {
    int TestCase;
    std::cin >> TestCase;
    Deque DD;
    DD.integerList(TestCase);

    return 0;
}