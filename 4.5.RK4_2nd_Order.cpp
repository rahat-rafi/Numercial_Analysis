#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;

double k=150.0, m=7.2, t=0.0, x=0.5, v=4.0, dt=0.01;

double f(double t, double x, double v)
{
    return v;
}
double g(double t, double x, double v)
{
    return -k*x/m;
}

void rk4 (double h, double t0, double x0, double v0)
{

        double k1, l1, k2, l2, k3, l3, k4, l4;
        k1 = h*f(t0,x0,v0);
        l1 = h*g(t0,x0,v0);
        k2 = h*f(t0+h/2, x0+k1/2, v0+l1/2);
        l2 = h*g(t0+h/2, x0+k1/2, v0+l1/2);
        k3 = h*f(t0+h/2, x0+k2/2, v0+l2/2);
        l3 = h*g(t0+h/2, x0+k2/2, v0+l2/2);
        k4 = h*f(t0+h, x0+k3, v0+l3);
        l4 = h*g(t0+h, x0+k3, v0+l3);
        x = x0 + (k1+ 2*k2 + 2*k3+ k4)/6;
        v = v0 + (l1+ 2*l2 + 2*l3+ l4)/6;

}

int main()
{
         ofstream fout("rk4-2.dat");
         for(t=0; t<=5.0; t+=dt)
         {
            rk4(dt,t,x,v);
            fout << t <<" "<< x <<" " << v << endl;
         }
        return 0;
}
