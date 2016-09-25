#include <iostream>
#include <queue>
#define MAX 1001

void mark(int c, int mapGraph[][MAX], int* marked, int without, int nCities);
int countIsland(int mapGraph[][MAX], int without, int nCities);

int main(int argc, char const *argv[])
{
  int n, m, k;
  std::cin >> n >> m >> k;

  int mapGraph[MAX][MAX] = {0};

  for (int i = 0; i < m; ++i)
  {
    int c1, c2;
    std::cin >> c1 >> c2;
    mapGraph[c1][c2] = mapGraph[c2][c1] = 1;
  }

  std::queue<int> checkList;

  for (int i = 1; i <= k; ++i)
  {
    int c;
    std::cin >> c;
    checkList.push(c);
  }

  while(!checkList.empty()) {
    int c = checkList.front();
    checkList.pop();
    std::cout << countIsland(mapGraph, c, n) - 1 << std::endl;
  }
  
  return 0;
}

void mark(int c, int mapGraph[][MAX], int marked[], int without, int nCities)
{
  marked[c] = 1;
  for (int i = 1; i <= nCities; ++i)
  {
    if (i != without && mapGraph[c][i] == 1 && marked[i] == 0)
    {
      mark(i, mapGraph, marked, without, nCities);
    }
  }
}

int countIsland(int mapGraph[][MAX], int without, int nCities)
{
  int marked[MAX] = {0};
  int ret = 0;
  for (int i = 1; i <= nCities; ++i)
  {
    if (i != without && marked[i] == 0)
    {
      ++ret;
      mark(i, mapGraph, marked, without, nCities);
    }
  }
  return ret;
}