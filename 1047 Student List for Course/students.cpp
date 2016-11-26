#include <cstdio>
#include <vector>
#include <algorithm>

struct stu
{
  char n[5];
  int i;
};

bool cmp(stu n1, stu n2)
{
  return n1.i < n2.i;
}

std::vector<std::vector<stu> > list(2501);

int main(int argc, char const *argv[])
{
  int n, k;
  std::scanf("%d %d", &n, &k);
  for (int i = 0; i < n; ++i)
  {
    stu newOne;
    int cnt;
    std::scanf("%s %d", newOne.n, &cnt);
    newOne.i = (newOne.n[0] - 'A') * 6760 + (newOne.n[1] - 'A') * 260 + (newOne.n[2] - 'A') * 10 + (newOne.n[3] - '0');
    for (int j = 0; j < cnt; ++j)
    {
      int c;
      std::scanf("%d", &c);
      list[c].push_back(newOne);
    }
  }
  for (int i = 1; i <= k; ++i)
  {
    int len = list[i].size();
    std::printf("%d %d\n", i, len);
    std::sort(list[i].begin(), list[i].end(), cmp);
    for (std::vector<stu>::iterator j = list[i].begin(); j != list[i].end(); ++j)
    {
      std::printf("%s\n", (*j).n);
    }
  }
  return 0;
}
