#include<iostream>
using namespace std;
int n,a[4001],ult,i,j,rez;
int d[4001][4001];
int main()
{
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i];
	for(i=1;i<=n;i++)
	for(j=ult=0;j<i;j++){
		d[i][j]=d[j][ult]+1;
		if(a[i]==a[j]) ult=j;
		if(d[i][j]>rez) rez=d[i][j];
	}
	cout<<rez;
	return 0;
}
