#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

#define input_read 20

using namespace std;

// fills matrix
void fillmat(int a[][4]) {
     char file1[input_read];
     cout<<"Enter the file name"<< endl;
    cin>> file1;
    ifstream input1(file1);
    if (input1.fail()){
       cout<< "error: could not find file"<< endl;
       system("PAUSE");
    exit(1);
    }
    
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++) {
            
                input1>> a[i][j];
                //cout<< a [i][j] << " ";
                //output<< filecontents [i][j] << " ";
            
        }
        //cout << "\n";
        //output << "\n";
    }
}

// outputs matrix
void outmat(int a[][4]) {
   for(int i=0; i<4; i++){
        for(int j=0; j<4; j++) {
            
                //input1>> a[i][j];
                cout<< a [i][j] << " ";
                //output << a [i][j] << " ";
            
        }
        cout << "\n";
        //output << "\n";
    } 
    cout << "\n\n"; 
}

// writes matrix
void writemat(int a[][4]) {
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
            
                //input1>> a[i][j];
                //cout<< a [i][j] << " ";
                output << a [i][j] << " ";
            
        }
        //cout << "\n";
        output << "\n";
    } 
    cout << "\nSaved\n\n"; 
}

// adds matrix
void addmat(int a[][4], int b[][4], int c[][4]) {
     for(int i=0; i<4; i++) {
         for(int j=0; j<4; j++) {
                c[i][j] = a[i][j] + b[i][j];
                //cout<< outs[i][j] << " ";
                //output << outs[i][j] << " ";
         }
         //cout << "\n";
         //output << "\n";
    }
}

// multiplies matrix
void mulmat(int a[][4], int b[][4], int c[][4]) {
     int sum=0;
    for (int i=0;i<4;i++)
    {
        for (int j=0;j<4;j++)
        {
            for (int k=0;k<4;k++)
	            sum=sum+(a[i][k]*b[k][j]);
            c[i][j]=sum;
            sum=0;
        }
    }
}

// main
int main() {

    int mata[4][4], matb[4][4], amat[4][4], mmat[4][4];
    
    fillmat(mata);
    outmat(mata);
    
    fillmat(matb);
    outmat(matb);
    
    addmat(mata, matb, amat);
    outmat(amat);
    writemat(amat);
    
    mulmat(mata, matb, mmat);
    outmat(mmat);
    writemat(mmat);
    
    system("PAUSE");
    return EXIT_SUCCESS;
    
}   
