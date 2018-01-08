#include<fstream>

using namespace std;

int Dx[4]={-1,0,1,0};
int Dy[4]={0,1,0,-1};
int a[50][50],m,n,NrObiecte;

ifstream fin("date.in");
ofstream fout("date.out");

void citire();
void Sterge_Obiect(int,int);

void citire()
{
	fin>>n>>m;
	for(int i=1;i<=n;++i)
	for(int j=1;j<=m;++j) fin>>a[i][j];
}

void Sterge_Obiect(int x,int y)
{
	if(a[x][y])
	{
		a[x][y]=0; //sterg acest element din imagine
		for(int dir=0;dir<4;dir++)
		Sterge_Obiect(x+Dx[dir],y+Dy[dir]);
	}
}

int main()
{
	citire();
	for(int i=1;i<=n;++i)
	for(int j=1;j<=m;++j)
	{
		if(a[i][j]) //am depistat un obiect
		{
			NrObiecte++;
			Sterge_Obiect(i,j);
		}
	}
	fout<<"Nr. obiecte = "<<NrObiecte<<"\n";
	return 0;
}
