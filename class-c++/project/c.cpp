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
    
    cout<<"Enter the file name"<< endl;
    cin>> file1;
    
    char fileout[input_read];
    cout<<"Enter the file name to save the output"<< endl;
    cin>> fileout;
    
    ifstream input1(file1);
    if (input1.fail()){
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
    
    char filecontents[200];
    while(!input1.eof()){
        input1>> filecontents;
        cout<< filecontents<< " ";
        output<< filecontents<< " ";
    }
    
    cout<< endl;
    output<< endl;
             
    system("PAUSE");
    return EXIT_SUCCESS;
}