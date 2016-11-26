#include <cstdio>

int n, m, l;
int order[201];
int stripe[10001];

int table[10001][201] = {{0}};

int main(int argc, char const *argv[])
{
  std::scanf("%d", &n);
  std::scanf("%d", &m);
  for (int i = 1; i <= m; ++i)
  {
    std::scanf("%d", order + i);
  }
  std::scanf("%d", &l);
  for (int i = 1; i <= l; ++i)
  {
    std::scanf("%d", stripe + i);
  }

  for (int i = 1; i <= l; ++i)
  {
    for (int j = 1; j <= m; ++j)
    {
      if (order[j] == stripe[i])
      {
        table[i][j] = table[i-1][j-1] > table[i - 1][j] ? table[i-1][j-1] : table[i - 1][j] + 1;
      }
      else
      {
        table[i][j] = table[i-1][j] > table[i][j-1] ? table[i-1][j] : table[i][j-1];
      }
    }
  }
  std::printf("%d\n", table[l][m]);
  return 0;
}
