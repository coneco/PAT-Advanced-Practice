#include <cstdio>
#include <cstring>

int m = 0;
int stack[100005];
int distr[100005] = {0};
int median;
int cnt = 0;

void push(int num);
void pop();

int main(int argc, char const *argv[])
{
  int n;
  std::scanf("%d", &n);
  while(n--) 
  {
    char comm[15];
    std::scanf("%s", comm);
    if (strcmp(comm, "Push") == 0)
    {
      int num;
      std::scanf("%d", &num);
      push(num);
    }
    if (strcmp(comm, "Pop") == 0)
    {
      pop();
    }
    if (strcmp(comm, "PeekMedian") == 0)
    {
      if (m)
      {
        printf("%d\n", median);
      }
      else
      {
        std::printf("Invalid\n");
      }
    }
  }
  return 0;
}

void push(int num)
{
  stack[m] = num;
  ++distr[num];
  ++m;
  if(m == 1)
  {
    median = num;
    ++cnt;
  }
  else if (num <= median)
  {
    ++cnt;
    if (cnt - distr[median] >= ((m%2) ? (m + 1)/2 : m/2))
    {
      int temp;
      for (int i = median - 1; 1; --i)
      {
        if (distr[i])
        {
          temp = i;
          break;
        }
      }
      cnt -= distr[median];
      median = temp;
    }
  }
  else
  {
    if (cnt < ((m%2) ? (m + 1)/2 : m/2))
    {
      int temp;
      for (int i = median + 1; 1; ++i)
      {
        if (distr[i])
        {
          temp = i;
          break;
        }
      }
      median = temp;
      cnt += distr[median];
    }
  }
}

void pop()
{
  if (!m)
  {
    std::printf("Invalid\n");
    return;
  }
  --m;
  int poped = stack[m];
  std::printf("%d\n", poped);
  --distr[poped];
  if (m)
  {
    if (poped <= median)
    {
      --cnt;
      if (cnt < ((m%2) ? (m + 1)/2 : m/2))
      {
        int temp;
        for (int i = median + 1; 1; ++i)
        {
          if (distr[i])
          {
            temp = i;
            break;
          }
        }
        median = temp;
        cnt += distr[median];
      }
    }
    else
    {
      if (cnt - distr[median] >= ((m%2) ? (m + 1)/2 : m/2))
      {
        int temp;
        for (int i = median - 1; 1; --i)
        {
          if (distr[i])
          {
            temp = i;
            break;
          }
        }
        cnt -= distr[median];
        median = temp;
      }
    }
  }
}
