#include<iostream>
using namespace std;

void citmat(int a[][101],int &n,int &m)
{
	int i,j;
    for(i=0;i<n;++i)
    for(j=0;j<m;++j)
	cin>>a[i][j];
}
void Genereaza (int A[][10], int &x, int &y)
{
cout << "Nr. de linii: ";
cin >> x;
cout << "Nr. de coloane: ";
cin >> y;
for (int i=0; i<x; i++)
for (int j=0; j<y; j++)
cin>>A[i][j];
}
int main()
{   int T[51][51],M,i,j,N,x,y;
	cin>>N>>M;
	Genereaza (T, N, M);
	for(i=1;i<=N;++i)
	{
		for(j=1;j<=M;++j)
		cout<<T[i][j]<<" ";
		cout<<"\n";
	}
}
