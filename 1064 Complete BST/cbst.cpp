#include <cstdio>
#include <algorithm>

int tree[1005];
int node[1005];
int N;
int idx = 0;

void buildTree(int root)
{
  if (root > N)
  {
    return;
  }
  buildTree(root * 2);
  tree[root] = node[idx++];
  buildTree(root * 2 + 1);
}

int main(int argc, char const *argv[])
{
  std::scanf("%d", &N);
  for (int i = 0; i < N; ++i)
  {
    std::scanf("%d", node + i);
  }
  std::sort(node, node + N);
  buildTree(1);
  std::printf("%d", tree[1]);
  for (int i = 2; i <= N; ++i)
  {
    std::printf(" %d", tree[i]);
  }
  return 0;
}
