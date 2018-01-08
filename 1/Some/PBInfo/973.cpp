#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	char a[256],v[]="aeiou";
	int i,n,l,j,pozi;
	bool ok;
	cin.getline(a,256);
	l=strlen(a);
	for(i=0;i<l;++i)
	{
		if(!strchr(v,a[i]))
		ok=false;
		if(strchr(" ",a[i]))
		{
			if(ok)
			for()
		}
	}
}
