#include <cstdio>
#include <cstring>

void getd(char* n, int len, char* nn, int* k);

int main(int argc, char const *argv[])
{
  char n1[200];
  char n2[200];
  char nn1[200];
  char nn2[200];
  int n, len1, len2;
  std::scanf("%d %s %s", &n, &n1, &n2);
  
  getd(n1, n, nn1, &len1);
  getd(n2, n, nn2, &len2);
  if (strcmp(nn1, nn2) == 0 && len1 == len2)
  {
    std::printf("YES 0.%s*10^%d\n", nn1, len1);
  }
  else
  {
    std::printf("NO 0.%s*10^%d 0.%s*10^%d\n", nn1, len1, nn2, len2);
  }
  return 0;
}

void getd(char* n, int len, char* nn, int* k)
{
  int i = 0, cnt = 0, pPoint = 0, pBegin;
  bool begin = false, end = false;
  while(n[i]) 
  {
    if (n[i] == '.')
    {
      pPoint = i;
      ++i;
      continue;
    }
    if (!cnt && n[i] == '0')
    {
      ++i;
      continue;
    }
    if (!cnt)
    {
      pBegin = i;
    }
    if (cnt < len)
    {
      nn[cnt] = n[i];
      ++cnt;
      ++i;
    }
    else
    {
      ++i;
    }
    
    if (cnt == len)
    {
      end = true;
    }
  }

  bool zero = false;
  while(cnt < len) 
  {
    nn[cnt] = '0';
    ++cnt;
  }
  
  nn[len] = '\0';
  
  if (!pPoint)
  {
    pPoint = i;
  }
  *k = pPoint - pBegin;
  if (*k < 0)
  {
    ++*k;
  }
  if (nn[0] == '0')
  {
    *k = 0;
  }
}