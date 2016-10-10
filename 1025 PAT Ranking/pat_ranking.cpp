#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>

typedef struct $testee
{
  long int id;
  int loc;
} testee;

bool testeeCmp(testee a, testee b)
{
  return a.id < b.id;
}

int main(int argc, char const *argv[])
{
  std::map<int, std::vector<testee> > ranklist;
  int n, tNum = 0;
  std::cin >> n;
  for (int loc = 1; loc <= n; ++loc)
  {
    int k;
    std::cin >> k;
    tNum += k;
    while(k--) 
    {
      long int id;
      int score;
      std::cin >> id >> score;
      testee ipt = {.id = id, .loc = loc};
      ranklist[score].push_back(ipt);
    }
  }

  std::cout << tNum << std::endl;

  int tRank = 1;
  int lRank[101], lRankNext[101];
  for (int i = 1; i <= n; ++i)
  {
    lRankNext[i] = 1;
  }
  for (int i = 100; i >= 0; --i)
  {
    int len = ranklist[i].size();
    if (len)
    {
      sort(ranklist[i].begin(), ranklist[i].end(), testeeCmp);
      for (int j = 1; j <= n; ++j) lRank[j] = lRankNext[j];
      for (std::vector<testee>::iterator iter = ranklist[i].begin(); iter != ranklist[i].end(); ++iter)
      {
        std::printf("%.13ld %d %d %d\n", (*iter).id, tRank, (*iter).loc, lRank[(*iter).loc]);
        ++lRankNext[(*iter).loc];
      }
      tRank += len;
    }
  }
  return 0;
}