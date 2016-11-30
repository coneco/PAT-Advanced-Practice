#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

struct man
{
  char n[9];
  int a;
  int w;
};

std::vector<man> v;

bool cmp(man n1, man n2)
{
  if (n1.w == n2.w && n1.a == n2.a)
  {
    return strcmp(n1.n, n2.n) < 0;
  }
  else if (n1.w == n2.w)
  {
    return n1.a < n2.a;
  }
  else
  {
    return n1.w > n2.w;
  }
}

int main(int argc, char const *argv[])
{
  int n, k;
  std::scanf("%d %d", &n, &k);
  v.resize(n);
  for (int i = 0; i < n; ++i)
  {
    std::scanf("%s %d %d", v[i].n, &(v[i].a), &(v[i].w));
  }
  std::sort(v.begin(), v.end(), cmp);
  for (int i = 1; i <= k; ++i)
  {
    int m, amin, amax;
    std::scanf("%d %d %d", &m, &amin, &amax);
    std::printf("Case #%d:\n", i);
    int cnt = 0;
    for (int j = 0; j < n; ++j)
    {
      if (v[j].a <= amax && v[j].a >= amin)
      {
        printf("%s %d %d\n", v[j].n, v[j].a, v[j].w);
        cnt++;
        if (cnt == m)
        {
          break;
        }
      }
    }
    if (!cnt)
    {
      std::printf("None\n");
    }
  }
  return 0;
}
