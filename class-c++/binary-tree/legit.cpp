#include <iostream>
#include <cstdlib>
#include <fstream>
#define INPUT_READ 20

using namespace std;

class BinarySearchTree
{
    private:
        struct tree_node
        {
           tree_node* left;
           tree_node* right;
           int data; // SSN
           float age; // age
           char name[20]; // name
           
        };
        tree_node* root;
    public:
        BinarySearchTree()
        {
           root = NULL;
        }
        bool isEmpty() const { return root==NULL; }
        void print_inorder();
        void inorder(tree_node*);
        void print_preorder();
        void preorder(tree_node*);
        void print_postorder();
        void postorder(tree_node*);
        void insert(int, float, char[20]);
        void insert2(int, float, char[20]);
        void insert3(int, float, char[20]);
        void remove(int);
};

// Smaller elements go left
// larger elements go right
void BinarySearchTree::insert(int d, float age, char name[20])
{
    tree_node* t = new tree_node;
    tree_node* parent;
    t->data = d;
    t->age = age;
    for(int i=0; i<20; i++) {
            t->name[i] = name[i];
    }
    t->left = NULL;
    t->right = NULL;
    parent = NULL;
  // is this a new tree?
  if(isEmpty()) root = t;
  else
  {
    //Note: ALL insertions are as leaf nodes
    tree_node* curr;
    curr = root;
    // Find the Node's parent
    while(curr)
    {
        parent = curr;
        if(t->data > curr->data) curr = curr->right;
        else curr = curr->left;
    }

    if(t->data < parent->data)
       parent->left = t;
    else
       parent->right = t;
  }
}

void BinarySearchTree::insert2(int d, float age, char name[20])
{
    tree_node* t = new tree_node;
    tree_node* parent;
    t->data = d;
    t->age = age;
    for(int i=0; i<20; i++) {
            t->name[i] = name[i];
    }
    t->left = NULL;
    t->right = NULL;
    parent = NULL;
  // is this a new tree?
  if(isEmpty()) root = t;
  else
  {
    //Note: ALL insertions are as leaf nodes
    tree_node* curr;
    curr = root;
    // Find the Node's parent
    while(curr)
    {
        parent = curr;
        if(t->age > curr->age) curr = curr->right;
        else curr = curr->left;
    }

    if(t->age < parent->age)
       parent->left = t;
    else
       parent->right = t;
  }
}

void BinarySearchTree::insert3(int d, float age, char name[20])
{
    tree_node* t = new tree_node;
    tree_node* parent;
    t->data = d;
    t->age = age;
    for(int i=0; i<20; i++) {
            t->name[i] = name[i];
    }
    t->left = NULL;
    t->right = NULL;
    parent = NULL;
  // is this a new tree?
  if(isEmpty()) root = t;
  else
  {
    //Note: ALL insertions are as leaf nodes
    tree_node* curr;
    curr = root;
    // Find the Node's parent
    while(curr)
    {
        parent = curr;
        if(t->name[0] > curr->name[0]) curr = curr->right;
        else curr = curr->left;
    }

    if(t->name[0] < parent->name[0])
       parent->left = t;
    else
       parent->right = t;
  }
}


void BinarySearchTree::remove(int d)
{
    //Locate the element
    bool found = false;
    if(isEmpty())
    {
        cout<<" This Tree is empty! "<<endl;
        return;
    }
    tree_node* curr;
    tree_node* parent;
    curr = root;
    while(curr != NULL)
    {
         if(curr->data == d)
         {
            found = true;
            break;
         }
         else
         {
             parent = curr;
             if(d>curr->data) curr = curr->right;
             else curr = curr->left;
         }
    }
    if(!found)
         {
        cout<<" Data not found! "<<endl;
        return;
    }


         // 3 cases :
    // 1. We're removing a leaf node
    // 2. We're removing a node with a single child
    // 3. we're removing a node with 2 children

    // Node with single child
    if((curr->left == NULL && curr->right != NULL)|| (curr->left != NULL
&& curr->right == NULL))
    {
       if(curr->left == NULL && curr->right != NULL)
       {
           if(parent->left == curr)
           {
             parent->left = curr->right;
             delete curr;
           }
           else
           {
             parent->right = curr->right;
             delete curr;
           }
       }
       else // left child present, no right child
       {
          if(parent->left == curr)
           {
             parent->left = curr->left;
             delete curr;
           }
           else
           {
             parent->right = curr->left;
             delete curr;
           }
       }
     return;
    }

         //We're looking at a leaf node
         if( curr->left == NULL && curr->right == NULL)
    {
        if(parent->left == curr) parent->left = NULL;
        else parent->right = NULL;
                  delete curr;
                  return;
    }


    //Node with 2 children
    // replace node with smallest value in right subtree
    if (curr->left != NULL && curr->right != NULL)
    {
        tree_node* chkr;
        chkr = curr->right;
        if((chkr->left == NULL) && (chkr->right == NULL))
        {
            curr = chkr;
            delete chkr;
            curr->right = NULL;
        }
        else // right child has children
        {
            //if the node's right child has a left child
            // Move all the way down left to locate smallest element

            if((curr->right)->left != NULL)
            {
                tree_node* lcurr;
                tree_node* lcurrp;
                lcurrp = curr->right;
                lcurr = (curr->right)->left;
                while(lcurr->left != NULL)
                {
                   lcurrp = lcurr;
                   lcurr = lcurr->left;
                }
                                    curr->data = lcurr->data;
                delete lcurr;
                lcurrp->left = NULL;
           }
           else
           {
               tree_node* tmp;
               tmp = curr->right;
               curr->data = tmp->data;
                              curr->right = tmp->right;
               delete tmp;
           }

        }
         return;
    }

}

