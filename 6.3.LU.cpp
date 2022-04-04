#include <iostream>
using namespace std;

void LU(int n)
{
    int i,j,k,p;
    double A[10][10],L[10][10]={0},U[10][10]={0},b[10],z[10]={0},x[10]={0},sum;
    cout<<"Enter the elements of A matrix"<<endl;
    for( i=1;i<=n;i++)
    {
        for( j=1;j<=n;j++)
        {
            cout<<"A["<<i<<","<<j<<"]=";
            cin>>A[i][j];
        }
    }

    cout<<"Enter the elements of b matrix"<<endl;
    for(i=1;i<=n;i++)
    {
        cout<<"b["<<i<<"]=";
        cin>>b[i];
    }

    for(k=1;k<=n;k++)
    {
        U[k][k]=1;
        for(i=k;i<=n;i++)
        {
            sum=0;
            for(p=1;p<=k;p++)
                sum=sum+L[i][p]*U[p][k];
            L[i][k]=A[i][k]-sum;
        }
        for(j=k+1;j<=n;j++)
        {
            sum=0;
            for(p=1;p<=k-1;p++)
                sum=sum+L[k][p]*U[p][j];
            U[k][j]=(A[k][j]-sum)/L[k][k];
        }
    }

    cout<<"L matrix is given below:"<<endl;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            cout<<L[i][j]<<'\t';
        cout<<endl;
    }
    cout<<"U matrix is given below:"<<endl;;

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            cout<<U[i][j]<<'\t';
        cout<<endl;
    }


 for(i=1;i<=n;i++)
 {
     sum=0;
     for(p=1;p<i;p++)
        sum=sum+L[i][p]*z[p];
     z[i]=(b[i]-sum)/L[i][i];
 }

 for(i=n;i>0;i--)
 {
     sum=0;
     for(p=n;p>i;p--)
        sum=sum+U[i][p]*x[p];
     x[i]=(z[i]-sum)/U[i][i];
 }

 cout<<"Set of solution is"<<endl;
 for(i=1;i<=n;i++)
    cout<<"x["<<i<<"]="<<x[i]<<endl;
 }

 int main()
 {
     int n;
     cout<<"Enter the order of matrix A:"<<endl;
     cin>>n;
     LU(n);
     return 0;
 }
