#include <iostream>

using namespace std;

int factorial(int n){
  int c=1;
  for(int i=1;i<=n;++i)
  c*=i;
  return c;
}

int cifre0(int n)
{
  int f=factorial(n);
  int nr=0;
  while(f%10==0){
    nr++;
    f/=10;
  }
  return nr;
}

int cifre1(int n)
{
  int nr=0;
  for(int i=5;n/i>=1;i*=5)
  nr+=n/i;
  return nr;
}

int main()
{
  int n;
  cin>>n;
  cout<<cifre0(n)<<"\n";
  cout<<cifre1(n)<<"\n";
}
