#include<iostream>
using namespace std;
int sum_div(int &n)
{
	int m;
	m=n;n=1;
	for(int i=2;i<=m/2;++i)
	if(m%i==0)n+=i;
}
int main()
{
	int n;
	cin>>n;
	sum_div(n);
	cout<<n;
}
