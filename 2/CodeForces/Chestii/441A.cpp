#include<iostream>
using namespace std;
int d[50],f;
int main()
{
	int i,j,k,n,a,b,s,g;
	cin>>n>>s;
	for(i=0;i<n;++i)
	{
		cin>>a;
		g=0;
		for(j=1;j<=a;++j)
		{
			cin>>b;
			if(s>b && g==0)
			{
				d[f]=i;f++;g=1;
			}
		}
	}
	cout<<f<<"\n";
	for(i=0;i<f;++i)
	cout<<d[i]+1<<" ";
}
