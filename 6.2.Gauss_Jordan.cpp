#include<iostream>
using namespace std;

void Jordan(int n)
{
    int i,j,k;
    double A[10][10],b,x[10];
    cout<<"Enter the elements of matrix"<<endl;
    for( i=1;i<=n;i++)
    {
        for( j=1;j<=n+1;j++)
        {
            cout<<"A["<<i<<","<<j<<"]=";
            cin>>A[i][j];
        }
    }
    for(j=1;j<=n;j++)
    {
        for(i=1;i<=n;i++)
        {
            if(i!=j)
            {
                b=A[i][j]/A[j][j];
                for(k=1;k<=n+1;k++)
                    A[i][k]=A[i][k]-b*A[j][k];
            }
        }
    }
    cout<<"Solution is:"<<endl;
    for(i=1;i<=n;i++)
    {
        x[i]=A[i][n+1]/A[i][i];
        cout<<"x"<<i<<"="<<x[i]<<endl;
    }
}

int main()
{
    int n;
    cout<<"Enter the size of the matrix"<<endl;
    cin>>n;
    Jordan(n);
    return 0;
}
