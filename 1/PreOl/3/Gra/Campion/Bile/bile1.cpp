#include<fstream>
#define maxn 301

using namespace std;

ifstream fin("bile1.in");
ofstream fout("bile1.out");

int n,m,res,nrviz;
int g[maxn][maxn],gt[maxn][maxn];
int d[maxn],dt[maxn],viz[maxn];

void dfs(int);
void dfsT(int);
void citire();
void rezolvare();

int main()
{
	citire();
	rezolvare();
	fout<<res<<"\n";
	return 0;
}

void citire()
{
	int tmp1,tmp2,i,j;
	for(i=0;i<maxn;i++)
	{
		d[i]=0;dt[i]=0;
		for(j=0;j<maxn;j++)
		g[i][j]=gt[i][j]=0;
	}
	fin>>n>>m;
	for(i=0;i<m;i++)
	{
		fin>>tmp1>>tmp2;
		tmp1--;tmp2--;
		g[tmp1][d[tmp1]]=tmp2;d[tmp1]++;
		gt[tmp2][dt[tmp2]]=tmp1;dt[tmp2]++;
	}
	fin.close();
}

void rezolvare()
{
	int i,j;
	for(i=0;i<n;i++)
	{
		nrviz=0;
		for(j=0;j<n;j++) viz[j]=0;
		dfs(i);
		if(nrviz>=((n+1)/2))res++;
		else
		{
			nrviz=0;
			for(j=0;j<n;j++) viz[j]=0;
			dfsT(i);
			if(nrviz>=((n+1)/2)) res++;
		}
	}
}

void dfs(int i)
{
	int j;
	for(j=0;j<d[i];j++)
	if(viz[g[i][j]]==0)
	{
		viz[g[i][j]]=1;
		nrviz++;
		dfs(g[i][j]);
	}
}

void dfsT(int i)
{
	int j;
	for(j=0;j<dt[i];j++)
	if(viz[gt[i][j]]==0)
	{
		viz[gt[i][j]]=1;
		nrviz++;
		dfsT(gt[i][j]);
	}
}
