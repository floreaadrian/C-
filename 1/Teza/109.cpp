#include<iostream>
using namespace std;
int main()
{
	int n,p,i=0,l=0;
	bool ok;
	cin>>n>>p;
	while(l<=n)
	{
		i=l;ok=false;
		while(i)
		{
			if(i%10<p){
				ok=true;
			}
			i/=10;
		}
		if(ok)cout<<l<<" ";
		l++;
	}
	return 0;
}
