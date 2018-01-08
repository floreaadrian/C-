#include<iostream>
using namespace std;
int cmmdc(int a,int b)
{
	while(a!=b)
    if(a>b) a=a-b;
    else b=b-a;
    return b;
}
int main()
{
	int a[21][21],i,j,n,s1=0,s2=0;
	cin>>n;
	for(i=0;i<n;++i)
	for(j=0;j<n;++j)
	cin>>a[i][j];
	for(i=0;i<=n-2;i++)
    for(j=i+1;j<=n-1;j++)
    s1+=a[i][j];
    for(i=1;i<=n-1;i++)
    for(j=0;j<=i-1;j++)
    s2+=a[i][j];
    cout<<cmmdc(s1,s2);
}
