/*
For the function x^3-x-2
*/

#include<iostream>
using namespace std;

double f(double x)
{
    return x*x*x-x-2;
}

void diff(double x,double h)
{
  cout<<"result="<<(f(x+h)-f(x-h))/(2*h);
}

int main()
{
    double x,h;
    cout<<"Enter the point "<<endl;
    cin>>x;
    cout<<"Enter the value of h "<<endl;
    cin>>h;
    diff(x,h);
    return 0;
}
