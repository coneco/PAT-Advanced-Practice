#include <iostream>
#include <stack>

bool isPop(int* a, int n, int m);

int main(int argc, char const *argv[])
{
  int m, n, k;
  std::cin >> m >> n >> k;
  while(k--) 
  {
    int* a = new int[n];
    for (int i = 0; i < n; ++i)
    {
      std::cin >> a[i];
    }
    bool res = isPop(a, n, m);
    std::cout << (res?"YES":"NO") << std::endl;
    delete[] a;
  } 
  return 0;
}

bool isPop(int* a, int n, int m)
{
  int cur = 1;
  std::stack<int> stk;
  for (int i = 0; i < n; ++i)
  {
    if (!stk.empty() && a[i] == stk.top())
    {
      stk.pop();
      continue;
    } 
    else if (stk.empty() || a[i] > stk.top())
    {
      while(stk.empty() || stk.top()!=a[i]) 
      {
        stk.push(cur++);
        if (stk.size() > m || cur > n + 1)
        {
          return false;
        }
      }
      stk.pop();
    }
    else{
      return false;
    }
  }
  return true;
}