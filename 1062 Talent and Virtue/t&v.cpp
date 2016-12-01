#include <cstdio>
#include <vector>
#include <algorithm>

std::vector<std::vector<std::vector<int> > > v;

int n, l, h, cnt = 0;

int main(int argc, char const *argv[])
{
  std::scanf("%d %d %d", &n ,&l, &h);
  v.resize(101);
  for (int i = 0; i < 101; ++i)
  {
    v[i].resize(101);
  }
  for (int i = 0; i < n; ++i)
  {
    int id, vir, tal;
    std::scanf("%d %d %d", &id, &vir, &tal);
    if (vir >= l && tal >=l)
    {
      ++cnt;
      v[vir][tal].push_back(id);
    }
  }
  printf("%d\n", cnt);
  for (int t = 200; t >= 2 * h; --t)
  {
    for (int vir = 100; vir >= h; --vir)
    {
      int tal = t - vir;
      if (tal >= h && tal <= 100)
      {
        std::sort(v[vir][tal].begin(), v[vir][tal].end());
        for (std::vector<int>::iterator i = v[vir][tal].begin(); i != v[vir][tal].end(); ++i)
        {
          printf("%.8d %d %d\n", *i, vir, tal);
        }
      }
    }
  }
  for (int t = 100 + h - 1; t >= l + h; --t)
  {
    for (int vir = 100; vir >= h; --vir)
    {
      int tal = t - vir;
      if (tal >= l && tal < h)
      {
        std::sort(v[vir][tal].begin(), v[vir][tal].end());
        for (std::vector<int>::iterator i = v[vir][tal].begin(); i != v[vir][tal].end(); ++i)
        {
          printf("%.8d %d %d\n", *i, vir, tal);
        }
      }
    }
  }
  for (int t = 2 * (h - 1); t >= 2 * l; --t)
  {
    for (int vir = h - 1; vir >= l; --vir)
    {
      int tal = t - vir;
      if (tal >= l && tal < h && vir >= tal)
      {
        std::sort(v[vir][tal].begin(), v[vir][tal].end());
        for (std::vector<int>::iterator i = v[vir][tal].begin(); i != v[vir][tal].end(); ++i)
        {
          printf("%.8d %d %d\n", *i, vir, tal);
        }
      }
    }
  }
  for (int t = 100 + h - 1; t >= 2 * l + 1; --t)
  {
    for (int vir = h - 1; vir >= l; --vir)
    {
      int tal = t - vir;
      if (tal > vir && tal <= 100)
      {
        std::sort(v[vir][tal].begin(), v[vir][tal].end());
        for (std::vector<int>::iterator i = v[vir][tal].begin(); i != v[vir][tal].end(); ++i)
        {
          printf("%.8d %d %d\n", *i, vir, tal);
        }
      }
    }
  }
  return 0;
}
