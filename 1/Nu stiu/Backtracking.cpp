#include<fstream>
using namespace std;
ifstream cin("permutari1.in");
ofstream cout("permutari1.in");
int st[10000],n;
void afisare(int p)
{
	for(int i=n;i>=1;i--)
	{
		cout<<st[i]<<" ";
	}cout<<"\n";
}
bool verf(int p)
{
	bool ok=true;
	for(int i=1;i<p;++i)
	{
		if(st[p]==st[i])
		ok=false;
	}
	return ok;
}
void back(int p)
{
	int pval;
	for(pval=1;pval<=n;pval++)
	{
		st[p]=pval;
		if(verf(p))
		{
			if(p==n)
			afisare(p);
		else back(p+1);
	}}
}
int main()
{
	cin>>n;
	back(1);
	return 0;
}
