#include <iostream>

int n;
int tree[1000];
int postree[1000];

bool isBST(int begin, int end, int postBegin, int postEnd);
bool ismBST(int begin, int end, int postBegin, int postEnd);

int main(int argc, char const *argv[])
{
  std::cin >> n;
  for (int i = 0; i < n; ++i)
  {
    std::cin >> tree[i];
  }
  if (isBST(0, n, 0, n) || ismBST(0, n, 0, n))
  {
    std::cout << "YES" << std::endl;
    std::cout << postree[0];
    for (int i = 1; i < n; ++i)
    {
      std::cout << ' ' << postree[i];
    }
    std::cout << std::endl;
  } 
  else
  {
    std::cout << "NO" << std::endl;
  }
  return 0;
}

bool isBST(int begin, int end, int postBegin, int postEnd)
{
  int length = end - begin;
  if (length < 3)
  {
    postree[postEnd - 1] = tree[begin];
    if (length == 2)
    {
      postree[postBegin] = tree[end - 1];
    }
    return true;
  }
  int rBegin = 0, lLength = 0;
  for (int i = begin + 1; i < end; ++i)
  {
    if (tree[i] >= tree[begin])
    {
      rBegin = i;
      break;
    }
    lLength++;
  }
  if (rBegin > 0)
  {
    for (int i = rBegin + 1; i < end; ++i)
    {
      if (tree[i] < tree[begin])
      {
        return false;
      }
    }
  }
  postree[postEnd - 1] = tree[begin];
  if (rBegin == 0 || rBegin == begin + 1)
  {
    return isBST(begin + 1, end, postBegin, postEnd - 1);
  } 
  else
  {
    return isBST(begin + 1, rBegin, postBegin, postBegin + lLength) && isBST(rBegin, end, postBegin + lLength, postEnd - 1);
  }
}

bool ismBST(int begin, int end, int postBegin, int postEnd)
{
  int length = end - begin;
  if (length < 3)
  {
    postree[postEnd - 1] = tree[begin];
    if (length == 2)
    {
      postree[postBegin] = tree[end - 1];
    }
    return true;
  }
  int rBegin = 0, lLength = 0;
  for (int i = begin + 1; i < end; ++i)
  {
    if (tree[i] < tree[begin])
    {
      rBegin = i;
      break;
    }
    lLength++;
  }
  if (rBegin > 0)
  {
    for (int i = rBegin + 1; i < end; ++i)
    {
      if (tree[i] >= tree[begin])
      {
        return false;
      }
    }
  }
  postree[postEnd - 1] = tree[begin];
  if (rBegin == 0 || rBegin == begin + 1)
  {
    return ismBST(begin + 1, end, postBegin, postEnd - 1);
  } 
  else
  {
    return ismBST(begin + 1, rBegin, postBegin, postBegin + lLength) && ismBST(rBegin, end, postBegin + lLength, postEnd - 1);
  }
}
