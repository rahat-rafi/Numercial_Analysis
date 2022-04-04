#include<iostream>
#include<cmath>
#include<fstream>
# define e 0.000001
using namespace std;
double J=100, T=10;
double f1(double m)
{return m;}
double f2(double m)
{return tanh((J*m)/T);}
double f(double m){
return m-tanh((J*m)/T);}
double df(double m){
return 1-((J/T)*(1-pow(tanh((J*m)/T),2)));}
double magnetization(double m){
double h=f(m)/df(m);
while (abs(h)>=e){
m=m-h;
h=f(m)/df(m);
}
return m;}
int main(){
ofstream fout("magnetization.dat");
for(double m=-3;m<=3;m+=0.0001)
fout<<m<<"  "<<f1(m)<<"  "<<f2(m)<<endl;
// initial guess for newton-raphson method
double m01=-2;
 //for negative root
double m02=2;
 //for positive root
double m1=magnetization(m01);
double m2=magnetization(m02);
cout<<"The magnetizations are m1= "<<m1<<" and m2= "<<m2<<endl;
return 0;}
