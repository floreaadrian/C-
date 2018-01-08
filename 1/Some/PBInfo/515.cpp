#include<iostream>

using namespace std;

int v[1001],d[1001];

int main()
{
	int n,u,p,i,aux,max;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>v[i];
		aux=v[i];
		while(aux){
			d[i]+=aux%10;
			aux/=10;
		}
	}
	for(u=n-1;u>0;u--){
		max=d[0];
		p=0;
		for(i=1;i<=u;i++){
			if(d[i]>max){
			max=d[i];
			p=i;
			}
		}
		v[p]=v[u];
		d[u]=max;
	}
	for(i=0;i<n;i++)
	cout<<v[i]<<" ";
}
