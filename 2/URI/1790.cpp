#include<iostream>
#include<set>
#include<vector>
#include<string.h>
#include <climits>
using namespace std;
int n,m,k,i,j,x,y,critic=0,timp,depth[1251],lowLink[1251],viz[1251];
vector <int> a[1251];
void df(int Node, int Father, int actLevel) {
    depth[Node] = lowLink[Node] = actLevel;
    viz[Node] = 1;
    for(int i=0;i<a[Node].size();i++)
        {
            if(a[Node][i] == Father) continue;
            if(!viz[a[Node][i]]) {
            df(a[Node][i], Node, actLevel + 1);
            lowLink[Node] = min(lowLink[Node], lowLink[a[Node][i]]);
             } else lowLink[Node] = min(lowLink[Node], depth[a[Node][i]]);
        }
    if(lowLink[Node]>depth[Father]) critic++;
    }
int main()
{
	while(!cin.eof())
    {
	cin>>n>>m;
	if(m)
    {
	for(i=1;i<=m;i++) {cin>>x>>y; a[x].push_back(y);
	a[y].push_back(x);}
	depth[0]=INT_MAX;
    df(1,0,1);
    cout<<critic<<"\n";
    }
    else cout<<"\n";
	memset(a,0,sizeof(a));
    memset(viz,0,sizeof(viz));
    memset(depth,0,sizeof(depth));
    memset(lowLink,0,sizeof(lowLink));critic=0;
	}
     return 0;
}
