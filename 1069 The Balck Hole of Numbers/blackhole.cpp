#include <cstdio>
#include <cstring>
#include <algorithm>

void minus(char* n1, char* n2, char* ans);
bool bigger(char i, char j);

int main(int argc, char const *argv[])
{
  char num[5];
  char rvNum[5];
  char next[5];
  std::scanf("%s", num);
  int len = strlen(num);
  if (len < 4)
  {
    for (int i = len - 1; i >= 0; --i)
    {
      num[3 - (len - 1 - i)] = num[i];
    }
    for (int i = 0; i < 4 - len; ++i)
    {
      num[i] = '0';
    }
  }
  while(1) 
  {
    minus(num, rvNum, next);
    printf("%s - %s = %s\n", num, rvNum, next);
    if (strcmp(next, "6174") == 0 || strcmp(next, "0000") == 0)
    {
      break;
    }
    strcpy(num, next);
  }
  return 0;
}

void minus(char* n1, char* n2, char* ans)
{
  std::sort(n1, n1 + 4, bigger);
  strcpy(ans, n1);
  for (int i = 3; i >= 0; --i)
  {
    n2[i] = n1[3-i];
    ans[i] = '0' + ans[i] - n2[i];
    if (ans[i] < '0')
    {
      ans[i] += 10;
      --ans[i-1];
    }
  }
}

bool bigger(char i, char j)
{
  return i > j;
}