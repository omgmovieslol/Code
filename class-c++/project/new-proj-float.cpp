#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

#define input_read 20

using namespace std;

// fills matrix
void fillmat(float a[], int size) {
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
    
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++) {
                m = i*size + j;
                input1>> a[m];
                //cout<< a [i][j] << " ";
                //output<< filecontents [i][j] << " ";
            
        }
        //cout << "\n";
        //output << "\n";
    }
}

// outputs matrix
void outmat(float a[], int size) {
   int m;
   for(int i=0; i<4; i++){
        for(int j=0; j<4; j++) {
                m = i*size + j;
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
void writemat(float a[], int size) {
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
   for(int i=0; i<4; i++){
        for(int j=0; j<4; j++) {
                m = i*size+j;
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
void addmat(float a[], float b[], float c[], int size) {
     int m;
     for(int i=0; i<4; i++) {
         for(int j=0; j<4; j++) {
                 m = i*size + j;
                c[m] = a[m] + b[m];
                //cout<< outs[i][j] << " ";
                //output << outs[i][j] << " ";
         }
         //cout << "\n";
         //output << "\n";
    }
}

// multiplies matrix
void mulmat(float a[], float b[], float c[], int size) {
     float sum=0;
     int m,n,o;
    for (int i=0;i<4;i++)
    {
        for (int j=0;j<4;j++)
        {
            for (int k=0;k<4;k++) {
                n = i*size + k;
                o = k*size + j;
                sum=sum+(a[n]*b[o]);
            }
            m = i*size + j;
            c[m]=sum;
            sum=0;
        }
    }
}

// main
int main() {

    //float mata[40], matb[40], amat[40], mmat[40];
    int size = 4;
    float* mata = new float[size*size];
    float* matb = new float[size*size];
    float* amat = new float[size*size];
    float* mmat = new float[size*size];
    
    
    fillmat(mata, size);
    outmat(mata, size);
    
    fillmat(matb, size);
    outmat(matb, size);
    
    addmat(mata, matb, amat, size);
    outmat(amat, size);
    writemat(amat, size);
    
    mulmat(mata, matb, mmat, size);
    outmat(mmat, size);
    writemat(mmat, size);
    
    system("PAUSE");
    return EXIT_SUCCESS;
    
}   
