#include<iostream>
using namespace std;
int sum_cif(int n,int &s)
{
	while(n>0)
	{
		s+=n%10;
		n/=10;
	}
	return s;
}
int main()
{
	int n,s=0;
	cin>>n;
	sum_cif(n,s);
	cout<<s;
}
