#include<iostream>
using namespace std;
int main()
{
	float me;
	int a,n,i,c=0;
	cin>>n;
	for(i=1;i<=n;++i)
	{
		cin>>a;
		if(a%2==0){
			me+=a;c++;
		}
	}
	cout<<me/c;
}
