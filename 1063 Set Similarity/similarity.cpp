#include <cstdio>
#include <set>

std::set<int> sets[51];
int N;
int nSets[51];

int main(int argc, char const *argv[])
{
  std::scanf("%d", &N);
  for (int i = 1; i <= N; ++i)
  {
    std::scanf("%d", nSets+i);
    for (int j = 0; j < nSets[i]; ++j)
    {
      int temp;
      std::scanf("%d", &temp);
      sets[i].insert(temp);
    }
    nSets[i] = sets[i].size();
  }
  

  int k;
  std::scanf("%d", &k);
  while(k--) 
  {
    int s1, s2;
    std::scanf("%d %d", &s1, &s2);
    int comm = 0;
    for (std::set<int>::iterator i = sets[s2].begin(); i != sets[s2].end(); ++i)
    {
      if (sets[s1].find(*i) != sets[s1].end())
      {
        ++comm;
      }
    }
    std::printf("%.1lf%%\n", comm * 100.0 / (nSets[s1] + nSets[s2] - comm));
  }
  return 0;
}