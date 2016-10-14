#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

typedef struct $player
{
  int aTime;
  int stay;
  int vip;
} player;

bool cmpPlayer(player p1, player p2);

int main(int argc, char const *argv[])
{
  std::vector<player> players;
  int n;
  std::scanf("%d", &n);
  for (int i = 0; i < n; ++i)
  {
    int aT, sty, v;
    player newOne;
    int a[3];
    std::scanf("%d:%d:%d %d %d", a, a+1, a+2, &sty, &v);
    aT = (a[0] - 8) * 3600 + a[1] * 60 + a[2];
    newOne.aTime = aT;
    newOne.stay = sty * 60;
    newOne.vip = v;
    players.push_back(newOne);
  }
  sort(players.begin(), players.end(), cmpPlayer);

  int k, m;
  std::scanf("%d %d", &k, &m);
  int remain[101] = {0};
  bool vTable[101] = {false};
  for (int i = 0; i < m; ++i)
  {
    int tn;
    std::scanf("%d", &tn);
    vTable[tn] = true;
  }
  int availVipTable = m;

  queue<player> waiting;
  std::vector<player>::iterator nextOne = players.begin();
  int vipInQueue = 0;

  int now = 0;

  while(true)
  {
    while (nextOne != players.end() && (*nextOne).aTime <= now)
    {
      waiting.push(*nextOne);
      ++nextOnel
    }
  }

  for (std::vector<player>::iterator i = players.begin(); i != players.end(); ++i)
  {
    std::printf("%d %d %d\n", (*i).aTime, (*i).stay, (*i).vip);
  }
  return 0;
}

bool cmpPlayer(player p1, player p2)
{
  if (p1.aTime < p2.aTime)
  {
    return true;
  }
  return false;
}