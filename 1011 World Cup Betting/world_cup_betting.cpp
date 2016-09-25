#include <cstdio>

int main(int argc, char const *argv[])
{
  char resList[] = {'W', 'T', 'L'}; 
  char buy[3];
  double cur, max;
  double mProfit = 0.65;
  for (int i = 0; i < 3; ++i)
  {
    max = 0;
    for (int j = 0; j < 3; ++j)
    {
      std::scanf("%lf", &cur);
      if (cur > max)
      {
        max = cur;
        buy[i] = resList[j];
      }
    }
    mProfit *= max;
  }
  mProfit = (mProfit - 1) * 2;
  std::printf("%c %c %c %.2lf\n", buy[0], buy[1], buy[2], mProfit);
  return 0;
}