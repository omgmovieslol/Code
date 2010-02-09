// James Wilson
// Project 1

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

#define input_read 20

using namespace std;

// fills matrix
void fillmat(float a[], int x, int y) {
     char file1[input_read];
     cout<<"Enter the file name"<< endl;
    cin>> file1;
    ifstream input1(file1);
    if (input1.fail()){
       cout<< "error: could not find file"<< endl;
       system("PAUSE");
    exit(1);
    }
    
    int m;
    
    for(int i=0; i<x; i++){
        for(int j=0; j<y; j++) {
                m = i*y + j;
                input1>> a[m];
                //cout<< a [i][j] << " ";
                //output<< filecontents [i][j] << " ";
            
        }
        //cout << "\n";
        //output << "\n";
    }
}

// outputs matrix
void outmat(float a[], int x, int y) {
   int m;
   for(int i=0; i<x; i++){
        for(int j=0; j<y; j++) {
                m = i*y + j;
                //input1>> a[i][j];
                cout<< a [m] << " ";
                //output << a [i][j] << " ";
            
        }
        cout << "\n";
        //output << "\n";
    } 
    cout << "\n\n"; 
}

// writes matrix
void writemat(float a[], int x, int y) {
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
                //input1>> a[i][j];
                //cout<< a [i][j] << " ";
                output << a [m] << " ";
            
        }
        //cout << "\n";
        output << "\n";
    } 
    cout << "\nSaved\n\n"; 
}

// adds matrix
/*void addmat(float a[], float b[], float c[], int x, int y, int x1, int x2) {
     int m;
     for(int i=0; i<x; i++) {
         for(int j=0; j<x1; j++) {
                 m = i*size + j;
                c[m] = a[m] + b[m];
                //cout<< outs[i][j] << " ";
                //output << outs[i][j] << " ";
         }
         //cout << "\n";
         //output << "\n";
    }
}*/

// multiplies matrix
void mulmat(float a[], float b[], float c[], int x, int y, int z) {
     float sum=0;
     int m,n,o;
    for (int i=0;i<x;i++)
    {
        for (int j=0;j<z;j++)
        {
            for (int k=0;k<y;k++) {
                n = i*y + k;
                o = k*z + j;
                sum=sum+(a[n]*b[o]);
            }
            m = i*z + j;
            c[m]=sum;
            sum=0;
        }
    }
}

// main
int main() {
// 3 x 4. 4  x 5
    //float mata[40], matb[40], amat[40], mmat[40];
    int size, x, y, z;
    cout << "Enter X: ";
    cin >> x;
    cout << "Enter Y: ";
    cin >> y;
    cout << "Enter Z: ";
    cin >> z;
    float* mata = new float[x*y];
    float* matb = new float[y*z];
    //float* amat = new float[size*size];
    float* mmat = new float[x*z];
    
    
    fillmat(mata, x, y);
    outmat(mata, x, y);
    
    fillmat(matb, y, z);
    outmat(matb, y, z);
    
    //addmat(mata, matb, amat, size);
    //outmat(amat, size);
    //writemat(amat, size);
    
    mulmat(mata, matb, mmat, x, y, z);
    outmat(mmat, x, z);
    writemat(mmat, x, z);
    
    system("PAUSE");
    return EXIT_SUCCESS;
    
}   
