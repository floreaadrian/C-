#include <iostream>

using namespace std;

int reverse(int n)
{
  int r=0;
  while(n>0)
  {
    r=r*10+n%10;
    n/=10;
  }
  return r;
}

bool pal(int n){
  if(reverse(n)==n)return true;
  return false;
}

bool pal1(int n){
  int m=0;
  if(n%10==0)return false;
  while(n>0){
    m=m*10+n%10;
    if(m==n)return true;
    n/=10;
    if(m==n)return true;
    if(m>n)return false;
  }
  return false;
}

int main()
{
  int n;
  cin>>n;
  if(pal(n))cout<<"Da\n";
  else cout<<"Nu\n";
  if(pal1(n))cout<<"Da\n";
  else cout<<"Nu\n";
  return 0;
}
