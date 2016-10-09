#include <iostream>
#include <vector>
#include <algorithm>

bool isPalin(std::vector<int> arg);

int main(int argc, char const *argv[])
{
  std::vector<int> num;
  int k;
  long int raw;
  std::cin >> raw >> k;
  while(raw) 
  {
    num.push_back(raw%10);
    raw/=10;
  }

  int i = 0;
  while(!isPalin(num) && i < k)
  {
    std::vector<int> temp = num;
    std::vector<int> newNum;
    reverse(temp.begin(), temp.end());
    int fw = 0;
    for (int j = 0; j < num.size(); ++j)
    {
      int sum = num[j] + temp[j] + fw;
      if (sum > 9)
      {
        sum -= 10;
        fw = 1;
      } else {
        fw = 0;
      }
      newNum.push_back(sum);
    }
    if (fw == 1)
    {
      newNum.push_back(1);
    }
    num = newNum;
    newNum.clear();
    ++i;
  }

  for (std::vector<int>::iterator iter = num.end() - 1; iter != num.begin(); --iter)
  {
    std::cout << *iter;
  }
  std::cout << num[0];
  std::cout << std::endl;
  std::cout << i << std::endl;
  return 0;
}

bool isPalin(std::vector<int> arg)
{
  bool ret = true;
  int i = 0;
  int j = arg.size() - 1;
  while(i < j) 
  {
    if (arg[i] != arg[j])
    {
      ret = false;
      break;
    }
    ++i;
    --j;
  }
  return ret;
}