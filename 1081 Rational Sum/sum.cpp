#include <cstdio>

struct rat
{
  int son;
  int mom;
};

rat sum(rat r1, rat r2)
{
  rat ret;
  ret.mom = r1.mom * r2.mom;
  ret.son = r1.son * r2.mom + r2.son * r1.mom;
  int big, sml;
  if (ret.son==0)
  {
    return (rat) {.son = 0, .mom=1};
  }
  if (ret.son > ret.mom)
  {
    big = ret.son;
    sml = ret.mom;
  } 
  else
  {
    sml = ret.son;
    big = ret.mom;
  }
  while(big%sml) 
  {
    int temp = big;
    big = sml;
    sml = temp % sml;
  }

  ret.son /= sml;
  ret.mom /= sml;
  return ret;
}

int main(int argc, char const *argv[])
{
  rat res = {.son = 0, .mom = 1};
  int N;
  std::scanf("%d", &N);
  while(N--) 
  {
    rat newOne;
    std::scanf("%d/%d", &(newOne.son), &(newOne.mom));
    res = sum(newOne, res);
  }

  int itg = res.son / res.mom;
  int son = res.son - itg * res.mom;
  int mom = res.mom;
  if (itg)
  {
    if (son)
    {
      std::printf("%d %d/%d\n", itg, son, mom);
    }else
    {
      std::printf("%d\n", itg);
    }
  }
  else
  {
    if (son)
    {
      std::printf("%d/%d\n", son, mom);
    }else
    {
      std::printf("0\n");
    }
  }
  return 0;
}