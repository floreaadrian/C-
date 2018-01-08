#include<iostream>
using namespace std;
int cmmnr(int n)
{
	int c=0,l;
	l=n;
	for(int i=1;i<=9;i++)
	{
		while(n>0)
		{
			if(n%10==i)
			c=c*10+i;
			n=n/10;
		}
		n=l;
	}
	return c;
}
int main()
{
	int n;
	cin>>n;
	cout<<cmmnr(n);
	return 0;
}
