#include <iostream>
#include <vector>

#define C_MAX 100
#define N_MAX 501

int c, n, s, m;
int mapGraph[N_MAX][N_MAX] = {0};
int checked[N_MAX] = {0};
int dist[N_MAX] = {0};
std::vector<int> lastStation[N_MAX];
std::vector<int> path, temppath;

int bikes[N_MAX];
int minSend = 0x7FFFFFFF, minBack = 0x7FFFFFFF;

void dijkstra (int start, int target);
void dfs(int target);

int main(int argc, char const *argv[])
{
  std::cin >> c >> n >> s >> m;
  for (int i = 0; i < n; ++i)
  {
    std::cin >> bikes[i + 1];
  }

  for (int i = 0; i < m; ++i)
  {
    int x, y, d;
    std::cin >> x >> y >> d;
    mapGraph[x][y] = mapGraph[y][x] = d;
  }

  dijkstra(0, s);

  dfs(s);

  std::cout << minSend << " 0";
  for (int i = path.size() - 2; i >= 0; --i)
  {
    std::cout << "->" << path[i];
  }
  std::cout << ' ' << minBack;

  return 0;
}

void dijkstra (int start, int target)
{
  checked[start] = 1;
  while(!checked[target])
  {
    int minDist = 0;
    int minDistI;
    std::vector<int> minDistILast;
    for (int i = 0; i < n + 1; ++i)
    {
      if (!checked[i])
      {
        for (int j = 0; j < n + 1; ++j)
        {
          if (checked[j] && mapGraph[i][j] != 0)
          {
            int distCur = dist[j] + mapGraph[i][j];
            if (minDist == 0 || distCur < minDist)
            {
              minDistILast.clear();
              minDist = distCur;
              minDistI = i;
              minDistILast.push_back(j);
            } 
            else if (distCur == minDist && i == minDistI)
            {
              minDistILast.push_back(j);
            }
          }
        }
      }
    }
    dist[minDistI] = minDist;
    lastStation[minDistI] = minDistILast;
    checked[minDistI] = 1;
  }
}

void dfs(int target)
{
  int perfect = c / 2;
  if (target == 0)
  {
    temppath.push_back(target);
    int send = 0, back = 0;
    for (int i = temppath.size() - 2; i >= 0; --i)
    {
      int diff = bikes[temppath[i]] - perfect;
      if (diff < 0)
      {
        if (back >= 0 - diff)
        {
          back += diff;
        } else {
          send += 0 - diff - back;
          back = 0;
        }
      } else if (diff > 0) {
        back += diff;
      }
    }

    if (send < minSend || (send == minSend && back < minBack))
    {
      minSend = send;
      minBack = back;
      path = temppath;
    }
    temppath.pop_back();
    return;
  }

  temppath.push_back(target);
  for (std::vector<int>::iterator i = lastStation[target].begin(); i != lastStation[target].end(); ++i)
  {
    dfs(*i);
  }
  temppath.pop_back();
}