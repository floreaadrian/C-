#include<iostream>
using namespace std;
int main()
{
	int d,i,n,p,c,a,ma=0;
	cin>>n;
	for(i=1;i<=n;++i)
	{
		cin>>a;
		d=2,p=0,c=0;
		while(a>1)
		{
			while(a%d==0)
			{
				a/=d;p++;
			}
			if(p)c++;
			d++;p=0;
		}
		if(c>ma)ma=c;
	}
	cout<<ma;
}
