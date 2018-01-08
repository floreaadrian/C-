#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	int l,i;
	char a[256],v[]="aeiou";
	cin.getline(a,256);
	l=strlen(a);
	for(i=0;i<l;++i)
	{
		if(strchr(v,a[i]))
		cout<<a[i]<<"p";
		else cout<<a[i];
	}
}
