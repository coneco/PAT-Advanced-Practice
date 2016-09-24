#include <cstdio>
#include <cstdlib>
#include <map>
#include <vector>

using namespace std;
map<int, vector<int> > tree;
int dk[100];

void countDk(int id, int level)
{
  if (tree[id].empty())
  {
    ++dk[level];
    return;
  }
  
  vector<int>::iterator iter = tree[id].begin();
  while(iter != tree[id].end())
  {
    countDk(*iter, level+1);
    iter++;
  }
}


int main()
{
  int n, m, maxDk;
  scanf("%d %d", &n, &m);
  maxDk = n - m;
  while (m--)
  {
    int par, k, chi;
    scanf("%d %d", &par, &k);
    while (k--)
    {
      scanf("%d", &chi);
      tree[par].push_back(chi);
    }
  }
  countDk(1, 0);
  int cDk = dk[0];
  printf("%d", dk[0]);
  for(int i = 1; cDk < maxDk; i++)
  {
    printf(" %d", dk[i]);
    cDk += dk[i];
  }
  printf("\n");
  return 0;
}
