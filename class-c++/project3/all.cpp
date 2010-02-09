#include <iostream>
#include <cstring> 
#include <fstream>
#include <stack>
#include <queue>

#define input_read 20
  
using namespace std;


int main() {
    stack<char> stackObject;

    stackObject.push('A');
    stackObject.push('B');
    stackObject.push('C');
    stackObject.push('D');
    stackObject.push('E');
    stackObject.push('F');
    stackObject.push('G');
    stackObject.push('H');

    cout << "Stack:\n";
    while(!stackObject.empty()) {
      cout << "Popping: ";
      cout << stackObject.top() << endl;
      stackObject.pop();
    }
    
     queue<char> queueObject;

    queueObject.push('A');
    queueObject.push('B');
    queueObject.push('C');
    queueObject.push('D');
    queueObject.push('E');
    queueObject.push('F');
    queueObject.push('G');
    queueObject.push('H');
    
    cout << "Queue:\n";
    while(!queueObject.empty()) {
      cout << "Pulling: ";
      cout << queueObject.front() << endl;
      queueObject.pop();
    }
    
    system("PAUSE");
    return EXIT_SUCCESS;
    
}

