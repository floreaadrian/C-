#include<iostream>
#include<math.h>
using namespace std;
bool prim(int n)
{
	int d=2,l;
	if(n%2==0)return 0;
	d++;
	l=sqrt(n);
	for(int i=d;i<=l;i+=2)
	if(n%i==0)return 0;
	return 1;
}
int main()
{
	int n,x[201],y[201],c=1,i;
	cin>>n;
	//if(prim(n))cout<<"p";else cout<<1;
	for(i=1;i<=n;++i)
	{
		cin>>x[i];
	}
	for(i=n;i>=1;i--)
	{
		if(prim(x[i]))
		{
			y[c]=x[i];
			c++;
		}
	}
	for(i=1;i<c;++i)
	cout<<y[i]<<" ";
}
