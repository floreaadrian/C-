#include<iostream>
using namespace std;
int main()
{
	long long a,b,n;
	cin>>n;
	for(int i=1;i<=n;++i)
	{
	cin>>a>>b;
	if((a*b)<=-1)
    cout<<"Overflow!"<<"\n";
    else cout<<a*b<<"\n";
	}
}
