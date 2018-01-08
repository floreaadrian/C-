#include<fstream>
#include<math.h>

using namespace std;

ifstream fin("input.in");
ofstream fout("output.out");

int main()
{
	int a[10001],b[10001],c[10001],n,i;
	fin>>n;
	for(i=1;i<=n;i++)
	fin>>a[i];
	for(i=1;i<=n;i++)
	fin>>b[i];
	int a1=0,b1=0;
	for(i=1;i<=n;i++)
	{
		if(a[i]==1)
		a1+=pow(2,i-1);
		if(b[i]==1)
		b1+=pow(2,i-1);
	}
	int c1=a1+b1;
	i=1;
	while(c1>0)
	{
		c[i]=c1%2;
		c1/=2;
		i++;
	}
	for(i=n+1;i>=1;i--)
	fout<<c[i]<<" ";
	return 0;
}
