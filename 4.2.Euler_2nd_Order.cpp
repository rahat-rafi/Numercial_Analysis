#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
using namespace std;
const double g = 9.80;
const double L = 1;
double t = 0, x = 0, w = 1, dt=0.1, w0;

//x = theta, w = omega, w0 = Old Omega

void Euler( double t, double x, double w, double dt)

{

    ofstream fout("euler-harmonic.dat");
    for(int i=0;i<=100;i++)
    {
        w0 = w;
        w -= (g/L) * x * dt;
        x += w0 * dt;
        t += dt;
        fout<< t <<" " << x <<" " << w <<endl;
    }
}

int main()
{
    Euler(t, x, w, dt);
    return 0;
}
