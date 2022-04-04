#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
void vol(double r,double n)
{
    double count=0;
    double x,y,z;
    srand(time(NULL));
    for(int i=1;i<=n;i++)
    {
        x=(double)rand()/(double)RAND_MAX;
        y=(double)rand()/(double)RAND_MAX;
        z=(double)rand()/(double)RAND_MAX;
        if(x*x+y*y+z*z<=1)
            count++;
    }
    cout<<"result="<<(r*r*r*8*count)/n;
}
int main()
{
    double r,n;
    cout<<"Enter radius of the sphere "<<endl;
    cin>>r;
    cout<<"Enter the number of points "<<endl;
    cin>>n;
    vol(r,n);
    return 0;
}
