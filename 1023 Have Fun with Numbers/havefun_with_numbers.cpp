#include <iostream>
#include <algorithm>
#include <string>
#include <map>



int main(int argc, char const *argv[])
{
  std::string sn;
  std::string sn2;
  std::cin >> sn;
  int fw = 0;
  for (int i = sn.length() - 1; i >= 0; --i)
  {
    sn2.append(1, (char)('0' + ((sn[i] - '0') * 2 + fw) % 10));
    fw = ((sn[i] - '0') * 2 + fw) / 10;
  }
  if (fw)
  {
    sn2.append(1, (char)(fw + '0'));
  }
  reverse(sn2.begin(), sn2.end());

  int m1[10] = {0};
  int m2[10] = {0};
  if (sn.length()!=sn2.length())
  {
    std::cout << "No" << std::endl;
  }
  else
  {
    for (int i = 0; i < sn.length(); ++i)
    {
      ++m1[sn[i] - '0'];
      ++m2[sn2[i] - '0'];
    }
    bool flag = true;
    for (int i = 0; i < 10; ++i)
    {
      if (m1[i] != m2[i])
      {
        flag = false;
      }
    }
    if (flag)
    {
      std::cout << "Yes" << std::endl;
    }
    else
    {
      std::cout << "No" << std::endl;
    }
  }
  std::cout << sn2 << std::endl;
  return 0;
}