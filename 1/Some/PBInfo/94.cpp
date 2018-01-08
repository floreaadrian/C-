#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	char a[21],v[]="aeiou";
	int i,n,l;
	cin>>a;
	l=strlen(a);
	for(i=0;i<l;++i)
	if(!strchr(v,a[i]))
	cout<<a[i];
}
