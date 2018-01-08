#include<fstream>
#include<string.h>
using namespace std;

ifstream fin("doarvocale.in");
ofstream fout("doarvocale.out");

int main()
{
	int c=0,i,l,n,j;
	bool kkk=true;
	char a[31],v[]="aeiou";
	fin>>n;
	for(j=1;j<=n;++j)
	{
		fin>>a;
		kkk=true;
		l=strlen(a);
		for(i=0;i<l;++i)
		{
			if(!strchr(v,a[i]))
			kkk=false;
		}
		if(kkk)c++;
	}
	fout<<c;
}
