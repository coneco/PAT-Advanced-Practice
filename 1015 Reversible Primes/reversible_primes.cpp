#include <iostream>
#include <cmath>
#include <queue>

int isPrime (int n);
int reverse(int n, int d);

int main(int argc, char const *argv[])
{
  int n;
  int d;
  while (std::cin >> n)
  {
    if (n < 0)
    {
      break;
    }
    std::cin >> d;
    if (isPrime(n) && isPrime(reverse(n, d)))
    {
      std::cout << "Yes" << std::endl;
    } else {
      std::cout << "No" << std::endl;
    }
  }
  
  return 0;
}

int isPrime(int n)
{
  double sqrtn = sqrt(n);
  if (n == 1)
  {
    return 0;
  }
  if (n == 2)
  {
    return 1;
  }
  if (n % 2 == 0)
  {
    return 0;
  }
  for (int i = 3; i < sqrtn + 1; i += 2)
  {
    if (n % i == 0)
    {
      return 0;
    }
  }
  return 1;
}

int reverse(int n, int d)
{
  std::queue<int> nums;
  while (n)
  {
    nums.push(n % d);
    n /= d;
  }

  while(!nums.empty())
  {
    int num = nums.front();
    nums.pop();
    n = n * d + num;
  }

  return n;
}