#include<fstream>
using namespace std;

ifstream fin("bursa.in");
ofstream fout("bursa.out");

int main()
{
	long long s;
	int n,a[500000],i,i_min,i_max,mi=500000,ma=0,s1,s2,m2,m;
	fin>>n>>s;
	for(i=1;i<=n;++i)
	{
		fin>>a[i];
		if(a[i]<mi){
			mi=a[i];
			i_min=i;
		}
		if(a[i]>ma){
			ma=a[i];
			i_max=i;
		}
	}
	if(i_min<i_max)
	{
		fout<<ma*s-mi*s;
	}else
	{
	while(i_max--)
	{
		if(a[i_max]<m2)
		m2=a[i_max];
	}
	while(i_min++)
	{
		if(a[i_min]>m)
		m=a[i_min];
	}
	s1=ma*s-m2*s;
	s2=m*s-mi*s;
	if(s1>s2)
	fout<<s1;else 
	fout<<s2;
    }
	return 0;
}
