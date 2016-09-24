#include <iostream>
#include <string>

long int radix10 (std::string n, long int r);
long int minRadix (std::string n);
int compare (std::string n2, long int r, long int num1);
long int max (long int n1, long int n2);
long int bSearch (std::string n2, long int num1);

int main (int argc, char const *argv[])
{
  int pruned = 0;
  std::string n1, n2;
  long int tag, radixN1;
  std::cin >> n1 >> n2 >> tag >> radixN1;
  if (tag == 2)
  {
    n1.swap(n2);
  }

  if (n1 == n2)
  {
    if (n1.length() == 1)
    {
      std::cout << radix10(n1, radixN1) + 1 << std::endl;
    } else {
      std::cout << radixN1 << std::endl;
    }
    pruned = 1;

  }

  if (!pruned)
  {
    long int res = bSearch(n2, radix10(n1, radixN1)); //pruning method in csdn is buggy
    if (res)
    {
      std::cout << res << std::endl;
    } else {
      std::cout << "Impossible" << std::endl;
    }
  }
  

  return 0;
}

long int radix10 (std::string n, long int r)
{
  long int num, ret = 0;
  
  for (int i = 0; i < n.length(); ++i)
  {
    if(n[i] >= '0' && n[i] <= '9') num = n[i] - '0';  
    else num = n[i] - 'a' + 10;  
    ret = ret * r + num;
  }
  return ret;
}

long int minRadix (std::string n)
{
  long int num, ret = 0;
  for (int i = 0; i < n.length(); ++i)
  {
    if(n[i] >= '0' && n[i] <= '9') num = n[i] - '0';  
    else num = n[i] - 'a' + 10;
    if (num > ret) ret = num;
  }
  return ret + 1;
}

//if n2 is larger than num1 at radix r return 1
//equal return 0
//less return -1 
int compare (std::string n2, long int r, long int num1)
{
  long int num, num2 = 0;
  long int d = 1;

  for (int i = n2.length() - 1; i >= 0; --i)
  {
    if(n2[i] >= '0' && n2[i] <= '9') num = n2[i] - '0';  
    else num = n2[i] - 'a' + 10;

    num2 += num * d;
    if (num2 > num1)
    {
      return 1;
    }
    d *= r;
  }

  if (num2 == num1)
  {
    return 0;
  }
  return -1;

}

long int max (long int n1, long int n2)
{
  return n1 > n2 ? n1 : n2;
}

long int bSearch (std::string n2, long int num1)
{
  long int left = minRadix(n2);
  long int right = max(left, num1);
  long int mean;

  while (left <= right)
  {
    mean = (left + right) / 2;
    int res = compare(n2, mean, num1);
    if (res == 0) return mean;
    else if (res == 1) right = mean - 1;
    else left = mean + 1; 
  }

  return 0;
}