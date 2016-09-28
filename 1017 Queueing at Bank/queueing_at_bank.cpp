#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

typedef struct bank_customer
{
  int aTime;
  int sLength;
} customer;

bool cusCmp (customer c1, customer c2);
bool empty (int* isServing, int k);

int main(int argc, char const *argv[])
{
  std::vector<customer> customers;
  int n, k, nServed = 0;
  int maxLength = 0;
  std::cin >> n >> k;
  for (int i = 0; i < n; ++i)
  {
    int hh, mm, ss;
    int sLength;
    customer cur;
    std::scanf("%d:%d:%d %d", &hh, &mm, &ss, &sLength);
    cur.aTime = (hh - 8) * (3600) + mm * 60 + ss;
    if (cur.aTime > 32400)
    {
      continue;
    }
    sLength *= 60;
    if (sLength > maxLength)
    {
      maxLength = sLength;
    }
    cur.sLength = sLength;
    customers.push_back(cur);
    ++nServed;
  }

  sort(customers.begin(), customers.end(), cusCmp);

  int totalWait = 0;
  int tRemain[100] = {0};
  int isServing[100] = {0};
  int now = 0;
  std::vector<customer>::iterator iter = customers.begin();

  while (iter != customers.end())
  {
    for (int i = 0; i < k; ++i)
    {
      if (!isServing[i] && iter != customers.end() && now >= (*iter).aTime)
      {
        isServing[i] = 1;
        tRemain[i] = (*iter).sLength;
        totalWait += (now - (*iter).aTime);
        ++iter;
      }
    }

    if (now < (*iter).aTime && empty(isServing, k))
    {
      now = (*iter).aTime;
      continue;
    }

    int minRemain = maxLength + 1;
    int minRI;
    for (int i = 0; i < k; ++i)
    {
      if (isServing[i] && tRemain[i] < minRemain)
      {
        minRI = i;
        minRemain = tRemain[i];
      }
    }

    if (now < (*iter).aTime && now + minRemain > (*iter).aTime)
    {
      minRemain = (*iter).aTime - now;
      for (int i = 0; i < k; ++i)
      {
        if (isServing[i])
        {
          tRemain[i] -= minRemain;
        }
      }
      now = (*iter).aTime;
      continue;
    }

    now += minRemain;
    for (int i = 0; i < k; ++i)
    {
      if (isServing[i])
      {
        tRemain[i] -= minRemain;
      }
    }
    isServing[minRI] = 0;

  }

  std::printf("%.1f\n", (totalWait / 60.0) / nServed);

  return 0;
}

bool cusCmp (customer c1, customer c2)
{
  return c1.aTime < c2.aTime;
}

bool empty (int* isServing, int k)
{
  for (int i = 0; i < k; ++i)
  {
    if (isServing[i])
    {
      return false; 
    }
  }
  return true;
}