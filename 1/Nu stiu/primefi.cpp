#include<iostream>
using namespace std;
int main()
{
	int a,i,n,ok;
	cin>>n;
	ok=1;
	for(i=2;i<=n/2;i=i+2)
	{
		if(n%i==0)ok=0;break;
	}
	if(ok)
	cout<<"Prim";else cout<<"Nu e prim";
	return 0;
}
