#include<iostream>

using namespace std;

int main()
{
	int a,n,max=0,i,cifra,aux,nrmax;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a;
		aux=a;
		while(a>0)
		{
			cifra=a%10;
			a/=10;
		}
		if(cifra>max){
			max=cifra;
			nrmax=aux;
		}if(cifra==max){
			if(aux>nrmax)
			nrmax=aux;
		}
	}
	cout<<nrmax;
	return 0;
}
