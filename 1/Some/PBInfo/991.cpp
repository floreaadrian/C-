#include<iostream>
using namespace std;
int main()
{
	int a[101][101],n,i,j,s=0;
	cin>>n;
	for(i=1;i<=n;++i)
	for(j=1;j<=n;++j)
	cin>>a[i][j];
	for(i=1;i<=n-1;i++)
    for(j=i;j<=n-1;j++)
    s+=a[i][j];
    cout<<s;
}
