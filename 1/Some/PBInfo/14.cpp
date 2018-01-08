#include<iostream>
using namespace std;
int prim(int n)
{
	for(int d=2;d<=n/2;d++)
	{
		if(n%d==0)return 0;
	}return 1;
}
int main()
{
	int n;
	cin>>n;
	cout<<prim(n);
	return 0;
}
