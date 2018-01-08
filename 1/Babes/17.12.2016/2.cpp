#include <iostream>

using namespace std;

bool eprim(int nr)
{
  if(nr<=1)return false;
  if(nr>=2 && nr%2==0)return false;
  int div=3;
  while(div*div<=nr){
    if(nr%div==0)return false;
    div+=2;
  }
  return true;
}

int nrPrime(int n,int a[100][100]){
  int nr = 0;
  for(int i=0;i<n;++i)
  for(int j=0;j<n;++j)
  if((i>j) && (i+j<n-1) && eprim(a[i][j]))nr++;
  else if((i<j) && (i+j>n-1) && eprim(a[i][j]))nr++;
  return nr;
}

int main()
{
  int n,a[100][100];
  cin>>n;
  for(int i=0;i<n;++i)
  for(int j=0;j<n;++j)
  cin>>a[i][j];
  cout<<nrPrime(n,a);
}
