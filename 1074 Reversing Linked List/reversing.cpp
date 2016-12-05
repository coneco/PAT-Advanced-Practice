#include <cstdio>
#include <stack>

struct node
{
  int addr;
  int data;
  int next;
};

node lList[100010];
std::stack<node> s;

int main(int argc, char const *argv[])
{
  int f, n, k;
  std::scanf("%d %d %d", &f, &n, &k);
  if(k == 0) k = 1;
  for (int i = 0; i < n; ++i)
  {
    int addr, data, next;
    std::scanf("%d %d %d", &addr, &data, &next);
    lList[addr].addr = addr;
    lList[addr].data = data;
    lList[addr].next = next;
  }
  int cur = f;
  int cnt = k;
  while(cnt < n) 
  {
    for (int i = 0; i < k; ++i)
    {
      if(cur == -1) break;
      s.push(lList[cur]);
      cur = lList[cur].next;
    }
    node temp;
    while(s.size() > 1) 
    {
      temp = s.top();
      std::printf("%.5d %d ", temp.addr, temp.data);
      s.pop();
      temp = s.top();
      std::printf("%.5d\n", temp.addr);
    }
    temp = s.top();
    if (cur!=-1) std::printf("%.5d %d %.5d\n", temp.addr, temp.data, cur);
    else 
    {
      std::printf("%.5d %d %d\n", temp.addr, temp.data, cur);
      break;
    }
    s.pop();
    cnt += k;
  }
  while(cur != -1) 
  {
    if(lList[cur].next!=-1) std::printf("%.5d %d %.5d\n", lList[cur].addr, lList[cur].data, lList[cur].next);
    else std::printf("%.5d %d %d\n", lList[cur].addr, lList[cur].data, lList[cur].next);
    cur = lList[cur].next;
  }
  return 0;
}
