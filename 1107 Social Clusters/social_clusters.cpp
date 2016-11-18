#include <cstdio>
#include <algorithm>
#define MAX 1002

bool exist[MAX] = {false};
int hobbies[MAX] = {0};
int par[MAX] = {0};

int find(int n);
void merge(int n1, int n2);

int main(int argc, char const *argv[])
{
  for (int i = 0; i < MAX; ++i)
  {
    par[i] = i;
  }
  int n;
  std::scanf("%d", &n);
  while(n--)
  {
    int k, h1;
    std::scanf("%d: %d", &k, &h1);
    k--;
    exist[h1] = true;
    while(k--) 
    {
      int h;
      std::scanf("%d", &h);
      exist[h] = true;
      merge(h1, h);
    }
    hobbies[find(h1)]++;
  }

  int count = 0;
  bool checked[MAX] = {false};
  int member[MAX];
  for (int i = 0; i < MAX; ++i)
  {
    if (exist[i] && find(i) == i && !checked[i])
    {
      checked[i] = true;
      member[count] = hobbies[i];
      count++;
    }
  }
  std::sort(member, member + count);

  std::printf("%d\n%d", count, member[count - 1]);
  --count;
  while(count) 
  {
    std::printf(" %d", member[--count]);
  }

  return 0;
}

int find(int n)
{
  int p = n;
  while(par[p] != p) {
    p = par[p];
  }
  while(par[n] != n) {
    int r = par[n];
    par[n] = p;
    n = r;
  }
  return p;
}

void merge(int n1, int n2)
{
  int pn1 = find(n1);
  int pn2 = find(n2);
  if (pn1 != pn2)
  {
    par[pn2] = pn1;
    hobbies[pn1] += hobbies[pn2];
  }
}