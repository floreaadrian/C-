#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	char a[256],v[]="aeiou";
	int c=0,i,l,n,c1=1;
	cin.getline(a,256);
	l=strlen(a);
	for(i=0;i<l;++i)
	{
		c1=0;
		if(strchr(v,a[i]))
		{
			while(strchr(v,a[i]))
			{
				i++;
				c1++;
			}
		}
		if(c1>=2)c++;
	}
	cout<<c;
}
