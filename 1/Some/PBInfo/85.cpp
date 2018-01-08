#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	char a[101],v[]="aeiou";
	int l,i,n;
	bool ok=0;
	cin.getline(a,101);
	l=strlen(a);
	for(i=0;i<l;++i)
	if(strchr(v,a[i])!=0)
	ok=1;
	if(ok)
	{
		for(i=0;i<l;++i)
		if(strchr(v,a[i])!=0)
		cout<<a[i]<<"*";else
		cout<<a[i];
	}else
	cout<<"FARA VOCALE";
}
