#include <iostream>
#include <cstring> 
#include <fstream>


#define input_read 20
  
using namespace std;

class Stack{
      
      public:
           Stack(void) {
                  top = 0;
           }
           int isEmpty(void) {
               return !top>0;
           }
           void push(int x) {
                top++;
                data[top] = x;
                //cout << data[top];
           }
           int pop(void) {
               //top;
               
               //return data[top];
               
               int q = data[top];
               top--;
               return q;
           }
          /* void push(int x)(
               data[++top] = x;
           }*/
    private:
              int data[100];
              int top;
};


int main() {
    
    Stack s;
    
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    
    while(!s.isEmpty()) {
        cout << s.pop() << "\nIlove Boys\n";
    }
    
    system("PAUSE");
    return EXIT_SUCCESS;
    
}

