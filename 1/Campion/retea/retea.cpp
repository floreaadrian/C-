#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <queue>
#include <bitset>
#include <string.h>
 
using namespace std;
 
ifstream fin("retea.in");
ofstream fout("retea.out");
 
const int maxn = 200005;
 vector <pair<int, pair<int, int> > > edges;
int n, m, father[maxn],k,total;
 
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
 
 void citire()
 {
 	fin >> n >> m >> k;
    for(int i = 1 ; i <= n ; ++ i)
        father[i] = i;
    for(int i = 1 ; i <= m ; ++ i) {
        int x, y, z;
        fin >> x >> y >> z;
        edges.push_back(make_pair(z, make_pair(x, y)));
    }
 }
inline void kruskal() {
    
    sort(edges.begin(), edges.end());
    vector <pair<int, int> > apm;
    for(int i = 0 ; i < edges.size() ; ++ i) {
        if(unite(edges[i].second.first, edges[i].second.second)) {
            total += edges[i].first;
            apm.push_back(edges[i].second);
        }
    }
    fout << total;
}

void sterge()
{
	for(int i=1;i<=m;i++)
	swap(edges[i],edges[i+1]);
	edges(m).first=0;
	edges(m).second=0;
}

int main()
{
	citire();
	kruskal();
	while(m--){
		sterge();
		kruskal();
	}
	return 0;
}
