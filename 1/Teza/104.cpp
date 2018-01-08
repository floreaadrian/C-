#include<iostream>
using namespace std;
int main()
{
	int n,i,c=0,l,a;
	cin>>n;
	a=n;
	while(a)
	{
		c++;a/=10;
	}
	cout<<c;
	return 0;
}
