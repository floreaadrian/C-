#include<iostream>
using namespace std;
int main()
{
	int a=1,n,i,m,b;
	bool ok=false;
	cin>>n;
	while(a<n)
	{
		if((a*a)+n==b*b)
		{
			ok=true;
			cout<<a<<" "<<b;
		}
		a++;
	}
	if(!ok)
	cout<<"nu exista";
	return 0;
}
