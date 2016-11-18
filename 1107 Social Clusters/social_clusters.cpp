#include <cstdio>

int hobbies[1001] = {0};
int par[1001] = {0};

void find(int n);
void merge(int n1, int n2);

int main(int argc, char const *argv[])
{
  int n;
  std::scanf("%d", &n);
  while(n--)
  {
    int k;
    std::scanf("%d:", &k);
    while(k--) 
    {
      int h;
      std::scanf("%d", &h);

    }
  }
  return 0;
}

void find(int n)
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

