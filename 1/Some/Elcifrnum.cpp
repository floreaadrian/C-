#include<iostream>
using namespace std;
int main()
{
	int p=0,n,i,k,nr=0;
	cin>>n>>k;
	while(n>0)
	{
		if(n%10!=k)
		{
			nr=nr+p*(n%10);
			p=p*10;  
			n=n/10;
		}
	}
	cout<<nr;
	return 0;
}
