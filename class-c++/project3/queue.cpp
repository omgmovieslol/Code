#include <iostream>
#include <cstring> 
#include <fstream>
#include <queue>


#define input_read 20
  
using namespace std;


int main() {
    queue<char> queueObject;

    queueObject.push('A');
    queueObject.push('B');
    queueObject.push('C');
    queueObject.push('D');

    while(!queueObject.empty()) {
      cout << "Popping: ";
      cout << queueObject.front() << endl;
      queueObject.pop();
    }
    
    system("PAUSE");
    return EXIT_SUCCESS;
    
}

