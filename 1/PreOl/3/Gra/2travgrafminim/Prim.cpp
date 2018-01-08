#include<fstream>
#define NMaxVf 100
#define Inf 10000

using namespace std;

ifstream fin("graf.in");
ofstream fout("graf.out");

int n,r,i,VfMin,nrv;
double g[NMaxVf][NMaxVf];
int p[NMaxVf],Z[NMaxVf];
double cmin[NMaxVf],CostMin;

void initializare()
{
	int i,j,k;
	double c;
	fin>>n>>r;
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	g[i][j]=Inf;
	for(i=1;i<=n;i++){
		g[i][i]=0;
		fin>>nrv;
		for(j=1;j<=nrv;j++){
			fin>>k>>c;
			g[i][k]=c;
		}
	}
	for(i=1;i<=n;i++)
	{
		cmin[i]=g[r][i];
		p[i]=r;Z[i]=1;
	}
	Z[r]=0; p[r]=0; nrv=n-1;
}

void afisare()
{
	int i;
	double cost=0;
	for(i=1;i<=n;i++)
	if(i!=r){
		fout<<p[i]<<" "<<i<<"\n";
		cost+=g[i][p[i]];
	}
	fout<<cost;
}

int main()
{
	initializare();
	while(nrv){
		CostMin=Inf;
		for(i=1;i<=n;i++){
			if(Z[i] && CostMin>cmin[i]){
				CostMin=cmin[i];
				VfMin=i;
			}
		}
		Z[VfMin]=0;
		nrv--;
		for(i=1;i<=n;i++)
		if(Z[i] && g[i][VfMin]<cmin[i])
		{
			p[i]=VfMin;
			cmin[i]=g[i][VfMin];
		}
	}
	afisare();
	return 0;
}
