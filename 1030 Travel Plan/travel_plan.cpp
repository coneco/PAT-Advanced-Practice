#include <iostream>
#define MAX 500

int N, M, S, D;
int mapGraph[MAX][MAX] = {0};
int costGraph[MAX][MAX];

int dist[MAX];
int cost[MAX];
int pre[MAX];
int visited[MAX] = {0};

void dijkstra();
void printPath(int d);

int main(int argc, char const *argv[])
{
  std::cin >> N >> M >> S >> D;
  for (int i = 0; i < M; ++i)
  {
    int c1, c2, distance, cost;
    std::cin >> c1 >> c2 >> distance >> cost;
    mapGraph[c1][c2] = mapGraph[c2][c1] = distance;
    costGraph[c1][c2] = costGraph[c2][c1] = cost;
  }
  dijkstra();
  printPath(D);
  std::cout << dist[D] << " " << cost[D] << std::endl;
  return 0;
}

void dijkstra()
{
  visited[S] = 1;
  dist[S] = 0;
  cost[S] = 0;
  while(!visited[D]) 
  {
    int minI, minDist=0, minPre, minCost;
    for (int i = 0; i < N; ++i)
    {
      if (!visited[i])
      {
        for (int j = 0; j < N; ++j)
        {
          if (visited[j] && mapGraph[i][j])
          {
            int curDist = dist[j] + mapGraph[i][j], curCost = cost[j] + costGraph[i][j];
            if (minDist == 0 || minDist > curDist || (minDist == curDist && minCost > curCost))
            {
              minI = i;
              minDist = curDist;
              minPre = j;
              minCost = curCost;
            }
          }
        }
      }
    }
    visited[minI] = 1;
    dist[minI] = minDist;
    pre[minI] = minPre;
    cost[minI] = minCost;
  }
}

void printPath(int d)
{
  if (d == S)
  {
    std::cout << d << " ";
    return;
  }
  printPath(pre[d]);
  std::cout << d << " ";
}