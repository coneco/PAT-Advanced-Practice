#include <cstdio>

#ifndef MAX
#define MAX(a, b) (a > b ? a : b)
#endif

typedef struct treeNode* pNode;

struct treeNode
{
  int num;
  int depth;
  pNode pLeft;
  pNode pRight;
};

int depth(pNode tree)
{
  if (tree != NULL)
  {
    return tree->depth;
  }
  else
  {
    return 0;
  }
}

pNode llr(pNode root)
{
  pNode newRoot = root -> pLeft;
  root -> pLeft = newRoot -> pRight;
  newRoot -> pRight = root;

  root -> depth = MAX(depth(root -> pLeft), depth(root -> pRight)) + 1;
  newRoot -> depth = MAX(depth(newRoot -> pLeft), root -> depth);
  return newRoot;
}

pNode rrr(pNode root)
{
  pNode newRoot = root -> pRight;
  root -> pRight = newRoot -> pLeft;
  newRoot -> pLeft = root;

  root -> depth = MAX(depth(root -> pLeft), depth(root -> pRight)) + 1;
  newRoot -> depth = MAX(depth(newRoot -> pRight), root -> depth);
  return newRoot;
}

pNode lrr(pNode root)
{
  root -> pLeft = rrr(root -> pLeft);
  return llr(root);
}

pNode rlr(pNode root)
{
  root -> pRight = llr(root -> pRight);
  return rrr(root);
}


pNode add(pNode tree, int k)
{
  if (tree == NULL)
  {
    tree = new treeNode;
    tree->num = k;
    tree->pLeft = NULL;
    tree->pRight = NULL;
  }
  else if (k < tree->num)
  {
    tree->pLeft = add(tree->pLeft, k);
    if (depth(tree->pLeft) - depth(tree->pRight) == 2)
    {
      if (k < tree->pLeft->num)
      {
        tree = llr(tree);
      }
      else
      {
        tree = lrr(tree);
      }
    }
  }
  else if (k > tree->num)
  {
    tree->pRight = add(tree->pRight, k);
    if (depth(tree->pRight) - depth(tree->pLeft) == 2)
    {
      if (k < tree->pRight->num)
      {
        tree = rlr(tree);
      }
      else
      {
        tree = rrr(tree);
      }
    }
  }
  tree->depth = MAX(depth(tree->pLeft), depth(tree->pRight)) + 1;
  return tree;
}

int main(int argc, char const *argv[])
{
  pNode avl = NULL;
  int n;
  std::scanf("%d", &n);
  while(n--) 
  {
    int k;
    std::scanf("%d", &k);
    avl = add(avl, k);
  }
  std::printf("%d\n", avl->num);
  return 0;
}
