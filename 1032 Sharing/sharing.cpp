#include <cstdio>
#include <map>
#define MAX 100000

int main(int argc, char const *argv[])
{
  int f1, f2, n;
  std::scanf("%d %d %d", &f1, &f2, &n);
  
  int dict[MAX];
  bool used[MAX] = {false};

  for (int i = 0; i < n; ++i)
  {
    int addr, next;
    char c;
    std::scanf("%d %c %d", &addr, &c, &next);
    dict[addr] = next;
  }

  while (f1 != -1)
  {
    used[f1] = true;
    f1 = dict[f1];
  }

  while (!used[f2] && f2 != -1)
  {
    f2 = dict[f2];
  }
  
  if (f2 == -1)
  {
    std::printf("-1\n");
  }
  else
  {
    std::printf("%.5d\n", f2);
  }
  
  return 0;
}