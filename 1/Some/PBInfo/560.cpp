#include<iostream>

using namespace std;

int main()
{
	int n,i=0,c=1,m=0,i1,i2,r;
	cin>>n;
	i=0;r=1;
	while(i<n)
	{
		c=r;
		while(i<n && c>0)
		{
			i1=1;
			i++;
			c--;
		}
		r++;c=r;
		while(i<n && c>0)
		{
			i1=0;
			i++;
			c--;
		}
		if(i==n && c>0)
		i1=1;
		r++;
	}
	if(n%5==0){
		cout<<n/5<<"\n";
		cout<<"DA\n";
	}else{
		cout<<n/5+1<<"\n";
		cout<<"NU\n";
	}
	if(i1)cout<<"micsunele";else
	cout<<"panselute";
	return 0;
}
