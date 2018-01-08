#include<iostream>
using namespace std;
int main()
{
	int s=0,v[1001],i,n,i_in=0,i_sf;
	cin>>n;
	for(i=1;i<=n;++i)
	{
		cin>>v[i];
		while(i_in==0 && i<=n)
		{
			if(v[i]%2==0)
			{
				s+=v[i];
				i_in=i;
			}
			i++;
			cin>>v[i];
		}
		if(v[i]%2==0)
		{
			i_sf=i;
		}
	}
	for(i=i_in+1;i<=i_sf;++i)
	{
		s+=v[i];
	}
	if(s!=0)
	cout<<s;else
	cout<<"NU EXISTA";
	return 0;
}
