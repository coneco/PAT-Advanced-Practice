#include <cstdio>
#include <cstring>

void rev(char* s);

int main(int argc, char const *argv[])
{
  int n;
  std::scanf("%d", &n);
  char kuchiguse[300];
  char input[300];
  int len;
  std::gets(input);
  for (int i = 0; i < n; ++i)
  {
    std::gets(input);
    len = strlen(input);
    rev(input);
    if (!i)
    {
      strcpy(kuchiguse, input);
    }
    else
    {
      for (int j = 0; j < 300; ++j)
      {
        if (kuchiguse[j] != input[j])
        {
          kuchiguse[j] = '\0';
          break;
        }
      }
    }
  }
  if (strlen(kuchiguse))
  {
    rev(kuchiguse);
    std::printf("%s\n", kuchiguse);
  }
  else
  {
    std::printf("nai\n");
  }
  
  return 0;
}

void rev(char* s)
{
  int len = strlen(s);
  char* start = s;
  char* end = s + len - 1;
  char temp;
  while(start < end) 
  {
    temp = *start;
    *start++ = *end;
    *end-- = temp;
  }
}
