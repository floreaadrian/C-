#include<iostream>
using namespace std;
int main()
{
	int n,i,a,c=0,s=0;
	float ma;
	cin>>n;
	if(n%2==0)
	{
		c++;
		s+=n;
	}
	while(n!=a)
	{
		cin>>a;
		if(a%2==0)
	{
		c++;
		s+=a;
	}
	}
	ma=(float)s/c;
	cout<<ma<<" "<<c;
}
