#include<fstream>

using namespace std;

ifstream fin("grade.in");
ofstream fout("grade.out");

int a[101][101];

int main()
{
	int n,m,x,y,i,j;
	fin>>n;
	while(fin>>x>>y){
		a[x][y]=a[y][x]=1;
	}
	for(i=1;i<=n;i++){
		m=0;
		for(j=1;j<=n;j++)
		{
			if(a[i][j]==1)
			m++;
		}
		fout<<m<<" ";
	}
	return 0;
}
