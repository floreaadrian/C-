#include <iostream>

using namespace std;

int reverse(int n){
  int r=0;
  while(n>0){
    r=r*10+n%10;
    n/=10;
  }
  return r;
}

int main()
{
  int n;
  cin>>n;
  cout<<reverse(n)<<"\n";
  return 0;
}
