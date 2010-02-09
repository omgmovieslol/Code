#include <iostream>
#include <cstring>   
using namespace std;
class Matrix       
{

 public:       
      Matrix ( ){          // Constructor
             cout<< "enter size of matrix/n";
             cin >> size;
             float *mat= new[size*size];
             }
      float getmat(int i, int j){
            float val;
            int m;
            m= i*size*j; 
            val=mat[m];
            return val;
            }
       float putmat (int i, int j, float val){
             int m;
             m= i*size*j;
             mat[m]= val;
             }

 private:       
      float *mat;
      int size;    
   
} ; 


int main()
{
   int i,j;
   float value;
   Matrix mata(); 
   
   
    system("PAUSE");
    return EXIT_SUCCESS;
}
