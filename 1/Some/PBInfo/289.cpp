#include<iostream>
using namespace std;

int prim(int a)
{
	int d,i;
	d=a/2;
	for(i=3;i<=d;i+=2)
	{
		if(a%i==0)return 0;
	}
	return 1;
}

int main()
{
	int n,i,v[201];
	bool ok=false;
	cin>>n;
	for(i=1;i<=n;++i)
	{
		cin>>v[i];
		if(v[i]%2!=0)
		if(prim(v[i]))
		{
			cout<<"DA";
			return 0;
		}
	}
	cout<<"NU";
}
