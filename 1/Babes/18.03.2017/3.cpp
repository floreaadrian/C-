#include <iostream>

using namespace std;

void citire(int a[][101],int& n)
{
	cin>>n;
	for(int i=1;i<=n;++i)
	for(int j=1;j<=n;++j)
	cin>>a[i][j];
}

void afisare(int a[][101],int n){
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j)
		cout<<a[i][j]<<" ";
		cout<<"\n";
	}
}

void determinamMin(int& minN,int& minS,int& minV,int& minE,int a[][101],int n){
	minN=minS=minV=minE=1005;
	for(int i=1;i<=n;++i)
	for(int j=1;j<=n;++j){
		if(i<j && j<n-i+1 && a[i][j]<minN)minN=a[i][j];
		if(i<j && j>n-i+1 && a[i][j]<minE)minE=a[i][j];
		if(i>j && j<n-i+1 && a[i][j]<minV)minV=a[i][j];
		if(i>j && j>n-i+1 && a[i][j]<minS)minS=a[i][j];
	}
}

void afisareMin(int& minN,int& minS,int& minV,int& minE,int a[][101],int n)
{
	determinamMin(minN,minS,minV,minE,a,n);
	cout<<"minim N="<<minN<<"\n";
	cout<<"minim E="<<minE<<"\n";
	cout<<"minim V="<<minV<<"\n";
	cout<<"minim S="<<minS<<"\n";
}

void inlocuimMin(int& minN,int& minS,int& minV,int& minE,int a[][101],int n){
	for(int i=1;i<=n;++i)
	for(int j=1;j<=n;++j){
		if(i<j && j<n-i+1 && a[i][j]==minN)a[i][j]=minE;
		if(i<j && j>n-i+1 && a[i][j]==minE)a[i][j]=minS;
		if(i>j && j<n-i+1 && a[i][j]==minV)a[i][j]=minN;
		if(i>j && j>n-i+1 && a[i][j]==minS)a[i][j]=minV;
	}
}

int main() {
	int n,a[101][101];
	citire(a,n);
	int minN,minS,minV,minE;
	afisareMin(minN,minS,minV,minE,a,n);
	inlocuimMin(minN,minS,minV,minE,a,n);
	afisare(a,n);
	return 0;
}
