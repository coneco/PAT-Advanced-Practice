#include <cstdio>

int main(int argc, char const *argv[])
{
  int n;
  std::scanf("%d", &n);
  int a = 1, ans = 0;
  while(n / a) 
  {
    int left = n / a / 10;
    int now = n / a % 10;
    int right = n % a;
    if (now == 0)
    {
      ans += left * a;
    }
    else if (now == 1)
    {
      ans += left * a + 1 + right;
    }
    else
    {
      ans += (left + 1) * a;
    }
    a *= 10;
  }
  std::printf("%d\n", ans);
  return 0;
}