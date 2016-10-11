#include <iostream>
#include <cstdio>
#include <string>

int main(int argc, char const *argv[])
{
  std::string s1;
  int sub[256] = {0};
  std::getline(std::cin, s1);
  char c;
  do
  {
    c = std::getchar();
    sub[c] = 1;
  } while (c != '\n');
  for (int i = 0; i < s1.length(); ++i)
  {
    if (!sub[s1[i]])
    {
      std::cout << s1[i];
    }
  }
  std::cout << std::endl;
  return 0;
}