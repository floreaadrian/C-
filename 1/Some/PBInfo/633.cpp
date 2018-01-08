#include<iostream>
using namespace std;
int main()
{
	int v[1001],i,p=0,im=0,n;
	cin>>n;
	for(i=1;i<=n;++i)
	{
		cin>>v[i];
		if(v[i]%2==0)p++;
		else im++;
	}
	if(p>im)cout<<p-im;else
	cout<<im-p;
}
