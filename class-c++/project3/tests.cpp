#include <iostream>
#include <cstring> 
#include <fstream>
#include <stack>


#define input_read 20
  
using namespace std;


int main() {
    stack<char> stackObject;

    stackObject.push('A');
    stackObject.push('B');
    stackObject.push('C');
    stackObject.push('D');

    while(!stackObject.empty()) {
      cout << "Popping: ";
      cout << stackObject.top() << endl;
      stackObject.pop();
    }
    
    system("PAUSE");
    return EXIT_SUCCESS;
    
}

