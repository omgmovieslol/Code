#include <cstdlib>
#include <iostream>
#include <fstream>

#include <string>

#define input_read 20

void multmat(int a[][4], int b[][4], int c[][4]) {
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

void addmatr(int a[][4], int b[][4], int c[][4]) {
     for(int i=0; i<4; i++) {
         for(int j=0; j<4; j++) {
                c[i][j] = a[i][j] + b[i][j];
               // cout<< c[i][j] << " ";
                //output << outs[i][j] << " ";
         }
//         cout << "\n";
//         output << "\n";
    }
}

void outputmatr(int a[][4], ofstream out) {
      for(int i=0; i<4; i++) {
         for(int j=0; j<4; j++) {
                //outs[i][j] = filecontents[i][j] + filecontents2[i][j];
                cout<< c[i][j] << " ";
                out << c[i][j] << " ";
         }
//         cout << "\n";
//         out << "\n";
    }
}

void readmatr(int a[][4], ifstream in) {
   for(int i=0; i<4; i++){
        for(int j=0; j<4; j++) {
            
                in >> filecontents[i][j];
                cout << filecontents [i][j] << " ";
                //output<< filecontents [i][j] << " ";
            
        }
//        cout << "\n";
        //output << "\n";
    }   
}  

using namespace std;
int main()
{
    int n;
    char file1[input_read];
    
    char file2[input_read];
    
    cout<<"Enter the file name"<< endl;
    cin>> file1;
    
    cout<<"Enter the other file name"<< endl;
    cin>> file2;
    
    char fileout[input_read];
    char file2out[input_read];
    cout<<"Enter the file name to save the output"<< endl;
    cin>> fileout;
    
    cout<<"Enter the file name to save the second output"<< endl;
    cin>> file2out;
    
    ifstream input1(file1);
    if (input1.fail()){
       cout<< "error: could not find file"<< endl;
       system("PAUSE");
    exit(1);
    }
    
    ifstream input2(file2);
    if (input2.fail()){
       cout<< "error: could not find file"<< endl;
       system("PAUSE");
    exit(1);
    }
    
    ofstream output(fileout, ofstream::out);
    if (output.fail()){
       cout<< "error: could not output file"<< endl;
       system("PAUSE");
    exit(1);
    }
    
    ofstream output2(file2out, ofstream::out);
    if (output2.fail()){
       cout<< "error: could not output file"<< endl;
       system("PAUSE");
    exit(1);
    }
    
    int filecontents[4][4];
    inputmatr(filecontents, input1);
    
    cout << "\n";
    
    int filecontents2[4][4];
    inputmatr(filecontents2, input2);
    
    cout << "\n";
    //output << "\n";
    
    int outs[4][4];
    
    addmatr(filecontents, filecontents2, outs);
    
    outputmatr(c, output);
    
    int c[4][4];
    
    multmat(filecontents, filecontents2, c);
    
    
    cout << "\n\n";
    
    outputmatr(c, output2);
                
                 
                    
    cout<< endl;
    output<< endl;
    output2 << endl;
             
    system("PAUSE");
    return EXIT_SUCCESS;
}
