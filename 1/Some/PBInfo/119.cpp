#include<iostream>
using namespace std;
int main()
{
	int mi1,mi2=0,n,i,a;
	cin>>n>>mi1;
	for(i=2;i<=n;i++)
	{
		cin>>a;
		if(a>=mi1)
		{
			mi2=mi1;
			mi1=a;
		}
	}
	cout<<mi1<<" "<<mi2;
}
