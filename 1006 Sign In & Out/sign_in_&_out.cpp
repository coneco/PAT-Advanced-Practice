#include <iostream>
#include <cstdio>
#include <string>

typedef struct tempus
{
  long int h;
  long int m;
  long int s;
} tim;

int rather (tim a, tim b)
{
  if ((a.h << 12) + (a.m << 6) + a.s > (b.h << 12) + (b.m << 6) + b.s)
  {
    return 1;
  } else {
    return 0;
  }
}

int main(int argc, char const *argv[])
{
  int m;
  std::cin >> m;
  std::string id, firster, laster;
  tim in, out;

  tim mostEarly = {.h = 24, .m = 0, .s = 0};
  tim mostLate = {.h = 0, .m = 0, .s = 0};
  while(m--)
  {
    std::cin >> id ;
    std::scanf("%ld:%ld:%ld", &in.h, &in.m, &in.s);
    std::scanf("%ld:%ld:%ld", &out.h, &out.m, &out.s);
    if(rather(mostEarly, in))
    {
      mostEarly = in;
      firster = id;
    }
    if(rather(out, mostLate))
    {
      mostLate = out;
      laster = id;
    }
  }

  std::cout << firster << ' ' << laster << std::endl;
  
  return 0;
}
