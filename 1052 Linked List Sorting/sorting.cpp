#include <cstdio>
#include <algorithm>

struct node
{
  int addr;
  int key;
  int next;
};

bool cmp(node n1, node n2)
{
  return n1.key < n2.key;
}

int main(int argc, char const *argv[])
{
  node nodes[100001];
  node list[100001];
  int n, head;
  std::scanf("%d %d", &n, &head);
  for (int i = 0; i < n; ++i)
  {
    int addr;
    std::scanf("%d", &addr);
    std::scanf("%d %d", &(nodes[addr].key), &(nodes[addr].next));
    nodes[addr].addr = addr;
  }

  int cur = head;
  int len = 0;
  while(cur != -1) 
  {
    list[len] = nodes[cur];
    ++len;
    cur = nodes[cur].next;
  }
  std::sort(list, list+len, cmp);
  if (len)
  {
    std::printf("%d %.5d\n", len, list[0].addr);
    for (int i = 0; i < len; ++i)
    {
      if (i != len - 1)
      {
        std::printf("%.5d %d %.5d\n", list[i].addr, list[i].key, list[i+1].addr);
      }
      else
      {
        std::printf("%.5d %d -1\n", list[i].addr, list[i].key);
      }
    }
  }
  else
  {
    std::printf("0 -1\n");
  }

  return 0;
}
