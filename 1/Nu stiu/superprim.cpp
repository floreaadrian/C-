#include<iostream>
using namespace std;
int main()
{
	int n,i,j,a,k,d,ok;
	for(i=100;i<=999;++i)
	{
		ok=1;
		n=i;
		while(n>0 && ok)
		{
			for(d=2;d<=n/2;++d)
			if(n%d==0){ok=0;}
			n=n/10;
		}if(ok)cout<<i<<" ";
	}return 0;
}
