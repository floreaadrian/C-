#include<iostream>
using namespace std;
int UCP(long long a)
{
bool ok=true;
while(ok)
{
	if(a%2==0)
	return a%10;
	a/=10;
}
}
int main()
{
	int n;
	cin>>n;
	cout<<UCP(n);
}
