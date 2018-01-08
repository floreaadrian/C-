#include<iostream>
using namespace std;
int main()
{
	int v[501],i,n,a,j;
	cin>>n;
	for(i=1;i<=n;++i)
	cin>>v[i];
	for(i=1;i<=n;++i)
	{
		for(j=i+1;j<=n;++j)
		{
			if(v[i]==v[j]){
				cout<<"NU";return 0;
			}
		}
	}
	cout<<"DA";
}
