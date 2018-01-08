#include<fstream>

using namespace std;

ifstream fin("graf_partial_1.in");
ofstream fout("graf_partial_1.out");

int a[101][101],v[101];

int main()
{
	int n,i,j,x,y,m,m1,ok,c=0;
	fin>>n;
	m=m1=0;
	while(fin>>x>>y){
		a[x][y]=a[y][x]=1;
		m++;
	}
	m*=2;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++)
		v[i]+=a[i][j];
		if(v[i]<m)
		m=v[i];
		if(v[i]>m1)
		m1=v[i];
	}
	c=0;
	for(i=1;i<=n;i++){
		if(i==m){
			for(j=1;j<=n;j++)
			{
				if(j==m1){
					if(a[i][j]==1)
					{
						a[i][j]=0;
						c++;
					}
				}
			}
		}else
		if(i==m1){
			for(j=1;j<=n;j++){
				if(j==m){
					if(a[i][j]==1)
					{
						a[i][j]=0;
						c++;
					}
				}
			}
		}
	}
	fout<<c/2<<"\n";
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++)
		fout<<a[i][j]<<" ";
		fout<<"\n";
	}
	return 0;
}
