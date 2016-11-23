#include <cstdio>

int n;
int dist[100001];

int shortest(int e1, int e2);

int main(int argc, char const *argv[])
{
  std::scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
  {
    int d;
    std::scanf("%d", &d);
    dist[i] = dist[i - 1] + d;
  }

  int m;
  std::scanf("%d", &m);
  while(m--) 
  {
    int e1, e2;
    std::scanf("%d %d", &e1, &e2);
    std::printf("%d\n", shortest(e1, e2));
  }
  return 0;
}

int shortest(int e1, int e2)
{
  int ret1 = e1 < e2 ? dist[e2-1] - dist[e1-1] : dist[e1-1] - dist[e2-1];
  int ret2 = dist[n] - ret1;
  return ret1 < ret2 ? ret1 : ret2;
}