#include<iostream>
using namespace std;
int main()
{
	int mi=0,i,a,n,c=1;
	cin>>n;
	cin>>a;
	mi=a;
	for(i=2;i<=n;++i)
	{
		cin>>a;
		if(a>mi){
			mi=a;c=1;
		}else if(mi==a)
		{
			c++;
		}
	}
	cout<<mi<<" "<<c;
}
