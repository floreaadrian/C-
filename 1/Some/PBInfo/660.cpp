#include<iostream>
using namespace std;
int main()
{
	int n,i,j,v[101],m,c=0;
	cin>>n;
	for(i=1;i<=n;++i)
	cin>>v[i];
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=n;++j)
		{
			for(m=1;m<=n;++m)
			{
				if(v[i]<v[j]+v[m])c++;
			}
		}
	}
	cout<<c;
}
