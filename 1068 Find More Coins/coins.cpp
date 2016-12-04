#include <cstdio>
#include <algorithm>
#define MAX(a, b) (a>b?a:b)

int coins[10002];
int dp[101][10002] = {{0}};

int N, M;

bool g(int a, int b)
{
  return a>b;
}

int main(int argc, char const *argv[])
{
  std::scanf("%d %d", &N, &M);
  for (int i = 1; i <= N; ++i)
  {
    std::scanf("%d", coins + i);
  }
  coins[0] = 0;
  std::sort(coins+1, coins+N+1, g);
  for (int i = 1; i <= M; ++i)
  {
    for (int j = 1; j <= N; ++j)
    {
      int mc;
      if (i-coins[j] >= 0)
      {
        mc = dp[i-coins[j]][j-1] + coins[j];
      }
      else
      {
        mc = 0;
      }
      dp[i][j] = MAX(dp[i][j-1], mc);
    }
  }
  if (dp[M][N] != M)
  {
    std::printf("No Solution");
  }
  else
  {
    int i = M, j = N;
    while(i>0&&j>0) 
    {
      if (dp[i][j] == dp[(i-coins[j])>0?(i-coins[j]):0][j-1] + coins[j])
      {
        printf("%d", coins[j]);
        i = i-coins[j]>0?i-coins[j]:0;
        --j;
        break;
      }
      else
      {
        --j;
      }
    }
    while(i>0&&j>0) 
    {
      if (dp[i][j] == dp[i-coins[j]>0?i-coins[j]:0][j-1] + coins[j])
      {
        printf(" %d", coins[j]);
        i = (i-coins[j])>0?(i-coins[j]):0;
        --j;
      }
      else
      {
        --j;
      }
    }
  }
  printf("\n");
  return 0;
}
