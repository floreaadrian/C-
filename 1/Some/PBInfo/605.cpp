#include<fstream>

using namespace std;

ifstream fin("crb.in");
ofstream fout("crb.out");

int v[1001],pc[1001];

int main()
{
	int n,i,u,p,max,c;
	fin>>n;
	for(i=0;i<n;i++)
	{
		fin>>v[i];
		pc[i]=v[i];
	}
	for(u=n-1;u>0;u--){
		max=v[0];
		p=0;
		for(i=1;i<=u;i++){
			if(v[i]<max){
			max=v[i];
			p=i;
			}
		}
		v[p]=v[u];
		v[u]=max;
	}
	for(i=0;i<n;i++)
	if(v[i]==pc[i])
	c++;
	fout<<c;
}
