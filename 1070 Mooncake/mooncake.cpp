#include <cstdio>
#include <algorithm>

int N, D;
struct mc
{
  double ivt;
  double prc;
  double upic;
};
mc mcs[1010];

bool cmp(mc m1, mc m2)
{
  return m1.upic > m2.upic;
}

int main(int argc, char const *argv[])
{
  std::scanf("%d %d", &N, &D);
  for (int i = 0; i < N; ++i)
  {
    std::scanf("%lf", &(mcs[i].ivt));
  }
  for (int i = 0; i < N; ++i)
  {
    std::scanf("%lf", &(mcs[i].prc));
    mcs[i].upic = mcs[i].prc / mcs[i].ivt;
  }
  std::sort(mcs, mcs+N, cmp);
  double res = 0;
  for (int i = 0; i < N; ++i)
  {
    if (D <= mcs[i].ivt)
    {
      res += mcs[i].upic * D;
      break;
    }
    else
    {
      D-=mcs[i].ivt;
      res += mcs[i].prc;
    }
  }
  std::printf("%.2lf\n", res);
  return 0;
}
