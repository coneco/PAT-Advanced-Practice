#include <cstdio>
#include <cstring>

char sn[100000];
char on[100000];

int main(int argc, char const *argv[])
{
  std::scanf("%s", sn);
  int pPoint, pE = 0, pStart = 0;
  bool positive = sn[0] != '-';
  strcpy(sn, sn + 1);
  int len = strlen(sn);
  for (int i = 0; i < len; ++i)
  {
    if (sn[i] == 'E')
    {
      pE = i;
    }
  }
  int e = 0;
  int wei = 1;
  for (int i = len - 1; i > pE + 1; --i)
  {
    
    e += (sn[i] - '0') * wei;
    wei *= 10;
  }
  if (sn[pE+1] == '-')
  {
    e *= -1;
  } 
  if (!positive)
  {
    std::printf("-");
  }

  int zeros;
  if (e < 0)
  {
    std::printf("0.");
    for (int i = 0; i < 0 - e - 1; ++i)
    {
      std::printf("0");
    }
    std::printf("%c", sn[0]);
    for (int i = 2; i < pE; ++i)
    {
      std::printf("%c", sn[i]);
    }
  }
  else if (e < pE - 2)
  {
    std::printf("%c", sn[0]);
    for (int i = 2; i < pE; ++i)
    {
      if (i == e + 2)
      {
        std::printf(".");
      }
      std::printf("%c", sn[i]);
    }
  } 
  else
  {
    std::printf("%c", sn[0]);
    for (int i = 2; i < pE; ++i)
    {
      std::printf("%c", sn[i]);
    }
    for (int i = 0; i < e - pE + 2; ++i)
    {
      std::printf("0");
    }
  }
  printf("\n");
  return 0;
}