#include <stdio.h>
  
int main()
{
  int a, b, s, absS, isHead;
  while(scanf("%d %d", &a, &b) != EOF)
  {
    isHead = 1;
    s = a + b;
    absS = s;
    if (s < 0) 
    {
      printf("-");
      absS = 0 - s;
    }
    if (absS >= 1000000)
    {
      isHead = 0;
      printf("%d,", absS / 1000000);
      absS = absS % 1000000;
    }
    if (absS >= 1000) 
    {
      if (isHead)
      {
        isHead = 0;
        printf("%d,", absS / 1000);
        absS = absS % 1000;
      } else 
      {
        printf("%.3d,", absS / 1000);
        absS = absS % 1000;
      }
    } else if (!isHead)
    {
      printf("000,");
    }
    if (isHead) 
    {
      printf("%d\n", absS);
    } else
    {
      printf("%.3d\n", absS);
    }
  }
  return 0;
}
