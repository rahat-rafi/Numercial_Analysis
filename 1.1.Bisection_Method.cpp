/*
Root finding using bisection method for equation: x^3-x-2=0,  
*/

#include<iostream>
using namespace std;

double f(double x)
{
    return x*x*x-x-2;
}

void bisection(double a,double b,double e)
{
    double c;
    if(f(a)*f(b)>0)
    {
        cout<<"No solution in the given interval"<<endl;
    }
    else
    {
        for(int i=0;abs(a-b)>e;i++)
        {
             c=(a+b)/2;
            if(f(a)*f(c)<0)
            b=c;
            else a=c;
        }
    }    
    cout<<"Solution is "<<c;
    
}   

int main()
{
    double a,b,e;
    cout<<"Enter initial values"<<endl;
    cin>>a>>b;
    cout<<"Enter order of accuracy"<<endl;
    cin>>e;
    bisection(a,b,e);
    return 0;
}
