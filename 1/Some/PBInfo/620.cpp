#include<iostream>
using namespace std;
int main()
{
	int a[101][101],n,m,i,j,aux,gasit;
	cin>>n>>m;
	for(i=1;i<=n;++i)
	for(j=1;j<=m;++j)
	cin>>a[i][j];
	for(j=1;j<=m;++j)
	{
	do
    {
    gasit=0;
    for(i=1;i<n;i++)
       if(a[i][j]<a[i+1][j])
    {
           aux=a[i][j];
           a[i][j]=a[i+1][j];
           a[i+1][j]=aux;
        gasit=1;
        }
    }while(gasit==1);
    }
for(i=1;i<=n;++i)
{
	for(j=1;j<=m;++j)
	cout<<a[i][j]<<" ";
	cout<<"\n";
}

}
