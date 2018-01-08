#include<iostream>
using namespace std;
int val[10000];
int div(int i,int &a)
{
    if(a%i==0)
	{
	val[i]++;
	a=a%i;
	}
}
int main()
{
	int a,b=0,c,i,j;
	cin>>a;
	while(a>0)
	{
		for(i=2;i<=a;++i)
		div(i,a);
	}
	for(i=1;i<=6;++i)
	cout<<val[i];
	return 0;
}
