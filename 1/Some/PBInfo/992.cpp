#include<iostream>
#include<string.h>
using namespace std;

int apcar(char s[],char c[])
{
	int co=0,l,i;
	l=strlen(s);
	for(i=0;i<l;++i)
	if(strchr(c,s[i]))
	co++;
	return co;
}

int main()
{
	char s[256],c[]="aeiouAEIOU";
	cin.getline(s,256);
	cout<<apcar(s,c);
}
