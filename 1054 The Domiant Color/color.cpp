#include <cstdio>


int main(int argc, char const *argv[])
{
  int m, n;
  std::scanf("%d %d", &m, &n);
  n = m * n;
  int cur = 0;
  int d = 0x7FFFFFFF, p;
  for (int i = 0; i < n; ++i)
  {
    std::scanf("%d", &p);
    if (p == d)
    {
      ++cur;
    }
    else if (cur == 0)
    {
      d = p;
      ++cur;
    }
    else
    {
      --cur;
    }
  }
  std::printf("%d\n", d);
  return 0;
}
