#include<iostream>
#include<vector>
#include<iterator>
using namespace std;

typedef vector <int> ::iterator It;

vector <int> G[10000];
int depth[10000],lowLink[10000],isCritic[10000],Used[1000];

void getCriticalEdges(int Node, int Father, int actLevel) {
    int fatherEdges = 0;
    depth[Node] = lowLink[Node] = actLevel;
    Used[Node] = 1;
    bool critic = false;
    for(It it = G[Node].begin(), fin = G[Node].end(); it != fin ; ++ it) {
        if(*it == Father) {
            ++ fatherEdges;
            continue;
        }
        if(!Used[*it]) {
            getCriticalEdges(*it, Node, actLevel + 1);
            lowLink[Node] = min(lowLink[Node], lowLink[*it]);
        } else lowLink[Node] = min(lowLink[Node], depth[*it]);
    }
    if(lowLink[Node] > depth[Father] && fatherEdges <= 1)
        critic = true;
    isCritic[Node] = critic;
}

int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	getCriticalEdges(1,0,1);
	for(int i=1;i<=n;i++)
	if(isCritic[i])
	cout<<i<<" ";
}
