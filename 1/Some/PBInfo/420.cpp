#include<fstream>

using namespace std;

ifstream fin("graf_partial.in");
ofstream fout("graf_partial.out");

int a[101][101];

int main()
{
	int n,x,y,i,j,c;
	fin>>n;
	c=0;
	while(fin>>x>>y){
		if(x%2!=y%2)
		a[x][y]=a[y][x]=1;
	}
	for(i=1;i<=n;i++)
	{
	for(j=1;j<=n;j++)
	if(a[i][j]==1)
	c++;
	}
	fout<<c/2;
	return 0;
}
