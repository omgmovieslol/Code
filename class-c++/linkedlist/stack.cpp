#include <iostream>
#include <cstdlib>

using namespace std;
//---------------------------//
struct node
{ 
   char name[20];
   int age;
   float height;
   node *nxt;
   node *prev;
   node *left;
};

node *start_ptr=NULL;
//---------------------------//
int main()
{
   void push ();
   void pop();
   char ch;
   //clrscr();
   cout<<"-----STACK-----\n";
   //cout<<"-----";
   do
   {
      cout<<"Type in P, P2 or E for the operation to be done.\n";
      cout<<"P-Push\n";
      cout<<"O-Pop\n";
      cout<<"E-Exit\n";
     
      cin>>ch;

      switch(ch)
      {
         case 'P':
         push();
         break;
   
         case 'O':
         pop();
         break;
   
         case 'E':
         exit(0);
      }
    }
   while(ch!='E');
   //return 0;

  
   system("PAUSE");
   return EXIT_SUCCESS;
}
//-----------------------------//
void pop()
{
   node *temp1,*temp2;
  
   if(start_ptr==NULL)
   cout<<"The list is empty\n";
 
   else
   {
      temp1=start_ptr;
      cout<<temp1->name<<", ";
         cout<<temp1->age<<", ";
         cout<<temp1->height<<" \n";;
         start_ptr=temp1->nxt;
    }
}
//-----------------------------//
void push ()
{
    node *temp;

    temp = new node;
    cout << "Please enter the name of the person: \n";
    cin >> temp->name;
    cout << "Please enter the age of the person: \n";
    cin >> temp->age;
    cout << "Please enter the height of the person: \n";
    cin >> temp->height;
    if (start_ptr == NULL)
    {
       temp->nxt=NULL;
       start_ptr = temp;
    }
    else
    {
       temp->nxt=start_ptr;
       start_ptr=temp;
    }
}
