#include<fstream>
#define NMax 101
#define MMax NMax*(NMax-1)/2

using namespace std;

ifstream fin("graf.in");
ofstream fout("graf.out");

typedef struct {int x,y;
} Muchie;
int n,m;
Muchie G[MMax];
int C[NMax];

void Citire();
void Desc_Comp_con();
void Afisare();

int main()
{
	Citire();
	Desc_Comp_con();
	Afisare();
	return 0;
}

void Citire()
{
	int i;
	fin>>n>>m;
	for(i=0;i<m;i++)
	fin>>G[i].x>>G[i].y;
}

void Desc_Comp_con()
{
	int i,j,min,max;
	for(i=1;i<=n;i++)C[i]=i;
	for(j=0;j<m;j++)
	if(C[G[j].x]!=C[G[j].y])
	{
		if(C[G[j].x]<C[G[j].y])
		min=C[G[j].x],max=C[G[j].y];
		else
		min=C[G[j].y],max=C[G[j].x];
		for(i=1;i<=n;i++)
		if(C[i]==max)C[i]=min;
	}
}

void Afisare()
{
	int nrc=0,i,j;
	for(i=1;i<=n;i++)
	if(C[i])
	{
		nrc++;
		fout<<"Componenta conexa "<<nrc<<": "<<i;
		for(j=i+1;i<=n;j++)
		if(C[j]==C[i]){
			fout<<" "<<j;
			C[j]=0;
		}
		fout<<"\n";
	}
}
