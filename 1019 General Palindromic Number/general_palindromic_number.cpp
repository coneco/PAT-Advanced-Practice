#include <iostream>

long int n, b, wei = 0;
long int num[100] = {0};

void getNum();
bool isPalin();

int main(int argc, char const *argv[])
{
  std::cin >> n >> b;

  getNum();
  if (isPalin())
  {
    std::cout << "Yes" << std::endl;
  }
  else
  {
    std::cout << "No" << std::endl;
  }
  std::cout << num[wei - 1];
  for (int i = wei - 2; i >= 0; --i)
  {
    std::cout << " " << num[i];
  }
  std::cout << std::endl;

  return 0;
}

void getNum()
{
  while(n) 
  {
    num[wei] = n % b;
    ++wei;
    n /= b;
  }
}

bool isPalin()
{
  int minWei = 0;
  int maxWei = wei - 1;
  while(minWei<maxWei) 
  {
    if (num[minWei] != num[maxWei])
    {
      return false;
    }
    ++minWei;
    --maxWei;
  }
  return true;
}