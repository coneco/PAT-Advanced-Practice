#include <cstdio>
#include <cstring>

char s[4][61];
int len[4];

int main(int argc, char const *argv[])
{
  char day[4];
  int hour;
  int min;
  for (int i = 0; i < 4; ++i)
  {
    std::scanf("%s", s[i]);
    len[i] = strlen(s[i]);
  }
  int i = 0;
  for (; 1; ++i)
  {
    if (s[0][i] == s[1][i] && s[0][i] <= 'G' && s[0][i] >= 'A')
    {
      if(s[0][i] == 'A') {
        strcpy(day, "MON");
      }
      else if(s[0][i] == 'B') 
      {
        strcpy(day, "TUE");
      }
      else if(s[0][i] == 'C') 
      {
        strcpy(day, "WED");
      }
      else if(s[0][i] == 'D') 
      {
        strcpy(day, "THU");
      }
      else if(s[0][i] == 'E') 
      {
        strcpy(day, "FRI");
      }
      else if(s[0][i] == 'F') 
      {
        strcpy(day, "SAT");
      }
      else
      {
        strcpy(day, "SUN");
      }
      break;
    }
  }
  ++i;
  for (; i < 60; ++i)
  {
    if (s[0][i] == s[1][i] && ((s[0][i] <= 'N' && s[0][i] >= 'A') || (s[0][i] <= '9' && s[0][i] >= '0')))
    {
      if (s[0][i] < 'A')
      {
        hour = s[0][i] - '0';
      } 
      else
      {
        hour = s[0][i] - 'A' + 10;
      }
      break;
    }
  }
  i = 0;
  for (; i < 60; ++i)
  {
    if (s[3][i] == s[2][i] && ((s[3][i] <= 'z' && s[3][i] >= 'a') || (s[3][i] >= 'A' && s[3][i] <= 'Z')))
    {
      min = i;
      break;
    }
  }
  std::printf("%s %02d:%02d\n", day, hour, min);
  return 0;
}

