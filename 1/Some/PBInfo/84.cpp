#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	char s[10],v[]="aeiouAEIOU",sch[2];
	int a,n,i,l,pozv,pozc;
	cin>>s;
	l=strlen(s);
	for(i=0;i<l;i++)
	{
		if(strchr(v,s[i]))
		{
		srtcpy(sch[0],s[i]);pozv=i;}
		break;
	}
	for(i=l-1;i>=0;i--)
	{
		if(strchr(v,s[i])==0)
		{
		strcpy(sch[1],s[i]);pozc=i;}
		break;
	}
	cout<<sch;
}
