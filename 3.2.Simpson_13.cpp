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

double sim_13 (double a, double b, int n)
{
    double I=0.0, J=0.0, h = (b-a)/n, Area;
    for(int i=1; i<n; i+=2)
    {
        I+=f(a+i*h);
    }
    for(int i=2; i<n; i+=2)
    {
        J+=f(a+i*h);
    }
    Area = (h/3)*(f(a)+4*I+2*J+f(b));
    return Area;
}

int main()
{
    double a = 0.0, b = M_PI/2;
    int n = 120;
    cout<<"Result: "<<sim_13(a,b,n)<<endl;
    return 0;
}
