#include<iostream>
using namespace std;

void Gauss(int n)
{
    int i,j,k;
    double A[10][10],b,x[10],sum=0;
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
            if(i>j)
            {
                b=A[i][j]/A[j][j];
                for(k=1;k<=n+1;k++)
                    A[i][k]=A[i][k]-b*A[j][k];
            }
        }
    }
    x[n]=A[n][n+1]/A[n][n];
    for(i=n-1;i>=1;i--)
    {
        sum=0;
        for(j=i+1;j<=n;j++)
        {
            sum=sum+A[i][j]*x[j];
        }
        x[i]=(A[i][n+1]-sum)/A[i][i];
    }
    cout<<"The solution is:"<<endl;
    for(i=1;i<=n;i++)
    {
        cout<<"x"<<i<<"="<<x[i]<<endl;
    }
}

int main()
{
    int n;
    cout<<"Enter the size of the matrix"<<endl;
    cin>>n;
    Gauss(n);
    return 0;
}
