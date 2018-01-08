#include<fstream>
#include<iostream>
using namespace std;

ifstream fin("mincols.in");
ofstream fout("mincols.out");

int main()
{
	int a[50][50],n,m,i,j,mi,in;
	bool ok=true;
	fin>>n>>m;
	for(i=1;i<=n;++i)
	for(j=1;j<=m;++j)
	fin>>a[i][j];
	for(j=1;j<=m;++j)
	{
		mi=1001;
		for(i=1;i<=n;++i)
		{
			if(a[i][j]<mi)
			mi=a[i][j];
		}
		fout<<mi<<" ";
	}
    return 0;
}
