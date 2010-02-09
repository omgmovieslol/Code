#include <cstdlib>
#include <iostream>
#include <fstream>

#include <string>

#define input_read 20

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
    //while(!input1.eof()){
        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++) {
                
                    input1>> filecontents[i][j];
                    cout<< filecontents [i][j] << " ";
                    //output<< filecontents [i][j] << " ";
                
            }
            cout << "\n";
            //output << "\n";
        }   
    //}
    
    cout << "\n";
    
    int filecontents2[4][4];
    //while(!input1.eof()){
        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++) {
                
                    input2 >> filecontents2[i][j];
                    cout<< filecontents2 [i][j] << " ";
                    //output<< filecontents2 [i][j] << " ";
                
            }
            cout << "\n";
            //output << "\n";
        }   
    //}
    
    cout << "\n";
    //output << "\n";
    
    int outs[4][4];
    
    for(int i=0; i<4; i++) {
         for(int j=0; j<4; j++) {
                outs[i][j] = filecontents[i][j] + filecontents2[i][j];
                cout<< outs[i][j] << " ";
                output << outs[i][j] << " ";
         }
         cout << "\n";
         output << "\n";
    }
    
    int c[4][4];
    
    int sum=0;
    for (int i=0;i<4;i++)
    {
        for (int j=0;j<4;j++)
        {
            for (int k=0;k<4;k++)
	            sum=sum+(filecontents[i][k]*filecontents2[k][j]);
            c[i][j]=sum;
            sum=0;
        }
    }
    
    cout << "\n\n";
    
    for(int i=0; i<4; i++) {
         for(int j=0; j<4; j++) {
                //outs[i][j] = filecontents[i][j] + filecontents2[i][j];
                cout<< c[i][j] << " ";
                output2 << c[i][j] << " ";
         }
         cout << "\n";
         output2 << "\n";
    }
                
                 
                    
    cout<< endl;
    output<< endl;
    output2 << endl;
             
    system("PAUSE");
    return EXIT_SUCCESS;
}
