#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
  std::string words;
  std::cin >> words;
  int l = words.length();
  int c = (l + 2) % 3;
  int n = (l + 2) / 3;
  int n2;
  if (c == 2)
  {
    n2 = n + 2;
  } else if (c == 1) {
    n2 = n + 1;
  } else {
    n2 = n;
  }
  std::string spaces = "";
  for (int i = 0; i < n2 - 2; ++i)
  {
    spaces += " ";
  }
  int h = 0, t = words.length() - 1;
  while(--n){
    std::cout << words[h++] << spaces << words[t--] << std::endl;
  }
  words = words.substr(h, n2);
  std::cout << words << std::endl;
  return 0;
}