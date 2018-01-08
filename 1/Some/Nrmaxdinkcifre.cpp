#include<iostream>
using namespace std;
int nrmax(int n,int k)
{
	int p=0,l,i;
	l=n;
	for(i=9;i>=1;i--)
	{
		n=l;
		while(n>0)
		{
			if(n%10==i)
			{
			p=p+i;
			p=p*10;
			k--;
			}
			n=n/10;
			if(k==0)
			break;
		}
		if(k==0)
		break;
	}
	return p/10;
}
int main ()
{
	int n,k;
	cin>>n>>k;
	cout<<nrmax(n,k);
	return 0;
}
