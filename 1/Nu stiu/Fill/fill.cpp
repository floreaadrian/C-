#include<fstream>
#include<iostream>
#include<iomanip>
using namespace std;
int a[100][100],n,m,r1=0,r0=0,g0=0,g1=0,b1=0,b0=0,nr=0;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

void fill(int x,int y,int k)
{
	if(a[x][y]==k)
	{
		a[x][y]=k;
		for(int i=0;i<4;++i)
		{
			fill(x+dx[i],y+dy[i],k);
		}
	}
}

int main()
{
    int i,j;
    ifstream f("fill.in");
    f>>m>>n;
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
            f>>a[i][j];
    int max=0;
    int k=1; 
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
            {
			if(a[i][j]==2){
                r0++;
                fill(i,j,2);
            }
            if(a[i][j]==1){
                g0++;
                fill(i,j,1);
            }
            if(a[i][j]==3){
                fill(i,j,3);
                b1++;
            }
		}
    cout<<r0<<" "<<g0<<" "<<b1;
}
