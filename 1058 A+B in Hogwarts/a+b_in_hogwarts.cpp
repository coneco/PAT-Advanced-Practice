#include <cstdio>

typedef struct hogwartsNumber
{
  long int g;
  int s;
  int k;
} h_num;

h_num sum(h_num a, h_num b);

int main(int argc, char const *argv[])
{
  h_num a, b;
  std::scanf("%ld.%d.%d %ld.%d.%d", &a.g, &a.s, &a.k, &b.g, &b.s, &b.k);
  h_num aPb = sum(a, b);
  std::printf("%ld.%d.%d\n", aPb.g, aPb.s, aPb.k);
  return 0;
}

h_num sum(h_num a, h_num b)
{
  h_num ret={.g=0, .s=0, .k=0};
  ret.k += (a.k + b.k);
  if (ret.k >= 29)
  {
    ret.k -= 29;
    ret.s += 1;
  }
  ret.s += (a.s + b.s);
  if (ret.s >= 17)
  {
    ret.s -= 17;
    ret.g += 1;
  }
  ret.g += (a.g + b.g);
  return ret;
}