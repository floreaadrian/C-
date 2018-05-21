#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

struct asteroid
{
  int n;
  int timeStamp;
  int minJ;
  vector<int> g[1000];
  bool com;
};

ifstream fin("data.in");
ofstream fout("data.out");

bool compare(asteroid a, asteroid b)
{
  if (a.n != b.n)
    return false;
  for (int i = 0; i < a.n; ++i)
  {
    if (a.g[i].size() != b.g[i].size())
      return false;
    for (int j = 0; j < a.g[i].size(); ++j)
    {
      if ((a.g[i][j] - a.minJ) != (b.g[i][j] - b.minJ))
        return false;
    }
  }
  return true;
}

bool gasit(vector<int> cauta, int val)
{
  for (auto it : cauta)
  {
    if (val == it)
      return true;
  }
  return false;
}

int main()
{
  vector<asteroid> v;
  int start, end, nrImg;
  fin >> start >> end >> nrImg;
  vector<int> salvate[1000];
  int timeStamp, n, m;
  for (int k = 0; k < nrImg; ++k)
  {
    fin >> timeStamp >> n >> m;
    int a[1000][1000];
    bool ok = false;
    bool nula = true;
    asteroid as;
    as.n = 0;
    as.minJ = 1000000;
    as.com = true;
    as.timeStamp = timeStamp;
    for (int i = 0; i < n; ++i)
    {
      ok = false;
      for (int j = 0; j < m; ++j)
      {
        fin >> a[i][j];
        if (a[i][j])
        {
          as.g[as.n].push_back(j);
          as.minJ = min(j, as.minJ);
          ok = true;
        }
      }
      if (ok)
      {
        as.n++;
        nula = false;
      }
    }
    if (!nula)
      v.push_back(as);
  }
  int contor = 0;
  for (int i = 0; i < v.size(); i++)
  {
    if (v[i].com)
    {
      v[i].com = false;
      salvate[contor].push_back(v[i].timeStamp);
      for (int j = i; j < v.size(); ++j)
        if (v[j].com)
        {
          if (compare(v[i], v[j]))
          {
            v[j].com = false;
            salvate[contor].push_back(v[j].timeStamp);
          }
        }
      contor++;
    }
  }
  vector<int> diferente[1000];
  for (int i = 0; i < contor; ++i)
  {
    sort(salvate[i].begin(), salvate[i].end());
    for (int j = 0; j < salvate[i].size(); ++j)
    {
      for (int k = j + 1; k < salvate[i].size(); ++k)
      {
        int dif = salvate[i][k] - salvate[i][j];
        if (gasit(salvate[i], 2 * dif + salvate[i][j]) &&
            gasit(salvate[i], salvate[i][j] - dif))
        {
          if (gasit(diferente[i], dif) == false)
            diferente[i].push_back(dif);
        }
      }
    }
  }
  int visited[100000] = {0};
  vector<int> solutie[10000];
  for (int i = 0; i < contor; ++i)
  {
    for (int j = 0; j < diferente[i].size(); ++j)
    {
      for (int k = 0; k < salvate[i].size(); ++k)
      {
        if ((gasit(salvate[i], diferente[i][j] + salvate[i][k]) ||
             gasit(salvate[i], salvate[i][k] - diferente[i][j])) &&
            !visited[salvate[i][k]])
        {
          visited[salvate[i][k]] = 1;
          solutie[j].push_back(salvate[i][k]);
        }
      }
      if (solutie[j].size() >= 4)
      {
        fout << solutie[j][0] << " " << solutie[j][solutie[j].size() - 1] << " "
             << solutie[j].size() << "\n";
      }
    }
  }

  return 0;
}
