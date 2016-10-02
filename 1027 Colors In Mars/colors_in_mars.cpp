#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
  int rgb10[3];
  std::string num13 = "0123456789ABC";
  std::string res = "#";
  std::cin >> rgb10[0] >> rgb10[1] >> rgb10[2];
  for (int i = 0; i < 3; ++i)
  {
    std::string temp = "  ";
    temp[1] = num13[rgb10[i] % 13];
    rgb10[i] /= 13;
    temp[0] = num13[rgb10[i]];
    res += temp;
  }
  std::cout << res << std::endl;
  return 0;
}