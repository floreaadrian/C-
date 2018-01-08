#include <iostream>

using namespace std;

bool perfect(int x){
  if(x==1)return 0;
  int sumdiv=1;
  for(int i=2;i<=x/2;++i)
  if(x%i==0)sumdiv+=i;
  if(sumdiv==x)return true;
  return false;
}

void gasestePerfecte(int a[],int n,int rez[],int& m){
  m=0;
  for(int i=0;i<n;++i)
  if(perfect(a[i]))rez[m++]=a[i];
}

void afisare(int a[],int n){
  if(n==0)
  cout<<"Nu exista numere perfecte in sir.\n";
  else for(int i=0;i<n;++i)
  cout<<a[i]<<" ";
}

void citireVector(int a[],int& n){
  int x;
  n=0;
  cin>>x;
  while(x>0){
    a[n++]=x;
    cin>>x;
  }
}

int main()
{
  int a[100],rez[100],n,m;
  citireVector(a,n);
  gasestePerfecte(a,n,rez,m);
  afisare(rez,m);
  cout<<"\n";
  return 0;
}
