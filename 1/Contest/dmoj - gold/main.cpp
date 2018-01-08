#include <iostream>
#include <string.h>

using namespace std;

int d[1005][1005];

int main()
{
    int sterge,insereaza,inlocuieste;
    char a[1005],b[1005],i,j;
    cin>>sterge>>insereaza>>inlocuieste;
    cin>>a>>b;
    int m=strlen(a),n=strlen(b);
    for(i=0;i<=m;i++)
        d[i][0]=i;
    for(j=0;j<=n;j++)
        d[0][j]=j;
   for(j=1;j<=n;j++)
     {
         for (i=1;i<=m;i++)
            if(a[i]==b[j])
            d[i][j]=d[i-1][j-1];
         else
         d[i][j]=min(d[i-1][j]+sterge,min(d[i][j-1]+insereaza,d[i-1][j-1]+inlocuieste));
    }
    cout<<d[m][n];
    return 0;
}
