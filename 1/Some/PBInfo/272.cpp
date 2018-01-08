#include<fstream>

using namespace std;

ifstream fin("paresort.in");
ofstream fout("paresort.out");

int v[1001],pc[1001];

int main()
{
	int n,i,u,p,max,nr;
	fin>>n;
	nr=0;
	for(i=0;i<n;i++)
	{
		fin>>v[i];
		if(v[i]%2==0){
		pc[nr]=v[i];
		nr++;
		}
	}
	if(nr==0)
	fout<<"nu exista";
	else{
	for(u=nr-1;u>0;u--){
		max=pc[0];
		p=0;
		for(i=1;i<=u;i++){
			if(pc[i]>max){
			max=pc[i];
			p=i;
			}
		}
		pc[p]=pc[u];
		pc[u]=max;
	}
	for(i=0;i<nr;i++)
	fout<<pc[i]<<" "; 
	}
	return 0;
}
