#include <cstdio>
#include <cstring>
#include <algorithm>

struct _num
{
  char n[9];
  int l;
};

bool numcmp(_num s1, _num s2);

int main(int argc, char const *argv[])
{
  int n;
  _num num[10001];
  std::scanf("%d", &n);
  for (int i = 0; i < n; ++i)
  {
    std::scanf("%s", num[i].n);
    num[i].l = strlen(num[i].n);
  }
  std::sort(num, num + n, numcmp);
  bool flag = true;
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < num[i].l; ++j)
    {
      if (flag && num[i].n[j] == '0');
      else
      {
        flag = false;
        printf("%c", num[i].n[j]);
      }
    }
  }
  if (flag)
  {
    std::printf("0");
  }
  printf("\n");
  return 0;
}

bool numcmp(_num s1, _num s2)
{
  char ss1[17];
  ss1[16] = '\0';
  char ss2[17];
  ss2[16] = '\0';
  strcpy(ss1, s1.n);
  strcpy(ss1 + s1.l, s2.n);
  strcpy(ss2, s2.n);
  strcpy(ss2 + s2.l, s1.n);
  return strcmp(ss1, ss2) < 0;
}
