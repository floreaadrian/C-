#include<fstream>
#include<cstdlib>
#define NMax 1001
#define sgn(x) ((x)>0?1:0)

using namespace std;

ifstream fin("honest.in");
ofstream fout("honest.out");

typedef struct{
	int y,c;
}Opinion;
int n,m,total;
Opinion *G[NMax],*GT[NMax];
int d[NMax],di[NMax],o[NMax];
int s[NMax];

void read_it(void);
void write_it(void);
void solve(void);
void top_sort(void);

int main()
{
	read_it();
	top_sort();
	solve();
	write_it();
	return 0;
}

void read_it(void)
{
	int i,x,y; char c;
	fin>>n>>m;
	for(i=0;i<m;i++)
	{
		fin>>x>>c>>y;
		d[x]++;di[y]++;
		G[x]=realloc(G[x],d[x]*sizeof(Opinion));
		G[x][d[x]-1].y=y;
		GT[y]=realloc(GT[y],di[y]*sizeof(Opinion));
		GT[y][di[y]-1].y=x;
		if(c=='c')G[x][d[x]-1].c=GT[y][di[y]-1].c=1;
		else G[x][d[x]-1].c=GT[y][di[y]-1].c=-1;
	}
	fin.close();
}

void solve(void){
	int i,j,how;
	s[o[1]]=1;
	for(i=2;i<=n;i++)
	{
		how=0;
		for(j=0;j<=di[o[i]];j++)
		if(GT[o[i]][j].c>0)
		{
			if(!how)
			how=s[GT[o[i]][j].y];
			else if(s[GT[o[i]][j].y]*how<0)
			{
				fout<<"contradictie";return;
			}
		}else{
			if(!how)
			how=-s[GT[o[i]][j].y];
			else if(-s[GT[o[i]][j].y]*how<0)
			{
				fout<<"contradictie";return;
			}
		}
		s[o[i]]=how;
	}
}

void write_it(void)
{
	int i,sum=0,sgn=1;
	for(i=1;i<=n;i++)
	if(s[i]>0)sum++;
	if(sum<n/2)sgn=-1;
	for(i=1;i<=n;i++)
	if(sgn*s[i]<0) fout<<"0\n";
	else fout<<"1\n";
	fout.close();
}

void top_sort()
{
	int i,nr=0,j,sdi[NMax];
	for(i=1;i<=n;i++) sdi[i]=di[i];
	while(nr<n)
	{
		for(i=1;i<=n && sdi[i];i++)
		for(j=i+1;j<=n && sdi[j];j++)
		o[++nr]=i; sdi[i]=-1;
		for(j=0;j<d[i];j++) sdi[G[i][j].y]--;
	}
}
