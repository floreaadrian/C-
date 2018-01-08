#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector <pair<float,string> > v;
	int n=24;
	for(int i=1;i<=24;++i)
	{
		float a,b,c;
		string s;
		cin>>s;
		cin>>a>>b>>c;
		float medie=(a+b+c)/3;
		v.push_back(make_pair(medie,s));
	}
	sort(v.begin(),v.end());
	for(auto it:v)
	cout<<it.second<<" "<<it.first<<"\n";
	return 0;
}
