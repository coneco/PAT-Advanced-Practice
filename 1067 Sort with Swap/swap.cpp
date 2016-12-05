#include <cstdio>

int ary[100005];
int N;

void swap(int* i1, int* i2)
{
  int temp = *i1;
  *i1 = *i2;
  *i2 = temp;
}

int M = 0;

int sort0(int k)
{

}

int main(int argc, char const *argv[])
{
  std::scanf("%d", &N);
  for (int i = 0; i < N; ++i)
  {
    std::scanf("%d", ary + i);
  }
  while(ary[0] != 0) 
  {
    int temp = ary[0];
    swap(ary, ary + temp);
    ++M;
  }
  for (int i = 1; i < N; ++i)
  {
    while (ary[i] != i)
    {
      swap(ary, ary + i);
      ++M;
      while(ary[0] != 0) 
      {
        int temp = ary[0];
        swap(ary, ary + temp);
        ++M;
      }
    }
  }
  printf("%d\n", M);
  return 0;
}