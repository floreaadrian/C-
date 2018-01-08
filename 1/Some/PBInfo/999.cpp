#include<fstream>
using namespace std;

ifstream fin("numere7.in");
ofstream fout("numere7.out");

int main()
{
	int a,b,a1,b1,c=0,n,i=9,nou,c1;
	fin>>a>>b;a1=a;b1=b;
	while(a)
	{
		c=c*10+a%10;
		if(c%10<i && c%10>0)
		{
		i=c%10;	
		}
		a/=10;
		
	}
	while(b)
	{
		c=c*10+b%10;
		if(c%10<i && c%10>0)
		{
		i=c%10;	
		}	
		b/=10;
	}
	nou=i;
	while(c)
	{
		c1=c;
		for(i=0;i<=9;++i)
		{
			if(c1%10==i)
			nou=nou*c1%10;
			c1/=10;
		}
		c/=10;
	}
	fout<<nou;
	return 0;
}
