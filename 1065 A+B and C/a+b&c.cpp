#include <cstdio>

int main(int argc, char const *argv[])
{
  int t;
  int i = 1;
  std::scanf("%d", &t);
  while(t--) 
  {
    long int a, b, c;
    std::scanf("%ld %ld %ld", &a, &b, &c);
    long int sum;
    sum = a + b;
    if (a > 0 && b > 0 && sum < a)
    {
      std::printf("Case #%d: true\n", i);
    }
    else if (a < 0 && b < 0 && sum > a)
    {
      std::printf("Case #%d: false\n", i);
    }
    else
    {
      if (sum > c)
      {
        std::printf("Case #%d: true\n", i);
      }
      else
      {
        std::printf("Case #%d: false\n", i);
      }
    }
    ++i;
  }
  return 0;
}
