#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main(int argc, char const *argv[])
{
  std::string color[] = {"S", "H", "C", "D"};
  std::vector<std::string> init(54);
  int idx = 0;
  for (int j = 0; j < 4; ++j)
  {
  
    for (int i = 1; i < 14; ++i)
    {
      std::string s;
      std::stringstream ss;
      ss << i;
      ss >> s;
      s = color[j] + s;
      init[idx++] = s;
    }
  }
  init[52] = "J1";
  init[53] = "J2";
  int k;
  int order[54];
  std::vector<std::string> res(54);
  std::cin >> k;
  for (int i = 0; i < 54; ++i)
  {
    std::cin >> order[i];
    --order[i];
  }
  while(k--)
  {
    for (int i = 0; i < 54; ++i)
    {
      res[order[i]] = init[i];
    }
    init = res;
  }
  std::cout << init[0];
  for (int i = 1; i < 54; ++i)
  {
    std::cout << " " << init[i];
  }
  std::cout << std::endl;
  return 0;
}