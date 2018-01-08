#include<iostream>
using namespace std;
int main()
{
	int v[1001],n,i,k=0,kmax=0,i_in,i_ul;
	cin>>n;
	for(i=1;i<=n;++i)
	cin>>v[i];
	for(i=1;i<n;++i)
	{
		if(v[i]==v[i+1])
		while(v[i]==v[i+1])
		{
			i++;
			k++;
		}
		if(k>=kmax)
		{
		kmax=k;
		i_ul=i;
	    i_in=i-k;
		}k=0;
	}
	cout<<i_in<<" "<<i_ul;
}
