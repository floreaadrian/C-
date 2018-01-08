#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	long long n,m,l;
	cin>>n;
	m=pow(n,(2007%4));
	while(m)
	{
		l=m%10;
		m/=10;
	}
	cout<<l;
}
