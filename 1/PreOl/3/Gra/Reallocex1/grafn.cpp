#include<fstream>
#include<cstdlib>
#define NMax 101

using namespace std;

ifstream fin("grafn.in");
ofstream fout("grafn.out");

int n;
int *a[NMax];

void citire();
void afisare();

int main()
{
	citire();
	afisare();
	return 0;
}

void citire(){
	int x,y,m,i;
	fin>>n>>m;
	for(i=1;i<=n;i++){
		a[i]=(int *)realloc(a[i],sizeof(int));
		a[i][0]=0;
	}
	for(i=0;i<m;i++){
		fin>>x>>y;
		a[x][0]++;
		a[x]=(int *)realloc(a[x],(a[x][0]+1)*sizeof(int));
		a[x][a[x][0]]=y;
		a[y][0]++;
		a[y]=(int *)realloc(a[y],(a[y][0]+1)*sizeof(int));
		a[y][a[y][0]]=x;
	}
}
void afisare(){
	int i,j;
	for(i=1;i<=n;i++)
	{
		fout<<"Lista de adiacenta a varfului "<<i<<": ";
		for(j=1;j<=a[i][0];j++)fout<<a[i][j]<<" ";
		fout<<"\n";
	}
}
