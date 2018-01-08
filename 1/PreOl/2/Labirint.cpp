#include<fstream>

using namespace std;

int Dx[8]={-1,-1,0,1,1,1,0,-1};
int Dy[8]={0,1,1,1,0,-1,-1,-1};
int L[20][20];
int n,m,xs,ys,xb,yb,NrSol;

ifstream fin("date.in");
ofstream fout("date.out");

void citire();
void afisare();
void cauta(int,int);
void Bordare();

void citire()
{
	fin>>n>>m>>xs>>ys>>xb>>yb;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	fin>>L[i][j];
	fin.close();
}

void afisare()
{
	fout<<"Solutia nr. "<<++NrSol<<"\n";
	for(int i=1;i<=n;i++)
	{
	   for(int j=1;j<=m;j++)
	   if(L[i][j]==2) fout<<"*";
	   else fout<<L[i][j];
	   fout<<"\n";
	}
	fout<<"\n";
}

void Bordare()
{ //bordam labirintul cu cate un perete
	for(int i=0;i<=n+1;i++) //peretele la stanga si la dreapta
	L[i][0]=L[i][m+1]=1;
	for(int i=0;i<=m+1;i++)
	L[0][i]=L[n+1][i]=1;
}

void cauta(int x,int y)
{
	L[x][y]=2; //marchez pozitia lui x,y
	if(x==xb && y==yb) afisare();
	else
	for(int dir=0;dir<8;dir++)
	if(!L[x+Dx[dir]][y+Dy[dir]]) //culoar nevizitat
	cauta(x+Dx[dir],y+Dy[dir]);
	L[x][y]=0;
}

int main()
{
	citire();Bordare();
	cauta(xs,ys);
	if(!NrSol)fout<<"Nu exista solutii!\n";
	return 0;
}
