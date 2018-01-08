#include<iostream>
#include<string.h>
using namespace std;
int main()
{
 char a[256],v[]="aeiou";
 int l,c=0,i;
 cin.getline(a,256);
 l=strlen(a);
 for(i=0;i<l;i++)
 {
 	if(strchr(v,a[i])!=0)
