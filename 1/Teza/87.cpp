#include<iostream>
using namespace std;
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	if(a<b && b<c){
		cout<<1;return 0;
	}
	if(a>b && b>c)
	{
		cout<<2;return 0;
	}
	if(b>a && b>c){
		cout<<3;return 0;
	}
	if(b<a && b<c)
	{
		cout<<4;return 0;
	}
}
