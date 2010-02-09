#include <iostream>
#include <cstring> 
#include <fstream>


#define input_read 20
  
using namespace std;

class stack{
      private:
              int data[100];
              int top;
      public:
           stack(void) {
                  top = 0;
           }
           int isEmpty(void) {
               return top;
           }
    
           int pop(void) {
               //assert(top > 0);
               return data[top--];
           }
    
           int push(int x)(
               data[++top] = x;
           }
};

class queue{
      private:
              int data[100];
              int top, bottom, count;
      public:
           queue() {
                  top = 0;
                  bottom = 0;
                  count = 0;
           }
           int isEmpty(void) {
               return top;
           }
    
           int pull(void) {
               assert(count > 0);
               count--;
               return data[bottom++];
           }
           int push(int x)(
               data[++top] = x;
           }
      
};

int main() {
    
    system("PAUSE");
    return EXIT_SUCCESS;
    
}

