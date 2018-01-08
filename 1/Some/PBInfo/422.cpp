#include<fstream>

using namespace std;

ifstream fin("graf_partial_2.in");
ofstream fout("graf_partial_2.out");

int a[101][101],v[101];

int main()
{
	int n,i,j,x,y,m,m1,ok,c;
	fin>>n;
	m1=0;
	while(fin>>x>>y){
		a[x][y]=a[y][x]=1;
		m++;
	}
	m*=2;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++)
		v[i]+=a[i][j];
		if(v[i]>m1)
		m1=v[i];
	}
	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		if(v[i]==m1 || v[j]==m1)
		{
			fout<<i<<" "<<j<<"\n";
		}
	}
	c=0;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++)
		if(a[i][j]==1)
		c++;
	}
	fout<<(m-c)/2<<"\n";
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++)
		fout<<a[i][j]<<" ";
		fout<<"\n";
	}
	return 0;
}
