#include<fstream>

using namespace std;

ifstream fin("date.in");
ofstream fout("date.out");

int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
int t[32][32],a[32][32],n,m,i_p,j_p,l_s,l_j;

void citire()
{
	int i,j;
	fin>>n>>m;
	fin>>i_p>>j_p;
	fin>>l_s>>l_j;
	for(i=1;i<=n;++i)
	for(j=1;j<=m;++j)
	fin>>a[i][j];
}

void bordare()
{
	int i,j;
	for(i=0;i<=n+1;++i) a[i][0]=a[i][m+1]=1000;
	for(j=0;j<=m+1;++j) a[0][j]=a[n+1][j]=1000;
}

void depune(int i,int j)
{
	int l,i_nou,j_nou;
	t[i][j]=1;
	for(l=0;l<4;l++)
	{
		i_nou=i+dx[l];j_nou=j+dy[l];
		if(t[i_nou][j_nou]==0)
		{
			if((a[i][j]>=a[i_nou][j_nou]) && (a[i][j]-a[i_nou][j_nou]<=l_j))
			depune(i_nou,j_nou);
			if((a[i][j]<a[i_nou][j_nou]) && (a[i_nou][j_nou]-a[i][j]<=l_s))
			depune(i_nou,j_nou);
		}
	}
}

int aria()
{
	int i,j,k,l,il,jl;
	int Max=0,p;
	for(i=1;i<=n;i++)
	  for(j=1;j<=m;j++)
	    if(t[i][j]) //pentru fiecare floare polenizata
	      for(k=1;k<=n;k++) //colt stanga sus
	        for(l=1;l<=m;l++) //se cauta
	          if(t[k][l]) //o alta floare polenizata
	          {
	          	//in dreptunghiul det de aceste doua flori se face
	          	//produsul elementelor (1-polenizata sau 0-nu)
	          	p=1;
	          	for(il=i;il<=k;il++)
	          	for(jl=j;jl<=l;jl++)
	          	p*=t[il][jl];
	          	if(p) //daca toate au fost 1
	          	 //am det un drept plin
	          	 if((k-i+1)*(l-j+1)>Max)Max=(k-i+1)*(l-j+1);
	          	 //retin maximul aflat pana acum
			  }
	return Max;
}

int main()
{
	citire();bordare();
	depune(i_p,j_p);
	int g=aria();
	fout<<g;
	return 0;
}
