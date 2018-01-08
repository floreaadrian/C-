#include<iostream>

using namespace std;

int max(int a,int b)
{
	if(a>b)return a;
	return b;
}

int main()
{
	int a,i,unm=0,dom=0,trm;
	for(i=1;i<=5;i++)
	{
		cin>>a;
		unm=max(a,unm);
		if(unm>dom)
		{
			trm=dom;
			dom=unm;
		}
	}
	cout<<trm<<" "<<dom<<" "<<unm;
}
