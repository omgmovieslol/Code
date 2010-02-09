
#include <iostream>
	
const int WIDTH = 5;  //Print field size
using namespace std;

const int MAXSIZE = 100;     
	
class Queue
{
	   
public:
   Queue ();
	      
   void push           (int n);     
   void pop            ();          
   int  getFirstInLine ();           
   bool isEmpty        ();
   
private:
   int size;                   //Queue length
   int line [MAXSIZE];
};

	
Queue::Queue ()
{
    size = 0;
}
	   
void Queue::push (int n)
{
   if (size < MAXSIZE)
   {
        line [size] = n;
        size++;
   }
}
	   
void Queue::pop ()
{   
    if (size > 0)
    {     
	
       for (int n = 0; n < size - 1; n++)
          line [n] = line [n + 1];
             
       size--;
    }
}

int Queue::getFirstInLine ()
{
    
    int temp = 0; 
    
    if (size > 0)
       temp = line [0];
       
    return temp;
}

bool Queue::isEmpty ()
{
   return size == 0;
}
     	   



int main() {
    Queue q;
    
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    
    while(!q.isEmpty()) {
        cout << q.getFirstInLine() << "\n";
        q.pop();
    }
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
