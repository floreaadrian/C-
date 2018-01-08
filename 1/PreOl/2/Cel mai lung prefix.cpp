#include<fstream>
#include<ctype.h>
#include<string.h>

using namespace std;

ofstream fout("date.out");

int Dx[8]={-1,-1,0,1,1,1,0,-1};
int Dy[8]={0,1,1,1,0,-1,-1,-1};
char s[200];
int Lg,LgMax,n,m;
char C[30][30];

void citire();
void bordare();
void cauta(int,int);

void citire()
{   
    ifstream fin("date.in");
	fin.getline(s,200); fin>>n>>m; fin.get();
	for(int i=1;i<=n;++i)
	{
	for(int j=1;j<=m;++j)
    fin.get(C[i][j]);
    fin.get();
	}
	fout.close();
}

void bordare()
{//bordez matricea cu spatii
	for(int i=0;i<=n+1;i++) C[i][0]=C[i][m+1]=' ';
	for(int j=0;j<=m+1;j++) C[0][j]=C[0][n+1]=' ';
}

void cauta(int i,int j)
{
	if(tolower(C[i][j])==tolower(s[Lg]))
	{
		Lg++;
		for(int k=0;k<8;++k) cauta(i+Dx[k],j+Dy[k]);
		Lg--;
	}else
	if(Lg>LgMax)LgMax=Lg;
}

int main()
{
	citire();bordare();
	for(int i=1;i<=n;++i)
	for(int j=1;j<=m;++j) cauta(i,j);
	//s[LgMax]=NULL;
	fout<<"Prefixul maximal este "<<s;
	return 0;
}
