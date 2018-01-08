#include<iostream>
using namespace std;
int main()
{
	int d,i,p,c,a;
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
	cout<<c;
}
