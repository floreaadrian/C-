#include<iostream>
#include<conio.h>
using namespace std;
int a[20][20],n,m,viz[100],gasit;
 
void dfmr(int nod)
{
 cout<<nod<<" ";
 viz[nod]=1;
 for(int k=1;k<=n;k++)
      if(a[nod][k]==1&&viz[k]==0)
               dfmr(k);      
}
 
int main()
{int x,y,j,i;

 cin>>n>>m;
 for(int i=1;i<=m;i++)
    {cin>>x>>y;
     a[x][y]=1;}
cout<<endl<<"matricea de adiacente"<<endl;
for(i=1;i<=n;i++)
   {for(j=1;j<=n;j++)
       cout<<a[i][j]<<" ";
   cout<<endl;}
cout<<endl<<"parcurgere in adancime incepand de la varful 1"<<endl;
dfmr(1);
 
getch();} 
