#include<iostream>
using namespace std;
int main()
{
	int a,b,c,k=0;
	cin>>a;
	while(cin>>a>>b>>c)
	{if((a+b+c)>1)
	k++;
	}
	cout<<k;
	return 0;
}
