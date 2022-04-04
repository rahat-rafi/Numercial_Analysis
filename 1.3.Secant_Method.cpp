/*
Root finding using secant method for equation: x^3-x-2=0
*/

#include<iostream>
using namespace std;
double f(double x)
{
    return x*x*x-x-2;
}

void Secant(double x0,double x1,double e)
{
    double x2;
    for(int i=0;abs(x0-x1)>e;i++)
    {
        x2=(x0*f(x1)-x1*f(x0))/(f(x1)-f(x0));
        x0=x1;
        x1=x2;
    }
    cout<<"Solution is "<<x2;
}

int main()
{
    double x0,x1,e;
    cout<<"Enter initial values"<<endl;
    cin>>x0>>x1;
    cout<<"Enter order of accuracy"<<endl;
    cin>>e;
    Secant(x0,x1,e);
    return 0;
}
