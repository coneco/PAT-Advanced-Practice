#include <cstdio>
#include <cmath>

void sci(double d, int* w, double* digit);

int main(int argc, char const *argv[])
{
  int n, nn = 1;
  double d1, d2;
  std::scanf("%d %lf %lf", &n, &d1, &d2);
  for (int i = 0; i < n; ++i)
  {
    nn *= 10;
  }
  int w1, w2;
  double dg1, dg2;
  sci(d1, &w1, &dg1);
  sci(d2, &w2, &dg2);
  int dgi1 = floor(dg1 * nn);
  int dgi2 = floor(dg2 * nn);
  if (dgi1 == dgi2 && w1 == w2)
  {
    printf("YES 0.%d*10^%d\n", dgi1, w1);
  }
  else
  {
    printf("NO 0.%d*10^%d 0.%d*10^%d\n", dgi1, w1, dgi2, w2);
  }
  return 0;
}

void sci(double d, int* w, double* digit)
{
  int k = 0;

  while(d >= 1) 
  {
    d /= 10;
    ++k;
  }
  *w = k;
  *digit = d;
}
