#include<fstream>
using namespace std;
ifstream f("submultimi.in");
ofstream g("submultimi.out");
int st[10000],k,n;
void afisare(int p)
{
	for(int i=1;i<=p;++i)
	g<<st[i]<<" ";
	g<<"\n";
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
			afisare(p);
			back(p+1);
		
	}
}
int main()
{
	f>>n;
	back(1);
	return 0;
}
