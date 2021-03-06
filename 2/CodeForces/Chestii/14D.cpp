#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#define maxn 201
using namespace std;
vector<int>v[maxn];
int n;
int s;
int dfs(int x,int pre)
{
	int r1=0;
	int r2=0;
	int t=0;
	for(int i=0;i<v[x].size();i++)
	{
		if(v[x][i]!=pre)
		{
			t=max(dfs(v[x][i],x),t);
			if(s>r1)
			{
				r2=r1;
				r1=s;
			}
			else
			r2=max(r2,s);
		}
	}
	t=max(t,r1+r2);
	s=r1+1;
	return t;
}
int main()
{
	cin>>n;
	memset(v,0,sizeof(v));
	int ans=0;
	for(int i=1;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for(int i=1;i<=n;i++)
	for(int j=0;j<v[i].size();j++)
	{
		int a=dfs(v[i][j],i);
		int b=dfs(i,v[i][j]);
		if(a*b>ans)
		ans=a*b;
	}
	cout<<ans<<endl;
	return 0;
}
