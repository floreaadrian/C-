#include<iostream>
#include<fstream>
#include<queue>
using namespace std;
int min(int x,int y)
{
	if(x>y)return x;
	return y;
}
int n, dp[255][255], xpaznic, ypaznic,minim=0,s[255][255];
const int dx[] = {0, 1, -1, 0, 1, -1, -1, 1};
const int dy[] = {1, 0, 0,-1,-1, 1, -1, 1};
queue < pair<int, int> > q;
ifstream fin("muzeu.in");
ofstream fout("muzeu.out");
bool inside(int x, int y) {
return x >= 1 && x <= n && y >= 1 && y <= n;
}
void lee() {
/// q.push(make_pair(xpaznic, ypaznic)); /// bag primul paznic in coada
/// dp[xpaznic][ypaznic] = 0; /// pun distanta 0
while(!q.empty()) { // cat timp coada nu este goala
int x = q.front().first; /// lum coordonatele
int y = q.front().second;
q.pop(); /// scoatedin din coada primul element
for(int i = 0 ; i < 4 ; ++ i) { /// iau toti cei 4vecini
int newx = x + dx[i];
int newy = y + dy[i]; //// ii determin pe baza vectorilor delta
if(dp[newx][newy] > dp[x][y] + 1) { //// daca respecta conditiile adica: inauntrul matricei si celula nevizitat si liber (camera)
dp[newx][newy] = dp[x][y] + 1; /// determin noua distanta minima
fout<<x<<" "<<y;
q.push(make_pair(newx, newy)); /// bag la coada
}
}
}
for(int i = 1 ; i <= n ; ++ i, fout << '\n')
for(int j = 1 ; j <= n ; ++ j)
fout << dp[i][j] << ' ';
}
int main ()
{
fin >> n;
for(int i = 1 ; i <= n ; ++ i)
for(int j = 1 ; j <= n ; ++ j) {
fin >> s[i][j];
if(s[i][j]<minim)
minim=s[i][j];
/// avem paznic
q.push(make_pair(i, j)); /// il bagam in coada, care inainte de for(initial) era goala
dp[i][j] = minim; /// distanta 0 (distanta de start)

}
lee();
}
