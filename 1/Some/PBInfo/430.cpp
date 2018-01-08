#include<fstream>

using namespace std;

ifstream fin("izolate.in");
ofstream fout("izolate.out");

int a[101][101],v[101];

int main()
{
	int n,m,x,y,i,j,c;
	fin>>n;
	while(fin>>x>>y){
		a[x][y]=a[y][x]=1;
	}
	c=0;
	for(i=1;i<=n;i++){
		m=0;
		for(j=1;j<=n;j++)
		{
			if(a[i][j]==1)
			m++;
		}
		if(m==0)
		{
			c++;
			v[c]=i;
		}
	}
	fout<<c<<" ";
	for(i=1;i<=c;i++)
	fout<<v[i]<<" ";
	return 0;
}
