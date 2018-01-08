#include<iostream>
using namespace std;
int main()
{
	int mi=1000000,ma=0,v[1001],n,i,i_mi,i_ma;
	cin>>n;
	for(i=1;i<=n;++i)
	{
		cin>>v[i];
		if(v[i]>ma){
		ma=v[i];i_ma=i;}
		if(v[i]<mi){
		mi=v[i];i_mi=i;}
	}
	cout<<i_mi<<" "<<i_ma;
}
