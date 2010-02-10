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
      Matrix (void ){          // Constructor
             cout<< "Enter X:\n";
             cin >> x;
             cout<< "Enter Y:\n";
             cin >> y;
             mat= new float[x*y];
      }
      Matrix (int a1, int a2 ){          // Constructor
             x = a1;
             y = a2;
             mat= new float[a1*a2];
      }
      friend Matrix operator+(const Matrix&,const Matrix&);
      friend Matrix operator*(const Matrix&,const Matrix&);

      Matrix& Matrix::operator=(const Matrix& source);
      Matrix(const Matrix& m);
      float getmat(int i, int j){
            return mat[i*x + j];
      }
       void putmat (int i, int j, float val){
             mat[i*x+j]= val;
       }
       int getsize(void) {
           return x*y;
       }
       int getx(void) {
           return x;
       }
       int gety(void) {
           return y;
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
          
            for(int i=0; i<x; i++){
                for(int j=0; j<y; j++) {
                        m = i*y + j;
                        //cout << m;
                        input1>> mat[m];
                        //cout << mat[m];
                }

            }
       }
          
       void printmat(void){
             for(int i=0; i<x; i++) {
                     for(int j=0; j<y; j++) {
                             cout << mat[i*y+j] << " ";
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
            for(int i=0; i<x; i++){
                for(int j=0; j<y; j++) {
                        m = i*y+j;
                        output << mat [m] << " ";
                  
                }
                output << "\n";
            }
            cout << "\nSaved\n\n";  
       }
       ~Matrix() {
            delete [] mat;
       }
       /*void add(Matrix mata, Matrix matb) {
            for(int i=0; i<x; i++) {
                    for(int j=0; j < mata.getx(); j++){
                            //cout << mat[i*size+j] << "\n";
                            //cout << mata.getmat(i,j) << "\n";
                            float thingy = mat[i*x+j] + mata.getmat(i,j);
                            //cout << thingy << "\n";
                            matb.putmat(i, j, thingy);
                    }
            }
       }*/
       /*void mul(Matrix mata, Matrix matb) {
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
       }*/
                
     

 private:     
      float *mat;
      int x, y;  
 
} ;

Matrix operator + (const Matrix& A,const Matrix& B)
{
        if(A.x != B.x || A.y != B.y) {
               cout << "Matrices are different sizes. Using B as the size of A.\n";
        }
        Matrix C(A.x, A.y);
        for(int r=0;r<A.x;r++){
                for(int c=0;c<A.y;c++) {
                        C.mat[r*A.y + c] = A.mat[r*A.y+c]+B.mat[r*B.y+c];

                }
        }
        return C;
}
Matrix operator * (const Matrix& A, const Matrix& B){
        if(A.y != B.x) {
               cout << "Incorrect matrix sizes. Trying something anyway.\n";
        }
        Matrix C(A.x, B.y);
        float sum=0;
        int m,n,o;
        for (int i=0;i<A.x;i++)
        {
            for (int j=0;j<B.y;j++)
            {
                sum = 0;
                for (int k=0;k<A.y;k++) {
                    n = i*A.y + k;
                    o = k*B.y + j;
                    sum=sum+(A.mat[n]*B.mat[o]);
                }
                m = i*B.y + j;
                C.mat[m] = sum;
                //cout << sum << " ";
            }
            //cout << "\n";
        }
        return C;
}

Matrix& Matrix::operator = (const Matrix& source) {
        for(int i=0; i<x*y; i++)
                mat[i] = source.mat[i];
        return (*this);
}

Matrix::Matrix(const Matrix& m){
     mat = new float[x*y];
     x = m.x;
     y = m.y;
     for (int i=0; i<x*y; ++i) {
         mat[i] = m.mat[i];
     }
}






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
 
 
   Matrix matc(mata.getx(), mata.gety());
 
   matc = mata + matb;
 
   matc.printmat();
   matc.writemat();
 
   Matrix matd(mata.getx(), matb.gety());
 
   matd = mata * matb;
 
   matd.printmat();
   matd.writemat();
 
 
    system("PAUSE");
    return EXIT_SUCCESS;
}
