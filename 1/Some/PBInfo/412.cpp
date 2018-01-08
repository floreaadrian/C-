#include<fstream>

using namespace std;

ifstream fin("adiacenta.in");
ofstream fout("adiacenta.out");

int a[101][101];

int main()
{
	int i,j,n,x,y,m;
	fin>>n>>m;
	for(i=1;i<=m;i++){
		fin>>x>>y;
		a[x][y]=a[y][x]=1;
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		fout<<a[i][j]<<" ";
		fout<<"\n";
	}
	return 0;
}
