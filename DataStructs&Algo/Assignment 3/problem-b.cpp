// class implementing a Stack of integers
#include <iostream>
#include <string>
#include <stdexcept>
#include <stack>


// fixed-length array (not a dynamic array)
class Stack {
    private:
    // array to store stack elements
    char* array;
    // maximum number of elements stack can hold
    size_t length;
    // current number of elements in stack
    size_t top;

    int *index;
   
   
    public:
    Stack(int);
    ~Stack();
    // pushes an element onto the stack
    void push(char val, int pos);
    // returns/removes the top element from the stack
    char pop(int &pos);

    bool ismatchingPair(char open, char close);
    void isBalanced(std::string,int);
    
    




   };

 
   Stack::Stack(int len) {
    length = len;
    array = new char[length];
    index = new int[length];
    top = 0;
   }

   Stack::~Stack() {
    delete [] array;
    delete[] index;

   }

   void Stack::push(char val,int pos ) {
   if (top < length - 1) {
         array[++top] = val;
         index[top] = pos;

    }
   }



   bool Stack::ismatchingPair(char open, char close){
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');

   }

char Stack::pop(int &pos) {
  if (top >= 0) {
        pos = index[top];
        return array[top--];
    }
    return '0';
   }



void Stack::isBalanced(std::string str, int valued){
    Stack s(valued);
    for(int i = 0; i < valued; i++){
        char trs = str[i];
        if (trs == ' ' ){
            continue;
        }else{
            if( trs == '(' || trs == '{' || trs == '['){
                s.push(trs,i);
            }else if (trs == ')' || trs == '}' || trs == ']'){
                int shock;
                char top = s.pop(shock);
                if(top == '0' || !ismatchingPair(top, trs)){
                    std::cout << trs << " " << i << std::endl;
                    return;
                }
            }
        }
    }

std::cout << "ok so far" << std::endl;
}

int main () {
    std::string str;
    int valued;
    std::cin >> valued;
    std::cin.ignore();
    std::getline(std::cin,str);

    Stack myStack(str.length());
    myStack.isBalanced(str,str.length());
    

    return 0;
}


    
