#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

using namespace std;

const int MAXSIZE = 100;         //Maximum size of the queue.
	
class Queue
{
friend ostream& operator<< (ostream&, Queue&);
	   
public:
   Queue ();
	      
   void push           (int n);      //Add person to the queue
   void pop            ();           //Remove person from beginning of queue
   int  getFirstInLine ();           //Get a copy of the first person in line
   bool isEmpty        ();
   
private:
   int size;                   //Queue length
   int line [MAXSIZE];
};
	  
#endif

