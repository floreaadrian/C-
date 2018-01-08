#include<fstream>
#include<algorithm>
using namespace std;

ifstream fin("bipartit.in");
ofstream fout("bipartit.out");

int a[101][101],v[101];

int main()
{
	int n,m,k,nr,x,y;
	fin>>n>>m;
	while(m--)
	{
		fin>>x>>y;
		a[x][y]=a[y][x]=1;
	}
	fin>>k;
	for(int i=1;i<=k;i++)
	{
		fin>>v[i];
	}
	sort(v,v+1,k);
	for(int i=1;i<=k;i++)
	fout<<v[i]<<" ";
	return 0;
}
