#include<iostream>
using namespace std;
int main()
{
	int v[101],i,j,n,c=0,b=0;
	cin>>n;
	for(i=1;i<=n;++i)
	{
		cin>>v[i];
		if(v[i]%2==0)
		{
		c++;b=0;
		}
		else {
		b++;c=0;
		}
		if(b==3 || c==3)
		{
			cout<<"DA";
			return 0;
		}
	}
	cout<<"NU";
}
