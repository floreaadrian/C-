#include<iostream>
#include<fstream>
#include <string.h>
#define max(a,b) (a>b)? a:b
using namespace std;
int c[1025][1025],n,m,sol[1025],k;
string a,b;
void afisare(int i,int j)
{

    k=c[n][m];
    while(k>0)
    {
       while(a[i]!=b[j])
          if (c[i-1][j]>c[i][j-1]) i--; else j--;


     sol[k]=a[i];
     i--;j--;
     k--;

    }
    k=c[n][m];
for(i=1;i<=k;i++)
  cout<<sol[i]<<" ";
  //fout.close();
}

int main()
{
    int i,j;
    cin>>a>>b;
    n=a.size();
    m=b.size();
    for(i=0;i<n;++i)
    {for(j=0;j<m;++j)
     if(a[i]==b[j])   c[i][j]=c[i-1][j-1]+1;
     else
     c[i][j]=max(c[i][j-1],c[i-1][j]);
    }
cout<<c[n][m]<<"\n";
afisare(n,m);
return 0;}
