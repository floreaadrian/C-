#include<iostream>
using namespace std;
int main()
{
	int ma,mi,n,i,dif,v[1001],c=0,i_in=1,i_sf=1;
	cin>>n;
	cin>>v[1];ma=v[1];mi=v[1];
	for(i=2;i<=n;++i)
	{
		cin>>v[i];
		if(v[i]>ma){
		ma=v[i];i_sf=i;
		}
		if(v[i]<mi){
		mi=v[i];
		i_in=i;
		}
    }
    if(i_in>i_sf)
    {
    	dif=i_sf;
    	i_sf=i_in;
    	i_in=dif;
	}
	for(i=i_in;i<=i_sf;++i)
	{
		cout<<v[i]<<" ";
	}
}
