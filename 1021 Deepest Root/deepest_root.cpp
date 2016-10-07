#include <iostream>
#include <cstring>
#include <map>
#include <vector>

int size, depth;
std::map<int, std::vector<int> > mapGraph;
int* pre;
int* deep;
bool* visited;


int find(int x);
int mix(int x, int y);
int rootLength(int root, int h);

int main(int argc, char const *argv[])
{
  std::cin >> size;
  pre = new int[size + 1];
  deep = new int[size + 1];
  visited = new bool[size + 1];
  for (int i = 1; i < size + 1; ++i)
  {
    pre[i] = i;
  }
  for (int i = 0; i < size-1; ++i)
  {
    int x,y;
    std::cin >> x >> y;
    mapGraph[x].push_back(y);
    mapGraph[y].push_back(x);
    mix(x, y);
  }

  int k = 0;
  bool* t = new bool[size + 1];
  memset(t, 0, sizeof(t));
  for (int i = 1; i < size + 1; ++i)
  {
    t[find(i)]=true;
  }
  for (int i = 1; i < size + 1; ++i)
  {
    if (t[i])
    {
      ++k;
    }
  }
  delete[] t;
  
  if (k >= 2)
  {
    std::cout << "Error: " << k << " components" << std::endl;
  }
  else
  {

    bool* deepests = new bool[size + 1];

    for (int j = 0; j < size + 1; ++j)
    {
      visited[j] = false;
    }

    depth = rootLength(1, 0);

    int newroot = 1;
    for (int i = 1; i < size + 1; ++i)
    {
      if (deep[i] == depth)
      {
        newroot = i;
        deepests[i] = true;
      } else {
        deepests[i] = false;
      }
    }

    for (int j = 0; j < size + 1; ++j)
    {
      visited[j] = false;
    }

    depth=rootLength(newroot,0);
    for (int i = 1; i < size + 1; ++i)
    {
      if (deep[i] == depth)
      {
        deepests[i] = true;
      }
    }
    std::vector<int> res;
    for (int i = 1; i < size + 1; ++i)
    {
      if (deepests[i])
      {
        res.push_back(i);
      }
    }
    delete[] deepests;
    for (std::vector<int>::iterator i = res.begin(); i != res.end(); ++i)
    {
      std::cout << *i << std::endl;
    }
  }
  
  delete[] deep;
  delete[] visited;
  delete[] pre;
  return 0;
}

int find(int x)
{
  int r = x;
  while(r != pre[r]) 
  {
    r = pre[r];
  }

  int i = x, j;
  while(i != pre[i]) 
  {
    j = pre[i];
    pre[i] = r;
    i = j;
  }
  return r;
}

int mix(int x, int y)
{
  int fx = find(x), fy = find(y);
  if (fx != fy)
  {
    pre[fy] = fx;
  }
}

int rootLength(int root, int h)
{
  visited[root] = true;
  deep[root] = h;
  int ret = h;
  for (std::vector<int>::iterator i = mapGraph[root].begin(); i != mapGraph[root].end(); ++i)
  {
    if (!visited[*i])
    {
      int cur = rootLength(*i, h + 1);
      if (cur > ret) ret = cur;
    }
  }
  return ret;
}