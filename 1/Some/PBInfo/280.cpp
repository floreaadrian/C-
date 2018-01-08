#include<iostream>
using namespace std;
int pal(int n)
{
	int s=0,in=n;
	while(n)
	{
		s=s*10+n%10;
		n/=10;
	}
	if(s==in)return 1;
	return 0;
}
int main()
{
	int n,ma=0,c=0;
	cin>>n;if(n==0)return 0;
	if(pal(n))ma=n;c=1;
	do
	{
		cin>>n;
		if(pal(n)){
			if(n>ma){
				ma=n;c=1;
			}else
			if(n==ma)c++;
		}
	}while(n!=0);
	if(c==0)
	cout<<"NU EXISTA";else
	cout<<ma<<" "<<c;
	return 0;
}
