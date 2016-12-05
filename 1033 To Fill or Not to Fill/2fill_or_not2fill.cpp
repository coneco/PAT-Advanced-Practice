#include <cstdio>
#include <algorithm>

typedef struct $station
{
  double price;
  double dist;
} sta;
sta stations[501];

bool cmpSta(sta s1, sta s2);

int main(int argc, char const *argv[])
{
  double cMax, d, dAvg;
  int n;
  std::scanf("%lf %lf %lf %d", &cMax, &d, &dAvg, &n);
  double r = cMax * dAvg;
  for (int i = 0; i < n; ++i)
  {
    sta newOne;
    std::scanf("%lf %lf", &((stations+i)->price), &((stations+i)->dist));
  }
  
  std::sort(stations, stations + n, cmpSta);
  
  int p = 0;
  double cost = 0;
  double tank = 0;

  bool get = false;
  while(p < n) 
  {
    double range = stations[p].dist + r;
    int next = p, next1 = p;
    for (int i = p + 1; stations[i].dist <= range; ++i)
    {
      if (stations[i].price < stations[next].price)
      {
        if (next1 == p)
        {
          next1 = i;
        }
        next = i;
      }
    }
    if (next == p)
    {
      if (range >= d)
      {
        double need = (d - stations[p].dist) / dAvg - tank;
        cost += stations[p].price * ( need > 0 ? need : 0);
        get = true;
        break;
      }
      if (range < stations[p+1].dist)
      {
        break;
      }
      cost += (cMax - tank) * stations[next].price;
      tank = cMax - (stations[p+1].dist - stations[p].dist)/dAvg;
      ++p;
    }
    else
    {
      double rangeCur = stations[p].dist + tank * dAvg;
      if (rangeCur >= stations[next].dist)
      {
        tank -= (stations[next].dist - stations[p].dist) / dAvg;
        p = next;
      }
      else
      {
        double need = (stations[next1].dist - rangeCur) / dAvg - tank;
        cost += (need > 0 ? need : 0) * stations[p].price;
        tank -= need > 0 ? tank : (stations[next1].dist - stations[p].dist) / dAvg;
        p = next1;
      }
    }
  }
  std::printf("%lf\n", cost);
  return 0;
}

bool cmpSta(sta s1, sta s2)
{
  return s1.dist < s2.dist;
}