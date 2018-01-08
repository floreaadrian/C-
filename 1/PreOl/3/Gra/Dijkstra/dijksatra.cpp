#include<fstream>
#define NMaxVf 50
#define Inf 10000

using namespace std;

ifstream fin("graf.in");
ofstream fout("graf.out");

int n,x0;
double c[NMaxVf][NMaxVf];
int pre[NMaxVf],m[NMaxVf];
double d[NMaxVf];

void initializare();
void afisare();

int main()
{
	int i,VfMin,j;
	double dMin;
	initializare();
	for(j=1;j<n;j++)
	{
		dMin=Inf;
		for(i=1;i<=n;i++)
		if(!m[i] && dMin>d[i])
		{
			dMin=d[i];
			VfMin=i;
		}
		m[VfMin]=1;
		for(i=1;i<=n;i++)
		if(!m[i] && d[i]>dMin+c[VfMin][i])
		{
			pre[i]=VfMin;
			d[i]=dMin+c[VfMin][i];
		}
	}
	afisare();
	return 0;
}

void initializare()
{
	int i,j,M,x,y;
	double C;
	fin>>n>>M>>x0;
	for(i=1;i<=n;i++)
	for(j=i+1;j<=n;j++)
	c[j][i]=c[i][j]=Inf;
	for(i=1;i<=M;i++)
	{
		fin>>x>>y>>C;
		c[j][i]=C;
	}
	for(i=1;i<=n;i++)
	{
		d[i]=c[x0][i];pre[i]=x0;
	}
	m[x0]=1;pre[x0]=0;
	fin.close();
}

void afisare()
{
	int i,j,lg,dr[NMaxVf];
	for(i=1;i<=n;i++)
	if(i!=x0)
	{
		fout<<"Costul drumului de cost minim de la "<<x0<<" la "<<i<<" este "<<d[i]<<"\n";
		fout<<"Deumul de cost minim: ";
		dr[0]=i;lg=0;
		while(pre[dr[lg]]){
			lg++;
			dr[lg]=pre[dr[lg-1]];
		}
		for(j=lg;j>=0;j--)fout<<" "<<dr[j];
		fout<<"\n";
	}
}
