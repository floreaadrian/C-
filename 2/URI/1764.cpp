#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <bitset>
#include <string.h>
 
using namespace std;
 
const int maxn = 200005;
 
int n, m, father[maxn];
vector <pair<int, pair<int, int> > > edges;

inline int find(int x) {
    if(father[x] != x)
        father[x] = find(father[x]);
    return father[x];
}
 
inline bool unite(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y)
        return false;
    father[x] = y;
    return true;
}
 
inline void kruskal() {
    sort(edges.begin(), edges.end());
    int total = 0;
    vector <pair<int, int> > apm;
    for(int i = 0 ; i < edges.size() ; ++ i) {
        if(unite(edges[i].second.first, edges[i].second.second)) {
            total += edges[i].first;
            apm.push_back(edges[i].second);
        }
    }
    cout<<total<<"\n";
}

int main()
{
	while(cin>>n>>m && n && m)
    {
	for(int i = 1 ; i <= n ; ++ i)
        father[i] = i;
    for(int i = 1 ; i <= m ; ++ i) {
        int x, y, z;
        cin >> x >> y >> z;
        edges.push_back(make_pair(z, make_pair(x, y)));
    }
	kruskal();
	edges.clear();
	memset(father,0,sizeof(father));
	}
	return 0;
}
