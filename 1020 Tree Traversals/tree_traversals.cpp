#include <iostream>
#include <vector>
#include <queue>

typedef struct biTreeNode
{
  int* postOrder;
  int* inOrder;
  int l;
} btNode;

std::queue<btNode> levelqueue;
std::vector<int> levelOrder;

void getLevelOrder(int* postOrder, int* inOrder, int l);
int getIndex(int n, int* arr, int l);

int main(int argc, char const *argv[])
{
  int n;
  int inOrder[30];
  int postOrder[30];

  std::cin >> n;
  for (int i = 0; i < n; ++i)
  {
    std::cin >> postOrder[i];
  }
  for (int i = 0; i < n; ++i)
  {
    std::cin >> inOrder[i];
  }

  btNode node = {.postOrder = postOrder, .inOrder = inOrder, .l = n};
  levelqueue.push(node);
  while(!levelqueue.empty())
  {
    btNode btnCur = levelqueue.front();
    getLevelOrder(btnCur.postOrder, btnCur.inOrder, btnCur.l);
    levelqueue.pop();
  }

  std::vector<int>::iterator iter = levelOrder.begin();
  std::cout << *iter;
  ++iter;
  while(iter != levelOrder.end()) {
    std::cout << " " << *iter;
    ++iter;
  }
  std::cout << std::endl;
  return 0;
}

int getIndex(int n, int* arr, int l)
{
  for (int i = 0; i < l; ++i)
  {
    if (n == arr[i])
    {
      return i;
    }
  }
  return -1;
}

void getLevelOrder(int* postOrder, int* inOrder, int l)
{
  levelOrder.push_back(postOrder[l - 1]);
  int rootI = getIndex(postOrder[l - 1], inOrder, l);

  btNode node;
  if (rootI > 0)
  {
    node.postOrder = postOrder;
    node.inOrder = inOrder;
    node.l = rootI;
    levelqueue.push(node);
  }

  if (rootI < l - 1)
  {
    node.postOrder = postOrder + rootI;
    node.inOrder = inOrder + rootI + 1;
    node.l = l - rootI - 1;
    levelqueue.push(node);
  }
}
