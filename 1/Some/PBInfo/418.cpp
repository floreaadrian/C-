#include<fstream>
#include<math.h>

using namespace std;

ifstream fin("subgraf.in");
ofstream fout("subgraf.out");

int a[101][101];

int prim(int n)
{
	int c;
	c=sqrt(n);
	if(n==2)
	return 1;
	if(n%2==0)
	return 0;
	for(int i=3;i<=c;i++)
	if(n%i==0)return 0;
	return 1;
}

int main()
{
	int n,x,y,c,i,j;
	fin>>n;
	while(fin>>x>>y){
		a[x][y]=a[y][x]=1;
	}
	for(i=2;i<=n;i++)
	{
		if(prim(i))
		for(j=1;j<=n;j++)
		a[i][j]=a[j][i]=0;
	}
	c=0;
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	if(a[i][j]==1)
	c++;
	fout<<c/2;
	return 0;
}
