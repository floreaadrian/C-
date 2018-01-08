#include<fstream>
#define MAXN 14
#define DoiLa 8192
#define Inf 30000

using namespace std;

ifstream fin("caini.in");
ofstream fout("caini.out");

typedef struct{
	int T[MAXN],mal;
} Config;
int c[DoiLa];
int G[MAXN][MAXN];
int n,max1=-1,nrc=0,NrCaini=0,Dusman[MAXN];
Config S;
int ConfigToNr(Config);
void NrToConfig(int,Config*);
void Succesor(int);
void CitGraf(void);
int NrMinMutari(int);
void Afisare(int,int);

int ConfigToNr(Config S)
{
	int rez=0,i;
	for(i=n;i>0;i--) rez=rez*2+S.T[i];
	return rez*2+S.mal;
}

void NrToConfig(int k,Config* S)
{
	int i;
	S->mal=k%2;k/=2;
	for(i=1;i<=n;i++)
	{
		S->T[i]=k%2;
		k/=2;
	}
}

void Succesor(int k)
{
	int i;
	if(k>n)
	{
		if(NrCaini>max1)
		max1=NrCaini;
		S.mal=0;
		c[nrc++]=ConfigToNr(S);
		S.mal=1;
		c[nrc++]=ConfigToNr(S);
	}else
	{
		S.T[k]=0;
		Succesor(k+1);
		if(!Dusman[k])
		{
			for(i=1;i<=G[k][0];i++)
			Dusman[G[k][i]]++;
			S.T[k]=1;
			NrCaini++;
			Succesor(k+1);
			for(i=1;i<=G[k][0];i++)
			Dusman[G[k][i]]--;
			NrCaini--;
		}
	}
}

void CitGraf()
{
	int k,a,b,i;
	fin>>n>>k;
	for(i=0;i<k;i++)
	{
		fin>>a>>b;
		G[a][0]++; G[a][G[a][0]]=b;
		G[b][0]++; G[b][G[b][0]]=a;
	}
	fin.close();
}

int NrMinMutari(int maxloc)
{
	int Dist[DoiLa],Q[DoiLa],p,u,i,k,j,start,cati;
	Config S,S1;
	for(i=0;i<DoiLa;Dist[i++]=-1)
	Dist[0]=0;
	Q[0]=0;p=u=0;
	while(p<=u)
	{
		k=Q[p++];
		NrToConfig(k,&S);
		start=(S.mal) ? 1:0;
		for(i=start;i<nrc;i+=2)
		{
			int k1=c[i];
			NrToConfig(k1,&S1);
			if(Dist[k1]==-1)
			{
				cati=0;
				for(j=1;j<=n;j++)
				if(S1.T[j])
				{
					if(S.T[j])
					{
						cati=Inf; break;
					}
					}else if(!S.T[j]) cati++;
					if(cati<=maxloc)
					{
						Dist[k1]=Dist[k]+1;
						if(k1==1) return Dist[k1];
						Q[++u]=k1;
					}
			}
		}
	}
	return -1;
}

void Afisare(int minmut,int minloc)
{
	fout<<minloc<<" "<<minmut<<"\n";
}

int main()
{
	int t;
	CitGraf();
	Succesor(1);
	t=NrMinMutari(n-max1);
	if(t!=-1) Afisare(t,n-max1+1);
	else Afisare(NrMinMutari(n-max1+1),n-max1+2);
	return 0;
}
