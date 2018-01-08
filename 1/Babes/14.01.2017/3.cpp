#include <iostream>

using namespace std;

int factIterativ(int n)
{
  int c=1;
  for(int i=1;i<=n;++i)
  c=c*i;
  return c;
}

int factRecursiv(int n)
{
  if(n==0) return 1;
  return n*factRecursiv(n-1);
}

int main()
{
  int n;
  cin>>n;
  cout<<factIterativ(n)<<"\n";
  cout<<factRecursiv(n)<<"\n";
  return 0;
}
