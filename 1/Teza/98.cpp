#include<iostream>
using namespace std;
int n,i=10,m;
int identic(int n)
{
int d,c;
c=n%10;
while (n>0)
{
d=n%10;
if(d==c)
n=n/10;
else
return 0;
}
if(n==0)
return 1;
}
int main()
{
cin>>n;
bool ok=true;
while(ok)
{
if(identic(i))
{
	m++;
}
if(m==n)
{
	cout<<i;
	return 0;
}
i++;
}
}
