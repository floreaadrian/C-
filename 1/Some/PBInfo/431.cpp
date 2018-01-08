#include<fstream>

using namespace std;

ifstream fin("graf_complet.in");
ofstream fout("graf_complet.out");

int a[51][51];

int main()
{
	int n,m,x,y,c,i,j;
	fin>>m;
	while(m--){
		fin>>n;
		c=0;
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				fin>>a[i][j];
				if(a[i][j]==1)
				c++;
			}
		}
		if(c==(n*n)-n)
		fout<<"DA\n";else
		fout<<"NU\n";
	}
	return 0;
}
