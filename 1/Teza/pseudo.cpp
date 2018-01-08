#include<iostream>
using namespace std;
int main()
{
	int a,b,s,n,p,x,nr,i,y,m;
	cin>>x>>m;
	y=1;
	while(m>0)
	{
		if(m%2==0)
		{
			m/=2;x=x*x;
		}else
		{
			m--;y=y*x;
		}
	}
	cout<<y;
}
