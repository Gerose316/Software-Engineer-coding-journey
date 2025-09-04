#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <stack>
#include <algorithm>




class Stack {
    private:
    // array to store stack elements
    int *array;
    // maximum number of elements stack can hold
    int length;
    // current number of elements in stack
    int top;
   // lecture and being used for the problem d and i dont even why it wont work
    public:
    Stack(int);
    ~Stack();
    // pushes an element onto the stack
    void push(int);
    // returns/removes the top element from the stack
    int pop();
    int lengthD();
    bool empty();
    int pairingSocks(int);
    int peek();
    void bracketDeleter(std::string);
    
    

    
   };
  

   int Stack::peek(){
       return array[top - 1];
   }

   int Stack::lengthD(){
       return top;
   }

   bool Stack::empty(){
       return top == 0;
   }

   Stack::Stack(int len) {
    length = len;
    array = new int[length];
    top = 0;
   }

   Stack::~Stack() {
    delete [] array;
   }
   void Stack::push(int value) {
    if (top == length) {
    throw std::out_of_range("Stack is full");
    } else {
    array[top] = value;
    top ++;
    }
   }
   int Stack::pop() {
    if (top == 0) {
    throw std::out_of_range("Stack is empty");
    } else {
    top --;
    return array[top];
    }

   }

   void Stack::bracketDeleter(std::string equation){
        Stack s(equation.length());
        std::vector<std::string> Parcy;

        std::vector<std::pair<int, int>> start;

        for(int i = 0; i < equation.length(); i++){
            if(equation[i] == '('){
                s.push(i);
            }else if(equation[i] == ')'){
                if(!s.empty()){
                    start.push_back({s.peek(), i});
                    s.pop();
                }
            }
        }
        int interval = start.size();
        int subsets = (1 << interval);


        for (int mask = 1; mask < subsets; mask++) {
            std::string vv = equation;
            std::vector<bool> carsei(equation.length(), false);
    
            for (int j = 0; j < interval; j++) {
                if (mask & (1 << j)) {
                    carsei[start[j].first] = true;
                    carsei[start[j].second] = true;
                }
            }
    
            std::string colc;
            for (int i = 0; i < vv.length(); i++) {
                if (!carsei[i]) {
                    colc += vv[i];
                }
            }
    
            if (std::find(Parcy.begin(), Parcy.end(), colc) == Parcy.end()) {
                Parcy.push_back(colc);
            }
        }








        














    std::sort(Parcy.begin(), Parcy.end());
    for(int i = 0; i < Parcy.size(); i++){
        std::cout << Parcy[i] << std::endl;
    }

}
   int main(){
    std::string equation;
    std::cin >> equation;
    Stack s(equation.length());
    s.bracketDeleter(equation);
    return 0;
   }
