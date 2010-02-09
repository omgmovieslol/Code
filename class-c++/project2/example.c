#include <iostream>
using namespace std;
class matrix
{
        int rows;
        int cols;
        double **mat;
public:
        matrix(int Rows=0, int Cols=0);
                friend matrix operator+(matrix,matrix);
        friend ostream & operator<<(ostream&, const matrix &);
        friend istream & operator>>(istream & , matrix &);

};
matrix ::matrix(int Rows, int Cols)
{
        rows=Rows;
        cols=Cols;
        mat=NULL;
        mat=new double *[rows];
        for(int i=0;i<rows;i++)
                mat=new double[cols];

}
matrix operator+(matrix A,matrix B)
{
        matrix C(A.rows,A.cols);
        for(int r=0;r<A.rows;r++)
                for(int c=0;c<A.cols;c++)
                        C.mat[r][c]=A.mat[r][c]+B.mat[r][c];
        return C;
}
ostream & operator<<(ostream & result, const matrix & C)
{
        for(int r=0;r<C.rows;r++)
        {
                cout<<endl;
                for(int c=0;c<C.cols;c++)
                        result<<C.mat[r][c]<<"\t";
        }
        cout<<endl;
        return result;
}
istream & operator >>(istream & show,matrix & C)
{
        for(int i=0;i<C.rows;i++)
        {
                for(int j=0;j<C.cols;j++)
                {
                        cout<<"Enter element mat["<<i<<"]["<<j<<"]";
                }
        }
        return show;
}
int main()
{
int n;
cout<<"enter the size of the matrix:";
cin>>n;
matrix A(n,n);
matrix B(n,n);
matrix C(n,n);
cin>>A;
cin>>B;
C=A+B;
cout<<A;
cout<<B;
cout<<C;
return 0;
}