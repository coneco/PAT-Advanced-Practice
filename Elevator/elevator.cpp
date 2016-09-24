#include <cstdio>

int main(int argc, char const *argv[])
{
  int n, now, next, diff, result = 0;
  now = 0;
  std::scanf("%d", &n);
  while (n--)
  {
    std::scanf("%d", &next);
    diff = next - now;
    if (diff >= 0)
    {
      result += diff * 6;
    } else {
      result += -diff * 4;
    }
    result += 5;
    now = next;
  }
  std::printf("%d\n", result);
  return 0;
}
