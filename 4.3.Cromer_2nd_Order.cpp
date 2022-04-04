#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
using namespace std;
const double g = 9.80;
const double L = 1;
double t = 0, x = 0, w = 1, dt=0.1, w0;

 //x = theta, w = omega, w0 = Old Omega

void Cromer( double t, double x, double w, double dt)

{
    ofstream fout("cromer-harmonic.dat");
    for(int i=0;i <=100;i++)
    {
        w -= (g/L) * x * dt;
        x += w * dt;
        t += dt;
        fout<< t <<" " << x <<" " << w <<endl;
    }
}

int main()
{
    Cromer(t, x, w,dt);
    return 0;
}
