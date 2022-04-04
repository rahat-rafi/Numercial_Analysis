#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>
using namespace std;

double f(double x)
{
    return 3*x*x;
}

void integration(double a,double b,double n)
{
    double count=0;
    double x,y,c,d;
    c=f(a);
    d=f(b);
    srand(time(NULL));
    for(int i=1;i<=n;i++)
    {
        x=a+(b-a)*(double)rand()/(double)RAND_MAX;
        if(d>=c)
        y=d*(double)rand()/(double)RAND_MAX;
        else y=c*(double)rand()/(double)RAND_MAX;
        if(y<=f(x))
            count++;
    }
    cout<<"result=";
    if(d>=c)
    cout<<(b-a)*d*count/n;
    else cout<<(b-a)*c*count/n;
}

int main()
{
    double a,b,n;
    cout<<"Enter lower and upper limits "<<endl;
    cin>>a>>b;
    cout<<"Enter the number of points "<<endl;
    cin>>n;
    integration(a,b,n);
    return 0;
}
