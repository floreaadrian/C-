#include<iostream>
using namespace std;
int main()
{
	int a,d,p,s=0;
	cin>>a;
	d=2,p=0;
	while(a>1)
	{
		while(a%d==0)
		{
			a/=d;p++;
		}
		s+=p;
		d++;p=0;
	}
	cout<<s;
}
