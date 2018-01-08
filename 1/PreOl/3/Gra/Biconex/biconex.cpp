#include<fstream>
#define NMax 101
#define MMax NMax*(NMax-1)/2

using namespace std;

ifstream fin("graf.in");
ofstream fout("graf.out");

int n,num,VfS,nrfii,nr,start=3;
int a[NMax][NMax];
int dfn[NMax],low[NMax],Art[NMax];

struct Muchie{int f,t;
} s[MMax];
void citire(void);
void biconex(int,int);
void initializare(void);
void afisare(int,int);

int main()
{
	int i;
	citire();
	initializare();
	biconex(start,-1);
	if(nrfii>1)
	Art[start]=1;
	fout<<"Punctele de articulatie sunt: ";
	for(i=1;i<=n;i++)
	if(Art[i])fout<<i<<" ";
	return 0;
}

void citire()
{
	int x,y,m,i;
	fin>>n>>m;
	for(i=0;i<m;i++)
	{
		fin>>x>>y;
		a[x][0]++; a[x][a[x][0]]=y;
		a[y][0]++; a[y][a[y][0]]=x;
	}
}

void initializare()
{
	int i;
	for(i=1;i<=n;i++) dfn[i]=low[i]=-1;
	s[0].f=start;s[0].t=-1;VfS=0;
}

int min(int x,int y)
{
	if(x<y)return x;
	return y;
}

void biconex(int u,int tu)
{
	int x,p;
	dfn[u]=low[u]=++num;
	for(p=1;p<=a[u][0];p++)
	{
		x=a[u][p];
		if(x!=tu && dfn[x]<dfn[u])
		{
			s[++VfS].f=x;s[VfS].t=u;
		}
		if(dfn[x]==-1){
			if(u==start)
			nrfii++;
			biconex(x,u);
			low[u]=min(low[u],low[x]);
			if(low[x]>=dfn[u])
			{
				if(u!=start)Art[u]=1;
				afisare(x,u);
			}
		}else
		if(x!=tu)
		low[u]=min(low[u],dfn[x]);
	}
}

void afisare(int x,int u)
{
	Muchie p;
	nr++;
	fout<<"Componenta biconexa "<<nr<<" contine muchiile:\n";
	do
	{
		p=s[VfS--];
		fout<<p.t<<" "<<p.f<<"\n";
	}while(p.t!=u || p.f!=x);
}
