/*
For the function sin(x)
*/

#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;

double f(double x)
{
    return sin(x);
}

void diff(double a,double b,double h)
{
  ofstream fout("diff.dat");
  for(double x=a;x<=b;x=x+0.01)
  {
      fout<<x<<'\t'<<(f(x+h)-f(x-h))/(2*h)<<endl;
  }
}

int main()
{
    double a,b,h;
    a=0;
    b=4*M_PI;
    h=0.001;
    diff(a,b,h);
    return 0;
}
