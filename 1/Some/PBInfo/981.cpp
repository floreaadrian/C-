#include<iostream>

using namespace std;

int ver(int n)
{
	while(n)
	{
		if(n%2==0)return 0;
		n/=2;
	}
	return 1;
}

int main()
{
	int a,c=0,b;
	cin>>a;
	for(int i=1;i<=a;i++)
	{
		cin>>b;
		if(ver(b))c++;
	}
	cout<<c<<"\n";
	return 0;
}
