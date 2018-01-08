#include<fstream>
#include<string.h>
using namespace std;
ifstream fin("palindrom.in");
ofstream fout("palindrom.in");
int main()
{
	int n,i,j,ln;
	char s[20],v[20];
	fin>>n;
	for(j=1;j<=n;++j)
	{
		fin>>s;
		ln=strlen(s);
		for(i=1;i<ln;++i)
		strcpy(s[i],v[ln-i]);
		if(strcmp(s,v)) fout<<1;
		else fout<<0;
	}
	return 0;
}
