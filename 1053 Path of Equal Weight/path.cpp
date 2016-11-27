#include <cstdio>
#include <vector>
#include <algorithm>

std::vector<int> nodes[100];
int weight[100];
int path[100];
int n, m, s;

bool cmp(int n1, int n2)
{
  return weight[n1] > weight[n2];
}

void dfs(int node, int d, int w)
{
  int tw = w + weight[node];
  path[d] = weight[node];
  if (!nodes[node].size())
  {
    if (tw == s)
    {
      std::printf("%d", path[0]);
      for (int i = 1; i <= d; ++i)
      {
        std::printf(" %d", path[i]);
      }
      std::printf("\n");
    }
    return;
  }

  for (std::vector<int>::iterator i = nodes[node].begin(); i != nodes[node].end(); ++i)
  {
    dfs(*i, d+1, tw);
  }
}

int main(int argc, char const *argv[])
{
  std::scanf("%d %d %d", &n, &m, &s);
  for (int i = 0; i < n; ++i)
  {
    std::scanf("%d", weight + i);
  }
  for (int i = 0; i < m; ++i)
  {
    int cur;
    int nc;
    std::scanf("%d %d", &cur, &nc);
    while(nc--) 
    {
      int c;
      std::scanf("%d", &c);
      nodes[cur].push_back(c);
    }
    sort(nodes[cur].begin(), nodes[cur].end(), cmp);
  }
  dfs(0, 0, 0);
  return 0;
}