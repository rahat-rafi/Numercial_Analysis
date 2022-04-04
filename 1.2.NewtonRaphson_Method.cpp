/*
Root finding using Newton-Raphson method for equation: x^3-x-2=0
*/

#include<iostream>
using namespace std;
double f(double x)
{
    return x*x*x-x-2;
}

double g(double x)  //g(x)=derivative of f(x)
{
    return 3*x*x-1;
}

void Newton(double y,double e)
{
    for(int i=0;abs(f(y)/g(y))>e;i++)
        y=y-(f(y)/g(y));
    cout<<"Solution is "<<y;
}

int main()
{
    double y,e;
    cout<<"Enter initial guess "<<endl;
    cin>>y;
    cout<<"Enter order of accuracy "<<endl;
    cin>>e;
    Newton(y,e);
    return 0;
}
