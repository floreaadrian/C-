#include <iostream>

using namespace std;

struct matrice()
{
  int m;
  int n;
  int elem[105][105];
};

void citesteMatrice(matrice& a){
  cin>>a.m>>a.n;
  for(int i=0;i<a.m;++i)
    for(int j=0;j<a.n;++j)
      cin>>a.elem[i][j];
}

void tipareste(matrice a){
  for(int i=0;i<a.m;++i){
    for(int j=0;j<a.n;++j)
    cout<<a.elem[i][j]<<" ";
    cout<<"\n";
  }
}

void suma2Mat(matrice& a,matrice b){
  for(int i=0;i<a.m;++i)
  for(int j=0;j<a.n;++j)
  a.elem[i][j]=a.elem[i][j]+b.elem[i][j];
}

bool eNula(matrice a){
  for(int i=0;i<n;++i)
  for(int j=0;j<m;++j)
  if(a.elem[i][j]!=0)return false;
  return true;
}

void initNula(int m,int n,matrice& a){
  a.m=m;
  a.n=n;
  for(int i=0;i<m;++i)
  for(int j=0;j<n;++j)
  a.elem[i][j]=0;
}

int main()
{
  matrice a,suma;
  citesteMatrice(a);
  initNula(a.m,a.n,suma);
  while(!enula(a)){
    suma2Mat(suma,a);
    citesteMatrice(a);
  }
  tipareste(suma);
  return 0;
}
