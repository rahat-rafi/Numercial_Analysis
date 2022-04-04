#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;

double t=0, x=1.0, dt = 0.1;

double f(double t, double x)
{
    return t*sqrt(x);
}

void rk4 (double h, double t0, double x0)
{


        double k1, k2, k3, k4;
        k1 = h*f(t0,x0);
        k2 = h*f(t0+h/2,x0+k1/2);
        k3 = h*f(t0+h/2,x0+k2/2);
        k4 = h*f(t0+h,x0+k3);
        x  = x0 + (k1+ 2*k2 + 2*k3+ k4)/6;

}

int main()
{
    ofstream fout("rk4-1.dat");
    for(t=0; t<=10.0; t+=dt)
       {
            rk4(dt,t,x);
            fout << t <<" "<< x <<" "<< (((t*t)+4)*((t*t)+4)/16.0)<<endl;
       }
    return 0;

}
