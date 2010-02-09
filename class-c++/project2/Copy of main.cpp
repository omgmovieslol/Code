#include <iostream>
#include <cstring> 
#include <fstream>


#define input_read 20
  
using namespace std;
class Matrix       
{
 //  float *mat;
  // int size; 
 public:       
      Matrix ( ){          // Constructor
             cout<< "enter size of matrix\n";
             cin >> size;
             mat= new float[size*size];
      }
      float getmat(int i, int j){
            return mat[i*size + j];
      }
       void putmat (int i, int j, float val){
             mat[i*size+j]= val;
       }
       int getsize(void) {
           return size;
       }
       void buildmat( void){
            char file1[input_read];
            cout<<"Enter the file name"<< endl;
            cin>> file1;
            ifstream input1(file1);
            if (input1.fail()){
               cout<< "error: could not find file"<< endl;
               system("PAUSE");
            exit(1);
            }
            
            //cout << size;
            
            int m;
            
            for(int i=0; i<size; i++){
                for(int j=0; j<size; j++) {
                        m = i*size + j;
                        //cout << m;
                        input1>> mat[m];
                        //cout << mat[m];
                }

            }
       }
            
       void printmat(void){
             for(int i=0; i<size; i++) {
                     for(int j=0; j<size; j++) {
                             cout << mat[i*size+j] << " ";
                     }
                     cout << "\n";
             }
             cout << "\n\n";
       }
       
       void writemat(void) {
            int m;
            char fileout[input_read];
            cout<<"Enter the file name to save the output"<< endl;
            cin>> fileout;
            ofstream output(fileout, ofstream::out);
            if (output.fail()){
               cout<< "error: could not output file"<< endl;
               system("PAUSE");
            exit(1);
            }
            for(int i=0; i<size; i++){
                for(int j=0; j<size; j++) {
                        m = i*size+j;
                        //input1>> a[i][j];
                        //cout<< a [i][j] << " ";
                        output << mat [m] << " ";
                    
                }
                //cout << "\n";
                output << "\n";
            } 
            cout << "\nSaved\n\n";    
            }
       void add(Matrix mata, Matrix matb) {
            //cout << mata.getsize() << "\n\n\n";
            for(int i=0; i<size; i++) {
                    for(int j=0; j < mata.getsize(); j++){
                            //cout << mat[i*size+j] << "\n";
                            //cout << mata.getmat(i,j) << "\n";
                            float thingy = mat[i*size+j] + mata.getmat(i,j);
                            //cout << thingy << "\n";
                            matb.putmat(i, j, thingy);
                    }
            }
       }
       void mul(Matrix mata, Matrix matb) {
            float sum=0;
            int m,n,o;
            for (int i=0;i<size;i++)
            {
                for (int j=0;j<size;j++)
                {
                    for (int k=0;k<size;k++) {
                        n = i*size + k;
                        o = k*size + j;
                        sum=sum+(mat[n]*mata.getmat(k,j));
                    }
                    m = i*size + j;
                    matb.putmat(i,j,sum);
                    sum=0;
                }
            }
       }
                  
       

 private:       
      float *mat;
      int size;    
   
} ;








int main()
{
   int i,j;
   float value;
   
   Matrix mata; 
   mata.buildmat();
   mata.printmat();
   
   Matrix matb;
   matb.buildmat();
   matb.printmat();
   
   Matrix matc;
   Matrix matd;
   
   mata.add(matb, matc);
   //mata.mul(matb, matd);
   matc.writemat();
   matc.printmat();
   
   mata.mul(matb, matd);
   matd.writemat();
   matd.printmat();
   
   
    system("PAUSE");
    return EXIT_SUCCESS;
}
