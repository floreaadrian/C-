#include <iostream>

using namespace std;

bool prim(int nr)
{
  if(nr<=1)return false;
  if(nr%2==0)return false;
  int div=3;
  while(div*div<=nr){
    if(nr%div==0)
    return false;
    div+=2;
  }
  return true;
}

int elemSir(int k){
  int poz_curenta=0;
  int val_curenta=1;
  int rezultat=val_curenta;
  while(poz_curenta<k){
    if(prim(val_curenta))
    poz_curenta+=val_curenta;
    else poz_curenta++;
    rezultat=val_curenta;
    val_curenta++;
  }
  return val_curenta;
}

int main()
{
  int k=citire();
  int rez=elemSir(k);
  afisareNumar(rez);
  return 0;
}
