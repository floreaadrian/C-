#include<fstream>
#include<string.h>
using namespace std;

ifstream fin("vocmax.in");
ofstream fout("vocmax.out");

int main()
{
	int c=0,c1=0,l,n,i,j;
	char a[251],ac[251],v[]="aeiou";
	fin>>n;
	for(j=1;j<=n;++j)
	{
		c=0;
		fin.getline(a,251);
		l=strlen(a);
		for(i=0;i<l;++i)
		{
			if(strchr(v,a[i]))
			c++;
		}
		if(c>c1)
		strcpy(ac,a);
		c1=c;
	}
	fout<<ac;
}
