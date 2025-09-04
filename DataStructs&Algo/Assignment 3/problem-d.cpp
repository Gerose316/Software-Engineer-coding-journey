#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>



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
    void Circuit(std::vector<int>);
    int lengthD();
    bool empty();

    
   };

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

   void Stack::Circuit(std::vector<int> vec){
       
        int len = vec.size();

        for(int i = 0; i < len; i++){
            if(!empty() && (array[top - 1] + vec[i]) % 2 == 0){
                pop();
            }else{
                push(vec[i]);
            }
            
        
        }
        std::cout << lengthD() << std::endl;

        
    }
      

   int main(){
        int len;
        std::cin >> len;
        std::vector<int> vec(len);


        for(int i = 0; i < len; i++){
            std::cin >> vec[i];
        }
        Stack s(len);
        s.Circuit(vec);

        
}
