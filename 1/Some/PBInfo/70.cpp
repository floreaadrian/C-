#include<iostream>
using namespace std;
int multipli(int a,int b,int c)
{
	int s=0;
	for(int i=a;i<=b;++i)
	{
		if(i%c==0)s++;
	}
	return s;
}
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	cout<<multipli(a,b,c);
}
