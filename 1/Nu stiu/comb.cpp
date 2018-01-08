#include<iostream>
using namespace std;
int st[10000],k,n;
void afisare(int p)
{
	for(int i=1;i<=p;++i)
	cout<<st[i]<<" ";
}
bool valid(int p)
{
	bool ok=true;
	for(int i=1;i<p;++i)
	if(st[i]==st[p])
	ok=false;
	return ok;
}
void back(int p)
{
	int pval;
	for(pval=st[p-1]+1;pval<=n;++pval)
	{
		st[p]=pval;
			if(k==p)afisare(p);
			else back(p+1);
		
	}
}
int main()
{
	cin>>n>>k;
	back(1);
	return 0;
}
