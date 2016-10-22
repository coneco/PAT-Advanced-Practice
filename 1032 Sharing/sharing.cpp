#include <cstdio>
#include <map>

int main(int argc, char const *argv[])
{
  std::map<int, bool> linked;
  int f1, f2, n;
  std::scanf("%d %d %d", &f1, &f2, &n);
  if (f1 == f2)
  {
    std::printf("%.5d\n", f1);
  } 
  else
  {
    for (int i = 0; i < n; ++i)
    {
      int addr, next;
      char data;
      std::scanf("%d %c %d", &addr, &data, &next);
      if (linked[next])
      {
        if (next == -1)
        {
          std::printf("%d\n", next);
        }
        else
        {
          std::printf("%.5d\n", next);
        }
        break;
      }
      else
      {
        linked[next] = true;
      }
    }
  }
  return 0;
}