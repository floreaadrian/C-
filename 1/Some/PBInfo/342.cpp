#include<fstream>
#include<queue>

using namespace std;

ifstream fin("date.in");
ofstream fout("date.out");

int di[8]={-1,-1,0,1,1,1,0,-1};
int dj[8]={0,1,1,1,0,-1,-1,-1};

int n,m,is,ib,js,jb,v[11][11],k=0,v1[11][11],i,j;

queue< pair <int , int > > coada;

void citire();
void lee();
bool ok(int,int);

void citire()
{
	fin>>n>>m;
	for(int i=1;i<=n;++i)
	for(int j=1;j<=m;++j)
	fin>>v[i][j];
	fin>>is>>js>>ib>>jb;
}

bool ok(int i,int j)
 {
 	if(i<1 || i>n || j<1 ||j>n)return false;
 	if(v[i][j]==1)return false;
 	return true;
 }

void lee()
 {
 	int i,j,i_urm,j_urm;
 	v1[is][js]=1;
 	coada.push(make_pair(is,js));
 	while( !coada.empty() )
 	{
 		i=coada.front().first;
 		j=coada.front().second;
 		coada.pop();
 		for(int dir=0 ; dir < 8 ; dir++ )
 		{
 			i_urm=i+di[dir];
 			j_urm=j+dj[dir];
 			if(ok(i_urm,j_urm) && v1[i_urm][j_urm] < 1)
 			{
 				v1[i_urm][j_urm]=v1[i][j]+1;
 				coada.push(make_pair(i_urm,j_urm));
			 }
		 }
	 }
 }

int main()
{
	citire();
	lee();
	fout<<v1[ib][jb];
	return 0;
}
