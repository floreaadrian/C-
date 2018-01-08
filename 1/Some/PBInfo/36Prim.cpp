#include<iostream>
#include<math.h>
using namespace std;

int d1,d2;

void i_prim(int n)
{
	bool ok=1,prim=1;
	int d,i;
	d1=n-1;d2=n-1;
	while(ok)
	{
		prim=true;
		if(d1%2==0)
		{
			d1--;
		}else {
		d1--;
		i=sqrt(d1);
		while(prim && i>=3)
		{
			if(d1%i==0)prim=false;
		}
	    }
		cout<<d1<<" ";
	}
	cout<<d1;
	ok=true;
	while(ok)
	{
		d2++;
		d=d2/2;
		if(d2%2==0)
		{
			d2++;
		}else
		for(int i=3;i<=d;++i)
		{
			if(d2%i==0) ok=false;
		}
	}
}

int main()
{
	int n,s=0;
	cin>>n;
	i_prim(n);
}
