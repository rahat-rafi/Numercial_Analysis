#include<iostream>
#include<cmath>
#include<fstream>

using namespace std;

double fact(int x)
{
     if(x==0)
        return 1;
     else if (x==1)
        return 1;
     else return x*fact(x-1);
}

double f(int n,double z,double theta)
{
    double a=pow(z,n)/(pow(2,(n+1))*fact(n));
    double b=cos(z*cos(theta))*pow(sin(theta),(2*n)+1);
    return a*b;
}

double bessel(int n, double z)
{
    int N=100;
    double a=0.0, b=M_PI, I=0.0, J=0.0, h=(b-a)/N, A=0.0;
    for(int i=1;i<N;i+=2)
    {
        I+=f(n,z,a+i*h);
    }
    for(int i=2;i<N;i+=2)
    {
        J+=f(n,z,a+i*h);
    }
    A=(h/3)*(f(n,z,a)+(4*I)+(2*J)+f(n,z,b));
    return A;
}

double g(double z)
{
return 0.5*bessel(0,z)*sqrt(z);
}

double fresnel(double x)
{
    int N=1000;
    double a=0.0,b=x, I=0.0, J=0.0, h=(b-a)/N, A=0.0;
    for(int i=1;i<N;i+=2)
    {
    I+=g(a+i*h);
    }
    for(int i=2;i<N;i+=2)
    {
    J+=g(a+i*h);
    }
    A=(h/3)*(g(a)+(4*I)+(2*J)+g(b));
    return A;
}
int main()
{
    ofstream fout("bessel.dat");
    for(double z=0.0;z<=25.0;z+=0.01)
    {
    fout<<z<<" "<<bessel(0,z)<<" "<<bessel(1,z)<<" "<<bessel(2,z)<<" "<<bessel(3,z)<<endl;
    }
    ofstream file("fresnel.dat");
    for(double x=0.0;x<=20;x+=0.1)
    {
    file<<x<<" "<<fresnel(x)<<endl;
    }
    return 0;
}
