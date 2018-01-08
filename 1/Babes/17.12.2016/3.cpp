#include <iostream>

using namespace std;

const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};

void copiazaMatrice(int n,int m,int a[100][100],int b[100][100])
{
  for(int i=0;i<n;++i)
  for(int j=0;j<m;++j)
  b[i][j]=a[i][j];
}

int nrVecini(int m,int n,int a[100][100],int i,int j){
  int rezultat=0;
  for(int k=0;k<4;++k)
  if((i+dx[k])>=0 && (i+dx[k])<n && (j+dy[k])>=0 && (j+dx[k])<m)
    if(a[dx[k]+i][dy[k]+j]==1)rezultat++;
    return rezultat;
}

bool esteImpadurita(int n,int m,int a[100][100]){
  for(int i=0;i<n;++i)
  for(int j=0;j<m;++j)
  if(a[i][j]==0)return false;
  return true;
}

void impadurire(int n,int m,int a[100][100],bool& sePoate,int& nrzile){
  int b[100][100];
  int nrCopaci=0;
  nrzile=0;
  do{
    nrCopaci=0;
    copiazaMatrice(n,m,a,b);
    for(int i=0;i<n;++i)
    for(int j=0;j<n;++j)
    if(a[i][j]==0)if(nrVecini(m,n,b,i,j)>=2){
      nrCopaci++;
      a[i][j]=1;
    }
    if(nrCopaci>0)nrzile++;
  }while(nrCopaci>0);
  sePoate=esteImpadurita(n,m,a);
}

int main()
{
  int a[100][100],n,m,nrzile;
  bool sePoate;
  cin>>n>>m;
  for(int i=0;i<n;++i)
  for(int j=0;j<m;++j)
  cin>>a[i][j];
  impadurire(n,m,a,sePoate,nrzile);
  if(sePoate)cout<<"sePoate = true\n";
  else cout<<"sePoate = false\n";
  cout<<"nrZile = "<<nrzile<<"\n";
  return 0;
}
