#include <iostream>

using namespace std;

bool prim(int nr)
{
  if(nr<=1)return false;
  else if(nr%2==0)return false;
  else {
    int div=3;
    while(div*div<=nr)
    {
      if(nr%div==0)return false;
      div+=2;
    }
  }
  return true;
}

int urmFactorPrim(int nr,int div_curent)
{
  div_curent++;
  while(div_curent<nr)
  {
    if(nr%div_curent==0 && prim(div_curent))
    return div_curent;
    div_curent++;
  }
  return 0;
}

void eInSolutie(int n,int p,int pos_curenta,int val){
  if(pos_curenta>=n && pos_curenta<=n+p)
  cout<<val<<" ";
}

bool candOprire(int n,int p,int pos_curenta)
{
  if(pos_curenta>n+p)
  return true;
  else return false;
}

void generare(int n,int p)
{
  int pos_curenta=1;
  int val_curenta=1;
  while(!candOprire(n,p,pos_curenta)){
      eInSolutie(n,p,pos_curenta,val_curenta);
      pos_curenta++;
      int factor = urmFactorPrim(val_curenta,1);
      while(!factor && !candOprire(n,p,pos_curenta)){
        eInSolutie(n,p,pos_curenta,factor);
        pos_curenta++;
        factor = urmFactorPrim(val_curenta,factor);
      }
      val_curenta++;
  }
}

int citire()
{
  int x;
  cin>>x;
  return x;
}

int main()
{
  int n=citire();
  int p=citire();
  generar(n,p);
  return 0;
}
