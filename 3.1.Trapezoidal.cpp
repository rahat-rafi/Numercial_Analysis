/*
For the function 1/(1+sin(x))
*/

#include<iostream>
#include<cmath>

using namespace std;

double f (double x)
{
    return 1/(1+sin(x));
}

double trap (double a, double b, int n)
{
    double I=0.0, h = (b-a)/n, Area;
    for(int i=1; i<n; i++)
    {
        I+=f(a+i*h);
    }
    Area = 0.5*h*(f(a)+2*I+f(b));
    return Area;
}

int main()
{
    double a = 0.0, b = M_PI/2;
    int n = 120;
    cout<<"Trap result: "<<trap(a,b,n)<<endl;
    return 0;
}
