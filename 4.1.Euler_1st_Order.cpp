#include<iostream>
#include<fstream>
#include<cmath>

using namespace std;

double f(double t, double y)
{
    return 2-exp(-4*t)-2*y;
}

void euler1(double h, double t0, double y0)
{
    double y=y0;
    ofstream fout("euler1.dat");
    for (double t=t0;t<=5.0; t+=h)
    {
        fout<<t<<" "<<y<<" "<<(1 + 0.5*exp(-4*t) - 0.5*exp(-2*t))<<endl;
        y+=h*f(t,y);
    }
}
int main()
{
    euler1(0.1,0.0,1.0);
    return 0;
}
