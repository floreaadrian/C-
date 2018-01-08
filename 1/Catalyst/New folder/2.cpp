#include <iostream>

using namespace std;

int f(int a,int b)
{
  c=1;
  while(b>0){
    if(b%2==1)c=(c*a)%10;
    a=(a*a)%10;
    b/=2;
  }
  return c;
}

int main()
{

  return 0;
}
