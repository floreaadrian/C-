#include<fstream>
#define NMax 101

using namespace std;

ifstream fin("graf.in");
ofstream fout("graf.out");

int n,nr,nrc,a[NMax][NMax],at[NMax][NMax],postordine[NMax],viz[NMax];

void Citire();
void DFS(int);
void DFST(int);

int main()
{
	int i;
	Citire();
	for(i=1;i<=n;i++)
	if(!viz[i])DFS(i);
	for(i=n;i>0;i--)
	if(viz[postordine[i]])
	{
		fout<<"Componenta tare-conexa "<<++nrc<<": ";
		DFST(postordine[i]);
		fout<<"\n";
	}
	return 0;
}

void Citire()
{
	int x,y,m,i;
	fin>>n>>m;
	for(i=1;i<=n;i++)
	{
		a[i][0]=0;
		at[i][0]=0;
	}
	for(i=0;i<m;i++){
		fin>>x>>y;
		a[x][0]++;
		a[x][a[x][0]]=y;
		at[y][0]++;
		at[y][at[y][0]]=x;
	}
}

void DFST(int x)
{
	int i;
	viz[x]=0;
	fout<<" "<<x;
	for(i=1;i<=at[x][0];i++)
	if(viz[at[x][i]])
	DFST(at[x][i]);
}

void DFS(int x)
{
	int i;
	viz[x]=1;
	for(i=1;i<=a[x][0];i++)
	if(!viz[a[x][i]])
	DFS(a[x][i]);
	postordine[++nr]=x;
}
