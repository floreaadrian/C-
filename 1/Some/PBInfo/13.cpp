#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	int i,l,n=0,j,m;
	char s[11];
	cin>>s;
	l=strlen(s);
	m=l;
	for(j=0;j<l;++j)
	{
		for(i=0;i<m;++i)
		{
		cout<<s[i];
		}cout<<"\n";
		m--;
	}
	m=l;
	for(j=0;j<l;++j)
	{
		for(i=n;i<l;++i)
		cout<<s[i];
		cout<<"\n";
		n++;
	}
}
