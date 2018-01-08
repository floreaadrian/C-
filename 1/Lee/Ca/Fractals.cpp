#include<iostream>
using namespace std;
int main()
{
	double n,i,s,a;
	cin>>n>>a;
	s=3*n;
	while(a)
	{
		s=s+(s*(1/4));
		a--;
	}
	cout<<s;
}
