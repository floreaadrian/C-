#include<fstream>

using namespace std;

ifstream fin("adiacenta1.in");
ofstream fout("adiacenta1.out");

int a[101][101];

int main()
{
	int i,j,n,x,y,m;
	fin>>x>>y;
	n=x;
	a[x][y]=a[y][x]=1;
	while(fin>>x>>y){
		a[x][y]=a[y][x]=1;
		if(x>n)
		n=x;
		if(y>n)
		n=y;
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		fout<<a[i][j]<<" ";
		fout<<"\n";
	}
	return 0;
}
