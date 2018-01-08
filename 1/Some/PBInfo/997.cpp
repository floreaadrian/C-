#include<fstream>
using namespace std;

ifstream fin("reuniune.in");
ofstream fout("reuniune.out");

int main()
{
	int v[1001],a[1001],i,j,n,m,b[2002],c=1;
	fin>>n>>m;
	for(i=1;i<=n;++i)
	fin>>a[i];
	for(i=1;i<=m;++i)
	fin>>v[i];
	for(i=1;i<=n;++i)
	for(j=1;j<=m;++j)
	{
		if(a[i]<v[j])b[c]=a[i];else 
		b[c]=v[j];
		c++;
	}
	for(i=1;i<=c;++i)
	fout<<b[i]<<" ";
}
