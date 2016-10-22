#include <cstdio>
#include <algorithm>

typedef struct $station
{
  double price;
  int dist;
} sta;
sta stations[501];

bool cmpSta(sta s1, sta s2);

int main(int argc, char const *argv[])
{
  int cMax, d, dAvg, n;
  std::scanf("%d %d %d %d", &cMax, &d, &dAvg, &n);
  for (int i = 0; i < n; ++i)
  {
    sta newOne;
    std::scanf("%lf %d", &((stations+i)->price), &((stations+i)->dist));
  }
  
  std::sort(stations, stations + n, cmpSta);
  
  int position = 0;
  int 
  return 0;
}

bool cmpSta(sta s1, sta s2)
{
  return s1.dist < s2.dist;
}