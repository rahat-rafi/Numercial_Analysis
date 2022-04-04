#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

void pi(double n)
{
    double count=0;
    double x,y;
    srand(time(NULL));
    for(int i=1;i<=n;i++)
    {
        x=(double)rand()/(double)RAND_MAX;
        y=(double)rand()/(double)RAND_MAX;
        if(x*x+y*y<=1)
            count++;
    }
    cout<<"result="<<4*count/n;
}

int main()
{
    double n;
    cout<<"Enter the number of points "<<endl;
    cin>>n;
    pi(n);
    return 0;
}
