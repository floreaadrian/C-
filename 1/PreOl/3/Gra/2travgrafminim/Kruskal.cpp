#include<fstream>
#define NMaxVf 50
#define NMaxMuchii NMaxVf*(NMaxVf-1)/2

using namespace std;

ifstream fin("graf.in");
ofstream fout("graf.out");

struct Muchie{ 
int e1,e2,cost;
};

Muchie G[NMaxMuchii];
int A[NMaxVf],c[NMaxVf];
int n,m;

void initializare()
{
	int i;
	fin>>n>>m;
	for(i=1;i<=m;i++)
	fin>>G[i].e1>>G[i].e2>>G[i].cost;
	for(i=1;i<=n;i++) c[i]=i;
}

void afisare()
{
	int i,CostApm=0;
	for(i=1;i<n;i++){
		fout<<"["<<G[A[i]].e1<<","<<G[A[i]].e2<<"] cost= "<<G[A[i]].cost<<"\n";
		CostApm+=G[A[i]].cost;
	}
	fout<<CostApm;
}

void sortaremuchii(int st,int dr)
{
	int i,j;
	Muchie x;
	if(st<dr){
		x=G[st];i=st;j=dr;
		while(i<j){
			while(i<j&&G[j].cost>=x.cost)j--;
			G[i]=G[j];
			while(i<j&&G[i].cost<=x.cost)i++;
			G[j]=G[i];
		}
		G[i]=x;
		sortaremuchii(st,i-1);
		sortaremuchii(i+1,dr);
	}
}

int main()
{
	int i,j,min,max,NrMSel;
	initializare();
	sortaremuchii(1,m);
	NrMSel=0;
	for(i=1;NrMSel<n-1;i++){
		if(c[G[i].e1]!=c[G[i].e2])
		A[++NrMSel]=i;
		if(c[G[i].e1]<c[G[i].e2]){
			min=c[G[i].e1];
			max=c[G[i].e2];
		}else {
			min=c[G[i].e2];
			max=c[G[i].e1];
		}
		for(j=1;j<=n;j++)
		if(c[j]==max) c[j]=min;
	}
	afisare();
	return 0;
}
