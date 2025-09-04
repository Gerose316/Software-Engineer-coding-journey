#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <deque>
#include <algorithm>






class Stack {
    private:
    // array to store stack elements
    bool *array;
    // maximum number of elements stack can hold
    int length;
    // current number of elements in stack
    int top;
   
    public:
    Stack(int);
    ~Stack();
    // pushes an element onto the stack
    void push(bool);
    // returns/removes the top element from the stack
    bool pop();
    void Circuit(int);
    bool isempty(){
        return top == 0;
    }
   };

   


   Stack::Stack(int len) {
    length = len;
    array = new bool[length];
    top = 0;
   }

   Stack::~Stack() {
    delete [] array;
   }
   void Stack::push(bool value) {
    if (top == length) {
    throw std::out_of_range("Stack is full");
    } 
    array[top++] = value;
   
    
   }
   bool Stack::pop() {
    if (top == 0) {
        throw std::out_of_range("Stack is empty");
    } 
        return array[--top];
    
}

void Stack::Circuit(int n){
    std::vector<bool> shark(n);
    char TorF;




    for (int i = 0; i < n; i++) {
        std::cin >> TorF;
        shark[i] = (TorF == 'T');
   }
   Stack stackeR(200);
   std::string macker;
  
   
   while(std::cin >> macker){
    if (macker.empty()) {
        break; 
    }
    if(isalpha(macker[0])){
        int index = macker[0] - 'A';
        if(index >= 0 && index < n) {
            stackeR.push(shark[index]);
        }

    }else if(macker == "*"){
            bool b = stackeR.pop();
            bool a = stackeR.pop();
            stackeR.push(a && b);
        }else if(macker == "+"){
            bool b = stackeR.pop();
            bool a = stackeR.pop();
            stackeR.push(a || b);
        }else if(macker == "-"){
            bool a = stackeR.pop();
            stackeR.push(!a);
        }


   }





   std::cout << (stackeR.pop() ? "T" : "F") << "\n";

}


   

   int main(){
    int n;
    std::cin >> n;
    Stack s(n);
    s.Circuit(n);
    return 0;
   }