#include<fstream>

using namespace std;

ifstream fin("gradmax.in");
ofstream fout("gradmax.out");

int a[101][101],v[101];

int main()
{
	int n,m,j,i,x,y,nr;
	fin>>n;
	while(fin>>x>>y){
		a[x][y]=a[y][x]=1;
	}
	m=0;
	nr=1;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++)
		v[i]+=a[i][j];
		if(v[i]>m){
			m=v[i];
			nr=1;
		}else if(v[i]==m)nr++;
	}
	fout<<nr;
	for(i=1;i<=n;i++)
	if(v[i]==m)
	fout<<" "<<i;
	return 0;
}
