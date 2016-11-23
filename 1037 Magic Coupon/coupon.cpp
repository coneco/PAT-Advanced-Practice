#include <cstdio>
#include <algorithm>

int gt(long l1, long l2){
  return l1 > l2;
}

int main(int argc, char const *argv[])
{
  long c_p[100001];
  int ncp = 0;
  long c_n[100001];
  int ncn = 0;
  long p_p[100001];
  int npp = 0;
  long p_n[100001];
  int npn = 0;

  int nc, np;
  std::scanf("%d", &nc);
  for (int i = 0; i < nc; ++i)
  {
    int ipt;
    std::scanf("%d", &ipt);
    if (ipt > 0)
    {
      c_p[ncp] = ipt;
      ++ncp;
    }
    else
    {
      c_n[ncn] = ipt;
      ++ncn;
    }
  }
  std::scanf("%d", &np);
  for (int i = 0; i < np; ++i)
  {
    int ipt;
    std::scanf("%d", &ipt);
    if (ipt > 0)
    {
      p_p[npp] = ipt;
      ++npp;
    }
    else
    {
      p_n[npn] = ipt;
      ++npn;
    }
  }
  std::sort(c_p, c_p + ncp, gt);
  std::sort(c_n, c_n + ncn);
  std::sort(p_p, p_p + npp, gt);
  std::sort(p_n, p_n + npn);

  int p = ncp < npp ? ncp : npp;
  int n = ncn < npn ? ncn : npn;
  long res = 0;
  for (int i = 0; i < p; ++i)
  {
    res += c_p[i] * p_p[i];
  }
  for (int i = 0; i < n; ++i)
  {
    res += c_n[i] * p_n[i];
  }
  std::printf("%ld\n", res);
  return 0;
}