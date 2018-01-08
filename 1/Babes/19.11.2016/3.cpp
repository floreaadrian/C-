#include <iostream>

using namespace std;

void SecventaLunga(double a[],int n,int& start,int &sfarsit)
{
  start=0,sfarsit=0;
  int mx=0,act=0;
  for(int i=0;i<n-1;++i)
  {
    if(a[i]<a[i+1])
    {
      act++;
    if(act>mx){
      start=i-act+1;
      sfarsit=i+1;
      mx=act;
    }
  }else act=0;
  }
}

void maximSecventa(double a[],int n)
{
  double mm=0;
  cout<<"Temperaturile maxime, din fiecare perioada in care temperaturile au crescut si apoi au scazut: ";
  for(int i=1;i<n-1;++i)
    if(a[i]>a[i-1] && a[i]>a[i+1])
    {
      cout<<a[i]<<" ";
      if(a[i]>mm)
      mm=a[i];
    }
    cout<<".\nTemperatura anuala maxima din perioada indicata este: ";
    cout<<mm;
}

void afisareSecv(double a[],int n,int an){
  int start,sfarsit;
  SecventaLunga(a,n,start,sfarsit);
  cout<<"Cea mai lunga perioada in care temperaturile au crescut in continuu este: "<<an+start<<"-"<<an+sfarsit<<"\n";
  for(int i=start;i<=sfarsit;++i)
  cout<<a[i]<<" ";
  cout<<"\n";
}

void citire(double a[],int& an,int& n)
{
  cin>>an;
  n=2016-an;
  for(int i=0;i<n;++i)
  cin>>a[i];
}

int main()
{
  double a[100];
  int n,an;
  citire(a,an,n);
  afisareSecv(a,n,an);
  maximSecventa(a,n);
  return 0;
}
