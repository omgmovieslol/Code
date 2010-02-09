#include <iostream>
#include <cstdlib>

using namespace std;
//---------------------------//
struct node
{ 
   char name[20];
   int age;
   int ssn;
   node *nxt;
   node *prev;
   node *left;
};


//---------------------------//
class tree {
    private:
        node *start_ptr;
    public:
    //-----------------------------//
    tree (void) {
         start_ptr=NULL;
    }
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
          cout<<temp1->ssn<<" \n";;
          start_ptr=temp1->nxt;
        }
    }
    //-----------------------------//
    void push ()
    {
        node *temp;
        
        node *temp2;
    
        temp = new node;
        cout << "Please enter the name of the person: \n";
        cin >> temp->name;
        cout << "Please enter the age of the person: \n";
        cin >> temp->age;
        cout << "Please enter the ssn of the person: \n";
        cin >> temp->ssn;
        if (start_ptr == NULL)
        {
           temp->nxt=NULL;
           temp->prev=NULL;
           temp->left=NULL;
           start_ptr = temp;
        }
        else
        {
           temp2 = place(start_ptr, temp->age);
           /*temp->prev=start_ptr;
           if(start_ptr->age > temp->age) {
               start_ptr->left = temp;
           } else {
               start_prt->right = temp;
           }
           start_ptr=temp;*/
        }
    }
    node place(node temp, int age) {
         if(temp==NULL) 
             return NULL;
         if(temp->age > age) {
             if(place(temp->nxt, age) == NULL)
                 return temp;
         } else {
             if(place(temp->prev, age))
                 return temp;
         }
    }
    
};
int main()
{
   void push ();
   void pop();
   char ch;
   cout<<"-----STACK-----\n";
   do
   {
      cout<<"Type in P, P2 or E for the operation to be done.\n";
      cout<<"P-Push\n";
      cout<<"O-Pop\n";
      cout<<"E-Exit\n";
     
      cin>>ch;
      tree t;
      
      switch(ch)
      {
         case 'P':
         t.push();
         break;
   
         case 'O':
         t.pop();
         break;
   
         case 'E':
         exit(0);
      }
    }
   while(ch!='E');

  
   system("PAUSE");
   return EXIT_SUCCESS;
}

