#include<iostream>
using namespace std;
int main()
{
	int n,v[101],a[101],i,s=0,c=0;
	float me;
	cin>>n;
	for(i=1;i<=n;++i)
	{
	cin>>v[i]>>a[i];
	s+=v[i]*a[i];c+=v[i];
    }
	cout<<s<<" "<<(float)s/c;
}
