#include<iostream>
using namespace std;
int i_prim(int n)
{
	int ok=1,l,s,pok=1;
	l=n;s=n;
	while(ok)
	{
		l--;
		for(int d=2;d<=l/2;d++)
	{
		if(l%d==0) ok=0;
		else ok=1;
	}
	}
	while(pok)
	{
		s++;
		for(int d=2;d<=s/2;d++)
	{
		if(s%d==0) pok=0;
		else pok=1;
	}
	}
	return l;
}
int main()
{
	int n;
	cin>>n;
	cout<<i_prim(n);
	return 0;
}
