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
    //开始服务下一个，如果有空柜台，队列中还有人，且下一个已经到达
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

    // 如果下一个还没到达且柜台已空，时间直接跳转至下一个人到达进入下一循环
    if (now < (*iter).aTime && empty(isServing, k)) 
    {
      now = (*iter).aTime;
      continue;
    }

    //到现在可以保证至少有一个柜台在服务，找到剩余时间最短的柜台
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

    //如果下一个人还没到达，且剩余服务时间最短的柜台结束服务时这个人已经来了，时间进行到这个人到来进入下一循环
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

    //若下一个人已到来但没有柜台可用或要等到剩余时间最短的柜台结束服务后才到，时间进行到下一次服务结束
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