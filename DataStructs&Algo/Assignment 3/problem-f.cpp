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
    int lengthD();
    bool empty();
    int pairingSocks(int);
    int peek();

    
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





   int Stack::pairingSocks(int len){
        
         int count = 0;
      std::vector<int> original(len);

         for(int i = 0; i < len; i++){
               std::cin >> original[i];
         }
        Stack aux(len);

         
         

            for(int i = 0; i < len; i++){
                if(!aux.empty() && aux.peek() == original[i]){
                    aux.pop();
            }else{
                aux.push(original[i]);
            }
            count++;

        }

        if(!aux.empty()){
            std::cout << "impossible" << std::endl;
            return 0;
        }else{

            std::cout << count << std::endl;
            return 0;
        }
            

        }
    

   int main(){
        int h;
        std::cin >> h;
        h = h * 2;
        Stack s(h);
        s.pairingSocks(h);
        return 0;

      
        
   }

