#include <iostream>

using namespace std;

int CifreIterativ(int numar,int baza,int cif)
{
  int contor=0;
  while(numar>0){
    if(numar%baza==cif)contor++;
    numar=numar/baza;
  }
  return contor;
}

int citire()
{
  int x;
  cin>>x;
  return x;
}

int main()
{
  int numar=citire();
  int baza=citire();
  int cif=citire();
  int rez=CifreIterativ(numar,baza,cif);
  return 0;
}
