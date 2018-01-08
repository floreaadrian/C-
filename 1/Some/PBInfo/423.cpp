#include<iostream>

using namespace std;

int main()
{
	int i,n;
	long long f,p,a;
	cin>>n;
	if(n==1)
	cout<<"1 1";
	else{
		cout<<1<<" "<<1<<" ";
		p=a=f=1;
		while(f<n)
		{
		f=p+a;
		if(f<=n)
		cout<<f<<" ";
		a=p;
		p=f;
		}
	}
	return 0;
}
