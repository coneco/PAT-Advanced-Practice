#include <cstdio>
#include <cstring>
#include <algorithm>
const int inf = 999999999;

int N, M, K, Ds;

int roads[1020][1020];
int dist[11][1020];
bool visited[11][1020] = {false};
double shortest[11];
double total[11] = {0};

bool feasi[11];

void dijkstra()
{
  for (int g = 1; g <= M; ++g)
  {
    feasi[g] = true;
    dist[g][g] = 0;
    int cnt = N + M;
    int t = N + M;
    while(cnt--) 
    {
      int u = -1, minn = inf;
      for (int i = 1; i <= t; ++i)
      {
        if (!visited[g][i] && dist[g][i] < minn)
        {
          u = i;
          minn = dist[g][i];
        }
      }
      if (u == -1)
      {
        break;
      }
      visited[g][u] = true;
      if (u > M && dist[g][u] > Ds)
      {
        feasi[g] = false;
        break;
      }
      for (int i = 1; i <= t; ++i)
      {
        if (!visited[g][i] && dist[g][i] > dist[g][u] + roads[u][i])
        {
          dist[g][i] = dist[g][u] + roads[u][i];
        }
      }
    }
    if (!feasi[g])
    {
      continue;
    }
    for (int i = M+1; i <= t; ++i)
    {
      total[g] += 1.0*dist[g][i];
      if (shortest[g] > dist[g][i])
      {
        shortest[g] = dist[g][i];
      }
    }
    total[g] /= N;
  }
}

int s2i(char* s)
{
  int len = strlen(s);
  if (s[0] == 'G')
  {
    if (len == 3)
    {
      return (s[2] - '0') + (s[1] - '0')*10;
    }
    else
    {
      return s[1] - '0';
    }
  }
  else
  {
    int ret = 0;
    int wei = 1;
    for (int i = len - 1; i >= 0; --i)
    {
      ret += (s[i]-'0')*wei;
      wei *= 10;
    }
    return ret + M;
  }
}

int main(int argc, char const *argv[])
{
  std::fill(roads[0], roads[0] + 1020 * 1020, inf);
  std::fill(dist[0], dist[0] + 11*1020, inf);
  std::fill(shortest, shortest + 11, inf);
  std::scanf("%d %d %d %d", &N, &M, &K, &Ds);
  for (int i = 0; i < K; ++i)
  {
    int n1, n2, d;
    char s1[10], s2[10];
    std::scanf("%s %s %d", s1, s2, &d);
    n1 = s2i(s1);
    n2 = s2i(s2);
    roads[n1][n2] = roads[n2][n1] = d;
  }
  dijkstra();

  bool can = false;
  int opt = 0;
  for (int i = 1; i <= M; ++i)
  {
    if (feasi[i])
    {
      can = true;
      if (opt == 0 || shortest[opt] < shortest[i])
      {
        opt = i;
      }
      else if (shortest[opt] == shortest[i])
      {
        if (total[opt] > total[i])
        {
          opt = i;
        }
      }
    }
  }
  if (can)
  {
    std::printf("G%d\n%.1lf %.1lf\n", opt, shortest[opt], total[opt]);
  }
  else
  {
    std::printf("No Solution\n");
  }
  return 0;
}
