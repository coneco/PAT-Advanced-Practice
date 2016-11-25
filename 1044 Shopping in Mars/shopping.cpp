#include <cstdio>

int chain[100001];
int n, m;
int ans[100001][2];
int nAns = 0;
int cnt = 0;
int cntA = 0x7FFFFFFF;

int main(int argc, char const *argv[])
{
  std::scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; ++i)
  {
    std::scanf("%d", chain + i);
  }
  int i = 1, j = 1;
  cnt = chain[i];

  bool flag = true;
  while(j <= n) 
  {
    if (cnt > m)
    {
      if (cnt < cntA)
      {
        cntA = cnt;
        nAns = 1;
        ans[0][0] = i;
        ans[0][1] = j;
      }
      else if (cnt == cntA)
      {
        ans[nAns][0] = i;
        ans[nAns][1] = j;
        ++nAns;
      }
      if (i == j)
      {
        ++i;
        ++j;
        cnt = chain[j];
      }
      else
      {
        cnt -= chain[i++];
      }
    }
    else if(cnt == m)
    {
      flag = false;
      std::printf("%d-%d\n", i, j);
      cnt -= chain[i++];
      cnt += chain[++j];
    }
    else
    {
      cnt += chain[++j];
    }
  }
  if (flag)
  {
    for (int i = 0; i < nAns; ++i)
    {
      std::printf("%d-%d\n", ans[i][0], ans[i][1]);
    }
  }
  return 0;
}
