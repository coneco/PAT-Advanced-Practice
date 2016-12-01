#include <cstdio>
#include <cmath>
#include <map>

long int n;
bool isPrime = true;
std::map<long int, int> factors;

int main(int argc, char const *argv[])
{
  std::scanf("%ld", &n);
  long int nn = n;
  long int sn = (long int) sqrt(n);
  while(!(n%2) && n != 1) 
  {
    if (factors.find(2) == factors.end())
    {
      factors[2] = 1;
      isPrime = false;
    }
    else
    {
      ++factors[2];
    }
    n /= 2;
  }
  long int i = 3;
  while(i <= sn && n != 1) 
  {
    if (!(n%i))
    {
      if (factors.find(i) == factors.end())
      {
        factors[i] = 1;
        isPrime = false;
      }
      else
      {
        ++factors[i];
      }
      n /= i;
    }
    else
    {
      i += 2;
    }
  }
  if (isPrime)
  {
    std::printf("%ld=%ld\n", n, n);
  }
  else
  {
    std::printf("%ld=", nn);
    std::map<long int, int>::iterator i = factors.begin();
    if ((*i).second == 1)
    {
      std::printf("%ld", (*i).first);
    }
    else
    {
      std::printf("%ld^%d", (*i).first, (*i).second);
    }
    ++i;
    while(i != factors.end()) 
    {
      if ((*i).second == 1)
      {
        std::printf("*%ld", (*i).first);
      }
      else
      {
        std::printf("*%ld^%d", (*i).first, (*i).second);
      }
      ++i;
    }
    std::printf("\n");
  }
  return 0;
}
