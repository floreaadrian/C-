#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int s,i,n;
	cin>>n;
	for(i=1;i<=n;++i)
	s+=pow(i,4);
	cout<<s%10;
}
