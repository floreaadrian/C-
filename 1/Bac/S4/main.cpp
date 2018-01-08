#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
    int n,m,a[100][100];
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
        {
            if(i>j)a[i][j]=i;
            else a[i][j]=j;
        }
     for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=m;++j)
                printf("%d ",a[i][j]);
            printf("\n");
        }
    return 0;
}
