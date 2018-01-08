#include <bits/stdc++.h>
using namespace std;
#define all(c) (c).begin(), (c).end()
#define cnt(c, x) ((c).find(x) != (c).end())
#define pb push_back
#define FOR(i, a, n) for(int i = (a); i < (n); i++)
#define REP(i, n) for(int i = 0; i < (n); i++)
#define SZ(x) ((int) (x).size())
#define mp(x,y) make_pair((x), (y))
#define mp3(x,y,z) make_pair((x), make_pair( (y), (z)))
#define foreach(C, i) for(auto i = (C).begin(); i != (C).end(); i++)
#define xx first
#define yy second
#define clr clear()
#define var(x) cout<< #x << " = "<<x<<"\n";
typedef vector<int> vi;
typedef map<int,int> mii;
typedef set<int> si;
typedef pair<int,int> pii;
typedef vector<pair<int,int> > vpii;

int main()
{
	int tc; cin>>tc;
	while (tc--)
	{
		int n,m; cin>>n>>m;
		vector<vector<int> > arr(n);
		vector<map<int,int> > rows(n);
		vector<map<int,int> > cols(m);
		for(int i=0;i<n;i++)
		{
			arr[i] = vector<int>(m);
			for(int j=0;j<m;j++)
			{
				cin>>arr[i][j];
				rows[i][arr[i][j]]++;
			}
		}
		for(int j=0;j<m;j++)
		{
			for(int i=0;i<n;i++)
			{
				cols[j][arr[i][j]]++;
			}
		}
		int gMa = -1;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				int ma = -1;
				for(int i=0;i<rows[i].size();i++)
				{
					int cnt = rows[i].second;
					auto it2 = cols[j].find(rows[i].first);
					if (it2 != cols[j].end())
						cnt += it2->second;
					if (cnt > ma)
					{
						if (rows[i].first == arr[i][j])
							cnt--;
						ma = cnt;
					}
				}
				if (ma > gMa)
					gMa = ma;
			}
		}
		cout<<gMa<<"\n";
	}
	return 0;
}
