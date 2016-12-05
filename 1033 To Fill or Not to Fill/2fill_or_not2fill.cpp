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
  stations[n].dist = d;
  std::sort(stations, stations + n, cmpSta);

  int p = 0;
  double cost = 0;
  double tank = 0;

  double dist = 0;
  while(p < n) 
  {
    double range = stations[p].dist + r;
    int next = p, next1 = p, next2 = p + 1;
    for (int i = p + 1; stations[i].dist <= range && i < n; ++i)
    {
      if (stations[i].price < stations[next].price)
      {
        next = i;
        if (next1 == p)
        {
          next1 = i;
        }
      }
      if (stations[i].price < stations[next2].price)
      {
        next2 =i;
      }
    }
    if (next == p)
    {
      if (range >= d)
      {
        double need = (d - stations[p].dist) / dAvg - tank;
        cost += stations[p].price * ( need > 0 ? need : 0);
        break;
      }
      if (range < stations[p+1].dist)
      {
        dist = range;
        break;
      }
      cost += (cMax - tank) * stations[next].price;
      tank = cMax - (stations[next2].dist - stations[p].dist)/dAvg;
      p = next2;
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
        double need = (stations[next1].dist - rangeCur) / dAvg;
        cost += (need > 0 ? need : 0) * stations[p].price;
        tank -= need > 0 ? tank : ((stations[next1].dist - stations[p].dist) / dAvg);
        p = next1;
      }
    }
  }
  if (!dist && !stations[0].dist) std::printf("%.2lf\n", cost);
  else
  {
    if (stations[0].dist)
    {
      std::printf("The maximum travel distance = 0.00\n");
    }
    else
    {
      std::printf("The maximum travel distance = %.2lf\n", dist);
    }
  }
  return 0;
}

bool cmpSta(sta s1, sta s2)
{
  return s1.dist < s2.dist;
}