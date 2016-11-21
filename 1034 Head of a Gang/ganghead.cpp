#include <cstdio>
#include <string>
#include <algorithm>

#ifndef MAX
#define MAX 17576
#endif

int par[MAX];
int head[MAX];
int weight[MAX] = {0};
int tWeight[MAX] = {0};
int num[MAX] = {0};
bool exist[MAX] = {false};

int find(int kid);
void merge(int k1, int k2);
char* i2n(int i);
int n2i(char* n);

int main(int argc, char const *argv[])
{
  for (int i = 0; i < MAX; ++i)
  {
    par[i] = i;
  }

  int n, k;
  
  std::scanf("%d %d", &n, &k);
  for (int i = 0; i < n; ++i)
  {
    char n1[4] = "   ";
    char n2[4] = "   ";
    int w;
    std::scanf("%s %s %d", n1, n2, &w);
    int ni1 = n2i(n1);
    int ni2 = n2i(n2);
    exist[ni1] = exist[ni2] = true;
    tWeight[find(ni1)] += w;
    weight[ni1] += w;
    weight[ni2] += w;
    merge(ni1, ni2);
  }

  for (int i = 0; i < MAX; ++i)
  {
    if (exist[i])
    {
      int pari = find(i);
      ++num[pari];
      if (weight[head[pari]] < weight[i] || num[pari] == 1)
      {
        head[pari] = i;
      }
    }
  }

  int nHead = 0;
  int heads[MAX + 1];
  int numHeads[MAX + 1];
  for (int i = 0; i < MAX; ++i)
  {
    if (num[i] > 2 && tWeight[i] > k)
    {
      heads[nHead] = head[i];
      numHeads[nHead] = num[i];
      ++nHead;
    }
  }

  std::sort(heads, heads+nHead);

  std::printf("%d\n", nHead);
  for (int i = 0; i < nHead; ++i)
  {
    char* hName = i2n(heads[i]);
    std::printf("%s %d\n", hName, numHeads[i]);
    delete[] hName;
  }


  return 0;
}

int find(int kid)
{
  int ret = kid;
  while(par[ret] != ret)
  {
    ret = par[ret];
  }
  int temp;
  while(par[kid] != kid) 
  {
    temp = par[kid];
    par[kid] = ret;
    kid = temp;
  }
  return ret;
}

void merge(int k1, int k2)
{
  int p1 = find(k1);
  int p2 = find(k2);
  if (p1 != p2)
  {
    par[p2] = p1;
    tWeight[p1] += tWeight[p2];
  }
}

char* i2n(int i)
{
  char* n = new char[4];
  n[3] = '\0';
  n[2] = (char)(i % 26 + 'A');
  i /= 26;
  n[1] = (char)(i % 26 + 'A');
  i /= 26;
  n[0] = (char)(i % 26 + 'A');
  return n;
}

int n2i(char* n)
{
  return (n[0] - 'A') * 676 + (n[1] - 'A') * 26 + (n[2]- 'A');
}