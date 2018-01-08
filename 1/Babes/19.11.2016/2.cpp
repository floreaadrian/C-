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

int urmperf(int nr){
  nr++;
  while(!perfect(nr))nr++;
  return nr;
}

void inserarePerfecte(int a[],int& n){
  int i=n*2-1;
  for(int j=n-1;j>=0;j--){
    a[i]=urmperf(a[j]);
    a[i-1]=a[j];
    i-=2;
  }
  n=n*2;
}

void citire(int a[],int& n){
  cin>>n;
  for(int i=0;i<n;++i)
  cin>>a[i];
}

void afisare(int a[],int n){
  for(int i=0;i<n;++i)
  cout<<a[i]<<" ";
  cout<<"\n";
}

int main()
{
    int a[100],n;
    citire(a,n);
    inserarePerfecte(a,n);
    afisare(a,n);
    return 0;
}
