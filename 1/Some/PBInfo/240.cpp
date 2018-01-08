#include<fstream>
using namespace std;

ifstream fin("maxn.in");
ofstream fout("maxn.out");

int main()
{
	int v[100001],a[100001],i,j,n,m=0;
	fin>>n;
	for(i=1;i<=n;++i)
	{
		fin>>v[i];
		if(v[i]>m)m=v[i];
		a[i]=m;
	}
	for(i=1;i<=n;++i)
	{
		fout<<a[i]<<" ";
	}
}
