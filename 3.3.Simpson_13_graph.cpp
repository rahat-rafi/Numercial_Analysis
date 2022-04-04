#include<iostream>
#include<cmath>
#include<fstream>

using namespace std;

double f(double t,double tau)
{
   return 100*(1-(2/sqrt(M_PI))*exp(-(tau*tau)));
}

double sim_13(double t)
{
    int i, n=100;
    double a=0, b=8/sqrt(t), I=0.0,J=0.0, h=(b-a)/n, A=0.0;
    for(i=1;i<n;i+=2)
        {
            I+=f(t,a+i*h);
        }
    for(i=2;i<n;i+=2)
        {
            J+=f(t,a+i*h);
        }
    A = (h/3)*(f(t,a)+(4*I)+(2*J)+f(t,b));
    return A;
}

int main()
{
    ofstream fout("simpson13.dat");
    for(double t=10; t<=200; t+=0.01)
    fout<<t<<" "<<sim_13(t)<<endl;
    return 0;
}
