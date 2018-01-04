//
// Created by Adrian-Paul Florea on 12/9/17.
//

#include <iostream>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        char a[101][101];
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j)
                scanf("%c",a[i][j]);
    }
}