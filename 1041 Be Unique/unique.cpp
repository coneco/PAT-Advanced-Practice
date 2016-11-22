#include <cstdio>

int main(int argc, char const *argv[])
{
  int n;
  std::scanf("%d", &n);
  int lotteries[10001] = {0};
  int seq[10001] = {0};
  seq[0] = 10002;
  int cur = 0;
  for (int i = 0; i < n; ++i)
  {
    int k;
    std::scanf("%d", &k);
    if (!lotteries[k])
    {
      seq[k] = cur;
      ++cur;
    }
    ++lotteries[k];
  }
  int ret = 0;
  for (int i = 1; i < 10001; ++i)
  {
    if (lotteries[i] == 1 && seq[i] < seq[ret])
    {
      ret = i;
    }
  }
  if (ret)
  {
    std::printf("%d\n", ret);
  }
  else
  {
    std::printf("None\n");
  }
  return 0;
}
