#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	char a[256];
	int n,l,i;
	cin.getline(a,256);
	l=strlen(a);
	a[0]=toupper(a[0]);
	for(i=0;i<l;++i)
	{
		if(strchr(" ",a[i+1]) || strchr(" ",a[i-1]))
		a[i]=toupper(a[i]);
	}
	cout<<a;
}
