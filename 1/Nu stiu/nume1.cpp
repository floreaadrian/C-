#include<iostream>
#include<string.h>
using namespace std;
int k,n;
char st[1000],u[2];
void afisare(int p)
{
	for(int i=1;i<=p;++i)
	cout<<st[i]<<" ";
}
int verf(int p)
{
	if(p>1&&st[p-1]=='a'&&st[p]=='a')return 0;else return 1;
}
void back(int p)
{
	u[1]='a';u[2]='m';
	int pval;
	for(pval=1;pval<=2;++pval)
	{st[p]=u[p];
	if(verf(p))
	{
		if(p==3)afisare(p);else back(p+1);
	}
	}
}
int main()
{
	back(1);
	return 0;
}
