#include<fstream>

using namespace std;

ifstream fin("date.in");
ofstream fout("date.out");

int dl[]={-1,0,1,0};
int dc[]={0,-1,0,1};

struct poz{
	char cul;//culoarea celulei
	int gr;//numarul grupului din care face parte celula
};

poz T[52][52];//tabla de joc
int n,m,linmax,colmin,nrclic;

void citire();
void afisare();
int prelucrare_tabla();
int det_grup(int,int,int,char);
void sterge_grup(int,int,int);
void refa_tabla(int,int);

int main()
{
	int dim;
	citire();
	do
	{
		linmax=0;colmin=m+1;
		dim=prelucrare_tabla();
		if(dim>1)
		{
			nrclic++;
			refa_tabla(linmax,colmin);
		}
	}while(dim>1);
	afisare();
	return 0;
}

void citire()
{
	int i,j;
	fin>>n>>m;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		fin>>T[i][j].cul;
	}
	//bordare
	for(i=0;i<=n+1;i++)  T[i][0].gr=T[i][m+1].gr=52*52+1;
	for(j=0;j<=m+1;j++)  T[0][j].gr=T[n+1][j].gr=52*52+1;
}

int det_grup(int grnum,int i,int j,char ch)
{
	int sum=1,k;
	if(T[i][j].cul!=ch)return 0;
	T[i][j].gr=grnum;
	for(k=0;k<4;k++)
	if(T[i+dl[k]][j+dc[k]].gr==0)
	sum+=det_grup(grnum,i+dl[k],j+dc[k],ch);
	return sum;
}

int prelucrare_tabla()
{
	int maxdim=0,dim,grnum=1,i,j;
	for(j=1;j<=m;j++)
	for(i=n;i>=1;i--)
	if(T[i][j].gr==0 && T[i][j].cul!=' ')//aceasta celula nu apartine nici unui grup
	{
		dim=det_grup(grnum,i,j,T[i][j].cul);
		//marcam grupul
		if(4>maxdim)
		{
			maxdim=dim;linmax=i;colmin=j;
		}else
		if(dim==maxdim)
		  if(j<colmin){
		  	colmin=j;linmax=i;
		  }else
		  if(j==colmin)
		    if(i>linmax)linmax=i;
		grnum++;
	}
	return maxdim;
}

void sterge_grup(int grnum,int i,int j)
{
	if(T[i][j].gr==grnum && T[i][j].cul!=' ')
	{
		T[i][j].cul=' ';
		sterge_grup(grnum,i-1,j);
		sterge_grup(grnum,i,j-1);
		sterge_grup(grnum,i+1,j);
		sterge_grup(grnum,i,j+1);
	}
}

void refa_tabla(int lin,int col)
{
	int i,j,i2,j2;
	sterge_grup(T[lin][col].gr,lin,col);
	for(j=1;j<=m;j++)
	{ //prelucram coloana j
		for(i=n;i>=1;i--)
		if(T[i][j].cul==' ')
		{//cauta mai sus un element colorat
		for(i2=i-1;i2>1 && T[i2][j].cul==' ';i2--);
		if(i2)//am gasit
			{
				T[i][j]=T[i2][j]; T[i2][j].cul=' ';
			}else break;
		}
	}
	for(j=1;j<=m;j++)
	if(T[n][j].cul==' ')//coloana j este vida
	{//caut in dreapta o coloana nevida
		for(j2=j+1;j2<=m && T[n][j2].cul==' ';j2++);
		if(j2<=m)//am gasit	
		//copiez coloana j2 peste coloanaj; sterg coloana j2
		for(i=1;i<=n;i++)
		{
			T[i][j]=T[i][j2];T[i][j2].cul=' ';
		}else break;
	}
	for(i=1;i<=n;i++)
	for(j=1;j<=m;j++)
	T[i][j].gr=0;
}

void afisare()
{
	fout<<nrclic<<"\n";
}
