#include<iostream>
using namespace std;
int n,i,j,x[1000][1000],y,l[100][100],u,p,k,a[100][100],q[1000][1000],ma;
bool ok;
void init()
{
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=n;++j)
		l[i][j]==1;
	}
	k=0;
	for(i=1;i<=n;++i)
	for(j=1;j<=n;++j)
	{
		ok=true;
		if(i>1 && a[i-1][j]<a[i][j])
		ok=false;
		if(i<n && a[i+1][j]<a[i][j])
		ok=false;
		if(j<1 && a[i][j-1]<a[i][j])
		ok=false;
		if(j<n && a[i][j+1]<a[i][j])
		ok=false;
		if(ok)
		{
			l[i][j]=0;
			k++;
			x[1][k]=i;
			x[2][k]=j;
		}
	}	
}
void intr(int c,int d)
{
	u++;
	if(u>2000)
	{
		u=1;
	}
	q[1][u]=c;
	q[2][u]=d;
}
void extr(int c,int d)
{
	p++;
	if(p>2000)
	{
		p=1;
	}
	c=q[1][p];
	d=q[2][p];
}
int lee(int x,int y)
{
	p=0;u=0;
	intr(x,y);
	while(p!=u)
	{
		extr(x,y);
		if(x>1)
		{
			if(a[x-1][y]>a[x][y])
			{
				if(l[x-1][y]>l[x][y]+1)
				{
					l[x-1][y]=l[x][y]+1;
					intr(x-1,y);
				}
			}
		}
		if(x<n)
		{
			if(a[x+1][y]>a[x][y])
			{
				if(l[x+1][y]>l[x][y]+1)
				{
					l[x+1][y]=l[x][y]+1;
					intr(x+1,y);
				}
			}
		}
		if(y>1)
		{
			if(a[x][y-1]>a[x][y])
			{
				if(l[x][y-1]>l[x][y]+1)
				{
					l[x][y-1]=l[x][y]+1;
					intr(x,y-1);
				}
			}
		}
		if(y<n)
		{
			if(a[x][y+1]>a[x][y])
			{
				if(l[x][y+1]>l[x][y]+1)
				{
					l[x][y+1]=l[x][y]+1;
					intr(x,y+1);
				}
			}
		}
	}
}
void scrie()
{
	ma=-1;
	for(i=1;i<=n;++i)
	for(j=1;j<=n;++j)
	{
		if(l[i][j]>ma)
		ma=l[i][j];
	}
	cout<<ma;
}
int main()
{
	cin>>n;
	for(i=1;i<=n;++i)
	for(j=1;j<=n;++j)
	cin>>a[i][j];
	init();
	for(i=1;i<=k;++i)
	lee(x[1][i],x[2][i]);
	scrie();
	return 0;
}
