#include<bits/stdc++.h>

using namespace std;


double f(double x)
{
    return x*x*x;
}

double Pn(double x, int n)
{
    if(n==0)
        return 1;
    else if(n==1)
        return x;
    else
        return ((2*n-1)*x*Pn(x,n-1) - (n-1)*Pn(x,n-2))/n;
}

double dPn(double x, int n)

{
    return (n/(x*x-1))*(x*Pn(x,n)-Pn(x,n-1));
}

double gauss (double a, double b, int n)
{
    double x0[n],x[n],w[n],c,h;
    for(int i=0; i<n; i++)
    {
        x0[i] = cos(M_PI*((i+1-0.25)/(n+0.5)));
        c = x0[i];
        h = Pn(c,n)/dPn(c,n);
        for(int i = 0; abs(h)>=0.000001; i++)
        {
            c = c-h;
            h = Pn(c,n)/dPn(c,n);
        }
        x[i] = c;
        w[i] = 2/((1-c*c)*(dPn(c,n)*dPn(c,n)));

    }
    double result = 0.0;
    for(int i=0; i<n; i++)
    {
        result += 0.5*(b-a)*(w[i]*f(0.5*(b-a)*x[i]+0.5*(a+b)));
    }
    return result;
}

int main()
{
    cout<<"Enter the values: "<<endl;
    double p,q,r;
    cin>>p>>q>>r;
    cout<<"Result :"<<gauss(p,q,r);
    return 0;
}
