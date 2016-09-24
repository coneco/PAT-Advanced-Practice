#include <cstdio>

int main() 
{
  int k, f, l, maxFirst, maxLast, sum, maxSum;
  std::scanf("%d", &k);
  int *a = new int[k];

  for (int i = 0; i < k; i++)
  {
    std::scanf("%d", a + i);
  }

  f = l = maxFirst = maxLast = 0;
  sum = maxSum = a[0];
  do
  {
    l += 1;
    if (sum < 0)
    {
      f = l;
      sum = a[l];
    } else {
      sum += a[l];
    }
    if (sum > maxSum)
    {
      maxSum = sum;
      maxFirst = f;
      maxLast = l;
    }
  } while (l < k -1);

  if (maxSum < 0)
  {
    std::printf("%d %d %d\n", 0, a[0], a[k-1]);
  } else {
    std::printf("%d %d %d\n", maxSum, a[maxFirst] ,a[maxLast]);
  }
  

  delete[] a;
  return 0;
}
