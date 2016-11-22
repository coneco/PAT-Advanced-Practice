#include <cstdio>
#include <cstring>

char sentence[1001];

int symlen(int k);
int symlen2(int k);

int main(int argc, char const *argv[])
{
  std::gets(sentence);
  int len = strlen(sentence);
  int prt = 0;
  for (int i = 0; i < len; ++i)
  {
    int s = symlen(i);
    if (s > prt)
    {
      prt = s;
    }
  }
  for (int i = 0; i < len - 1; ++i)
  {
    int s = symlen2(i);
    if (s > prt)
    {
      prt = s;
    }
  }
  std::printf("%d\n", prt);
  return 0;
}

int symlen(int k)
{
  int ret = 1;
  int s = k - 1;
  int e = k + 1;
  while(s >= 0 && k < 1001) 
  {
    if (sentence[s] != sentence[e])
    {
      break;
    }
    ret += 2;
    --s;
    ++e;
  }
  return ret;
}

int symlen2(int k)
{
  int ret = 0;
  int s = k;
  int e = k + 1;
  while(s >= 0 && k < 1001) 
  {
    if (sentence[s] != sentence[e])
    {
      break;
    }
    ret += 2;
    --s;
    ++e;
  }
  return ret;
}