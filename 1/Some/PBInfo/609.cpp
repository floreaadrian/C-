#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	char a[101],v[]="aeiou";
	int n,i,j,l;
	cin.getline(a,101);
	l=strlen(a);
	for(i=0;i<l;++i)
	{
		if(strchr(v,a[i]))
		cout<<a[i]<<a[i];
		else cout<<a[i];
	}
}
