#include <cstdio>

int main(int argc, char const *argv[])
{
  int n, m;
  int wallet[100001] = {0};
  std::scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i)
  {
    int k;
    std::scanf("%d", &k);
    ++wallet[k];
  }

  bool flag = true;
  for (int i = 0; i <= m/2; ++i)
  {
    if (wallet[i])
    {
      --wallet[i];
      if (wallet[m - i])
      {
        flag = false;
        std::printf("%d %d\n", i, m - i);
        break;
      }
      ++wallet[i];
    }
  }
  if(flag)
  {
    std::printf("No Solution\n");
  }
  return 0;
}
