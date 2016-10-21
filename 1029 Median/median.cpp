#include <cstdio>
#define MAX 1000000

int main()
{
  int n1, n2;
  int* s1 = new int[MAX];
  int* s2 = new int[MAX];

  std::scanf("%d", &n1);
  for (int i = 0; i < n1; ++i)
  {
    std::scanf("%d", s1 + i);
  }

  std::scanf("%d", &n2);
  for (int i = 0; i < n2; ++i)
  {
    std::scanf("%d", s2 + i);
  }

  int n = n1 + n2;
  int* s = new int[MAX + MAX];
  for (int i = 0, i1 = 0, i2 = 0; i < n; ++i)
  {
    if ((s1[i1] <= s2[i2] && i1 < n1) || i2 == n2)
    {
      s[i] = s1[i1];
      ++i1;
    }
    else
    {
      s[i] = s2[i2];
      ++i2;
    }
  }
  if (n % 2)
  {
    std::printf("%d\n", s[n / 2]);
  }
  else
  {
    std::printf("%d\n", s[n / 2 - 1]);
  }
  
  delete[] s1;
  delete[] s2;
  delete[] s;
  return 0;
}