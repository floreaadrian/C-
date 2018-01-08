#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int n,m,k,x,y,critic=0,timp,depth[1251],lowLink[1251],viz[1251];
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
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>x;
			if(x)
			a[i].push_back(j);
		}
	}
	depth[0]=INT_MAX;
	df(1,0,1);
	for(int i=1;i<=n;i++)
    {
    	if(!viz[n])
		df(i,0,1);
	}
    if(critic==0)
    cout<<"Bazinga!\n";
	else cout<<"Fail!\n";
}
