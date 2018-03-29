#include <set>
#include <vector>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int urandom(int limit)
{
	int val = random() / (RAND_MAX/limit);
	if (val >= limit) val = limit-1;
	return val;
}

void add_edges(int m, vector<set<int> >& graph)
{
	int const n = graph.size();
	for(int k=0 ; k<m ; ++k){
		while(true){
			int const i = urandom(n);
			int const j = urandom(n);
			if(graph[i].find(j) == graph[i].end()){
				graph[i].insert(j);
				break;
			}
		}
		
	}
}

void generate(int n, int m, vector<set<int> >& graph)
{
	graph.clear();
	graph.resize(n);
	long long n_long = n;
	long long m_long = m;
	long long n2 = n_long * n_long;
	if (2*m_long < n2){
		add_edges(m, graph);
	} else {
		if(m>n2) m=n2;
		add_edges(n*n-m, graph);
		for(int i=0 ; i<n ; ++i){
			set<int> s;
			for(int j=0 ; j<n ; ++j){
				if(graph[i].find(j) == graph[i].end()){
					s.insert(j);
				}
			}
			std::swap(graph[i], s);
		}
	}
}


int main()
{
	int m, n;
	vector<set<int> > graph;
	generate(n, m, graph);
	printf("%d %d\n", n, m);
	for(int i=0 ; i<n ; ++i){
		set<int> const& s(graph[i]);
		for(set<int>::iterator it=s.begin() ; it!=s.end() ; ++it){
			printf("%d %d %d\n", i, *it, urandom(100)+1);
		}
	}
	return 0;
}
