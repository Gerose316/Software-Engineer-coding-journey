
#include <iostream>
#include <unordered_map>
#include <vector>
#include <stdexcept>
#include <string>

using namespace std;

// Custom Deque class implementation
template <typename T>
class deque {
private:
    T* arr;             // Dynamic array
    size_t capacity;    // Total capacity of array
    size_t front_idx;   // Index of front element
    size_t size_;       // Current number of elements

    // Resize array when needed
    void resize(size_t new_capacity) {
        T* new_arr = new T[new_capacity];
        
        // Copy elements to new array, centered in the middle
        size_t new_front = (new_capacity - size_) / 2;
        for (size_t i = 0; i < size_; i++) {
            new_arr[new_front + i] = arr[(front_idx + i) % capacity];
        }
        
        delete[] arr;
        arr = new_arr;
        capacity = new_capacity;
        front_idx = new_front;
    }

public:
    // Constructor
    deque(size_t initial_capacity = 16) : capacity(initial_capacity), front_idx(initial_capacity / 2), size_(0) {
        arr = new T[capacity];
    }
    
    // Destructor
    ~deque() {
        delete[] arr;
    }
    
    // Copy constructor
    deque(const deque& other) : capacity(other.capacity), front_idx(other.front_idx), size_(other.size_) {
        arr = new T[capacity];
        for (size_t i = 0; i < capacity; i++) {
            arr[i] = other.arr[i];
        }
    }
    
    // Assignment operator
    deque& operator=(const deque& other) {
        if (this != &other) {
            delete[] arr;
            capacity = other.capacity;
            front_idx = other.front_idx;
            size_ = other.size_;
            arr = new T[capacity];
            for (size_t i = 0; i < capacity; i++) {
                arr[i] = other.arr[i];
            }
        }
        return *this;
    }
    
    // Add element to front
    void push_front(const T& value) {
        if (size_ == capacity) {
            resize(capacity * 2);
        }
        
        front_idx = (front_idx == 0) ? capacity - 1 : front_idx - 1;
        arr[front_idx] = value;
        size_++;
    }
    
    // Add element to back
    void push_back(const T& value) {
        if (size_ == capacity) {
            resize(capacity * 2);
        }
        
        arr[(front_idx + size_) % capacity] = value;
        size_++;
    }
    
    // Remove element from front
    void pop_front() {
        if (empty()) {
            throw std::out_of_range("Deque is empty");
        }
        
        front_idx = (front_idx + 1) % capacity;
        size_--;
        
        if (size_ > 0 && size_ < capacity / 4) {
            resize(capacity / 2);
        }
    }
    
    // Remove element from back
    void pop_back() {
        if (empty()) {
            throw std::out_of_range("Deque is empty");
        }
        
        size_--;
        
        if (size_ > 0 && size_ < capacity / 4) {
            resize(capacity / 2);
        }
    }
    
    // Get front element
    T& front() {
        if (empty()) {
            throw std::out_of_range("Deque is empty");
        }
        return arr[front_idx];
    }
    
    // Get front element (const)
    const T& front() const {
        if (empty()) {
            throw std::out_of_range("Deque is empty");
        }
        return arr[front_idx];
    }
    
    // Get back element
    T& back() {
        if (empty()) {
            throw std::out_of_range("Deque is empty");
        }
        return arr[(front_idx + size_ - 1) % capacity];
    }
    
    // Get back element (const)
    const T& back() const {
        if (empty()) {
            throw std::out_of_range("Deque is empty");
        }
        return arr[(front_idx + size_ - 1) % capacity];
    }
    
    // Check if deque is empty
    bool empty() const {
        return size_ == 0;
    }
    
    // Get size of deque
    size_t size() const {
        return size_;
    }
    
    // Clear deque
    void clear() {
        size_ = 0;
        front_idx = capacity / 2;
    }
    
    // Access element at index
    T& operator[](size_t index) {
        if (index >= size_) {
            throw std::out_of_range("Index out of range");
        }
        return arr[(front_idx + index) % capacity];
    }
    
    // Access element at index (const)
    const T& operator[](size_t index) const {
        if (index >= size_) {
            throw std::out_of_range("Index out of range");
        }
        return arr[(front_idx + index) % capacity];
    }
};

int main() {
    int n;
    cin >> n;
    
    deque<string> names;
    vector<string> allnames;
    
    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        names.push_back(temp);
        allnames.push_back(temp);
    }
    
    string results;
    cin >> results;
    
    string w1, w2, b1, b2;
    w1 = names.front(); names.pop_front();
    b1 = names.front(); names.pop_front();
    w2 = names.front(); names.pop_front();
    b2 = names.front(); names.pop_front();
    
    unordered_map<string, vector<int>> timeplaying;
    for (auto i : allnames) {
        timeplaying[i] = {0};
    }
    
    vector<string> win1, win2;
    vector<int> winStreak;
    char prev = 'A';
    
    for (char i : results) {
        for (auto& name : allnames) {
            timeplaying[name].push_back(0);
        }
        
        timeplaying[w1].pop_back();
        timeplaying[w2].pop_back();
        timeplaying[b1].pop_back();
        timeplaying[b2].pop_back();
        
        timeplaying[w1].push_back(timeplaying[w1].back() + 1);
        timeplaying[w2].push_back(timeplaying[w2].back() + 1);
        timeplaying[b1].push_back(timeplaying[b1].back() + 1);
        timeplaying[b2].push_back(timeplaying[b2].back() + 1);
        
        int w = (i == prev) ? winStreak.back() + 1 : 1;
        
        if (i == 'W') {
            win1.push_back(w1);
            win2.push_back(w2);
            swap(w1, w2);
            names.push_back(b2);
            b2 = b1;
            b1 = names.front(); names.pop_front();
            prev = 'W';
        } else {
            win1.push_back(b1);
            win2.push_back(b2);
            swap(b1, b2);
            names.push_back(w2);
            w2 = w1;
            w1 = names.front(); names.pop_front();
            prev = 'B';
        }
        
        winStreak.push_back(w);
    }
    
    int best = 0;
    for (int streak : winStreak) {
        best = max(best, streak);
    }
    
    for (size_t i = 0; i < winStreak.size(); i++) {
        if (winStreak[i] == best) {
            string winner1 = win1[i - best + 1];
            string winner2 = win2[i - best + 1];
            int t1 = timeplaying[winner1][i];
            int t2 = timeplaying[winner2][i];
            if (t1 >= t2) {
                cout << winner1 << " " << winner2 << endl;
            } else {
                cout << winner2 << " " << winner1 << endl;
            }
        }
    }
    
    return 0;
}
