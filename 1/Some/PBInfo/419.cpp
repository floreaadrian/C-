#include<fstream>

using namespace std;

ifstream fin("subgraf1.in");
ofstream fout("subgraf1.out");

int a[101][101],v[101];

int main()
{
	int n,m,i,j,x,y,c,s;
	fin>>n;
	while(fin>>x>>y)
	{
		a[x][y]=a[y][x]=1;
		m+=2;
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++)
		v[i]+=a[i][j];
		if(v[i]<m)
		m=v[i];
	}
	for(i=1;i<=n;i++)
	{
		if(v[i]==m)
		for(j=1;j<=n;j++)
		a[i][j]=a[j][i]=0;
	}
	c=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		if(a[i][j]==1)
		c++;
	}
	fout<<c/2;
	return 0;
}