void BinarySearchTree::print_inorder()
{
  inorder(root);
}

void BinarySearchTree::inorder(tree_node* p)
{
    if(p != NULL)
    {
        if(p->left) inorder(p->left);
        //cout<<" "<<p->data<<" ";
        cout << "\nName: " << p->name << "\nSSN: " << p->data << "\nAge: " << p->age;
        if(p->right) inorder(p->right);
    }
    else return;
}

void BinarySearchTree::print_preorder()
{
  preorder(root);
}

void BinarySearchTree::preorder(tree_node* p)
{
    if(p != NULL)
    {
        //cout<<" "<<p->data<<" ";
        cout << "\nName: " << p->name << "\nSSN: " << p->data << "\nAge: " << p->age;
        if(p->left) preorder(p->left);
        if(p->right) preorder(p->right);
    }
    else return;
}

void BinarySearchTree::print_postorder()
{
  postorder(root);
}

void BinarySearchTree::postorder(tree_node* p)
{
    if(p != NULL)
    {
        if(p->left) postorder(p->left);
        if(p->right) postorder(p->right);
        //cout<<" "<<p->data<<" ";
        cout << "\nName: " << p->name << "\nSSN: " << p->data << "\nAge: " << p->age;
    }
    else return;
}

void read_file(BinarySearchTree &t, int g)
{
char file1[INPUT_READ];
char nametemp[20];
int temp;        
float agetemp;                           
cout << "Enter the filename" << endl;
cin >> file1; 
ifstream input1(file1); 
if (input1.fail())     
       {
       cout << "Error: Could not find file" << endl;
                                                      
       system("PAUSE");
       exit(1);
       }
    for(int rows=0; rows<9; rows++)
    {
          input1 >> nametemp;
          input1 >> temp;
          input1 >> agetemp;
          switch(g) {
                    case 0:
                              t.insert(temp, agetemp, nametemp);
                              break;
                    case 1:
                              t.insert2(temp, agetemp, nametemp);
                              break;
                    case 2:
                              t.insert3(temp, agetemp, nametemp);
                              break;
          }
    }
}

int main()
{
    BinarySearchTree b, c, d;
    int ch,tmp,tmp1;
    int g=0;
    read_file(b,0);
    read_file(c,1);
    read_file(d,2);
    while(1)
    {
       cout<<endl<<endl;
       cout<<" Binary Search Tree Operations "<<endl;
       cout<<" ----------------------------- "<<endl;
       cout<<" 1. In-Order Traversal - SSN "<<endl;
       cout<<" 2. In-Order Traversal - Age "<<endl;
       cout<<" 3. In-Order Traversal - Name "<<endl;
       //cout<<" 4. Post-Order Traversal "<<endl;
       //cout<<" 5. Removal "<<endl;
       cout<<" 6. Exit "<<endl;
       cout<<" Enter your choice : ";
       cin>>ch;
       switch(ch)
       {
           case 1 : cout<<" In-Order Traversal - SSN "<<endl;
                    cout<<" -------------------"<<endl;
                    b.print_inorder();
                    //cin>>tmp;
                    //g++;
                    //read_file(b,g);
                    //b.read_file;
                    //b.insert(tmp);
                    //b.read_file;
                    break;
           case 2 : cout<<endl;
                    cout<<" In-Order Traversal - Age "<<endl;
                    cout<<" -------------------"<<endl;
                    c.print_inorder();
                    break;
           case 3 : cout<<endl;
                    cout<<" In-Order Traversal - Name "<<endl;
                    cout<<" -------------------"<<endl;
                    d.print_inorder();
                    break;
           case 4 : cout<<endl;
                    cout<<" Post-Order Traversal "<<endl;
                    cout<<" --------------------"<<endl;
                    b.print_postorder();
                    break;
           case 5 : cout<<" Enter data to be deleted : ";
                    cin>>tmp1;
                    b.remove(tmp1);
                    break;
           case 6 : system("pause");
                    return 0;
                    break;
       }
    }
}
