#include<iostream>
using namespace std;
int main()
{
	int m=0,i,j,n;
	cin>>n;
	while(n)
	{
		if(n%10>m)m=n%10;
		n/=10;
	}
	cout<<m;
}
