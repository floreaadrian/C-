#include<iostream>
using namespace std;
int main()
{
	int a[26],aux,i,n,x,p;
	cin>>n>>x>>p;n++;
	for(i=1;i<p;++i)
	cin>>a[i];
	a[p]=x;
	for(i=p+1;i<=n;++i)
	cin>>a[i];
	for(i=1;i<=n;++i)
	cout<<a[i]<<" ";
	return 0;
}
