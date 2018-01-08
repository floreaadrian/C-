#include <iostream>

using namespace std;

typedef double(*functie)(double);

double radacinaFunctieIterativ(double a,double b,double epsilon,double f)
{
  while(b-a>epsilon){
    double mijloc = (a+b)/2.0;
    if(f(a)*f(mijloc)<0)
    b=mijloc;
    else a=mijloc;
  }
  return (a+b)/2.0;
}

double functie1(double a){
  return a*a*a-a-2;
}

double functie2(double a){
  return a*a+10*a+3;
}

double citire(){
  double x;
  cin>>x;
  return x;
}

void afisare(double x){
  cout<<x;
}

int main()
{
  double a=citire();
  double b=citire();
  double epsilon=citire();
  double rezultat=radacinaFunctieIterativ(a,b,epsilon,functie1);
  afisare(rezultat);
  return 0;
}
